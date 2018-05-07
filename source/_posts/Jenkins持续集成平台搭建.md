---
title: Jenkins持续集成平台搭建
date: 2017-08-16 11:55:43
categories: [Jenkins]
tags: [jenkins]
---

##### Jenkins 部署
1. 创建``Jenkins``运行目录
```bash
# Jenkins主目录
mkdir /opt/Jenkins/Home
# Jenkins缓存位置
mkdir /opt/Jenkins/tmp
# 脚本存放位置
mkdir /opt/Jenkins/script
```

2. 设置``jenkins``主目录
第一种方法是使用WEB容器工具设置``JENKINS_HOME``环境参数。
```bash
打开tomcat的bin目录，编辑catalina.sh文件。
在# OS specific support.  $var _must_ be set to either true or false.上面添加：export JENKINS_HOME=""
在引号中填入你的路径。
```
第二种是在环境变量中设置``JENKINS_HOME``。
```bash
# 编辑对应用户的终端的环境变量设置文件
编辑profile文件：vim ~/.bashrc
在最后加入：export JENKINS_HOME="/home/souche/jenkins/Home"
```

  <!--more-->

3. 下载``jenkins.war``
[下载地址](https://jenkins.io/download/)
把下载的``war``包放入``/opt/Jenkins``目录下

4. 编写启动脚本
```bash
/usr/bin/java -Dfile.encoding=UTF-8 \
                    -XX:PermSize=256m -XX:MaxPermSize=512m -Xms256m -Xmx512m \
                    -Djava.io.tmpdir=/opt/Jenkins/tmp \
                    -jar /opt/Jenkins/jenkins.war \
                    --httpListenAddress=127.0.0.1 \
                    --httpPort=8080 \
                    >> /opt/Jenkins/nohup.out \
                    2>&1 &
```


```bash
# 设置编码格式
-Dfile.encoding=UTF-8
# 设置内存占用
-XX:PermSize=256m -XX:MaxPermSize=512m -Xms256m -Xmx512m
# 指定Jenkins运行缓存位置
-Djava.io.tmpdir=/opt/Jenkins/tmp
# 指定执行的war包
-jar /opt/Jenkins/jenkins.war
# 指定本地IP，可能是127.0.0.1，也可能是内网对应的IP
--httpListenAddress=127.0.0.1
# 指定本地端口
--httpPort=8080
# 指定Jenkins运行日志输出位置
>> /opt/Jenkins/nohup.out
# 设置进程在后台运行
2>&1 &
```
新建脚本文件存放脚本``startJenkins.sh``，放到``script``目录下。
执行脚本

```bash
# 赋予可执行权限
chmod a+x startJenkins.sh
# 执行脚本，启动Jenkins
./startJenkins.sh
```

5. ``Jenkins``主目录介绍
```bash
# jenkins主配置文件
-rw-r--r--   1 taoyi  wheel   1.6K  8 16 01:43 config.xml
-rw-r--r--   1 taoyi  wheel   159B  8 16 01:43 hudson.model.UpdateCenter.xml
-rw-------   1 taoyi  wheel   1.7K  8 16 01:27 identity.key.enc
-rw-r--r--   1 taoyi  wheel    94B  8 16 01:27 jenkins.CLI.xml
-rw-r--r--   1 taoyi  wheel     4B  8 16 01:43 jenkins.install.InstallUtil.lastExecVersion
-rw-r--r--   1 taoyi  wheel     4B  8 16 01:30 jenkins.install.UpgradeWizard.state
# 包含所有的项目，包含所有项目对应的配置文件，包括挂到slave中的项目的配置文件
drwxr-xr-x   4 taoyi  wheel   136B  8 16 09:35 jobs
drwxr-xr-x   4 taoyi  wheel   136B  8 16 01:29 logs
-rw-r--r--   1 taoyi  wheel   907B  8 16 01:43 nodeMonitors.xml
# 所有的slave节点配置文件
drwxr-xr-x   2 taoyi  wheel    68B  8 16 01:27 nodes
# Jenkins插件
drwxr-xr-x   2 taoyi  wheel    68B  8 16 01:27 plugins
-rw-r--r--   1 taoyi  wheel    64B  8 16 01:27 secret.key
-rw-r--r--   1 taoyi  wheel     0B  8 16 01:27 secret.key.not-so-secret
drwx------  15 taoyi  wheel   510B  8 16 01:44 secrets
drwxr-xr-x   5 taoyi  wheel   170B  8 16 01:27 updates
drwxr-xr-x   3 taoyi  wheel   102B  8 16 01:27 userContent
# 在Jenkins中添加的所有用户都会在这个目录下新建文件夹管理，每个用户都会有一个config.xml配置文件
drwxr-xr-x   4 taoyi  wheel   136B  8 16 01:40 users
drwxr-xr-x  25 taoyi  wheel   850B  8 16 01:27 war
# 挂在本机下的所有项目的工作空间
drwxr-xr-x   3 taoyi  wheel   102B  8 16 01:44 workspace
```

##### 问题总结
1. ``Jenkins console``输出乱码
在``/etc/profile``中添加``export JAVA_TOOL_OPTIONS="-Dfile.encoding=UTF-8"``
在``Jenkins``系统管理里，添加环境变量``Key``：``LANG``，``Value``：``en_US.UTF-8``（如果系统默认的已经是en_US.UTF-8，就不用设置了）


##### 好用的Jenkins插件

1. ``Build User Vars Plugin``【获取项目构建人】

插件名称：``user build vars plugin``

变量值表
{% raw %}
<html>
	<body>
		<table border="1">
			<tr>
				<th>Variable</th>
				<th>Description</th>
			</tr>
			<tr>
				<td>BUILD_USER</td>
				<td>Full name (first name + last name) </td>
			</tr>
			<tr>
				<td>BUILD_USER_EMAIL</td>
				<td>Email address</td>
			</tr>
			<tr>
				<td>BUILD_USER_FIRST_NAME</td>
				<td>First name</td>
			</tr>
			<tr>
				<td>BUILD_USER_ID</td>
				<td>Jenkins user ID</td>
			</tr>
			<tr>
				<td>BUILD_USER_LAST_NAME</td>
				<td>Last name</td>
			</tr>
		</table>
	</body>
</html>
{% endraw %}

在jenkins任务中使用构建变量：注意需要勾选 "Set jenkins user build variables."


2. ``Naginator``【任务失败重新构建插件】
在``构建后操作``中选择``Retry build after failure``。``Fixed delay``填写每次重试的时间延迟，单位是秒。``Maximum number of successive failed builds``文本框中填写重试次数。


3. ``Publish Over SSH``【通过ssh构建项目】

4. ``触发远程构建（例如，使用脚本）``
{% asset_img 构建触发器_身份验证令牌.png 构建触发器_身份验证令牌 %}
设置身份验证令牌``TOKEN_NAME``，可以随意定义。
```bash
# 默认参数执行远程构建
JENKINS_URL/job/JOB_NAME/build?token=TOKEN_NAME
# 参数化形式执行远程构建
JENKINS_URL/job/JOB_NAME/buildWithParameters?token=TOKEN_NAME&params1=params1&...
```

5. 常用插件汇总
``Build Environment Plugin``构建环境插件，可以进行构建环境比较。
``Build Flow Plugin``工作流插件，支持DSL脚本定义工作流
``Build Graph View Plugin``build Flow插件视图（安装后需要重新才能生效）
``Build Monitor View``使用心得：基于该插件可以实现dashboard功能
``Build Pipeline Plugin View ``Pipeline 管道流图表展示插件
``Build Timestamp Plugin ``任务log时间戳插件，使得job log的每次输出前面都增加当时的时间
``Build-timeout Plugin``job构建超时插件
``BuildResultTrigger Plugin``根据其他的job的成功或失败来启动此build。
``Cron Column Plugin`` 通过定时任务例行的运行一些job
``Files Found Trigger``检测指定的目录，如果发现指定模式的文件则启动build。
``HTTP Request Plugin``使用心得：在构建前后可以通过该插件以http形式调用各种api接口实现和内部系统的联动
``Job Configuration History Plugin``使用心得：使job具备版本管理的能力，diff和rollback功能更是非常赞
``Job Import Plugin``使用心得：可以快速导入其他jenkins集群的已有job，需要认证的jenkins系统导入需要提供凭证才可以
``Join Plugin``这也是一个触发job的插件，亮点在于它触发job的条件是等待所有当前job的下游的job都完成才会发生。
``Multijob Plugin``多任务插件
``Naginator Plugin``任务重试插件
``Parameterized Trigger Plugin``这是一个扩展型的插件，使各个job连接的时候可以传递一些job相关的信息
``Periodic Backup``使用心得：备份是运维一个系统必须要保障的事情，该插件的恢复功能可能不可用，需要手工进行，好处在于可以定时备份
``Publish Over SSH Plugin``通过ssh发布文件
``Rebuild Plugin``重新执行插件
``Status Monitor Plugin``构建状态插件
``ws-cleanup Plugin ``workspace清理插件

