---
title: Shell小脚本
date: 2017-11-04 15:51:48
categories: [Shell]
tags: [shell]
---

##### 删除目录下的除今天外的所有文件夹

1. 目录下的文件夹规律【年月日时分秒】
```bash
# taoyi @ TaoYi-Mac in ~/Desktop/test0001 [15:54:29] 
$ ll
total 0
drwxr-xr-x  2 taoyi  staff    68B 11  3 18:29 20171027121219
drwxr-xr-x  3 taoyi  staff   102B 11  3 18:30 20171101124273
drwxr-xr-x  3 taoyi  staff   102B 11  3 18:29 20171102124212
drwxr-xr-x  2 taoyi  staff    68B 11  3 18:29 20171103121216
drwxr-xr-x  3 taoyi  staff   102B 11  3 18:29 20171103124211
drwxr-xr-x  2 taoyi  staff    68B 11  3 18:29 20171103124216
drwxr-xr-x  2 taoyi  staff    68B 11  3 18:29 20171104124212
```

<!--more-->

2. shell脚本
```bash
ls -l /Users/taoyi/Desktop/test0001/ | awk '/^d/ {print $NF}' > /Users/taoyi/Desktop/test0001/dir						# 目录下的所有文件夹名称写入文件``dir``

for i in $(grep -v `date +%Y%m%d` /Users/taoyi/Desktop/test0001/dir)													# `date +%Y%m%d`，获取当天的年月日
do
    rm -rf /Users/taoyi/Desktop/test0001/$i																				# 删除目录下的文件夹
done

rm -rf /Users/taoyi/Desktop/test0001/dir																				# 删除写入的文件``dir``
```

##### kill指定name的pid

```bash
# kill指定name的pid
# 示例："./kill_pidname.sh jhost"

pid_name=$1
ps -ef | grep -v grep | grep $pid_name | while read username pid other
do
    kill -9 $pid
done
```

##### adb截图导出并展示

```bash
adb shell /system/bin/screencap -p /sdcard/screenshot.jpg
adb pull /sdcard/screenshot.jpg ~/shell-tools/ScreenShots/
open ~/shell-tools/ScreenShots/screenshot.jpg
```

##### android打包并安装

```bash
cd /Users/taoyi/git_projects/Gitlab/androidclientnative/
git checkout develop
git pull

rm -rf /Users/taoyi/git_projects/Gitlab/androidclientnative/app/build/
rm -rf /Users/taoyi/shell-tools/APK/*.apk

gradle clean assembleFengcheBeta
# gradle clean assembleFengchePreview
# gradle clean assembleFengcheRelease

cp -rf /Users/taoyi/git_projects/Gitlab/androidclientnative/app/build/outputs/apk/beta/*.apk /Users/taoyi/shell-tools/APK/
adb uninstall com.souche.fengche
adb install /Users/taoyi/shell-tools/APK/*.apk
```