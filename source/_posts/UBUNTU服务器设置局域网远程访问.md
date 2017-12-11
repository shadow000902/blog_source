---
title: UBUNTU服务器设置局域网远程访问
date: 2016-11-29 16:18:35
categories: [Linux]
tags: [ubuntu]
---

##### 安装``ssh``
```
sudo apt-get install openssh-server
```

##### 查看``ssh``服务是否启动
```
ps -ef | grep ssh
```

  <!--more-->

##### 如果``ssh``服务没有启动，启动``ssh``服务
```
service ssh start
```

##### 修改``ssh``配置文件
```
sudo vim /etc/ssh/sshd_config
```

``` shell
# Authentication:
LoginGraceTime 120
#PermitRootLogin without-password               # 该行首加一个“#”注释掉该行
PermitRootLogin yes                             # 添加该行，增加一个配置项
StrictModes yes
```

##### 局域网远程访问
``` shell
ssh root@192.168.0.1
# root 远程服务器访问用户名
# 192.168.0.1 远程服务器局域网IP
```
