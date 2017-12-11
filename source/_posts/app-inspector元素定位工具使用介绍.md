---
title: app-inspector元素定位工具使用介绍
date: 2017-02-13 00:00:45
categories: [Tools]
tags: [app-inspector]
---

##### 前置安装配置，包括如下：
```bash
info AppiumDoctor  ✔ The Node.js binary was found at: /usr/local/bin/node
info AppiumDoctor  ✔ Node version is 6.9.0
info AppiumDoctor  ✔ Xcode is installed at: /Applications/Xcode.app/Contents/Developer
info AppiumDoctor  ✔ Xcode Command Line Tools are installed.
info AppiumDoctor  ✔ DevToolsSecurity is enabled.
info AppiumDoctor  ✔ The Authorization DB is set up properly.
info AppiumDoctor  ✔ Carthage was found at: /usr/local/bin/carthage
info AppiumDoctor  ✔ HOME is set to: /Users/taoyi
info AppiumDoctor  ✔ ANDROID_HOME is set to: /opt/android-sdk-macosx
info AppiumDoctor  ✔ JAVA_HOME is set to: /Library/Java/JavaVirtualMachines/jdk1.8.0_91.jdk/Contents/Home
info AppiumDoctor  ✔ adb exists at: /opt/android-sdk-macosx/platform-tools/adb
info AppiumDoctor  ✔ android exists at: /opt/android-sdk-macosx/tools/android
info AppiumDoctor  ✔ emulator exists at: /opt/android-sdk-macosx/tools/emulator
info AppiumDoctor  ✔ Bin directory of $JAVA_HOME is set
```

  <!--more-->

##### 安装app-inspector
```bash
npm install -g app-inspector
```
##### 获取设备UDID
```bash
adb devices                 # android
xcrun simctl list           # IOS
```
##### 启动app-inspector
```bash
app-inspector -u YOUR-DEVICE-ID
```
启动成功
```bash
➜  ~ app-inspector -u 0862E662-79FE-4831-9EF7-D0D0D1055FFF
>> xctest-client start with port: 8900
>> WebDriverAgent version: 1.0.41
>> iOS device started: 0862E662-79FE-4831-9EF7-D0D0D1055FFF
>> inspector start at: http://192.168.31.20:5678
  <-- GET /
  --> GET / 200
  ...
```
浏览器查看结果如图：
{% asset_img app-inspector获取IOS元素示例.png app-inspector获取IOS元素示例 %}

ANDROID启动成功
```bash
➜  ~ app-inspector -u 127.0.0.1:62001
INSTRUMENTATION_STATUS: numtests=1
>> socket server ready
>> socket client ready
>> Android device started: 127.0.0.1:62001
>> inspector start at: http://172.16.8.99:5678
  <-- GET /
recive: {"cmd":"getSource","args":{}}

return: {"data":{"value":true,"status":0},"success":true}

>> Dump Android XML success, save to /usr/local/lib/node_modules/app-inspector/.temp/android.json
  --> GET / 200
  <-- GET /
  ···
```
浏览器查看结果如图：
{% asset_img app-inspector获取ANDROID元素示例.png app-inspector获取ANDROID元素示例 %}
