---
title: Jenkins中slave的设置
date: 2017-06-24 13:02:12
categories: [Jenkins]
tags: [jenkins]
---

##### 在Jenkins中配置从节点
{% asset_img 配置从节点.png 配置从节点 %}
增加节点后，实际并没有直接连上，还需要在节点服务器上进行相应的配置

  <!--more-->

##### 在从节点服务器的host中的加入配置

```bash
sudo vim /etc/hosts
```
```bash
111.111.111.111 jenkins.shadow.com						# 前部分IP为Jenkins的内网地址，后部分为Jenkins的对外访问域名
```

##### 从节点服务器上配置Jenkins节点配置
{% asset_img 从节点配置要点.png 从节点配置要点 %}
点击上图中的``slave.jar``的链接，下载该文件，放在上方指定的``Jenkins``工作目录下
```bash
test@test-devtesting-00001:~/jenkins$ ll
total 760
drwxrwxr-x  3 test test   4096 Jun 23 16:04 ./
drwx------ 18 test test   4096 Jun 24 13:47 ../
-rw-rw-r--  1 test test   7623 Jun 23 16:04 maven33-agent.jar
-rw-rw-r--  1 test test  19971 Jun 23 16:04 maven33-interceptor.jar
-rw-rw-r--  1 test test   6764 Jun 23 16:04 maven3-interceptor-commons.jar
-rw-rw-r--  1 test test    738 Jun  8 16:52 slave-agent.jnlp
-rw-rw-r--  1 test test 717563 May  2 17:29 slave.jar								# 上方下载的slave.jar文件
-rwxrwxr-x  1 test test    114 Jun  6 19:28 start_jenkins.sh*						# 启动Jenkinsslave的脚本
drwxrwxr-x 14 test test   4096 Jun 24 12:43 workspace/								# Jenkins项目的工作目录
```
将提示中的启动``Jenkins``的脚本写入文件``start_jenkins.sh``中
```shell
java -jar slave.jar -jnlpUrl http://jenkins.shadow.com/computer/test-devtesting-00001/slave-agent.jnlp 2>&1 &
```
赋予``start_jenkins.sh``执行权限
```bash
chmod a+x start_jenkins.sh
```
启动slave
```bash
./start_jenkins.sh
```
回到Jenkins节点列表，查看添加的节点，状态如图就说明启动成功了。
{% asset_img 节点列表.png 节点列表 %}

至此，slave节点就配置并启动完毕了。