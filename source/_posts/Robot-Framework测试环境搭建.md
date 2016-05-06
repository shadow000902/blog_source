---
title: Robot-Framework测试环境搭建
date: 2016-05-06 14:16:53
categories: [Robot-Framework]
tags: [robot-framework]
---

#### 1. 安装python环境。
由于Robot Framework是基于python2开发的，所以必须选择安装python2版本，不然会造成很多异常，之后需要的一些依赖python2的库也无法安装。这里我选择安装的是[Anaconda2](https://www.continuum.io/downloads)，它自身就包含较多的python库，比较好用。

<!--more-->


#### 2. 安装Robot Framework
2.1 源码安装。[下载地址](https://pypi.python.org/pypi/robotframework)
``` bash
cd .../robotframework/
python setup.py install
```
2.2 通过pip安装
``` bash
pip install robotframework
```

#### 3. 安装wxPython。[下载地址](http://www.wxpython.org/download.php)
exe文件，正常安装

#### 4. 安装ride。
RIDE 是Robot Framework 测试数据的编辑器。它使测试用例的创建、运行、测试项目的组织可以在图形界面下完成。
2.1 源码安装。[下载地址](https://pypi.python.org/pypi/robotframework-ride)
``` bash
cd .../robotframework-ride/
python setup.py install
```
2.2 通过pip安装
``` bash
pip install robotframework-ride
```

#### 5. 命令行启动ride
定位到ride安装的位置，`C:\Anaconda2\Scripts\`
``` bash
python ride.py
```

#### 6. 遇到ride无法启动的问题
``` bash
Python 2.7.11 |Anaconda 4.0.0 (64-bit)| (default, Feb 16 2016, 09:58:36) [MSC v.1500 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license" for more information.
Anaconda is brought to you by Continuum Analytics.
Please check out: http://continuum.io/thanks and https://anaconda.org
>>> from robotide import main
wxPython not found.
You need to install wxPython 2.8 toolkit with unicode support to run RIDE.
wxPython 2.8.12.1 can be downloaded from
http://sourceforge.net/projects/wxpython/files/wxPython/2.8.12.1/
```
安装的ride是基于wxPython 2.8.12.1 编译的，所以就需要安装 wxPython 2.8.12.1。