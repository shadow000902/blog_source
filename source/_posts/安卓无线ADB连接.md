---
title: 安卓无线ADB连接
date: 2017-11-04 22:00:31
categories: [Android]
tags: [adb]
---

1. 在手机上安装``QPython``
GitHub上的[下载链接](https://github.com/qpython-android/qpython/releases)

2. 在手机上打开``QPython``软件的``Terminal``，安装``uiautomator2``
```bash
# Since uiautomator2 is still developing, you have to add --pre to install development version
pip install --pre uiautomator2
```

  <!--more-->

3. 在手机上安装``app-uiautomator.apk``
最新版[下载链接](https://github.com/openatx/android-uiautomator-server/releases)

4. 导入最新版的``atx-agent``到手机中
最新版[下载地址](https://github.com/openatx/atx-agent/releases)
下载以``linux_armv7.tar.gz``结尾的二进制包。绝大部分手机都是linux-arm架构的。
解压出``atx-agent``文件，导入到手机中并启动：
```bash
adb push atx-agent /data/local/tmp
adb shell chmod 755 /data/local/tmp/atx-agent
# launch atx-agent in daemon mode
adb shell /data/local/tmp/atx-agent -d
# example: server started, listening on 192.168.28.230:7912
```
假设手机的地址是``$DEVICE_URL``(eg: `http://192.168.28.230:7912`)

5. 无线访问手机系统
    1. 获取当前程序版本
        ```bash
        curl $DEVICE_URL/version
        # expect example: 0.0.7
        ```
    2. 安装应用
        ```bash
        curl -X POST -d url="http://some-host/some.apk" $DEVICE_URL/install
        # expect example: install id
        ```

        ```bash
        # get install progress
        curl -X GET $DEVICE_URL/install/1
        {"id":"1","totalSize":985435,"copiedSize":16951,"message":"downloading"}
        # or
        {"id":"1","totalSize":985435,"copiedSize":985435,"message":"success installed"}
        # or
        {"id":"1","totalSize":985435,"copiedSize":342641,"message":"error install","error":"exit status 1"}
        ```
    3. 上传文件
        ```bash
        # 上传到/sdcard目录下 (url以/结尾)
        curl -F "file=@somefile.txt" $DEVICE_URL/upload/sdcard/

        # 上传到/sdcard/tmp.txt
        curl -F "file=@somefile.txt" $DEVICE_URL/upload/sdcard/tmp.txt
        ```
    4. 程序自升级
        升级程序从gihub releases里面直接下载，升级完后自动重启
        ```bash
        # 升级到最新版
        curl 10.0.0.1:7912/upgrade
        ```

        ```bash
        # 指定升级的版本
        curl "$DEVICE_URL/upgrade?version=0.0.7"
        ```
    5. ``ATX Log Path``
        ```bash
        /sdcard/atx-agent.log
        ```

RESOURCE:
    [testerhome_10361](https://testerhome.com/topics/10361)
    [testerhome_10298](https://testerhome.com/topics/10298)
    [github_uiautomator2](https://github.com/openatx/uiautomator2)
    [github_android-uiautomator-server](https://github.com/openatx/android-uiautomator-server)
    [github_atx-agent](https://github.com/openatx/atx-agent)
    [github_qpython](https://github.com/qpython-android/qpython)