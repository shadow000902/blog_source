---
title: Windows平台下载Android源码
date: 2016-04-26 23:22:58
categories: [Android]
tags: [android, 源码]
---

#### 准备工作
1. 需要[git](https://git-scm.com/download/)软件，自行下载安装
2. 需要[python](https://www.python.org/)环境，自行下载安装

  <!--more-->

#### 使用git手动下载android源码
1. 自行新建用来存放android源码的文件夹，如android-source，即目录D:/android-source
2. 依次执行如下命令：
``` bash
cd D:/android-source
git clone https://android.googlesource.com/platform/manifest.git    # 遇到443错误码的就是被墙了，自行翻墙解决
cd manifest
git tag                                                             # 列出android各个分支版本
git checkout android-6.0.1_r1                                       # 下载需要的android源码
```
3. 等待完成就下载完了所有对应版本的android源码，manifest/default.xml文件中记录的就是android6.0.1系统各个模块的路径.

#### 使用python脚本批量下载
##### download-src.py脚本
```python
import xml.dom.minidom
import os
from subprocess import call

#downloaded source path
rootdir = "D:/android-source"

#git program path
git = "D:/Program Files/Git/bin/git.exe"

dom = xml.dom.minidom.parse("D:/manifest/default.xml")
root = dom.documentElement

prefix = git + " clone https://android.googlesource.com/"
suffix = ".git"

if not os.path.exists(rootdir):
    os.mkdir(rootdir)

for node in root.getElementsByTagName("project"):
    os.chdir(rootdir)
    d = node.getAttribute("path")
    last = d.rfind("/")
    if last != -1:
        d = rootdir + "/" + d[:last]
        if not os.path.exists(d):
            os.makedirs(d)
        os.chdir(d)
    cmd = prefix + node.getAttribute("name") + suffix
    call(cmd)
```
##### 执行此脚本的前提
已经执行了git checkout，选择好了要下载的Android源码版本，如果你的manifest文件不是D:/manifest/default.xml，还要把里面的git.exe的路经修改成你的安装路径，请自行修改脚本，执行这个脚本之后，就开始自动下载了
