---
title: Android-Studio连接夜神模拟器
date: 2016-03-14 12:25:46
categories: [Android]
tags: [android-studio]
---

1. 安装并启动夜神模拟器
2. 运行cmd命令，cd到夜神模拟器的安装目录的bin目录下，执行命令：
```bash
adb connect 127.0.0.1:62001
```
3. 此时在Android-Studio的设备位置就能看到已经连接到了夜神模拟器。
