---
title: Maven-Web实例从服务器部署到Jenkins集成
date: 2017-06-24 12:48:41
categories: [Jenkins]
tags: [jenkins]
---

##### Jenkins环境准备
1. Jenkins安装，这个就不说了
2. Jenkins环境配置

	进入 系统管理-Global Tool Configuration
	配置JDK：建议放到用户可操作的目录下，如：/home/test/devtool/jdk1.8.0_91
	配置MVN：建议放到用户可操作的目录下，如：/home/test/devtool/apache-maven-3.3.9

  <!--more-->

```bash
test@test-devtesting-00001:~/devtool$ ll
total 8308
drwxrwxr-x  3 test test    4096 Jun 23 16:18 ./
drwx------ 18 test test    4096 Jun 24 12:43 ../
drwxrwxr-x  6 test test    4096 Jun  6 21:39 apache-maven-3.3.9/
lrwxrwxrwx  1 test test      25 Jun 23 16:18 jdk1.8.0_91/
```

##### 服务器环境准备
1. 首先需要把服务器加入到Jenkins的slave中，即配置Jenkins的从节点
2. 服务器环境配置：建议**配置完全同Jenkins中的环境配置**，包括JDK和MVN，不然会有很多让人头痛无法解决的问题

##### 服务器部署WEB实例
1. 在用户目录下新建两个目录，一个用来存放源代码，一个用来存放Web实例
```bash
test@test-devtesting-00001:~$ ll
total 144
drwx------ 18 test test  4096 Jun 24 12:43 ./
drwxr-xr-x  7 root root  4096 May 24 17:55 ../
drwxrwxr-x  3 test test  4096 Jun 23 16:18 devtool/						# 环境配置
drwxrwxr-x  3 test test  4096 Jun 23 16:04 jenkins/						# Jenkins工作目录
drwxr-xr-x 12 test test  4096 Jun 20 10:58 projects/					# 源代码目录
drwxrwxr-x 16 test test  4096 Jun 23 14:52 tomcats/						# Web实例目录
```
	在projects目录下，每个项目会有一个源代码的git目录；每个源代码的git目录会对应一个Web实例地址，即一个tomcat实例

2. 使用``git clone git-address``命令拉取源代码到``projects``目录下
3. 在``tomcats``目录下新建一个tomcat实例，命名为自己需要的名称，最好从名称就比较好辨识
4. 修改``tomcat``目录下的``conf``目录下的``server.xml``文件，修改本地和远程端口映射
```xml
<Server port="22221" shutdown="SHUTDOWN">
<!--该port也需要修改，不可重复-->
  <Listener className="org.apache.catalina.startup.VersionLoggerListener" />
...
...
    <Connector port="10021" protocol="HTTP/1.1"
    <!--这里的port对应服务器上的端口，不可重复，否知会引起冲突，无法部署成功-->
               connectionTimeout="20000"
               redirectPort="11121" URIEncoding="utf-8"
               <!--这里的redirectPort也需要修改，不可重复-->
               maxPostSize="0" maxHttpHeaderSize="81920"/>
```
	如果只是部署在本地，也需要确保端口不冲突
5. 编写部署的脚本``deploy.sh``，放到``tomcat``目录下
```bash
#!/bin/sh
set -m
#set var
dir_src="/home/test/projects/git-file"
dir_tomcat_home="/home/test/tomcats/test-tomcat"
file_war="ROOT.war"
file_catalina_out=$dir_tomcat_home"/logs/catalina.out"

echo "----update code from git begin"
cd $dir_src																				# 进入源代码目录
git checkout develop																	# checkout需要的分支
#git checkout master
git pull
echo "----update code from git end"

echo "----build project begin"
mvn clean install -U -DskipTests=true													# maven编译war包
echo "----build project end"

echo "----shutdown tomcat"
ps -ef | grep $dir_tomcat_home | awk '{ print $2 }' | xargs kill -9						# kill当前tomcat进程
sleep 1s

echo "----reset war file"
rm -r $dir_tomcat_home/webapps/ROOT
cp -r $dir_src/module-name/target/$file_war $dir_tomcat_home/webapps/ROOT.war			# 拷贝新的war包到$dir_tomcat_home/webapps目录下，并命名为ROOT.war

echo "----start tomcat "
cd $dir_tomcat_home
touch logs/catalina.out
sh bin/startup.sh &																		# 启动tomcat，并自动部署war包

echo "----show pid"
tail -f logs/catalina.out																# 实时日志输出
```
6. 部署服务
	进入``tomcat``目录下
	赋予脚本可执行权限
```bash
chmod a+x deploy.sh
```
	执行脚本
```bash
./deploy.sh
```

	至此，即可完成在服务器上的Web实例部署。

##### Jenkins集成Web实例部署
1. 新建一个``Jenkins``项目
	因为我们的Web项目是从maven进行编译的，所以在新建项目时，选择``构建一个maven项目``
