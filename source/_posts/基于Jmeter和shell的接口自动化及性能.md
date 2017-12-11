---
title: 基于Jmeter和shell的接口自动化及性能
date: 2016-03-14 19:41:36
categories: [Automation]
tags: [jmeter, 接口, 自动化]
---

#### 主要目标
由于接口数量较多，测试人员在功能测试中比较难覆盖到所有的接口，该教程主要用于对服务端所有接口做遍历测试，修改线程数及单用例执行时间后还可用作接口性能测试。

#### 实现流程
自动化的场景模拟真实手工测试，操作步骤和手工测试一样。

  <!--more-->

{% asset_img 测试流程图.png 测试流程图 %}

#### 准备工作
1. 系统环境：CentOS
2. 测试工具：[apache-jmeter-2.13](http://jmeter.apache.org/download_jmeter.cgi)
3. 运行环境：[JDK](http://www.oracle.com/technetwork/java/javase/downloads/index.html)
4. Python环境
5. 服务器监控：[nmon](http://nmon.sourceforge.net/pmwiki.php?n=Site.Download)

#### 具体实现
##### 自动化脚本文件管理

```bash
[root@root ~]# cd ..
[root@root /]# cd data
[root@root data]# cd loadtest/
[root@root loadtest]# ll -l
total 68
-rw-r--r-- 1 root root  3327 Mar  7 17:54 genHTML.sh            # 生成html报告
drwxr-xr-x 2 root root  4096 Mar 14 20:05 log                   # 日志存放目录
-rw-r--r-- 1 root root  1382 Mar  8 14:52 MainThreadScript.sh   # 主流程脚本
-rw-r--r-- 1 root root   871 Mar  7 17:10 monitor.sh            # 服务器监控脚本
drwxr-xr-x 2 root root  4096 Mar  5 21:13 report
-rw-r--r-- 1 root root  1174 Mar  5 10:55 sendmail.py           # 发送测试报告邮件脚本
-rw-r--r-- 1 root root    42 Mar  5 11:08 serverlist            # 接口所在服务器列表
-rw-r--r-- 1 root root   787 Mar  5 10:50 style.css             # html样式
-rw-r--r-- 1 root root  1156 Mar 14 20:05 summary.txt           # 测试结果数据输出文件
drwxr-xr-x 2 root root  4096 Mar 14 18:05 testcase              # 测试用例存放文件夹
```

##### 主流程脚本 MainThreadScript.sh
```sh
#/bin/bash

source /etc/profile
Jmeter_Home='/usr/local/apache-jmeter-2.13'
TestReport='/data/loadtest/report'
LogDIR='/data/loadtest/log'
Date=`date +"%F"`
cd /data/loadtest/
>summary.txt
#清理上次执行结果
run_test()
{
#获取测试用例
 for i in `find "./testcase" -name "*.jmx" | awk -F '.' '{print $2}'`
  do
  echo $i "用例执行中。。。"
  casename=`echo "$i" | awk -F '/' '{print $3}'`>log/${casename}.txt
  echo -n "$i ">>summary.txt
  #发起监控
  ./monitor.sh >/dev/null 2>&1 &
  #开始执行测试
  $Jmeter_Home/bin/jmeter -n -t /data/loadtest${i}.jmx>>log/${casename}.txt
  sleep 31
  #如果执行31s还未结束，强制终止执行
  ps -ef | grep java |grep -v grep | awk '{print $2}' |xargs kill -9 2>/dev/null
  sleep 3
  #提取结果
  grep 'summary =' log/${casename}.txt| tail -1 |awk -F '[\t / (]+' '{if($7>5 && $17<1.00){printf("%s %d %d %d %.2f% pass ",$7,$10,$3,$16,100-$17)}else{printf("%s %d %d %d %.2f%% fail ",$7,$10,$3,$16,100-$17)}}'>>summary.txt
  #cat monitor.txt >>summary.txt
  echo '' >> summary.txt
#echo '' >> summary.txt
  #获取关键日志
  #echo "${LogDIR}${i}.log"
#echo "start ssh catalina.out > log.#"
  #ssh 120.26.136.232 'tail -n 300 /mnt2/tomcat_content_me/logs/catalina.out'>"${LogDIR}/${casename}${Date}.log"
 done
}
run_test
sleep 3
#生成html报告
sh genHTML.sh
sleep 1
#发送邮件
python sendmail.py
```

##### 服务器监控
服务器日志收集方面，使用nmon监控工具，因为它可以后台收集结果保存到文件。由于每个用例只执行30秒，所以只需要监控30秒，每5秒监控一次，对应命令：
```bash
nmon -f -t -s5 -c60 -F /data/test.nmon
```
每个测试用例执行完后再读取这个结果文件，获取有用的信息。
当前只统计了磁盘IO和CPU的占用率信息，原始文件保存在本地目录，如果需要，可以手动改查找到。

##### 服务器监控脚本 monitor.sh

```sh
#!/bin/bash
#读取监控服务器列表
SERVERLIST=`cat serverlist`
DATE=`date +'%F'`
mkdir -p /data/loadtest/monitor/$DATE
TIME=`date +'%T'`
#发起监控
for i in $SERVERLIST
do
  ssh $i 'nmon -f -t -s5 -c60 -F /data/test.nmon >/dev/null 2>&1 &'
done
#监控30秒
sleep 30
>monitor.txt
#收集监控结果，保存到monitor.txt
for i in $SERVERLIST
do
 scp $i:/data/test.nmon /data/loadtest/monitor/$DATE/${i}_${TIME}.nmon
 io=`cat /data/loadtest/monitor/$DATE/${i}_${TIME}.nmon|grep "DISKBUSY,T" | awk -F ',' '{sum+=$3} END {printf("%.2f%",sum/NR)}'`
 cpu=`cat /data/loadtest/monitor/$DATE/${i}_${TIME}.nmon|grep "CPU_ALL,T" | awk -F ',' '{sum+=$6} END {printf("%.2f%",100-sum/NR)}'`
 #net=`cat /data/loadtest/monitor/$DATE/${i}_${TIME}.nmon|grep "NET,T"|awk -F ',' '{sum_r+=$4}{sum_w+=$6} END {print sum_r/NR,sum_w/NR}'`
 echo -n "${cpu} ${io} ">>monitor.txt
done
```
将用例执行结果和监控结果都汇总到summary.txt里，方面后续生成html格式的报告

##### 生成html报告 genHTML.sh
```sh
#!/bin/sh
>index.html
echo "<html><head><META http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/><title>用户端自动化性能测试报告</title>">>index.html
echo `cat style.css`>>index.html
(
cat <<EOF
<script language="JavaScript">
               function show_detail(detail){
                           if(detail.style.display=="none"){
                           detail.style.display="";
                           }
                           else{
                           detail.style.display="none";
                           }
                           }
                           </script>
EOF
)>>index.html
echo "</head><body><h1>用户端自动化性能测试报告</h1><hr size="1">">>index.html
sum=`cat summary.txt | wc -l`
sucess=`cat summary.txt|grep pass |grep -v grep|wc -l`
fail=`expr $sum - $sucess`
rate=`echo "$sucess $sum"|awk '{printf("%.2f%%",$1/$2*100)}'`
(
cat <<EOF
<table><tr><td>
<h2>结果汇总</h2>
<table width="60%" cellspacing="2" cellpadding="5" border="0" class="details" align="left">
<tr><th>总接口数</th><th>成功接口数</th><th>失败接口数</th><th>测试通过率</th></tr>
<tr align="center"><td>$sum</td><td>$sucess</td><td>$fail</td><td>$rate</td></tr>
</tr></table>
</td></tr>
EOF
)>>index.html
(
cat <<EOF
<tr><td>
<h2>概要结果</h2>
<table width="95%" cellspacing="2" cellpadding="5" border="0" class="details" align="left">
<tr valign="top">
<th>测试接口</th><th>每秒请求数(tps)</th><th>平均响应时间(ms)</th><th>总事务数</th><th>失败事务数</th><th>事务成功率</th><th>测试结果</th>
</tr>
<tr valign="top" class="">
EOF
)>>index.html
cat summary.txt |while read line
do
  echo $line | awk '{if($7=="pass"){print "<tr><td>"$1"</td><td>"$2"</td><td>"$3"</td><td>"$4"</td><td>"$5"</td><td>"$6"</td><td class=\"Pass\">"$7"</td></tr>"}else{print "<tr><td>"$1"</td><td>"$2"</td><td>"$3"</td><td>"$4"</td><td>"$5"</td><td>"$6"</td><td class=\"Failure\">"$7"</td></tr>"}}'>>index.html
done
echo "</tr></table></td></tr>">>index.html
echo "<table><tr><td><font color="red"><b>测试结果pass标准：tps>10000且事务成功率>90%</b></font><td></tr><tr><td><h2><a href=\"javascript:show_detail(detail)\">详细结果查看附件</a></h2></td></tr></table>">>index.html
#echo "<div class=\"page_details_expanded\" id=\"detail\" style=\"display:none;\" width=\"95%\">">>index.html
(
cat <<EOF
<table width="95%" cellspacing="2" cellpadding="5" border="0" class="details" align="left" id="detail" style="display:none">
<tr valign="top">
<th>测试接口</th><th>每秒请求数tps</th><th>平均响应时间(ms)</th><th>总事务数</th><th>失败事务数</th><th>成功率</th><th>测试结果</th><th>nginx服务器cpu</th><th>nginx服务器io</th><th>web服务器cpu</th><th>web服务器io</th><th>service服务器cpu</th><th>service服务器io</th><th>主数据库服务器cpu</th><th>主数据库服务器io</th><th>从数据库服务器cpu</th><th>从数据库服务器io</th>
</tr>
<tr valign="top" class="">
EOF
)>>index.html
j=1
for i in `cat summary.txt`
do
   if [ `expr $j % 17 ` != 0 ]; then
      echo '<td align="left">'$i'</td>'>>index.html
   else
      echo '<td align="left">'$i'</td></tr>'>>index.html
   fi
   j=`expr $j + 1`
done
echo "</tr></table></td></tr></table></body></html>">>index.html
```

##### html样式 style.css
```html
<style type="text/css">
body {
        font:normal 68% verdana,arial,helvetica;
        color:#000000;
     }
table tr td, table tr th {
         font-size: 78%;
     }
table.details tr th{
         color: #ffffff;
         font-weight: bold;
         text-align:center;
         background:#2674a6;
         white-space: nowrap;
     }
table.details tr td{
        background:#eeeee0;
        white-space: nowrap;
     }
h1 {
        margin: 0px 0px 5px; font: 265% verdana,arial,helvetica
   }
h2 {
        margin-top: 1em; margin-bottom: 0.5em; font: bold 185% verdana,arial,helvetica
   }
h3 {
        margin-bottom: 0.5em; font: bold 115% verdana,arial,helvetica
   }
.Failure {
        font-weight:bold; color:red;
   }
.Pass {
        font-weight:bold; color:green;
   }
</style>
```

#### 发送测试结果邮件 sendmail.py

```python
#!/usr/bin/env python
#coding: utf-8
import string
import smtplib
import os
import datetime
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.header import Header

today = datetime.date.today()
sender = '526077432@qq.com'
receiverlist = ["526077432@qq.com"]
subject = '%s %s' % ('用户端自动化性能测试报告',today)
smtpserver = 'smtp.qq.com'
username = '526077432@qq.com'
password = 'XXXXXX'
f = open('index.html',"r")
content = f.read()

#msg = MIMEText(content,'html','utf-8')
msg = MIMEMultipart()
msg.attach(MIMEText(content,'html','utf-8'))

msg['From'] = '526077432@qq.com'
msg['to'] = ','.join(receiverlist)
msg['Subject'] = subject

att=MIMEText(open('index.html','rb').read(),'base64','gb2312')
att["Conten-Type"]='application/octet-stream'
att["Content-Disposition"]='attachment;filename="Load test result.html"'
msg.attach(att)

smtp = smtplib.SMTP()
smtp.connect(smtpserver)
smtp.ehlo()
smtp.starttls()
smtp.ehlo()
#smtp.set_debuglevel(1)
smtp.login(username, password)
smtp.sendmail(msg['From'],msg['to'],msg.as_string())
smtp.quit()
```

#### Jmeter测试用例编写
我目前使用的方法：
1. 使用Jmeter的GUI客户端进行编写，填写各个参数另存为新的jmx用例文件。
2. 分析jmx文件，直接修改jmx文件中的各个参数，另存为新的jmx用例文件。
实践起来还是GUI客户端比较快捷，但是依旧存在问题：如果服务器IP或者域名变化，所有的用例就得重新编辑一遍，非常耗时且繁琐。
所以还是需要去研究一个更加快捷的jmx用例管理和修改的方法。

#### SSH免密码登录


本文参考至testerhome文章：[https://testerhome.com/topics/4264](https://testerhome.com/topics/4264)
