---
title: 常用Adb命令列表
date: 2016-03-16 22:37:41
categories: [Adb]
tags: [android, adb]
---


1. 安装APK（如果加 -r 参数，保留已设定数据，重新安装filename.apk）
``` bash
adb install XXX.apk
adb install -r XXX.apk
```

<!--more-->

2. 卸载APK（如果加 -k 参数，为卸载软件但是保留配置和缓存文件）
``` bash
adb uninstall 包名(如：cn.highing.hichat)
adb uninstall -k 包名(如：cn.highing.hichat)
```
3. 查看当前所有连接的设备id
``` bash
adb devices
```
4. 对某一设备操作
``` bash
adb -s 设备id 命令
```
5. 导入文件到设备（该命令也可以实现安装APK，只要把APK导入到"/system/app"或者"/data/app"就OK）
``` bash
adb push 文件 设备路径
```
6. 从设备导出文件
``` bash
adb pull 设备文件 本地路径
```
7. 查看log信息
``` bash
adb logcat
adb logcat -v time
logcat -v time > /mnt/sdcard/aa.txt 2>&1 & (离线抓取log保存在手机)
```
8. 进入shell模式
``` bash
adb shell
```
9. 启动activity（可能需要root权限）
``` bash
adb shell am start -n 包名/包名+类名（-n 类名,-a action,-d date,-m MIME-TYPE,-c category,-e 扩展数据,等） （cn.highing.hichat/.ui.MainActivity）
```
10. 获取设备ID号
``` bash
adb get-serialno
```
11. 开启/关闭adb服务
``` bash
adb kill-server
adb start-server
```
12. 访问sqlite3
``` bash
adb shell sqlite3
```
13. 重启设备
``` bash
adb reboot
```
14. 挂载分区（可使系统分区重新可写）
``` bash
adb remount
```
15. 发布端口（可以设置任意的端口号，做为主机向模拟器或设备的请求端口）
``` bash
adb forward tcp:5555 tcp:8000
```
16. 查看最上层的Activity名字
``` bash
linux: adb shell dumpsys activity | grep "mFocusedActivity"
windows: adb shell dumpsys activity | findstr "mFocusedActivity"
         adb shell dumpsys window windows | grep -E "mCurrentFlcus|mFocuseApp"
```
17. 抓取重启的log
``` bash
cat /proc/kmsg > /mnt/sdcard/kmsg.txt 2>&1 &
```
18. 查找占用指定端口的pid（进程id）
``` bash
netstat -ano|findstr <指定端口号>
```
19. monkey命令
``` bash
adb shell monkey -v time 500
adb shell monkey -p cn.highing.hichat --ignore-crashes  --ignore-timeouts --ignore-security-exceptions  --pct-trackball 0 --pct-nav 0 --pct-majornav 0 --pct-syskeys 0 --pct-anyevent 0  -v -v -v --throttle 500 1200000000 -v time > /mnt/sdcard/monkeysys.txt 2>&1 &
```
20. adb录屏
``` bash
adb shell screenrecord /mnt/sdcard/test0001.mp4
```
21. 获取Android版本号
``` bash
adb shell getprop ro.build.version.release
```
22. 获取SDK版本号
``` bash
adb shell getprop ro.build.version.sdk
```
23. 获取设备型号
``` bash
adb shell getprop ro.product.model
```
24. 获取指定pid的应用包名
``` bash
windows: ps | findstr cn.highing.hichat
linux: ps | grep -w cn.highing.hichat
```
25. 获取电池状态
``` bash
adb shell dumpsys battery
```
26. 进入bootloader
``` bash
adb reboot bootloader
```
27. 获取系统中安装的系统应用包名列表
``` bash
adb shell pm list packages -s
```
28. 获取系统中安装的第三方应用包名列表
``` bash
adb shell pm list packages -3
```
29. 模糊查询应用包名
``` bash
adb shell pm list packages qq
```
30. 获取启动应用所花时间
``` bash
adb shell am start -W -n 包名/包名+类名
```
31. 清除应用用户数据
``` bash
adb shell pm clear cn.highing.hichat
```