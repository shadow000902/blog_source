---
title: Linux 安装 shadowsocks
date: 2016-10-09 19:43:52
categories: [Linux]
tags: [linux, shadowsocks]
---

#### 安装shadowsocks命令行程序，配置命令
##### ``python`` ``pip``安装``shadowsocks``
```
sudo apt-get update
sudo apt-get install python-pip
sudo apt-get install python-setuptools m2crypto
pip install shadowsocks
sudo apt install shadowsocks                                            # ubuntu 16.04的安装方法
```

  <!--more-->

##### 启动``shadowsocks``
安装好后，在本地需要用到``sslocal``，
使用方法：``sslocal -c`` 后面加上我们的``json``配置文件，或者像下面这样直接命令参数写上运行.
```
sslocal -s 11.22.33.44 -p 50003 -k "123456" -l 1080 -t 600 -m aes-256-cfb
-s                          # 代表服务IP
-p                          # 代表服务器的端口
-k                          # 代表密码，需要加双引号（""）
-l                          # 代表本地端口
-t                          # 代表超时时间，单位毫秒
-m                          # 代表加密方法，默认为（aes-256-cfb）
```
为了方便我推荐直接用 ``sslcoal -c`` 配置文件路径 这样的方式，简单好用。
在``/home/user/``下新建一个``shadowsocks.json``文件。
内容如下：
```
{
    "server":"11.22.33.44",
    "server_port":50003,
    "local_port":1080,
    "password":"123456",
    "timeout":600,
    "method":"aes-256-cfb"
}
```
运行``shadowsocks``
```
sslocal -c /home/user/shadowsocks.json
```

#### 安装shadowsocks GUI图形界面程序
在``ubuntu``上可以通过``PPA``源码安装
```
sudo add-apt-repository ppa:hzwhuang/ss-qt5
sudo apt-get update
sudo apt-get install shadowsocks-qt5
```
然后在应用程序中就可以找到，之后的配置和windows一样。
