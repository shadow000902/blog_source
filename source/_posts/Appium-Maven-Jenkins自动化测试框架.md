---
title: Appium-Maven-Jenkins自动化测试框架
date: 2016-09-19 14:07:38
categories: [Appium]
tags: [Appium, Maven, Jenkins]
---

#### 前置条件
1. ``JDK``安装
2. ``Appium``安装［``node``安装，``npm``安装］
3. ``Maven``安装
4. ``Jenkins slave``设置
5. ``Android SDK``安装

  <!--more-->

#### 环境可用的情况
1. ``adb -devices``命令可用
2. ``appium --session-override``服务可用
3. ``mvn package``编译可用

#### 框架介绍
框架主要以``appium``测试框架为基础，用maven进行依赖的管理，以及编译执行测试。
##### 框架目录结构
{% asset_img 目录结构.png 目录结构 %}
```
├── data                                                                    # 项目测试数据存放位置
│   ├── login.xls
│   └── workbench.xls
├── default.xml
├── grid
│   ├── 1.Start_Android_Emulator.sh
│   ├── 2.Start_Appium_Grid_Server.sh
│   ├── 3.Start_Appium_Server_001.sh
│   ├── 4.Start_Appium_Server_002.sh
│   ├── nodeconfig_1.json
│   ├── nodeconfig_2.json
│   └── selenium-server-standalone.jar
├── pom.xml                                                                 # maven项目文件
├── README.md
├── res                                                                     # 项目测试app存放位置
│   ├── app
│   │   ├── android
│   │   │   └── android.txt
│   │   └── ios
│   │       └── ios.txt
│   └── properties
│       ├── app.properties
│       └── config.properties
├── runAll.xml                                                              # testng执行入口
├── runSingle.xml
├── runSmoke.xml
├── testngForParallel.xml
└── src
    ├── main
    │   └── java
    │       └── com
    │           └── shadow
    │               └── dfcAppium
    │                   └── App.java
    └── test
        └── java
            └── com
                └── shadow
                    └── dfcAppium
                        ├── base                                            # 项目基础类
                        │   ├── BasePrepare.java
                        │   ├── StartAppium.java
                        │   └── StopAppium.java
                        ├── pages                                           # 页面元素类
                        │   ├── InitPage.java
                        │   ├── LoginPage.java
                        │   ├── StockmanagePage.java
                        │   └── WorkbenchPage.java
                        ├── pageshelper                                     # 页面元素帮助类
                        │   ├── InitPageHelper.java
                        │   ├── LoginPageHelper.java
                        │   ├── StockmanagePageHelper.java
                        │   └── WorkbenchPageHelper.java
                        ├── plugins                                         # 报告插件
                        │   ├── excelReporter                               # excel报告插件
                        │   │   ├── ExcelReporter.java
                        │   │   ├── TestResultListener.java
                        │   │   └── utils
                        │   │       └── CreateExcelForResult.java
                        │   └── htmlReporter                                # html报告插件
                        │       ├── PowerEmailableReporter.java
                        │       ├── RetryListener.java
                        │       ├── TestngRetry.java
                        │       ├── TestResultListener.java
                        │       └── utils
                        │           └── ConfigReader.java
                        ├── testcases                                       # 测试用例存放位置
                        │   ├── login
                        │   │   └── LoginPage_001_Login_Test.java
                        │   └── workbench
                        │       └── WorkbenchPage_001_Workbench_Test.java
                        └── utils                                           # 各种工具类
                            ├── AppiumUtil.java
                            ├── ExcelDataProvider.java
                            ├── LogConfiguration.java
                            ├── PropertiesDataProvider.java
                            └── SelectDriver.java
```
##### 框架运行介绍
``testcases``下的测试用例都是继承至``BasePrepare.java``类，这个类的主要作用是启动和关闭APP，以及数据提供。

举``Login``的例子，介绍框架中用例的运行原理：
1）``LoginPage_001_Login_Test``继承至``BasePrepare``类，启动app，后续步骤中``BasePrepare``作为数据提供者提供数据，步骤中，调用帮助类从页面元素类中获取元素，进行``输入／点击``等操作，帮助类又会调用``AppiumUtil``的``API``进行操作并输出实时的操作日志。
大致结构如下图所示：
{% asset_img 用例运行结构.png 用例运行结构 %}
最后``testng``文件调用``excel``插件生成``excel``报告。

#### 持续集成
##### 前置条件
    [代码仓库地址](http://git.souche.com/testGroup/dfcAppium.git)
    ``Jenkins``上配置好安卓测试环境，包括本地配置的所有环境。
由于大风车有``Native Library``，导致无法在``X86``的模拟器上安装，而且``arm``的模拟器奇慢，所以选择在安卓真机上执行测试。在执行测试前要确保指定的设备与运行持续集成的服务器通讯正常。
##### 持续集成结果展示：
{% asset_img Excel测试报告.png Excel测试报告 %}

#### 备注：appium源码安装
##### 安装cnpm
```
npm install -g cnpm --registry=https://registry.npm.taobao.org
```
##### 下载源代码
```
git clone https://github.com/appium/appium.git
```
##### 编译安装
```
cd appium               # 进入appium源码目录
cnpm install            # 执行安装
```
##### 用``cnpm link``命令将``appium link``到系统，可以忽略``warn``
```
cnpm link
```
##### 查看安装结果
```
appium -v

➜  appium git:(master) appium -v
1.6.0-beta3
```
