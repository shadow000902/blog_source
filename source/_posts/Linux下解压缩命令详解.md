---
title: Linux下解压缩命令详解
date: 2016-07-07 00:52:04
categories: [Linux]
tags: [linux]
---

1. zip&unzip
```
zip -r mydata.zip mydata        # 压缩mydata文件夹到mydata.zip
unzip mydata.zip -d mydatabak   # 把mydata.zip解压到mydatabak文件夹中
```

  <!--more-->

2. tar
```
tar -zxvf android-sdk_r24.4.1-linux.tgz   ＃解压到当前目录
```
3. XXX.tar.xz
```
xz -d XXX.tar.xz
tar xvf XXX.tar
```
4. XXX.tgz & XXX.tar.gz
```
gunzip XXX.tgz
tar xvf XXX.tar
or
tar xvf XXX.tar.gz
```
