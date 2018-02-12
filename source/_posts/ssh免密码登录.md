---
title: ssh免密码登录
date: 2016-05-26 01:32:43
categories: [Tips]
tags: [ssh]
---
#### 免密介绍

其实不能说是免密码登录，你在第一次登录进账户的时候还是需要密码的。但是再用该受信任用户身份访问其他节点的时候可以让你不用输入密码。也就是一次验证，处处通行。真正的术语叫做公钥登录。

> 所谓”公钥登录”，原理很简单，就是用户将自己的公钥储存在远程主机上。登录的时候，远程主机会向用户发送一段随机字符串，用户用自己的私钥加密后，再发回来。远程主机用事先储存的公钥进行解密，如果成功，就证明用户是可信的，直接允许登录shell，不再要求密码。这种方法要求用户必须提供自己的公钥。如果没有现成的，可以直接用ssh-keygen生成一个。

  <!--more-->

具体的原理相对来说就比较复杂了。参见阮一峰的这篇博客[SSH原理与运用(一):远程登录](http://www.ruanyifeng.com/blog/2011/12/ssh_remote_login.html)。

#### 设置免密

免密码登录：
生成本用户的密钥，再把公钥存成authorized_key文件。
``` bash
ssh user@host 'mkdir -p .ssh && cat >> .ssh/authorized_keys' < ~/.ssh/id_rsa.pub
```
过程是：
1. ``ssh user@host``，表示登录远程主机,当然远程用户名和本地一致的时候可以省略，直接使用``ssh host``。
2. ``mkdir -p .ssh``，如果用户主目录中的.ssh目录不存在，就创建一个。
3. ``'cat >> .ssh/authorized_keys' < ~/.ssh/id_rsa.pub``的作用，是将本地的公钥文件``~/.ssh/id_rsa.pub``，重定向追加到远程文件authorized_key的末尾。

写入authorized_keys文件后，公钥登录的设置就完成了。
最后还要对``.ssh``目录和``.ssh/authorized_keys``文件的权限做确认，``.ssh``目录的权限必须是``700``，``.ssh/authorized_keys``文件权限必须是``600``。

#### 设置快捷登录
我们可以利用``ssh``的用户配置文件``config``管理 多个免密码``ssh``会话。``ssh``的用户配置文件是放在当前用户根目录下的``.ssh``文件夹里（**``~/.ssh/config``**，不存在则新创建一个），其配置写法如下：
```bash
# 别名：比如 jhost
Host 别名
    # 用户名：比如 taoyi
    User 用户名
    # 主机名：比如 192.168.1.1，主机名也可以是域名
    HostName 主机名
    # 密钥文件的路径：比如 ~/.ssh/id_rsa
    IdentityFile 密钥文件的路径
```
