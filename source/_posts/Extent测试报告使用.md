---
title: Extent测试报告使用
date: 2017-01-18 00:13:28
categories: [Tools]
tags: [测试报告]
---

#### 安装MongoDB数据库
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
    ...
```

#### 安装ExtentX服务
##### 下载``ExtentX``代码
```bash
git clone https://github.com/anshooarora/extentx.git
```
##### 启动``ExtentX``服务
```bash
cd extentx
node app.js
```
##### 启动成功的日志
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
info:                 --'-------'
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
##### ``ExtentX``服务默认的用户名和密码
```bash
user:       root
password:   password
```

#### 测试框架集成extent测试报告框架
##### ``pom.xml``文件中增加依赖
```xml
<dependency>
    <groupId>com.relevantcodes</groupId>
    <artifactId>extentreports</artifactId>
    <version>2.41.2</version>
</dependency>
```
##### ``testng.xml``文件中修改``listeners``
```xml
    <listeners>
        <!-- extent报告 -->
        <listener class-name="com.souche.dfcAppium.plugins.extentReporter.ExtentTestNGITestListener" />
    </listeners>
```
##### 加载报告插件
{% asset_img 报告插件存放位置.png 报告插件存放位置 %}
