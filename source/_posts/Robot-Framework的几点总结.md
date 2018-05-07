---
title: Robot-Framework的几点总结
date: 2017-12-16 21:59:38
categories: [RobotFramework]
tags: [robotframework]
---

##### 命令行执行RF用例
```bash
# 执行整个项目下的所有用例
pybot /opt/robotframework/
# 执行某个suite中的所有用例
pybot /opt/robotframework/rf.robot
# 执行具体的某个用例
pybot --test case_1 /opt/robotframework/rf.robot
# 执行项目中指定标签的用例
pybot --include tagName /opt/robotframework/
```

  <!--more-->

##### IDE设置命令行执行RF用例
```bash
# 执行单条用例
/usr/local/bin/pybot -d results -t testcase001 ./
```
{% asset_img SingleTestCase.png SingleTestCase %}

```bash
# 执行单个suite
/usr/local/bin/pybot -d results testsuite001.robot
```
{% asset_img TestSuite.png TestSuite %}

##### 指定RF用例执行后日志的保存位置
其实上面的``-d``参数就是用来指定Log的保存位置的，默认``-d results``指定日志保存在运行命令的目录的``results``文件夹下。
在``ride``中的``run``标签下，``Arguments``中填入``-d results``也能达到同样的效果。

##### 重新运行上一轮``Fail``的``Case``
使用``-R``参数，同``--rerunfailed output``，后面跟前次执行生成的``results/output.xml``，这样就只会运行上次失败了的Case。

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

##### 所有的安装内容
```bash
pip install robotframework
pip install robotframework-ride
pip install robotframework-appiumlibrary
pip install robotframework-selenium2library
pip install robotframework-databaselibrary
pip install robotframework-sshlibrary
pip install robotframework-requests
pip install robotframework-HttpLibrary
pip install robotframework-difflibrary
pip install requests
pip install PyMySQL
pip install MySQL-python
```