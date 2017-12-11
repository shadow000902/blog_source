---
title: 应用重签名工具re-sign.jar使用
date: 2017-03-05 14:46:33
categories: [Tools]
tags: [重签名, re-sign.jar]
---

#### 下载 re-sign.jar
[下载地址](http://download.csdn.net/download/christopher_lv/8569477)

#### 应用 re-sign.jar
##### 把 re-sign.jar 放到 .android 文件夹下

  <!--more-->

```bash
➜  .android ll
total 216
-rw-r--r--   1 taoyi  staff   2.1K  7  5  2016 debug.keystore
-rw-r--r--@  1 taoyi  staff    47K  3  4 22:35 re-sign.jar
```

##### 运行 re-sign.jar
```bash
cd .android
java -jar re-sign.jar
```

##### 把应用拖放到窗口进行重签名
{% asset_img 重签名工具使用.png 重签名工具使用 %}

重签名成功
{% asset_img 重签名成功.png 重签名成功 %}
```bash
➜  .android java -jar re-sign.jar                   
Running jarsigner
Command line: /Library/Java/JavaVirtualMachines/jdk1.8.0_91.jdk/Contents/Home/bin/jarsigner -keystore /Users/taoyi/.android/debug.keystore -storepass android -keypass android /var/folders/6c/t0zm0zy90p12fjr77h9qtktr0000gp/T/resigner3271202971406261445.apk androiddebugkey
jarsigner finished with following output:
jar å·²ç­¾åã

è­¦å:
æªæä¾ -tsa æ -tsacert, æ­¤ jar æ²¡ææ¶é´æ³ãå¦ææ²¡ææ¶é´æ³, åå¨ç­¾åèè¯ä¹¦çå°ææ¥æ (2046-06-28) æä»¥åçä»»ä½æ¤éæ¥æä¹å, ç¨æ·å¯è½æ æ³éªè¯æ­¤ jarã
Running zipalign
Command line: /opt/android-sdk-macosx/tools/zipalign -f 4 /var/folders/6c/t0zm0zy90p12fjr77h9qtktr0000gp/T/resigner3271202971406261445.apk /Users/taoyi/git_projects/dfcAppium/res/app/android/fengche_debug.apk
zipalign finished with following output:
```
