---
title: Shell小脚本
date: 2017-11-04 15:51:48
categories: [Tips]
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
# 目录下的所有文件夹名称写入文件``dir``
ls -l /Users/taoyi/Desktop/test0001/ | awk '/^d/ {print $NF}' > /Users/taoyi/Desktop/test0001/dir

# `date +%Y%m%d`，获取当天的年月日
for i in $(grep -v `date +%Y%m%d` /Users/taoyi/Desktop/test0001/dir)
do
	# 删除目录下的文件夹
    rm -rf /Users/taoyi/Desktop/test0001/$i
done

# 删除零时写入的文件``dir``
rm -rf /Users/taoyi/Desktop/test0001/dir
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
# 调用安卓系统内部截图命令screencap截图保存
adb shell /system/bin/screencap -p /sdcard/screenshot.jpg
# 导出图片到本地目录
adb pull /sdcard/screenshot.jpg ~/shell-tools/ScreenShots/
# 打开图片
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

##### Shell脚本解析xml文件字段

示例文件内容``build.xml``
```xml
  <parameters>
    <hudson.model.StringParameterValue>
      <name>SCHEME</name>
      <description>scheme configuration of this project StoreCI</description>
      <value>Coding_iOS</value>
    </hudson.model.StringParameterValue>
    <hudson.model.StringParameterValue>
      <name>CONFIGURATION</name>
      <description>configuration of packing, Release/Debug</description>
      <value>Release</value>
    </hudson.model.StringParameterValue>
    <hudson.model.StringParameterValue>
      <name>OUTPUT_FOLDER</name>
      <description>output folder for build artifacts, it is located in workspace/project root dir.</description>
      <value>build_outputs</value>
    </hudson.model.StringParameterValue>
    <hudson.model.StringParameterValue>
      <name>BRANCH</name>
      <description>git repository branch</description>
      <value>master</value>
    </hudson.model.StringParameterValue>
  </parameters>
  <causeBag class="linked-hash-map">
    <entry>
      <hudson.model.Cause_-UserIdCause>
        <userId>shadow</userId>
      </hudson.model.Cause_-UserIdCause>
      <int>1</int>
    </entry>
  </causeBag>
```

```bash
# 获取<userId>shadow</userId>中的shadow
sed -n 's/.*>\(.*\)<\/userId>/\1/p' $JENKINS_HOME/jobs/$JOB_NAME/builds/$BUILD_NUMBER/build.xml
# 获取<userId>shadow</userId>中的shadow，赋值给userId
# 使用位置：Jenkins获取构建人
userId=(`sed -n 's/.*>\(.*\)<\/userId>/\1/p' $JENKINS_HOME/jobs/$JOB_NAME/builds/$BUILD_NUMBER/build.xml`)
```

##### Shell脚本获取文本特定字段

```bash
# 获取log文件第一行中，``[0m``字符后面的所有字符
head -1 $JENKINS_HOME/jobs/$JOB_NAME/builds/$BUILD_NUMBER/log | awk -F '\\[0m' '{print $NF}'
```

##### Jenkins获取构建人，并赋值到变量并使用

取值``shell``
```bash
head -1 $JENKINS_HOME/jobs/$JOB_NAME/builds/$BUILD_NUMBER/log | awk -F '\\[0m' '{print $NF}' > userId
read userId < userId
echo "userId=${userId}" > userId.txt
```
``set Build Name``中加入构建人
```bash
${PROPFILE,file="userId.txt",property="userId"}
```

##### Jenkins获取安卓APP版本号并赋值给变量并使用

取值``shell``
```bash
versionName=`cat app/gradle.properties | grep 'VERSION_NAME' | cut -d '=' -f 2 `
echo "versionName=${versionName}" > versionName.txt
```
``set Build Name``中加入安卓APP版本号
```bash
${PROPFILE,file="versionName.txt",property="versionName"}
```

##### 获取目录的所有csv文件并合并为一个csv文件
```bash
cd /Users/taoyi/git_projects/Gitlab/RF_InterfaceTest
# 获取./Library/output/api-docs/souche/*/*.csv文件并移动到./Library目录下
mv -f ./Library/*/*/*/*/*.csv ./Library 
# 把所有的csv文件合并为一个together.csv文件
cat ./Library/*.csv > together.csv

rm -rf ./Library/output
rm -rf ./Library/*.csv

mv -f together.csv ./Library
```

##### ``Json``中的字典转化成``Robot-Framework``的参数格式
```bash
# ``Json``中的字典转化成``Robot-Framework``的参数格式
# 先把需要修改的json文本写入文件，再对该文件进行操作
# 示例："./change_Dict.sh pice"

file_name=$1
sed -ig 's/":/=/g' $file_name
sed -ig 's/"//g' $file_name
sed -ig 's/,/    /g' $file_name
```
