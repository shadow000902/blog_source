---
title: Logcat日志过滤与解析
date: 2016-11-21 00:15:48
categories: [Android]
tags: [logcat, adb]
---

##### ``logcat``指定``某APP``輸出``ERROR``以上級別的日誌，``显示同一个进程的所有输出``
```java
#!/bin/sh  
echo 本腳本實現顯示指定包名APP的ERROR以上級別的日誌，建議崩潰之後，重新開啓此腳本  
package_name=$1  
pid=`adb shell ps | grep $package_name |awk '{print $2}'`  
adb logcat -v time *:E | grep -E --color=auto $pid  
```

  <!--more-->

##### 只显示需要的输出，白名单
``` bash
adb logcat | grep MyApp
adb logcat | grep -i myapp #忽略大小写。
adb logcat | grep --color=auto -i  myapp #设置匹配字符串颜色。更多设置请查看 grep 帮助。
```
仅显示 Error 级别 tag 为 MyApp 的输出：
```
adb logcat | grep "^E.MyApp"
```
也可以匹配多个，使用 | 分割多个匹配表达式，要加转义符。例如要匹配 tag 为 MyApp 和 MyActivity 的输出：
```
adb logcat | grep "^..MyApp\|^..MyActivity"
adb logcat | grep -E "^..MyApp|^..MyActivity"  #使用 egrep 无须转义符
```

##### 过滤不需要的输出，黑名单
还是使用 grep，用法也跟上面的一样，加一个 -v 即可。例如要过滤 tag 为 MyApp 和 MyActivity 的输出：
```
adb logcat | grep -v "^..MyApp\|^..MyActivity"
adb logcat | grep -vE "^..MyApp|^..MyActivity"  #使用 egrep 无须转义符
```

##### 从当前开始显示
logcat 有缓存，如果仅需要查看当前开始的 log，需要清空之前的。
```
adb logcat -c && adb logcat
```

##### 过滤``log``文件
有时需要分析 log 文件，过滤 log 文件还是使用 grep。例如 log 文件为 myapp.log，要匹配 tag 为 MyApp 和 MyActivity 的输出，然后输出到 newmyapp.log：
```
cat myapp.log | grep "^..MyApp\|^..MyActivity" > newmyapp.log
```

##### logcat 详细用法
###### 日志输出优先级
优先级有下列集中，是按照从低到高顺利排列的:
```
V — Verbose (lowest priority)
D — Debug
I — Info
W — Warning
E — Error
F — Fatal
S — Silent (highest priority, on which nothing is ever printed)
```
```
adb logcat ActivityManager:I MyApp:D *:S
adb logcat *:W                                                                  # 输出日志等级高于``Warning``的日志
```
###### 日志输出的格式
日志信息包括了许多元数据域包括标签和优先级。可以修改日志的输出格式，所以可以显示出特 定的元数据域。可以通过 -v 选项得到格式化输出日志的相关信息。
```
brief — Display priority/tag and PID of originating process (the default format).
process — Display PID only.
tag — Display the priority/tag only.
thread — Display process:thread and priority/tag only.
raw — Display the raw log message, with no other metadata fields.
time — Display the date, invocation time, priority/tag, and PID of the originating process.
long — Display all metadata fields and separate messages with a blank lines.
```
```
adb logcat -v thread
```
只能通过 ``-v ``选项来规定输出格式 ``option``
###### 查看可用日志的缓冲区
Android日志系统有循环缓冲区，并不是所有的日志系统都有默认循环缓冲区。为了得到 日志信息，你需要通过-b 选项来启动logcat 。如果要使用循环缓冲区，你需要查看剩余的 循环缓冲期:
```
radio — 查看缓冲区的相关的信息.
events — 查看和事件相关的的缓冲区.
main — 查看主要的日志缓冲区
```
```
adb logcat -b radio
```
