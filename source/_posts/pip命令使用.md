---
title: pip命令使用
date: 2016-08-08 16:38:38
categories: [Python]
tags: [pip]
---

1. 安装``mitmproxy``
```
sudo -H pip install mitmproxy --upgrade --ignore-installed six
```
由于``six-1.4.1``无法被卸载，也无法被更新，所以在安装需要更新six的软件时，就会一直报错。
解决办法就是安装软件的时候，忽略``six-1.4.1``，也就是``--ignore-installed six``
