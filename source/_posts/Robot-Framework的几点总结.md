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
