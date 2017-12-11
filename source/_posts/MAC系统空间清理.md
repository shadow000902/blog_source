---
title: MAC系统空间清理
date: 2016-11-29 18:03:51
categories: [Tips]
tags: [mac, ]
---

1. 删除Emacs——可以节省出60MB+的硬盘空间
```
sudo rm -rf /usr/share/emacs/
```

2. 移除系统嗓音文件——可以节省出500MB-3GB+硬盘空间
```
cd /System/Library/Speech/
sudo rm -rf Voices/*
```

  <!--more-->

3. 删除所有系统日志——可以节省出100MB-2GB硬盘空间
```
sudo rm -rf /private/var/log/*
```

4. 删除快速查看生成的缓存文件——可以节省出100MB-300MB硬盘空间
```
sudo rm -rf /private/var/folders/
```

5. 禁用SafeSleep休眠模式——能节省出4GB-16GB空间
```
sudo pmset -a hibernatemode 0                           # 禁用SafeSleep功能
cd /private/var/vm/
sudo rm sleepimage
touch sleepimage                                        # 要防止OS X继续创建该文件，所以我们需要下面的命令生成一个无法被替换的空文件
chmod 000 /private/var/vm/sleepimage
sudo pmset -a hibernatemode 3                           # 重新开启SafeSleep功能
sudo rm /private/var/vm/sleepimage
```

6. 清除缓存文件——可以节省1GB-10GB硬盘空间
```
cd ~/Library/Caches/
rm -rf ~/Library/Caches/*
```

7. 删除临时文件——可以节省500MB-5GB硬盘空间
```
cd /private/var/tmp/
rm -rf TM*
```
