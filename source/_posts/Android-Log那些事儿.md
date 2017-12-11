---
title: Android Log那些事儿
date: 2016-10-08 00:19:09
categories: [Android]
tags: [android, adb, log]
---

#### 实时日志抓取
1. 抓取应用程序的日志
```
logcat -b main -v threadtime > /sdcard/main.log
```

  <!--more-->

2. 抓取跟 radio/telephony 相关的信息
```
logcat -b radio -v threadtime > /sdcard/radio.log
```

3. 抓取系统事件日志，如触屏事件
```
logcat -b events -v threadtime > /sdcard/events.log
```

4. 抓取kernel log
```
logcat -b kernel > /sdcard/kernel.log
```

5. 导出当前缓存的 kernel log
```
adb shell dmesg > /sdcard/dmesg.log
```

6. 实时查看kernel log
```
adb shell kmsgcat
```

7. 抓取 printk生成的内核消息
```
adb shell cat /proc/kmsg > kernel.log
```

8. 抓取 TCP/IP协议相关的日志
```
adb shell tcpdump -s 10000 -w /sdcard/tcpip.pcap
```

#### 状态Log
1. 获取系统状态信息，如手机的内存信息、CPU信息、缓存等
```
adb shell dumpstate > /sdcard/dumpstate.log
```

2. 获取系统进程有关的信息。比如：当前运行的服务，进程信息等
```
adb shell dumpsys
```

3. 如果想查看特定进程的特定service ，如 com.android.mms进程的meminfo，可以使用
```
adb shell dumpsys meminfo com.souche.fengche
meminfo                                     # 显示内存信息
cpuinfo                                     # 显示CPU信息
account                                     # 显示accounts信息
activity                                    # 显示activities的信息
window                                      # 显示键盘，窗口和它们的关系
wifi                                        # 显示wifi信息
```

4. 获取 所有状态信息。包括 dumpsys,dmesg和dumpstate
```
adb shell bugreport > /sdcard/bugreport.log
```

5. 查看内存信息
```
adb shell cat /proc/meminfo
```

6. 查看虚拟内存信息
```
adb shell cat /proc/vmstate
```

#### Log分析
1. ``Exception``
有没有捕获异常

2. ``ANR``
``ANR``的``log``一般都位于 ``/data/anr/``
例子： ``E/ActivityManager( 957): ANR in com.ipanel.join.appstore``

3. ``Fatal``
``Fatal`` 一般比较严重，很多都很动态库和空指针有关，一般会接下来打印 ``"Build fingerprint:"`` 或 ``"NullPointerException"``

4. ``Build fingerprint``
动态库问题

5. ``NullPointerException``
空指针问题

6. ``kernel panic``
只有加载到内核空间的驱动模块才能直接导致``kernel panic``，你可以在系统正常的情况下，使用``lsmod``查看当前系统加载了哪些模块。
除此之外，内建在内核里的组件（比如memory map等）也能导致panic。
``kernel panic``分为 两种：
``hard panic``（关键字： ``Aieee``)
``soft panic``（关键字： ``Oops``）

7. ``tombstone``
``tombstone`` 一般是由Dalvik错误，状态监视调试器，C层代码以及libc的一些问题导致的。
当系统发生``tombstone``的时候，``kernel``首先会上报一个严重的警告信号（``signal``）,上层接收到之后，进程的调试工具会把进程中当时的调用栈现场保存起来，并在系统创建了``data/tombstones``目录后把异常时的进程信息写在此目录里面，开发者需要通过调用栈来分析整个调用流程来找出出问题的点。
日志路径： ``/data/tombstones``

8. ``system crash``
``kernel log``会出现： ``service 'activity' died``
``'activity'`` 可以是任意的``activity``。
