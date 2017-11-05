---
title: Robot-Framework踩坑总结
date: 2017-05-15 20:16:55
categories: [ROBOTFRAMEWORK]
tags: [robot-framework]
---

##### List中的字典循环
```robotframework
*** Test Cases ***
takeValueFromCircle
	# 从返回结果中提取出List
	@{items}=    set variable    ${json["data"]["items"]}
	# 循环List中的item
	: FOR    ${params}    IN    @{items}
	# 把item中的一个参数（每个参数都是一个字典）转化为Str格式，顺便去除 "u" 标识
	\    ${params}    Dumps    ${params}
	# 把字典转化为json
	\    ${params}    to json    ${params}
	#\    Log    ${params["carId"]}
	# 对每个item取出来的字典中的某个字段进行判断，如果是需要的值，就把另一个需要的值取出来，并打印出来
	\    RUN KEYWORD IF    "${params["carInfo"]["status"]}"=="评估中"    Log    ${params["carId"]}
```

<!--more-->

##### wait until keyword succeeds关键字使用
```robotframework
*** Test Cases ***
"Wait until ..." with normal error
    # Keyword is run multiple times, until timeout. Each run gives an exception
    # traceback.
    Wait Until Keyword Succeeds    1 sec    0.5    Keyword With Normal Error

"Wait until ..." with AttributeError
    # Keyword is run only once, even if there is time left until the timeout.
    # There is no exception traceback like above.
    Wait Until Keyword Succeeds    1 sec    0.5    Keyword With AttributeError

*** Keywords ***
Keyword With Normal Error
    ${obj} =    Evaluate    "foo"
    Should Be Equal As Strings    ${obj}    "bar"

Keyword With AttributeError
    # In real life, this would get an object and use some of its (valid) attributes.
    # In case of an error, and in Teardown context (continue-on-failure), a None object
    # is returned instead causing the next keyword to create an AttributeError.
    ${obj} =    Evaluate    "foo"
    Should Be Equal As Strings    ${obj.bad_attr}    "foo"
```

```robotframework
*** Test Cases ***
003.导出进度-/pc/export/taizhangaction/progress.json
    wait until keyword succeeds    3 min    5 sec    导出进度-/pc/export/taizhangaction/progress.json
    
*** Keywords ***
导出进度-/pc/export/taizhangaction/progress.json
    ${params}=    Create Dictionary    jobId=${jobId}
    &{json}=    Rest.Post    /pc/export/taizhangaction/progress.json    ${params}    form    ${hosts["erp-online"]}
    Should Be True    ${json["success"]}
	should be equal as strings    ${json["data"]["progress"]}    100
	${URL}=    set variable    ${json["data"]["url"]}
```
5秒执行一次关键字，如果``${json["data"]["progress"]}!=100``，执行一次关键字，直到相等时，执行一次关键字中的最后一行代码。

##### 一个完整的独立case
```robotframework
*** Test Cases ***
登录
    ${dict}=    Create Dictionary    Content-Type=application/x-www-form-urlencoded
    Create Session    _session    http://dfc.souche.com    ${dict}
    ${params}=    Create Dictionary    loginName=15558135526    password=souche2015    jPushId=jpushid001
    ${response}=    Post Request    _session    /rest/account/login    params=${params}    headers=${dict}
    Should Be Equal As Strings    ${response.status_code}    200
    &{json}=    Set Variable    ${response.json()}
    Should Be True    &{json}[success]
    Log    &{json}[success]
```

##### 对请求proxy、tag、headers、session、response的整体封装
```robotframework
*** Keywords ***
Rest.Post
    [Arguments]    ${uri}    ${params}    ${type}=form    ${cur_host}=${EMPTY}
    #设置代理服务器，这样方便调试代码
    &{proxy}=    Create Dictionary    http=http://127.0.0.1:8888
    #根据tag来区分请求应使用哪个host
    ${host}=    Set Variable    \ \ ${EMPTY}
    : FOR    ${tag}    IN    @{TEST TAGS}
    \    ${host}=    Evaluate    $hosts.get($tag,"")
    \    Run Keyword If    "${host}"!=""    Exit For Loop
    #创建session,跨域模式，不需要维护Session
    Run Keyword If    "${cur_host}"!=""    Create Session    _session    ${cur_host}    proxies=${proxy}
    ...    ELSE    Create Session    _session    ${host}    proxies=${proxy}
    #已登录的用户在请求中带上token
    Run Keyword If    "${token}"!=""    Set To Dictionary    ${params}    token=${token}
    Log    ${token}
    #根据请求数据的类型设置header
    &{headers}=    Run Keyword If    "${type}"=="form"    Create Dictionary    Content-Type=application/x-www-form-urlencoded    TT=${token}
    ...    ELSE IF    "${type}"=="json"    Create Dictionary    Content-Type=application/json    TT=${token}
    ${response}=    Post Request    _session    ${uri}    ${params}    headers=&{headers}
    Should Be Equal As Strings    ${response.status_code}    200
    &{json}=    Set Variable    ${response.json()}
    [Return]    &{json}
```