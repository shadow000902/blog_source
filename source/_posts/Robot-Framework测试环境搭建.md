---
title: Robot-Framework测试环境搭建
date: 2016-05-06 14:16:53
categories: [Robot-Framework]
tags: [robot-framework]
---

1. 安装python环境。
由于Robot Framework是基于python2开发的，所以必须选择安装python2版本，不然会造成很多异常，之后需要的一些依赖python2的库也无法安装。这里我选择安装的是[Anaconda2](https://www.continuum.io/downloads)，它自身就包含较多的python库，比较好用。

<!--more-->

2. 安装Appium。如果安装过程中遇到问题，还请看[Appium安装](http://shadow000902.space/2016/03/31/Appium安装/)
```
npm install appium -g
```

2. 安装Robot Framework
2.1 源码安装。[下载地址](https://pypi.python.org/pypi/robotframework)
``` bash
cd .../robotframework/
python setup.py install
```
2.2 通过pip安装
``` bash
pip install robotframework
```

3. 安装wxPython。[下载地址](http://www.wxpython.org/download.php)
3.1 windows环境：exe文件，正常安装
3.2 **mac环境**：``brew``安装，修改源码
```bash
brew install wxpython                   # 使用Homebrew安装wxpython
```
对于``wxPython``的版本控制语句存在于``/Library/Python/2.7/site-packages/robotide/__init__.py``文件中
```python
import sys
import os
from string import Template

errorMessageTemplate = Template("""$reason
You need to install wxPython 2.8.12.1 with unicode support to run RIDE.
 36 wxPython 2.8.12.1 can be downloaded from http://sourceforge.net/projects/wxpython/files/wxPython/2.8.12.1/""")
supported_versions = ["2.8"]

try:
    import wxversion
    from wxversion import VersionError
    if sys.platform == 'darwin':
        supported_versions.append("2.9")
        supported_versions.append("3.0")            # 新增该代码，让ride支持wxpython3.0
    wxversion.select(supported_versions)
    import wx
```
4. 安装ride。
RIDE 是Robot Framework 测试数据的编辑器。它使测试用例的创建、运行、测试项目的组织可以在图形界面下完成。
4.1 源码安装。[下载地址](https://pypi.python.org/pypi/robotframework-ride)
``` bash
cd .../robotframework-ride/
python setup.py install
```
4.2 通过pip安装
``` bash
pip install robotframework-ride
```

5. 命令行启动ride
5.1 Windows
定位到ride安装的位置，`C:\Anaconda2\Scripts\`
``` bash
python ride.py
```
5.2 mac
ride.py已经自动加入到了环境变量下面
可以直接通过运行``ride.py``执行

6. 遇到ride无法启动的问题【Windows】
```bash
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

还有另一个问题，可能会遇到ride界面工具crash的问题
需要删除``.robotframework``
```bash
rm -rf ~/.robotframework/
```

7. 安装robotframework-appiumlibrary
``` bash
pip install robotframework-appiumlibrary
```

8. 安装robotframework-selenium2library
``` bash
pip install robotframework-selenium2library
```
