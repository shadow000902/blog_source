---
title: Linux下命令行安装配置android-sdk
date: 2016-07-07 00:05:16
categories: [Linux]
tags: [sdk, linux]
---

1. 首先需要下载android sdk tools only
```
wget https://dl.google.com/android/android-sdk_r24.4.1-linux.tgz
tar -zxvf android-sdk_r24.4.1-linux.tgz
```

  <!--more-->

2. 查看可用的SDK组件
```
android list sdk --all
```

3. 下载需要的组件, 注意--all 这个参数一定要加上, 否则后面filter里的序号不起作用
```
android update sdk -u --all --filter 1,2,3,5
```

4. 更新已安装的``SDK``
```
android update sdk --no-ui
```
