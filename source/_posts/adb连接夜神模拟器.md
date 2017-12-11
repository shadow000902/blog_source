---
title: Adb连接夜神模拟器
date: 2016-03-21 00:04:06
categories: [Android]
tags: [adb]
---

#### 准备工作
1. 需要adb，电脑当然要有Android-sdk，且配置了~/Android-sdk/platform-tools/的环境变量，以便adb可以在任意位置使用
2. 安装[夜神模拟器](http://www.yeshen.com/)

  <!--more-->

#### 实际步骤
其实很简单：
1. 打开夜神模拟器
2. 打开CMD命令窗口，输入
``` bash
adb connect 127.0.0.1:62001
```
结果如下图就说明连接成功了
{% asset_img adb-connected.png adb-connected %}

#### 注意点
网上很多说，CMD到夜神模拟器的安装位置~/Nox/bin/下，输入：
``` bash
box_adb.exe connect 127.0.0.1:62001
```

这个命令使用的是夜神模拟器自带的nox_adb.exe来连接的，这样的话就导致Android-sdk的adb，也就是你自己系统的adb还是没法和夜神模拟器连接，导致很多系统的adb命令依旧没法使用
所以还是建议使用:
``` bash
adb connect 127.0.0.1:62001
```
来连接。
