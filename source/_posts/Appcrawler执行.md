---
title: Appcrawler执行
date: 2016-07-19 16:38:41
categories: [Appcrawler]
tags: [appcrawler]
---

1. 启动Appium服务器
```
TaoYi-Mac:~ taoyi$  appium --session-override -p 4730 --no-reset
```

<!--more-->

2. 运行appcrawler，执行测试
```
TaoYi-Mac:appcrawler taoyi$ java -jar appcrawler-1.2.1.jar -a /usr/local/TestGroupCode/appcrawler/fengche.apk
```
