---
title: Extent测试报告使用
date: 2017-01-18 00:13:28
categories: [测试报告]
tags: [测试报告]
---

### 一、安装MongoDB数据库
1. 下载[MongoDB](https://fastdl.mongodb.org/osx/mongodb-osx-x86_64-3.4.1.tgz)
2. 安装``MongoDB``
```bash
tar -zxvf mongodb-osx-x86_64-3.4.1.tgz
mv mongodb-osx-x86_64-3.4.1 /opt/mongodb-3.4.1/
```

<!--more-->

3. 把``MongoDB``加入环境变量
```bash
vim ~/.bash_profile
```
```bash
export PATH=/opt/mongodb-3.4.1/bin:$PATH
```
4. 创建``MongoDB``数据库存放数据的目录
```bash
mkdir /data/mongodb
```
5. 启动``MongoDB``数据库，并把目录指向指定的目录
```bash
mongod --dbpath /data/mongodb/
```
默认方式启动``MongoDB``的话，目录会默认指向``/data/db/``目录
```bash
mongod          # 默认方式启动
```
6. 启动成功的日志
```bash
➜  ~ mongod --dbpath /data/mongodb/
2017-01-22T00:25:23.191+0800 I CONTROL  [initandlisten] MongoDB starting : pid=2411 port=27017 dbpath=/data/mongodb/ 64-bit host=TaoYi-Mac.local
2017-01-22T00:25:23.192+0800 I CONTROL  [initandlisten] db version v3.4.1
2017-01-22T00:25:23.192+0800 I CONTROL  [initandlisten] git version: 5e103c4f5583e2566a45d740225dc250baacfbd7
2017-01-22T00:25:23.192+0800 I CONTROL  [initandlisten] allocator: system
2017-01-22T00:25:23.192+0800 I CONTROL  [initandlisten] modules: none
2017-01-22T00:25:23.192+0800 I CONTROL  [initandlisten] build environment:
2017-01-22T00:25:23.192+0800 I CONTROL  [initandlisten]     distarch: x86_64
2017-01-22T00:25:23.192+0800 I CONTROL  [initandlisten]     target_arch: x86_64
2017-01-22T00:25:23.192+0800 I CONTROL  [initandlisten] options: { storage: { dbPath: "/data/mongodb/" } }
2017-01-22T00:25:23.192+0800 W -        [initandlisten] Detected unclean shutdown - /data/mongodb/mongod.lock is not empty.
2017-01-22T00:25:23.193+0800 I -        [initandlisten] Detected data files in /data/mongodb/ created by the 'wiredTiger' storage engine, so setting the active storage engine to 'wiredTiger'.
2017-01-22T00:25:23.193+0800 W STORAGE  [initandlisten] Recovering data from the last clean checkpoint.
2017-01-22T00:25:23.194+0800 I STORAGE  [initandlisten] wiredtiger_open config: create,cache_size=3584M,session_max=20000,eviction=(threads_max=4),config_base=false,statistics=(fast),log=(enabled=true,archive=true,path=journal,compressor=snappy),file_manager=(close_idle_time=100000),checkpoint=(wait=60,log_size=2GB),statistics_log=(wait=0),
2017-01-22T00:25:24.136+0800 I CONTROL  [initandlisten] 
2017-01-22T00:25:24.136+0800 I CONTROL  [initandlisten] ** WARNING: Access control is not enabled for the database.
2017-01-22T00:25:24.136+0800 I CONTROL  [initandlisten] **          Read and write access to data and configuration is unrestricted.
2017-01-22T00:25:24.136+0800 I CONTROL  [initandlisten] 
2017-01-22T00:25:24.136+0800 I CONTROL  [initandlisten] 
2017-01-22T00:25:24.136+0800 I CONTROL  [initandlisten] ** WARNING: soft rlimits too low. Number of files is 256, should be at least 1000
2017-01-22T00:25:24.310+0800 I FTDC     [initandlisten] Initializing full-time diagnostic data capture with directory '/data/mongodb/diagnostic.data'
2017-01-22T00:25:24.311+0800 I NETWORK  [thread1] waiting for connections on port 27017
2017-01-22T00:25:25.022+0800 I FTDC     [ftdc] Unclean full-time diagnostic data capture shutdown detected, found interim file, some metrics may have been lost. OK
```

### 二、安装ExtentX服务
1. 下载``ExtentX``代码
```bash
git clone https://github.com/anshooarora/extentx.git
```
2. 启动``ExtentX``服务
```bash
cd extentx
node app.js
```
3. 启动成功的日志
```bash
➜  extentx git:(master) node app.js 
info: 
info:                .-..-.
info: 
info:    Sails              <|    .-..-.
info:    v0.12.4             |\
info:                       /|.\
info:                      / || \
info:                    ,'  |'  \
info:                 .-'.-==|/_--'
info:                 `--'-------' 
info:    __---___--___---___--___---___--___
info:  ____---___--___---___--___---___--___-__
info: 
info: Server lifted in `/Users/taoyi/git_projects/ExtentX`
info: To see your app, visit http://localhost:1337
info: To shut down Sails, press <CTRL> + C at any time.

debug: -------------------------------------------------------
debug: :: Sun Jan 22 2017 00:27:28 GMT+0800 (CST)

debug: Environment : development
debug: Port        : 1337
debug: -------------------------------------------------------
```
启动``ExtentX``服务时，可能会报一些错，是因为少一些依赖的包，使用``npm install 错误提示的包名``安装好需要的依赖，之后就可以正常启动了
4. ``ExtentX``服务默认的用户名和密码
```bash
user:       root
password:   password
```

### 三、测试框架集成extent测试报告框架
1. ``pom.xml``文件中增加依赖
```xml
<dependency>
    <groupId>com.relevantcodes</groupId>
    <artifactId>extentreports</artifactId>
    <version>2.41.2</version>
</dependency>
```
2. ``testng.xml``文件中修改``listeners``
```xml
    <listeners>
        <!-- extent报告 -->
        <listener class-name="com.souche.dfcAppium.plugins.extentReporter.ExtentTestNGITestListener" />
    </listeners>
```
3. 加载报告插件
![](http://o6lw1c1bf.bkt.clouddn.com/报告插件存放位置.png)
