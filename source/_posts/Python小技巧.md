---
title: Python小技巧
date: 2018-03-06 21:08:43
categories: [Python]
tags: [python]
---

#### pip使用技巧
##### 安装指定版本的第三方库
```bash
pip install robotframework==2.8.7
```
要用``pip``安装指定版本的``Python``包，只需通过``==``操作符指定即可。

  <!--more-->

##### 在指定位置安装第三方
```bash
pip install -t /Users/taoyi/.pyenv/versions/2.7.14/lib/python2.7/site-packages lxml
```
``pip``安装的包不一定是用户想要的位置，此时可以用``-t``选项来指定位置。

##### 通过requirement.txt文件来管理pip的第三方库
文件内容如下：
```bash
robotframework==3.0.2
robotframework-ride==1.5.2
robotframework-appiumlibrary==1.4.6
robotframework-DatabaseLibrary==1.0.1
robotframework-Selenium2Library==3.0.0
robotframework-requests==0.4.7
robotframework-sshlibrary==2.1.3
robotframework-HttpLibrary==0.4.2
requests==2.18.4
PyMySQL==0.8.0
MySQL-python==1.2.5
```
然后通过以下命令来批量安装第三方库
```bash
pip install -r requirement.txt
```

##### 查看有更新的``pip``第三方库
```zsh
# taoyi @ TaoYi-Mac in ~ [16:27:56]
$ pip list --outdate --trusted-host pypi.douban.com
Package                   Version Latest  Type
------------------------- ------- ------- -----
robotframework-ride       1.5.2   1.5.2.1 sdist
robotframework-sshlibrary 2.1.3   3.0.0   sdist
setuptools                28.8.0  39.1.0  wheel
```

##### 更新指定的第三方库
```bash
pip install --upgrade robotframework-sshlibrary
```

##### 查看第三方库的详细信息
```bash
pip show robotframework-sshlibrary
```

##### pip配置文件更新
``pip``配置文件是``~/.pip/pip.conf``文件
```bash
[global]
index-url = http://mirrors.aliyun.com/pypi/simple/

[global]                                              # 设置pip的全局的源
index-url = http://pypi.douban.com/simple

[install]                                             # pip install指定的安装源
trusted-host=pypi.douban.com

[list]                                                # pip list命令接口的展示方式设置
format=columns
```