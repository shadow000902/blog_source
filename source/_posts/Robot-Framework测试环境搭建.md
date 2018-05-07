---
title: Robot-Framework测试环境搭建
date: 2016-05-06 14:16:53
categories: [RobotFramework]
tags: [robot-framework]
---

#### 安装python环境。
由于Robot Framework是基于python2开发的，所以必须选择安装python2版本，不然会造成很多异常，之后需要的一些依赖python2的库也无法安装。这里我选择安装的是[Anaconda2](https://www.continuum.io/downloads)，它自身就包含较多的python库，比较好用。

  <!--more-->

#### 安装Appium。如果安装过程中遇到问题，还请看[Appium安装](http://shadow000902.space/2016/03/31/Appium安装/)
```bash
npm install appium -g
```

#### 安装Robot Framework
##### 源码安装。[下载地址](https://pypi.python.org/pypi/robotframework)
```bash
cd .../robotframework/
python setup.py install
```
##### 通过pip安装
```bash
pip install robotframework
```

#### 安装wxPython。[下载地址](http://www.wxpython.org/download.php)
##### windows环境：exe文件，正常安装
##### **mac环境**：``brew``安装，修改源码
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
#### 安装ride。
RIDE 是``Robot Framework``测试数据的编辑器。它使测试用例的创建、运行、测试项目的组织可以在图形界面下完成。
##### 源码安装。[下载地址](https://pypi.python.org/pypi/robotframework-ride)
```bash
cd .../robotframework-ride/
python setup.py install
```
##### 通过pip安装
```bash
pip install robotframework-ride
```
最新版本``1.5.2.1``可能会出现闪退的问题，那就需要降级，先卸载该版本，然后下载``1.5.2``版本

#### 命令行启动ride
##### Windows
定位到ride安装的位置，`C:\Anaconda2\Scripts\`
```bash
python ride.py
```
##### mac
ride.py已经自动加入到了环境变量下面
可以直接通过运行``ride.py``执行

#### 安装robotframework-appiumlibrary
```bash
pip install robotframework-appiumlibrary
```

#### 安装robotframework-selenium2library
```bash
pip install robotframework-selenium2library
```

#### 问题解决

##### 遇到ride无法启动的问题【Windows】
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

##### mac 强制安装 wxpython2.8.12.1
下载[wxPython2.8-osx-unicode-2.8.12.1-universal-py2.7.dmg](https://sourceforge.net/projects/wxpython/files/wxPython/2.8.12.1/wxPython2.8-osx-unicode-2.8.12.1-universal-py2.7.dmg/download)；打开得到``wxPython2.8-osx-unicode-universal-py2.7.pkg``；右键显示包内容，再得到``wxPython2.8-osx-unicode-universal-py2.7.pax.gz``和``postflight``；解压``wxPython2.8-osx-unicode-universal-py2.7.pax.gz``，再得到``/usr/local/lib/wxPython-unicode-2.8.12.1``，把该文件夹放入系统的``/usr/local/lib/``中，切换到``postflight``目录，运行命令``sudo ./postflight``，安装好wxpython2.8.12.1。
执行``ride.py``提示：
```bash
python should be executed in 32-bit mode with wxPython on OSX.
```
是因为wxpython是32位的，而我们安装的是64位的。
输入以下命令强制执行32位：
```bash
defaults write com.apple.versioner.python Prefer-32-Bit -bool yes
```

##### ride 一次使用后再次打开崩溃的问题
因为用``pip install robotframework-ride``安装的``ride``是1.5.2.1版本，会出现这个问题，所以安装指定的1.5.2版本
```bash
pip install robotframework-ride==1.5.2
```

##### 切换使用``pyenv``来管理python环境后，``ride.py``无法启动
因为安装的``ride.py``在启动时，调用了虚拟环境的``python``，但是虚拟环境的python无法启动GUI界面，所以如果需要使用``ride.py``的GUI界面，就需要从系统python安装的``ride.py``去启动。
这样就需要使用系统的``pip``，也就是``/usr/local/bin/``目录下的``pip``来安装``ride.py``。
然后通过``/usr/local/bin/ride.py``来启动``ride.py``。

