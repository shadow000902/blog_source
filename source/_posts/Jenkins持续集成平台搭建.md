---
title: Jenkins持续集成平台搭建
date: 2017-08-16 11:55:43
categories: [JENKINS]
tags: [jenkins]
---

##### Jenkins 部署
1. 创建``Jenkins``运行目录
```bash
mkdir /opt/Jenkins/Home						# Jenkins主目录
mkdir /opt/Jenkins/tmp							# Jenkins缓存位置
mkdir /opt/Jenkins/script						# 脚本存放位置
```

  <!--more-->

2. 下载``jenkins.war``
[下载地址](https://jenkins.io/download/)
把下载的``war``包放入``/opt/Jenkins``目录下

3. 编写启动脚本
```bash
/usr/bin/java -Dfile.encoding=UTF-8 \
                    -XX:PermSize=256m -XX:MaxPermSize=512m -Xms256m -Xmx512m \
                    -Djava.io.tmpdir=/opt/Jenkins/tmp \
                    -jar /opt/Jenkins/jenkins.war \
                    --httpPort=8080 \
                    >> /opt/Jenkins/nohup.out \
                    2>&1 &
```

```bash
-Dfile.encoding=UTF-8																			# 设置编码格式
-XX:PermSize=256m -XX:MaxPermSize=512m -Xms256m -Xmx512m			# 设置内存占用
-Djava.io.tmpdir=/opt/Jenkins/tmp														# 指定Jenkins运行缓存位置
-jar /opt/Jenkins/jenkins.war																# 指定执行的war包
--httpPort=8080																					# 指定本地端口
>> /opt/Jenkins/nohup.out																	# 指定Jenkins运行日志输出位置
2>&1 &																								# 设置进程在后台运行
```
新建脚本文件存放脚本``startJenkins.sh``，放到``script``目录下。
执行脚本：
```bash
chmod a+x startJenkins.sh																	# 赋予可执行权限
./startJenkins.sh																				# 执行脚本，启动Jenkins
```

4. ``Jenkins``主目录介绍
```bash
-rw-r--r--   1 taoyi  wheel   1.6K  8 16 01:43 config.xml																# jenkins主配置文件
-rw-r--r--   1 taoyi  wheel   159B  8 16 01:43 hudson.model.UpdateCenter.xml
-rw-------   1 taoyi  wheel   1.7K  8 16 01:27 identity.key.enc
-rw-r--r--   1 taoyi  wheel    94B  8 16 01:27 jenkins.CLI.xml
-rw-r--r--   1 taoyi  wheel     4B  8 16 01:43 jenkins.install.InstallUtil.lastExecVersion
-rw-r--r--   1 taoyi  wheel     4B  8 16 01:30 jenkins.install.UpgradeWizard.state
drwxr-xr-x   4 taoyi  wheel   136B  8 16 09:35 jobs																# 包含所有的项目，包含所有项目对应的配置文件，包括挂到slave中的项目的配置文件
drwxr-xr-x   4 taoyi  wheel   136B  8 16 01:29 logs
-rw-r--r--   1 taoyi  wheel   907B  8 16 01:43 nodeMonitors.xml
drwxr-xr-x   2 taoyi  wheel    68B  8 16 01:27 nodes																# 所有的slave节点配置文件
drwxr-xr-x   2 taoyi  wheel    68B  8 16 01:27 plugins																# Jenkins插件
-rw-r--r--   1 taoyi  wheel    64B  8 16 01:27 secret.key
-rw-r--r--   1 taoyi  wheel     0B  8 16 01:27 secret.key.not-so-secret
drwx------  15 taoyi  wheel   510B  8 16 01:44 secrets
drwxr-xr-x   5 taoyi  wheel   170B  8 16 01:27 updates
drwxr-xr-x   3 taoyi  wheel   102B  8 16 01:27 userContent
drwxr-xr-x   4 taoyi  wheel   136B  8 16 01:40 users																# 在Jenkins中添加的所有用户都会在这个目录下新建文件夹管理，每个用户都会有一个config.xml配置文件
drwxr-xr-x  25 taoyi  wheel   850B  8 16 01:27 war
drwxr-xr-x   3 taoyi  wheel   102B  8 16 01:44 workspace															# 挂在本机下的所有项目的工作空间
```

