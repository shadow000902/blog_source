---
title: Appium运行日志解析
date: 2016-03-31 11:10:40
categories: [Appium]
tags: [appium]
---

#### Appium脚本/python代码     //android_simple.py


  <!--more-->

```python
import os
from time import sleep

import unittest

from appium import webdriver

# Returns abs path relative to this file and not cwd
PATH = lambda p: os.path.abspath(
    os.path.join(os.path.dirname(__file__), p)
)

class SimpleAndroidTests(unittest.TestCase):
    def setUp(self):
        desired_caps = {}
        desired_caps['platformName'] = 'Android'
        desired_caps['platformVersion'] = '6.0'
        desired_caps['deviceName'] = 'Nexus 5'
        desired_caps['app'] = PATH(
            '../../../sample-code/apps/ApiDemos/bin/ApiDemos-debug.apk'
        )

        self.driver = webdriver.Remote('http://localhost:4723/wd/hub', desired_caps)

    def tearDown(self):
        # end the session
        self.driver.quit()

    def test_find_elements(self):
        el = self.driver.find_element_by_accessibility_id('Graphics')
        el.click()
        el = self.driver.find_element_by_accessibility_id('Arcs')
        self.assertIsNotNone(el)

        self.driver.back()

        el = self.driver.find_element_by_accessibility_id("App")
        self.assertIsNotNone(el)

        els = self.driver.find_elements_by_android_uiautomator("new UiSelector().clickable(true)")
        self.assertGreaterEqual(12, len(els))

        self.driver.find_element_by_android_uiautomator('text("API Demos")')


    def test_simple_actions(self):
        el = self.driver.find_element_by_accessibility_id('Graphics')
        el.click()

        el = self.driver.find_element_by_accessibility_id('Arcs')
        el.click()

        self.driver.find_element_by_android_uiautomator('new UiSelector().text("Graphics/Arcs")')


if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(SimpleAndroidTests)
    unittest.TextTestRunner(verbosity=2).run(suite)
```


#### Appium运行日志解析

