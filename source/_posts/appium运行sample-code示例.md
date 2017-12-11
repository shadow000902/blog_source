---
title: appium运行sample-code示例
date: 2016-03-23 00:09:35
categories: [Appium]
tags: [appium]
---

#### 准备工作
0. android-sdk，jdk，python啥的就不说了，自己解决
1. 安装node.js
2. 安装appium
``` bash
npm install -g appium   # npm --registry http://registry.cnpmjs.org install -g appium (推荐这种,npm的国内镜像)
```

  <!--more-->

3. 检查appium运行环境是否可用
``` bash
C:\Users\shadow>appium
[Appium] Welcome to Appium v1.5.0
[Appium] Appium REST http interface listener started on 0.0.0.0:4723
```
4. 安装selenium (前提已安装好python)
``` bash
pip install selenium    # pip install selenium -i http://pypi.douban.com/simple （使用国内地址）
```
5. 安装appium-python-client
``` bash
pip install Appium-Python-Client
```
至此，需要的软件和环境都已经安装完毕，下面就可以开始去运行sample-code的脚本了

#### 运行Appium
1. 默认方式运行appium
``` bash
C:\Users\shadow>appium
[Appium] Welcome to Appium v1.5.0
[Appium] Appium REST http interface listener started on 0.0.0.0:4723
```
默认运行在本地ip的4723端口，每次运行用例都会重置app

2. 指定方式运行appium
``` bash
C:\Users\shadow>appium -a 127.0.0.1 -p 4723 -U 8XV5T15A20009865 --no-reset
[Appium] Welcome to Appium v1.5.0
[Appium] Non-default server args:
[Appium]   address: '127.0.0.1'
[Appium]   udid: '8XV5T15A20009865'
[Appium]   noReset: true
[Appium] Deprecated server args:
[Appium]   -U,--udid => --default-capabilities '{"udid":"8XV5T15A20009865"}'
[Appium]   --no-reset => --default-capabilities '{"noReset":true}'
[Appium] Default capabilities, which will be added to each request unless overridden by desired capabilities:
[Appium]   udid: '8XV5T15A20009865'
[Appium]   noReset: true
[Appium] Appium REST http interface listener started on 127.0.0.1:4723
```

``` bash
-a 127.0.0.1                                                    # 指定服务器
-p 4723                                                         # 指定端口
-U 8XV5T15A20009865                                             # 指定设备，U指设备的udid
--no-reset                                                      # 直接运行app，而不重置app
```

#### 执行脚本
##### 编辑sample-code中的python脚本，以适应自己的机器运行
脚本存放位置：
在安装appium的时候，同时就下载好了示例脚本和需要的apk文件，存放在C:\Users\shadow\AppData\Roaming\npm\node_modules\appium\sample-code目录中

脚本如下(截取了配置部分)：
```python

PATH = lambda p: os.path.abspath(
    os.path.join(os.path.dirname(__file__), p)
)

class ComplexAndroidTests(unittest.TestCase):
    def setUp(self):
        desired_caps = {}
        desired_caps['platformName'] = 'Android'
        desired_caps['platformVersion'] = '4.4.2'   # 设备的安卓版本
        desired_caps['deviceName'] = 'Nexus_6P'     # 设备的型号，可以在设置-关于里查看
        desired_caps['app'] = PATH(                 # apk存放的相对路径，也可使用绝对路径
            '../../../sample-code/apps/ApiDemos/bin/ApiDemos-debug.apk'
        )

        self.driver = webdriver.Remote('http://localhost:4723/wd/hub', desired_caps)

    def tearDown(self):
        self.driver.quit()
```

##### 运行脚本
2.1 打开appium
``` bash
C:\Users\shadow>appium
[Appium] Welcome to Appium v1.5.0
[Appium] Appium REST http interface listener started on 0.0.0.0:4723
```
2.2 运行python脚本
``` bash
py.test andrid_complex.py
```
如果成功的话就能在打开appium的cmd窗口中看到有log不断的打印出来，结束后，在运行python脚本的cmd窗口就能看到用例的运行结果

我是在git bash下运行的，结果如下：
``` bash
shadow@shadow MINGW64 ~/AppData/Roaming/npm/node_modules/appium/sample-code/examples/python
$ py.test android_complex.py
============================= test session starts =============================
platform win32 -- Python 3.5.1, pytest-2.8.1, py-1.4.30, pluggy-0.3.1
rootdir: C:\Users\shadow\AppData\Roaming\npm\node_modules\appium\sample-code\examples\python, inifile:
collected 3 items

android_complex.py F..

================================== FAILURES ===================================
___________________ ComplexAndroidTests.test_find_elements ____________________

self = <android_complex.ComplexAndroidTests testMethod=test_find_elements>

.........
# 失败项的log

C:\Anaconda3\lib\site-packages\selenium\webdriver\remote\errorhandler.py:194: WebDriverException
==================== 1 failed, 2 passed in 214.41 seconds =====================
```

appium下的结果：
```bash
shadow@shadow MINGW64 ~/Desktop
$ appium
[Appium] Welcome to Appium v1.5.0
[Appium] Appium REST http interface listener started on 0.0.0.0:4723
[HTTP] --> POST /wd/hub/session
[MJSONWP] Calling AppiumDriver.createSession() with args: [{"platformName":"Android","deviceName":"Nexus_6P","platformVersion":"4.4.2","app":"C:\\Users\\shadow\\AppData\\Roaming\\npm\\node_modules\\appium\...
[Appium] Creating new AndroidDriver session
[Appium] Capabilities:
[Appium]   platformName: 'Android'
[Appium]   deviceName: 'Nexus_6P'
[Appium]   platformVersion: '4.4.2'
[Appium]   app: 'C:\\Users\\shadow\\AppData\\Roaming\\npm\\node_modules\\appium\\sample-code\\apps\\ApiDemos\\bin\\ApiDemos-debug.apk'

......
# appium执行的log

[debug] [MJSONWP] Received response: null
[debug] [MJSONWP] But deleting session, so not returning
[MJSONWP] Responding to client with driver.deleteSession() result: null
[HTTP] <-- DELETE /wd/hub/session/f58223b0-4ab0-47b2-b092-e165da16d5f7 200 1943 ms - 76
```

如此，一个用例就成功的运行了

接下来的任务就是如何有效高效的编写高质量的自动化测试用例了~
