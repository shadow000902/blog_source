---
title: adb进阶应用
date: 2016-03-23 23:23:02
categories: [Android]
tags: [android, adb]
---

1. 连接多个设备，在指定设备运行adb命令
```bash
adb -s <serialNumber> <command>     # serialNumber: adb devices 获取的设备ID号
```

  <!--more-->

2. 无线adb连接
```bash
shadow@shadow MINGW64 ~/Desktop
$ adb devices                       # 连接手机，获取设备ID号
List of devices attached
8XV5T15A20009865        device

shadow@shadow MINGW64 ~/Desktop
$ adb tcpip 5566                    # 开启无线端口号：5566（数字任选，不冲突就OK）
restarting in TCP mode port: 5566

shadow@shadow MINGW64 ~/Desktop
$ adb connect 192.168.1.104:5566    # adb连接手机无线端口，IP地址为手机获取的局域网地址
adb server is out of date.  killing...
* daemon started successfully *
connected to 192.168.1.104:5566

shadow@shadow MINGW64 ~/Desktop
$ adb devices                       # 再次获取连接的设备，可以看到adb无线连接的设备
List of devices attached
192.168.1.104:5566      device
8XV5T15A20009865        device

shadow@shadow MINGW64 ~/Desktop
$ adb devices                       # 拔掉USB线后，留下无线adb连接的设备，和有线连接一样，可以执行各种adb命令
List of devices attached
192.168.1.104:5566      device
```

3. 记录无线通讯日志
```bash
adb shell
logcat -b radio
```
4. 获取系统占用信息
```bash
adb shell top
```
5. 通过adb获取CPU的值
```bash
adb shell dumpsys cpuinfo
adb shell dumpsys cpuinfo | grep packagename        # 获取指定应用的CPU值
adb shell top -m 5 -s cpu                           # 查看前5个进程cup的使用情况
adb shell top -n l | grep packagename
adb -s #udid# shell dumpsys cpuinfo|grep #filter#|awk '{print '$(date +%Y%m%d%H%M%S)',$1,$2}'|grep #pid#
```
6. 通过adb获取内存
```bash
adb shell dumpsys meminfo
adb shell dumpsys meminfo packagename or Pid        # 获取指定应用的内存占用
adb shell dumpsys meminfo packagename | grep TOTAL  # 获取指定应用的最大内存限制
adb shell getprop | grep heapgrowthlimit            # 查看单个应用程序的最大内存限制
adb shell procrank                                  # 取系统所有应用的内存限制数值
```
6.1 内存PSS抓取命令
```bash
adb -s #udid# shell dumpsys meminfo|awk '/process:/,/adjustment:/{if(i>1)print x;x=$0;i++}'|grep #filter#|grep #pid#|awk '{print '$(date +%Y%m%d%H%M%S)',$1,$3}'
```
6.2 查看USS和PSS
```bash
adb shell procrank | grep packagename
```

7. 通过adb获取流量
```bash
adb shell cat /proc/"+Pid+"/net/dev
adb shell cat /proc/5432/net/dev
adb shell cat /proc/net/xt qtaguid/stats | grep uid # 取单个uid的流量情况
adb -s 8XV5T15A20009865 shell cat /proc/net/xt qtaguid/stats | grep 12345
```
7.1 抓取下行流量
```bash
adb -s #udid# shell cat /proc/net/xt_qtaguid/stats|grep #uid#|awk '{tx_bytes+=$6}END{print '$(date +%Y%m%d%H%M%S)',tx_bytes}
```
7.2 抓取上行流量
```bash
adb -s #udid# shell cat /proc/net/xt_qtaguid/stats|grep #uid#|awk '{tx_bytes+=$8}END{print '$(date +%Y%m%d%H%M%S)',tx_bytes}
```
7.3 抓取上行和下行流量
```bash
adb -s #udid# shell cat /proc/net/xt_qtaguid/stats|grep #uid#|awk '{rx_bytes+=$6}{tx_bytes+=$8}END{print '$(date +%Y%m%d%H%M%S)',rx_bytes,tx_bytes}
```