``` bash
C:\Users\Tao Yi\AppData\Roaming\npm\node_modules\.bin>appium
info: Welcome to Appium v1.4.16 (REV ae6877eff263066b26328d457bd285c0cc62430d)

# 启动REST http服务器，默认监听本地4723端口，用于接收客户端（Test Case+Selenium/Appium Driver)发过来的JSON格式的命令指示
info: Appium REST http interface listener started on 0.0.0.0:4723
info: Console LogLevel: debug

# 根据客户端提供的capabilities指示建立一个Android Sesision用于跟客户端保持后续通信
info: --> POST /wd/hub/session {"desiredCapabilities":{"platformVersion":"6.0","app":"E:\\Appium\\sample-code\
\apps\\ApiDemos\\bin\\ApiDemos-debug.apk","platformName":"Android","deviceName":"Nexus 5"}}
info: Client User-Agent string: Python-urllib/3.5
info: [debug] No appActivity desired capability or server param. Parsing from apk.
info: [debug] No appPackage desired capability or server param. Parsing from apk.
info: [debug] Using local app from desired caps: E:\Appium\sample-code\apps\ApiDemos\bin\ApiDemos-debug.apk
info: [debug] Creating new appium session b3868a3e-3d5e-484a-8202-8b8612591e1b
info: Starting android appium

# 获取jdk、adb信息
info: [debug] Getting Java version
info: Java version is: 1.8.0_45
info: [debug] Checking whether adb is present
info: [debug] Using adb from E:\android-sdk\platform-tools\adb.exe

# 使用工具“aapt dump badging ApiDemos-debug.apk"来获得ApiDemos-debug的packageName和launchable activityName，注意示例代码中是没有指定这个两个capabilities的
info: [debug] Parsing package and activity from app manifest
info: [debug] Checking whether aapt is present
info: [debug] Using aapt from E:\android-sdk\build-tools\android-4.4W\aapt.exe
info: [debug] Extracting package and launch activity from manifest.
info: [debug] executing cmd: E:\android-sdk\build-tools\android-4.4W\aapt.exe dump badging E:\Appium\sample-co
de\apps\ApiDemos\bin\ApiDemos-debug.apk
info: [debug] badging package: io.appium.android.apis
info: [debug] badging act: io.appium.android.apis.ApiDemos
info: [debug] Parsed package and activity are: io.appium.android.apis/io.appium.android.apis.ApiDemos
info: [debug] Using fast reset? true
info: [debug] Preparing device for session
info: [debug] Checking whether app is actually present
info: Retrieving device

# 开始调用adb，找到连接上的设备，设置设备id
info: [debug] Trying to find a connected android device
info: [debug] Getting connected devices...
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe devices
info: [debug] 1 device(s) connected
info: Found device 0721b62c00e1a31f
info: [debug] Setting device id to 0721b62c00e1a31f

# 等待设备准备好响应命令
info: [debug] Waiting for device to be ready and to respond to shell commands (timeout = 5)
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f wait-for-device
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "echo 'ready'"
info: [debug] Starting logcat capture
info: [debug] Getting device API level
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "getprop ro.build
.version.sdk"
info: [debug] Device is at API Level 23
info: Device API level is: 23
info: [debug] Extracting strings for language: default
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "getprop persist.
sys.language"
info: [debug] Current device persist.sys.language:
info: [debug] java -jar "C:\Users\Tao Yi\AppData\Roaming\npm\node_modules\appium\node_modules\appium-adb\jars\
appium_apk_tools.jar" "stringsFromApk" "E:\Appium\sample-code\apps\ApiDemos\bin\ApiDemos-debug.apk" "C:\Users\
Tao Yi\AppData\Local\Temp\io.appium.android.apis"
info: [debug] Reading strings from converted strings.json
info: [debug] Setting language to default

# 将生成的apk属性信息文件strings.json存到了设备目录下
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f push "C:\\Users\\Tao Yi
\\AppData\\Local\\Temp\\io.appium.android.apis\\strings.json" /data/local/tmp
info: [debug] Checking whether aapt is present
info: [debug] Using aapt from E:\android-sdk\build-tools\android-4.4W\aapt.exe
info: [debug] Retrieving process from manifest.
info: [debug] executing cmd: E:\android-sdk\build-tools\android-4.4W\aapt.exe dump xmltree E:\Appium\sample-co
de\apps\ApiDemos\bin\ApiDemos-debug.apk AndroidManifest.xml
info: [debug] Set app process to: io.appium.android.apis
info: [debug] Not uninstalling app since server not started with --full-reset
info: [debug] Checking app cert for E:\Appium\sample-code\apps\ApiDemos\bin\ApiDemos-debug.apk.
info: [debug] executing cmd: java -jar "C:\Users\Tao Yi\AppData\Roaming\npm\node_modules\appium\node_modules\a
ppium-adb\jars\verify.jar" E:\Appium\sample-code\apps\ApiDemos\bin\ApiDemos-debug.apk
info: [debug] App already signed.
info: [debug] Zip-aligning E:\Appium\sample-code\apps\ApiDemos\bin\ApiDemos-debug.apk
info: [debug] Checking whether zipalign is present
info: [debug] Using zipalign from E:\android-sdk\build-tools\android-4.4W\zipalign.exe
info: [debug] Zip-aligning apk.
info: [debug] executing cmd: E:\android-sdk\build-tools\android-4.4W\zipalign.exe -f 4 E:\Appium\sample-code\a
pps\ApiDemos\bin\ApiDemos-debug.apk "C:\Users\Tao Yi\AppData\Local\Temp\116231-12276-7u17bp\appium.tmp"
info: [debug] MD5 for app is 29649242b53e9a67ba855b067422713c
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "ls /data/local/t
mp/29649242b53e9a67ba855b067422713c.apk"
info: [debug] Getting install status for io.appium.android.apis
info: [debug] Getting device API level
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "getprop ro.build
.version.sdk"
info: [debug] Device is at API Level 23

# 读取这个apk安装情况
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "pm list packages
 -3 io.appium.android.apis"

# 读取的结果，apk已经安装
info: [debug] App is installed
info: App is already installed, resetting app
info: [debug] Running fast reset (stop and clear)

# 停止并且重置应用
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "am force-stop io
.appium.android.apis"
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "pm clear io.appi
um.android.apis"

# 建立Appium Server到目标机器上的端口转发
info: [debug] Forwarding system:4724 to device:4724
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f forward tcp:4724 tcp:47
24

# 往设备上push一个AppiumBootstrap.jar文件，这是目标机器上通过uiautomator工具（框架）运行的服务端，用于接受处理client端发送过来的命令
info: [debug] Pushing appium bootstrap to device...
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f push "C:\\Users\\Tao Yi
\\AppData\\Roaming\\npm\\node_modules\\appium\\build\\android_bootstrap\\AppiumBootstrap.jar" /data/local/tmp/

# 往设备上安装一个settings_apk-debug.apk文件
info: [debug] Pushing settings apk to device...
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f install "C:\Users\Tao Y
i\AppData\Roaming\npm\node_modules\appium\build\settings_apk\settings_apk-debug.apk"

# 往设备上安装一个unlock_apk-debug.apk文件
info: [debug] Pushing unlock helper app to device...
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f install "C:\Users\Tao Y
i\AppData\Roaming\npm\node_modules\appium\build\unlock_apk\unlock_apk-debug.apk"
info: Starting App

# kill掉所有的uiautomator进程，保证uiautomator没有在跑
info: [debug] Attempting to kill all 'uiautomator' processes
info: [debug] Getting all processes with 'uiautomator'
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "ps 'uiautomator'
"
info: [debug] No matching processes found

# 通过adb把目标机器上的AppiumBootStrap跑起来
info: [debug] Running bootstrap
info: [debug] spawning: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell uiautomator runtest Ap
piumBootstrap.jar -c io.appium.android.bootstrap.Bootstrap -e pkg io.appium.android.apis -e disableAndroidWatc
hers false
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: numtests=1
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: stream=
info: [debug] [UIAUTOMATOR STDOUT] io.appium.android.bootstrap.Bootstrap:
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: id=UiAutomatorTestRunner
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: test=testRunServer
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: class=io.appium.android.bootstrap.Bootstrap
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: current=1
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS_CODE: 1
info: [debug] [BOOTSTRAP] [debug] Socket opened on port 4724
info: [debug] [BOOTSTRAP] [debug] Appium Socket Server Ready
info: [debug] [BOOTSTRAP] [debug] Loading json...

# 唤醒设备
info: [debug] Waking up device if it's not alive
info: [debug] Pushing command to appium work queue: ["wake",{}]
info: [debug] [BOOTSTRAP] [debug] json loading complete.
info: [debug] [BOOTSTRAP] [debug] Registered crash watchers.
info: [debug] [BOOTSTRAP] [debug] Client connected
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"wake","params":{}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: wake
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "dumpsys window"
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":true}
info: [debug] Screen already unlocked, continuing.
info: [debug] Pushing command to appium work queue: ["getDataDir",{}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"getDataDir","params":{}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: getDataDir
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":"\/data\/local\/tmp"}
info: [debug] dataDir set to: /data/local/tmp
info: [debug] Pushing command to appium work queue: ["compressedLayoutHierarchy",{"compressLayout":false}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"compressedLayoutHierarchy","
params":{"compressLayout":false}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: compressedLayoutHierarchy

# 获取设备API版本
info: [debug] Getting device API level
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "getprop ro.build
.version.sdk"
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":false}
info: [debug] Device is at API Level 23

# 通过adb在目标机器上 Launch ApiDemos应用
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "am start -S -a a
ndroid.intent.action.MAIN -c android.intent.category.LAUNCHER -f 0x10200000 -n io.appium.android.apis/io.appiu
m.android.apis.ApiDemos"
info: [debug] Waiting for pkg "io.appium.android.apis" and activity "io.appium.android.apis.ApiDemos" to be fo
cused
info: [debug] Getting focused package and activity
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "dumpsys window w
indows"
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "getprop ro.build
.version.release"
info: [debug] Device is at release version 6.0
info: [debug] Device launched! Ready for commands
info: [debug] Setting command timeout to the default of 60 secs
info: [debug] Appium session started with sessionId b3868a3e-3d5e-484a-8202-8b8612591e1b
info: <-- POST /wd/hub/session 303 30932.362 ms - 74

# 通知PC端目标应用已经在目标机器启动成功
info: --> GET /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b {}
info: [debug] Responding to client with success: {"status":0,"value":{"platform":"LINUX","browserName":"Androi
d","platformVersion":"6.0","webStorageEnabled":false,"takesScreenshot":true,"javascriptEnabled":true,"database
Enabled":false,"networkConnectionEnabled":true,"locationContextEnabled":false,"warnings":{},"desired":{"platfo
rmVersion":"6.0","app":"E:\\Appium\\sample-code\\apps\\ApiDemos\\bin\\ApiDemos-debug.apk","platformName":"Andr
oid","deviceName":"Nexus 5"},"app":"E:\\Appium\\sample-code\\apps\\ApiDemos\\bin\\ApiDemos-debug.apk","platfor
mName":"Android","deviceName":"0721b62c00e1a31f"},"sessionId":"b3868a3e-3d5e-484a-8202-8b8612591e1b"}
info: <-- GET /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b 200 9.267 ms - 602 {"status":0,"value":{"pl
atform":"LINUX","browserName":"Android","platformVersion":"6.0","webStorageEnabled":false,"takesScreenshot":tr
ue,"javascriptEnabled":true,"databaseEnabled":false,"networkConnectionEnabled":true,"locationContextEnabled":f
alse,"warnings":{},"desired":{"platformVersion":"6.0","app":"E:\\Appium\\sample-code\\apps\\ApiDemos\\bin\\Api
Demos-debug.apk","platformName":"Android","deviceName":"Nexus 5"},"app":"E:\\Appium\\sample-code\\apps\\ApiDem
os\\bin\\ApiDemos-debug.apk","platformName":"Android","deviceName":"0721b62c00e1a31f"},"sessionId":"b3868a3e-3
d5e-484a-8202-8b8612591e1b"}

# 定位菜单按钮：Bootstrap通过的UIAutomator的UISelector类根据Text获得菜单按钮的ID并返回给客户端
info: --> POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/element {"using":"accessibility id","sessi
onId":"b3868a3e-3d5e-484a-8202-8b8612591e1b","value":"Graphics"}
info: [debug] Waiting up to 0ms for condition
info: [debug] Pushing command to appium work queue: ["find",{"strategy":"accessibility id","selector":"Graphic
s","context":"","multiple":false}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"find","params":{"strategy":"
accessibility id","selector":"Graphics","context":"","multiple":false}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: find
info: [debug] [BOOTSTRAP] [debug] Finding Graphics using ACCESSIBILITY_ID with the contextId:  multiple: false

info: [debug] [BOOTSTRAP] [debug] Using: UiSelector[DESCRIPTION=Graphics, INSTANCE=0]
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":{"ELEMENT":"1"}}
info: [debug] Responding to client with success: {"status":0,"value":{"ELEMENT":"1"},"sessionId":"b3868a3e-3d5
e-484a-8202-8b8612591e1b"}

# BootStrap执行“点击”命令
info: <-- POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/element 200 344.090 ms - 87 {"status":0,"v
alue":{"ELEMENT":"1"},"sessionId":"b3868a3e-3d5e-484a-8202-8b8612591e1b"}
info: --> POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/element/1/click {"sessionId":"b3868a3e-3d5
e-484a-8202-8b8612591e1b","id":"1"}
info: [debug] Pushing command to appium work queue: ["element:click",{"elementId":"1"}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"element:click","params":{"el
ementId":"1"}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: click
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":true}
info: [debug] Responding to client with success: {"status":0,"value":true,"sessionId":"b3868a3e-3d5e-484a-8202
-8b8612591e1b"}
info: <-- POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/element/1/click 200 139.311 ms - 76 {"stat
us":0,"value":true,"sessionId":"b3868a3e-3d5e-484a-8202-8b8612591e1b"}
info: --> POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/element {"using":"accessibility id","sessi
onId":"b3868a3e-3d5e-484a-8202-8b8612591e1b","value":"Arcs"}
info: [debug] Waiting up to 0ms for condition
info: [debug] Pushing command to appium work queue: ["find",{"strategy":"accessibility id","selector":"Arcs","
context":"","multiple":false}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"find","params":{"strategy":"
accessibility id","selector":"Arcs","context":"","multiple":false}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: find
info: [debug] [BOOTSTRAP] [debug] Finding Arcs using ACCESSIBILITY_ID with the contextId:  multiple: false
info: [debug] [BOOTSTRAP] [debug] Using: UiSelector[DESCRIPTION=Arcs, INSTANCE=0]
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":{"ELEMENT":"2"}}
info: [debug] Responding to client with success: {"status":0,"value":{"ELEMENT":"2"},"sessionId":"b3868a3e-3d5
e-484a-8202-8b8612591e1b"}
info: <-- POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/element 200 766.030 ms - 87 {"status":0,"v
alue":{"ELEMENT":"2"},"sessionId":"b3868a3e-3d5e-484a-8202-8b8612591e1b"}
info: --> POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/back {"sessionId":"b3868a3e-3d5e-484a-8202
-8b8612591e1b"}
info: [debug] Pushing command to appium work queue: ["pressBack"]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"pressBack","params":{}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: pressBack
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":true}
info: [debug] Responding to client with success: {"status":0,"value":true,"sessionId":"b3868a3e-3d5e-484a-8202
-8b8612591e1b"}
info: <-- POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/back 200 1045.398 ms - 76 {"status":0,"val
ue":true,"sessionId":"b3868a3e-3d5e-484a-8202-8b8612591e1b"}
info: --> POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/element {"using":"accessibility id","sessi
onId":"b3868a3e-3d5e-484a-8202-8b8612591e1b","value":"App"}
info: [debug] Waiting up to 0ms for condition
info: [debug] Pushing command to appium work queue: ["find",{"strategy":"accessibility id","selector":"App","c
ontext":"","multiple":false}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"find","params":{"strategy":"
accessibility id","selector":"App","context":"","multiple":false}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: find
info: [debug] [BOOTSTRAP] [debug] Finding App using ACCESSIBILITY_ID with the contextId:  multiple: false
info: [debug] [BOOTSTRAP] [debug] Using: UiSelector[DESCRIPTION=App, INSTANCE=0]
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":{"ELEMENT":"3"}}
info: [debug] Responding to client with success: {"status":0,"value":{"ELEMENT":"3"},"sessionId":"b3868a3e-3d5
e-484a-8202-8b8612591e1b"}
info: <-- POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/element 200 39.881 ms - 87 {"status":0,"va
lue":{"ELEMENT":"3"},"sessionId":"b3868a3e-3d5e-484a-8202-8b8612591e1b"}
info: --> POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/elements {"using":"-android uiautomator","
sessionId":"b3868a3e-3d5e-484a-8202-8b8612591e1b","value":"new UiSelector().clickable(true)"}
info: [debug] Waiting up to 0ms for condition
info: [debug] Pushing command to appium work queue: ["find",{"strategy":"-android uiautomator","selector":"new
 UiSelector().clickable(true)","context":"","multiple":true}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"find","params":{"strategy":"
-android uiautomator","selector":"new UiSelector().clickable(true)","context":"","multiple":true}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: find
info: [debug] [BOOTSTRAP] [debug] Finding new UiSelector().clickable(true) using ANDROID_UIAUTOMATOR with the
contextId:  multiple: true
info: [debug] [BOOTSTRAP] [debug] Parsing selector: new UiSelector().clickable(true)
info: [debug] [BOOTSTRAP] [debug] UiSelector coerce type: boolean arg: true
info: [debug] [BOOTSTRAP] [debug] Using: UiSelector[CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] getElements selector:UiSelector[CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (0)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=0, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (1)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=1, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (2)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=2, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (3)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=3, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (4)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=4, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (5)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=5, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (6)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=6, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (7)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=7, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (8)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=8, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (9)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=9, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (10)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=10, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (11)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=11, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Element[] is null: (12)
info: [debug] [BOOTSTRAP] [debug] getElements tmp selector:UiSelector[INSTANCE=12, CLICKABLE=true]
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":[{"ELEMENT":"4"},{"ELEMENT":"5"},{"ELE
MENT":"6"},{"ELEMENT":"7"},{"ELEMENT":"8"},{"ELEMENT":"9"},{"ELEMENT":"10"},{"ELEMENT":"11"},{"ELEMENT":"12"},
{"ELEMENT":"13"},{"ELEMENT":"14"},{"ELEMENT":"15"}]}
info: [debug] Responding to client with success: {"status":0,"value":[{"ELEMENT":"4"},{"ELEMENT":"5"},{"ELEMEN
T":"6"},{"ELEMENT":"7"},{"ELEMENT":"8"},{"ELEMENT":"9"},{"ELEMENT":"10"},{"ELEMENT":"11"},{"ELEMENT":"12"},{"E
LEMENT":"13"},{"ELEMENT":"14"},{"ELEMENT":"15"}],"sessionId":"b3868a3e-3d5e-484a-8202-8b8612591e1b"}
info: <-- POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/elements 200 267.317 ms - 271 {"status":0,
"value":[{"ELEMENT":"4"},{"ELEMENT":"5"},{"ELEMENT":"6"},{"ELEMENT":"7"},{"ELEMENT":"8"},{"ELEMENT":"9"},{"ELE
MENT":"10"},{"ELEMENT":"11"},{"ELEMENT":"12"},{"ELEMENT":"13"},{"ELEMENT":"14"},{"ELEMENT":"15"}],"sessionId":
"b3868a3e-3d5e-484a-8202-8b8612591e1b"}
info: --> POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/element {"using":"-android uiautomator","s
essionId":"b3868a3e-3d5e-484a-8202-8b8612591e1b","value":"text(\"API Demos\")"}
info: [debug] Waiting up to 0ms for condition
info: [debug] Pushing command to appium work queue: ["find",{"strategy":"-android uiautomator","selector":"tex
t(\"API Demos\")","context":"","multiple":false}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"find","params":{"strategy":"
-android uiautomator","selector":"text(\"API Demos\")","context":"","multiple":false}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: find
info: [debug] [BOOTSTRAP] [debug] Finding text("API Demos") using ANDROID_UIAUTOMATOR with the contextId:  mul
tiple: false
info: [debug] [BOOTSTRAP] [debug] Parsing selector: text("API Demos")
info: [debug] [BOOTSTRAP] [debug] UiSelector coerce type: class java.lang.String arg: "API Demos"
info: [debug] [BOOTSTRAP] [debug] Using: UiSelector[TEXT=API Demos]
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":{"ELEMENT":"16"}}
info: [debug] Responding to client with success: {"status":0,"value":{"ELEMENT":"16"},"sessionId":"b3868a3e-3d
5e-484a-8202-8b8612591e1b"}
info: <-- POST /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b/element 200 21.357 ms - 88 {"status":0,"va
lue":{"ELEMENT":"16"},"sessionId":"b3868a3e-3d5e-484a-8202-8b8612591e1b"}

# 测试完成，删除session，目标机器模拟点击Home按钮把目标应用放在后台
info: --> DELETE /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b {}
info: Shutting down appium session
info: [debug] Pressing the HOME button
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "input keyevent 3"

# 关闭logcat
info: [debug] Stopping logcat capture
info: [debug] Logcat terminated with code null, signal SIGTERM
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"shutdown"}
info: [debug] [BOOTSTRAP] [debug] Got command of type SHUTDOWN
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":"OK, shutting down"}
info: [debug] [BOOTSTRAP] [debug] Closed client connection
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: numtests=1
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: stream=.
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: id=UiAutomatorTestRunner
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: test=testRunServer
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: class=io.appium.android.bootstrap.Bootstrap
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: current=1
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS_CODE: 0
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: stream=
info: [debug] [UIAUTOMATOR STDOUT] Test results for WatcherResultPrinter=.
info: [debug] [UIAUTOMATOR STDOUT] Time: 5.738
info: [debug] [UIAUTOMATOR STDOUT] OK (1 test)
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS_CODE: -1

# 关闭Uiautomator进程
info: [debug] Sent shutdown command, waiting for UiAutomator to stop...
info: [debug] UiAutomator shut down normally
info: [debug] Cleaning up android objects
info: [debug] Cleaning up appium session
info: [debug] Responding to client with success: {"status":0,"value":null,"sessionId":"b3868a3e-3d5e-484a-8202
-8b8612591e1b"}
info: <-- DELETE /wd/hub/session/b3868a3e-3d5e-484a-8202-8b8612591e1b 200 1101.263 ms - 76 {"status":0,"value"
:null,"sessionId":"b3868a3e-3d5e-484a-8202-8b8612591e1b"}
# 第一个test执行完毕，结束工作完毕

新的test开始执行
info: --> POST /wd/hub/session {"desiredCapabilities":{"platformVersion":"6.0","app":"E:\\Appium\\sample-code\
\apps\\ApiDemos\\bin\\ApiDemos-debug.apk","platformName":"Android","deviceName":"Nexus 5"}}
info: Client User-Agent string: Python-urllib/3.5
info: [debug] No appActivity desired capability or server param. Parsing from apk.
info: [debug] No appPackage desired capability or server param. Parsing from apk.
info: [debug] Using local app from desired caps: E:\Appium\sample-code\apps\ApiDemos\bin\ApiDemos-debug.apk
info: [debug] Creating new appium session 7da33fde-d7a2-4c56-89ad-21d3564cd8d4
info: Starting android appium
info: [debug] Getting Java version
info: Java version is: 1.8.0_45
info: [debug] Checking whether adb is present
info: [debug] Using adb from E:\android-sdk\platform-tools\adb.exe
info: [debug] Parsing package and activity from app manifest
info: [debug] Checking whether aapt is present
info: [debug] Using aapt from E:\android-sdk\build-tools\android-4.4W\aapt.exe
info: [debug] Extracting package and launch activity from manifest.
info: [debug] executing cmd: E:\android-sdk\build-tools\android-4.4W\aapt.exe dump badging E:\Appium\sample-co
de\apps\ApiDemos\bin\ApiDemos-debug.apk
info: [debug] badging package: io.appium.android.apis
info: [debug] badging act: io.appium.android.apis.ApiDemos
info: [debug] Parsed package and activity are: io.appium.android.apis/io.appium.android.apis.ApiDemos
info: [debug] Using fast reset? true
info: [debug] Preparing device for session
info: [debug] Checking whether app is actually present
info: Retrieving device
info: [debug] Trying to find a connected android device
info: [debug] Getting connected devices...
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe devices
info: [debug] 1 device(s) connected
info: Found device 0721b62c00e1a31f
info: [debug] Setting device id to 0721b62c00e1a31f
info: [debug] Waiting for device to be ready and to respond to shell commands (timeout = 5)
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f wait-for-device
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "echo 'ready'"
info: [debug] Starting logcat capture
info: [debug] Getting device API level
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "getprop ro.build
.version.sdk"
info: [debug] Device is at API Level 23
info: Device API level is: 23
info: [debug] Extracting strings for language: default
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "getprop persist.
sys.language"
info: [debug] Current device persist.sys.language:
info: [debug] java -jar "C:\Users\Tao Yi\AppData\Roaming\npm\node_modules\appium\node_modules\appium-adb\jars\
appium_apk_tools.jar" "stringsFromApk" "E:\Appium\sample-code\apps\ApiDemos\bin\ApiDemos-debug.apk" "C:\Users\
Tao Yi\AppData\Local\Temp\io.appium.android.apis"
info: [debug] Reading strings from converted strings.json
info: [debug] Setting language to default
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f push "C:\\Users\\Tao Yi
\\AppData\\Local\\Temp\\io.appium.android.apis\\strings.json" /data/local/tmp
info: [debug] Checking whether aapt is present
info: [debug] Using aapt from E:\android-sdk\build-tools\android-4.4W\aapt.exe
info: [debug] Retrieving process from manifest.
info: [debug] executing cmd: E:\android-sdk\build-tools\android-4.4W\aapt.exe dump xmltree E:\Appium\sample-co
de\apps\ApiDemos\bin\ApiDemos-debug.apk AndroidManifest.xml
info: [debug] Set app process to: io.appium.android.apis
info: [debug] Not uninstalling app since server not started with --full-reset
info: [debug] Checking app cert for E:\Appium\sample-code\apps\ApiDemos\bin\ApiDemos-debug.apk.
info: [debug] executing cmd: java -jar "C:\Users\Tao Yi\AppData\Roaming\npm\node_modules\appium\node_modules\a
ppium-adb\jars\verify.jar" E:\Appium\sample-code\apps\ApiDemos\bin\ApiDemos-debug.apk
info: [debug] App already signed.
info: [debug] Zip-aligning E:\Appium\sample-code\apps\ApiDemos\bin\ApiDemos-debug.apk
info: [debug] Checking whether zipalign is present
info: [debug] Using zipalign from E:\android-sdk\build-tools\android-4.4W\zipalign.exe
info: [debug] Zip-aligning apk.
info: [debug] executing cmd: E:\android-sdk\build-tools\android-4.4W\zipalign.exe -f 4 E:\Appium\sample-code\a
pps\ApiDemos\bin\ApiDemos-debug.apk "C:\Users\Tao Yi\AppData\Local\Temp\116231-12276-uqycx8\appium.tmp"
info: [debug] MD5 for app is 29649242b53e9a67ba855b067422713c
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "ls /data/local/t
mp/29649242b53e9a67ba855b067422713c.apk"
info: [debug] Getting install status for io.appium.android.apis
info: [debug] Getting device API level
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "getprop ro.build
.version.sdk"
info: [debug] Device is at API Level 23
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "pm list packages
 -3 io.appium.android.apis"
info: [debug] App is installed
info: App is already installed, resetting app
info: [debug] Running fast reset (stop and clear)
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "am force-stop io
.appium.android.apis"
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "pm clear io.appi
um.android.apis"
info: [debug] Forwarding system:4724 to device:4724
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f forward tcp:4724 tcp:47
24
info: [debug] Pushing appium bootstrap to device...
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f push "C:\\Users\\Tao Yi
\\AppData\\Roaming\\npm\\node_modules\\appium\\build\\android_bootstrap\\AppiumBootstrap.jar" /data/local/tmp/

info: [debug] Pushing settings apk to device...
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f install "C:\Users\Tao Y
i\AppData\Roaming\npm\node_modules\appium\build\settings_apk\settings_apk-debug.apk"
info: [debug] Pushing unlock helper app to device...
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f install "C:\Users\Tao Y
i\AppData\Roaming\npm\node_modules\appium\build\unlock_apk\unlock_apk-debug.apk"
info: Starting App
info: [debug] Attempting to kill all 'uiautomator' processes
info: [debug] Getting all processes with 'uiautomator'
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "ps 'uiautomator'
"
info: [debug] No matching processes found
info: [debug] Running bootstrap
info: [debug] spawning: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell uiautomator runtest Ap
piumBootstrap.jar -c io.appium.android.bootstrap.Bootstrap -e pkg io.appium.android.apis -e disableAndroidWatc
hers false
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: numtests=1
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: stream=
info: [debug] [UIAUTOMATOR STDOUT] io.appium.android.bootstrap.Bootstrap:
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: id=UiAutomatorTestRunner
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: test=testRunServer
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: class=io.appium.android.bootstrap.Bootstrap
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: current=1
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS_CODE: 1
info: [debug] [BOOTSTRAP] [debug] Socket opened on port 4724
info: [debug] [BOOTSTRAP] [debug] Appium Socket Server Ready
info: [debug] [BOOTSTRAP] [debug] Loading json...
info: [debug] Waking up device if it's not alive
info: [debug] Pushing command to appium work queue: ["wake",{}]
info: [debug] [BOOTSTRAP] [debug] json loading complete.
info: [debug] [BOOTSTRAP] [debug] Registered crash watchers.
info: [debug] [BOOTSTRAP] [debug] Client connected
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"wake","params":{}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: wake
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "dumpsys window"
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":true}
info: [debug] Screen already unlocked, continuing.
info: [debug] Pushing command to appium work queue: ["getDataDir",{}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"getDataDir","params":{}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: getDataDir
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":"\/data\/local\/tmp"}
info: [debug] dataDir set to: /data/local/tmp
info: [debug] Pushing command to appium work queue: ["compressedLayoutHierarchy",{"compressLayout":false}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"compressedLayoutHierarchy","
params":{"compressLayout":false}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: compressedLayoutHierarchy
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":false}
info: [debug] Getting device API level
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "getprop ro.build
.version.sdk"
info: [debug] Device is at API Level 23
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "am start -S -a a
ndroid.intent.action.MAIN -c android.intent.category.LAUNCHER -f 0x10200000 -n io.appium.android.apis/io.appiu
m.android.apis.ApiDemos"
info: [debug] Waiting for pkg "io.appium.android.apis" and activity "io.appium.android.apis.ApiDemos" to be fo
cused
info: [debug] Getting focused package and activity
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "dumpsys window w
indows"
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "getprop ro.build
.version.release"
info: [debug] Device is at release version 6.0
info: [debug] Device launched! Ready for commands
info: [debug] Setting command timeout to the default of 60 secs
info: [debug] Appium session started with sessionId 7da33fde-d7a2-4c56-89ad-21d3564cd8d4
info: <-- POST /wd/hub/session 303 30301.492 ms - 74
info: --> GET /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4 {}
info: [debug] Responding to client with success: {"status":0,"value":{"platform":"LINUX","browserName":"Androi
d","platformVersion":"6.0","webStorageEnabled":false,"takesScreenshot":true,"javascriptEnabled":true,"database
Enabled":false,"networkConnectionEnabled":true,"locationContextEnabled":false,"warnings":{},"desired":{"platfo
rmVersion":"6.0","app":"E:\\Appium\\sample-code\\apps\\ApiDemos\\bin\\ApiDemos-debug.apk","platformName":"Andr
oid","deviceName":"Nexus 5"},"app":"E:\\Appium\\sample-code\\apps\\ApiDemos\\bin\\ApiDemos-debug.apk","platfor
mName":"Android","deviceName":"0721b62c00e1a31f"},"sessionId":"7da33fde-d7a2-4c56-89ad-21d3564cd8d4"}
info: <-- GET /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4 200 4.489 ms - 602 {"status":0,"value":{"pl
atform":"LINUX","browserName":"Android","platformVersion":"6.0","webStorageEnabled":false,"takesScreenshot":tr
ue,"javascriptEnabled":true,"databaseEnabled":false,"networkConnectionEnabled":true,"locationContextEnabled":f
alse,"warnings":{},"desired":{"platformVersion":"6.0","app":"E:\\Appium\\sample-code\\apps\\ApiDemos\\bin\\Api
Demos-debug.apk","platformName":"Android","deviceName":"Nexus 5"},"app":"E:\\Appium\\sample-code\\apps\\ApiDem
os\\bin\\ApiDemos-debug.apk","platformName":"Android","deviceName":"0721b62c00e1a31f"},"sessionId":"7da33fde-d
7a2-4c56-89ad-21d3564cd8d4"}
info: --> POST /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4/element {"using":"accessibility id","sessi
onId":"7da33fde-d7a2-4c56-89ad-21d3564cd8d4","value":"Graphics"}
info: [debug] Waiting up to 0ms for condition
info: [debug] Pushing command to appium work queue: ["find",{"strategy":"accessibility id","selector":"Graphic
s","context":"","multiple":false}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"find","params":{"strategy":"
accessibility id","selector":"Graphics","context":"","multiple":false}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: find
info: [debug] [BOOTSTRAP] [debug] Finding Graphics using ACCESSIBILITY_ID with the contextId:  multiple: false

info: [debug] [BOOTSTRAP] [debug] Using: UiSelector[DESCRIPTION=Graphics, INSTANCE=0]
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":{"ELEMENT":"1"}}
info: [debug] Responding to client with success: {"status":0,"value":{"ELEMENT":"1"},"sessionId":"7da33fde-d7a
2-4c56-89ad-21d3564cd8d4"}
info: <-- POST /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4/element 200 624.523 ms - 87 {"status":0,"v
alue":{"ELEMENT":"1"},"sessionId":"7da33fde-d7a2-4c56-89ad-21d3564cd8d4"}
info: --> POST /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4/element/1/click {"sessionId":"7da33fde-d7a
2-4c56-89ad-21d3564cd8d4","id":"1"}
info: [debug] Pushing command to appium work queue: ["element:click",{"elementId":"1"}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"element:click","params":{"el
ementId":"1"}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: click
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":true}
info: [debug] Responding to client with success: {"status":0,"value":true,"sessionId":"7da33fde-d7a2-4c56-89ad
-21d3564cd8d4"}
info: <-- POST /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4/element/1/click 200 139.135 ms - 76 {"stat
us":0,"value":true,"sessionId":"7da33fde-d7a2-4c56-89ad-21d3564cd8d4"}
info: --> POST /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4/element {"using":"accessibility id","sessi
onId":"7da33fde-d7a2-4c56-89ad-21d3564cd8d4","value":"Arcs"}
info: [debug] Waiting up to 0ms for condition
info: [debug] Pushing command to appium work queue: ["find",{"strategy":"accessibility id","selector":"Arcs","
context":"","multiple":false}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"find","params":{"strategy":"
accessibility id","selector":"Arcs","context":"","multiple":false}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: find
info: [debug] [BOOTSTRAP] [debug] Finding Arcs using ACCESSIBILITY_ID with the contextId:  multiple: false
info: [debug] [BOOTSTRAP] [debug] Using: UiSelector[DESCRIPTION=Arcs, INSTANCE=0]
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":{"ELEMENT":"2"}}
info: [debug] Responding to client with success: {"status":0,"value":{"ELEMENT":"2"},"sessionId":"7da33fde-d7a
2-4c56-89ad-21d3564cd8d4"}
info: <-- POST /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4/element 200 740.757 ms - 87 {"status":0,"v
alue":{"ELEMENT":"2"},"sessionId":"7da33fde-d7a2-4c56-89ad-21d3564cd8d4"}
info: --> POST /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4/element/2/click {"sessionId":"7da33fde-d7a
2-4c56-89ad-21d3564cd8d4","id":"2"}
info: [debug] Pushing command to appium work queue: ["element:click",{"elementId":"2"}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"element:click","params":{"el
ementId":"2"}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: click
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":true}
info: [debug] Responding to client with success: {"status":0,"value":true,"sessionId":"7da33fde-d7a2-4c56-89ad
-21d3564cd8d4"}
info: <-- POST /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4/element/2/click 200 130.684 ms - 76 {"stat
us":0,"value":true,"sessionId":"7da33fde-d7a2-4c56-89ad-21d3564cd8d4"}
info: --> POST /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4/element {"using":"-android uiautomator","s
essionId":"7da33fde-d7a2-4c56-89ad-21d3564cd8d4","value":"new UiSelector().text(\"Graphics/Arcs\")"}
info: [debug] Waiting up to 0ms for condition
info: [debug] Pushing command to appium work queue: ["find",{"strategy":"-android uiautomator","selector":"new
 UiSelector().text(\"Graphics/Arcs\")","context":"","multiple":false}]
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"action","action":"find","params":{"strategy":"
-android uiautomator","selector":"new UiSelector().text(\"Graphics/Arcs\")","context":"","multiple":false}}
info: [debug] [BOOTSTRAP] [debug] Got command of type ACTION
info: [debug] [BOOTSTRAP] [debug] Got command action: find
info: [debug] [BOOTSTRAP] [debug] Finding new UiSelector().text("Graphics/Arcs") using ANDROID_UIAUTOMATOR wit
h the contextId:  multiple: false
info: [debug] [BOOTSTRAP] [debug] Parsing selector: new UiSelector().text("Graphics/Arcs")
info: [debug] [BOOTSTRAP] [debug] UiSelector coerce type: class java.lang.String arg: "Graphics/Arcs"
info: [debug] [BOOTSTRAP] [debug] Using: UiSelector[TEXT=Graphics/Arcs]
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":{"ELEMENT":"3"}}
info: [debug] Responding to client with success: {"status":0,"value":{"ELEMENT":"3"},"sessionId":"7da33fde-d7a
2-4c56-89ad-21d3564cd8d4"}
info: <-- POST /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4/element 200 851.825 ms - 87 {"status":0,"v
alue":{"ELEMENT":"3"},"sessionId":"7da33fde-d7a2-4c56-89ad-21d3564cd8d4"}
info: --> DELETE /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4 {}
info: Shutting down appium session
info: [debug] Pressing the HOME button
info: [debug] executing cmd: E:\android-sdk\platform-tools\adb.exe -s 0721b62c00e1a31f shell "input keyevent 3
"
info: [debug] Stopping logcat capture
info: [debug] Logcat terminated with code null, signal SIGTERM
info: [debug] [BOOTSTRAP] [debug] Got data from client: {"cmd":"shutdown"}
info: [debug] [BOOTSTRAP] [debug] Got command of type SHUTDOWN
info: [debug] [BOOTSTRAP] [debug] Returning result: {"status":0,"value":"OK, shutting down"}
info: [debug] [BOOTSTRAP] [debug] Closed client connection
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: numtests=1
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: stream=.
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: id=UiAutomatorTestRunner
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: test=testRunServer
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: class=io.appium.android.bootstrap.Bootstrap
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: current=1
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS_CODE: 0
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS: stream=
info: [debug] [UIAUTOMATOR STDOUT] Test results for WatcherResultPrinter=.
info: [debug] [UIAUTOMATOR STDOUT] Time: 5.576
info: [debug] [UIAUTOMATOR STDOUT] OK (1 test)
info: [debug] [UIAUTOMATOR STDOUT] INSTRUMENTATION_STATUS_CODE: -1
info: [debug] Sent shutdown command, waiting for UiAutomator to stop...
info: [debug] UiAutomator shut down normally
info: [debug] Cleaning up android objects
info: [debug] Cleaning up appium session
info: [debug] Responding to client with success: {"status":0,"value":null,"sessionId":"7da33fde-d7a2-4c56-89ad
-21d3564cd8d4"}
info: <-- DELETE /wd/hub/session/7da33fde-d7a2-4c56-89ad-21d3564cd8d4 200 1152.228 ms - 76 {"status":0,"value"
:null,"sessionId":"7da33fde-d7a2-4c56-89ad-21d3564cd8d4"}
```
