---
title: Mac系统自带Terminal登录ssh自动记录密码
date: 2016-07-12 10:03:45
categories: [Tips]
tags: [mac, ssh]
---
系统自带终端的ssh是标准的OpenSSH client

如果需要克隆会话功能，可以通过配置打开。
``` bash
vim ~/.ssh/config
```

  <!--more-->

把一下内容：
``` bash
Host *
    ControlMaster auto
    ControlPath ~/.ssh/%h-%p-%r
    ControlPersist yes
```
填入config文件中

查看config中的内容：
```
$ cat .ssh/config
Host *
    ControlMaster auto
    ControlPath ~/.ssh/%h-%p-%r
    ControlPersist yes
```
这样每连上一个服务器都会自动在~/.ssh/下创建一个socket文件，下次用相同用户名、端口、主机名进行连接就会自动复用。