2. ``Jenkins``项目配置
	勾选``参数化构建过程``
{% asset_img 参数化构建过程.png 参数化构建过程 %}
	指定服务器
{% asset_img 指定slave.png 指定slave %}
	配置源代码地址，设置分支变量获取
{% asset_img 配置git地址.png 配置git地址 %}
	配置项目构建名称``构建次数-分支名``
{% asset_img 设置项目构建名称.png 设置项目构建名称 %}
	Maven编译配置，有些git项目可能``pom.xml``文件并不在项目根目录下，需要手动指定，且是相对路径
{% asset_img maven编译配置.png maven编译配置 %}
	最后增加``Execute shell``，完成war包部署
{% asset_img 部署代码配置.png 部署代码配置 %}
```bash
#!/bin/bash
set -o errexit
set -o xtrace

export BUILD_ID=pleaseDontKillMe																		# 该项设置，可以避免Jenkins部署实例的时候，部署结束，进程就被kill

dir_tomcat_home="/home/test/tomcats/test-tomcat"														# 设置tomcat实例变量
file_war="ROOT.war"																						# 代码打出的war包名称，需要自己先手动打包一次知道名称后再指定
file_catalina_out=${dir_tomcat_home}"/logs/catalina.out"												# 设置实时日志输出目录变量

echo "----shutdown tomcat"

# ps -ef | grep ${dir_tomcat_home} | awk '{ print $2 }' | xargs kill -9
ps auxwww | grep java | grep ${dir_tomcat_home} | awk '{print $2}' | xargs kill -9 2>/dev/null;			# 获取并kill当前tomcat进程，如果当前进程存在的话
sleep 1s

echo "----reset war file"
rm -rf ${dir_tomcat_home}/webapps/ROOT;																	# 移除war包解压后的目录
rm -rf ${dir_tomcat_home}/webapps/ROOT.war;																# 移除前一次部署的war包
cp -r ${WORKSPACE}/module-name/target/$file_war ${dir_tomcat_home}/webapps/ROOT.war						# 拷贝新的war包到${dir_tomcat_home}/webapps目录下，并命名为ROOT.war

echo "----start tomcat"
sh ${dir_tomcat_home}/bin/startup.sh;																	# 启动tomcat，自动部署war包

#echo "----show pid"
#tail -f ${dir_tomcat_home}/logs/catalina.out
```
	BUID_ID是jenkins的一个特殊的运行时变量，之所以这么做，原因就是直接使用shell启动tomcat是不行的，因为jenkins进程退出后其创建的、包括其调用的脚本创建的进程都将被一起销毁
	至此``Jenkins``项目配置完成，保存即可。

	附带另一个部署脚本：
```bash
#!/bin/sh  
echo "Tomcat:$1"  
echo "Module:$2"  
echo "++++++++++++++++++++++++++++++++"  
pid=$(jps -v |grep $1 | grep -v 'grep $1' | awk '{print $1}')  
#if instance is running,shutdown it!  
if [ "$pid" ];then  
    echo "Current instance is running,pid:$pid"  
    echo "Shutdown now!"  
    cd $1/bin  
    ./shutdown.sh  
    sleep 3s  
fi  
#but somethimes,shutdown operation will be failure!  
#check status for 10 times  
i=0  
while [ $i -lt 10 ]  
do  
    pid=$(jps -v |grep $1 | grep -v 'grep $1' | awk '{print $1}')  
    if [ "$pid" ];then  
        sleep 1s  
        if [ $i -ge 10 ]  
        then  
            kill -9 $pid  
            break  
        else  
            ((i++))  
        fi  
    else  
        break  
    fi  
done  
#remove current application files  
cd $1/webapps  
rm -r -f ROOT  
rm -f ROOT.war  
cd $1/bin  
cd $WORKSPACE/$2/target  
cp ROOT.war $1/webapps  
cd $1/bin  
./startup.sh  
sleep 3s  
pid=$(jps -v |grep $1 | grep -v 'grep $1' | awk '{print $1}')  
echo "restart ok!"  
echo "pid:$pid"  
echo "++++++++++++++++++++++++++++++++"  
```
	脚本使用的脚本：
```bash
BUILD_ID=dontKillMe /home/deploy.sh "<tomcat_home>" "<module_name>"
```
	这个脚本，就是执行“关闭tomcat”、“删除文件”、“复制文件”、“重启tomcat”过程；脚本中可以引用jenkins的一些系统变量，比如“$WORKSPACE”表示当前build项目的工作空间；此脚本接收2个参数，我们约定，第一个参数表示“tomcat home路径”，第二个参数表示“项目module名称”用于告知需要部署那个web项目（这在多modules项目中有用）。

3. 执行构建
{% asset_img 分支构建.png 分支构建 %}













