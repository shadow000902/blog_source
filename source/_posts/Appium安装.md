---
title: Appium安装
date: 2016-03-31 18:19:45
categories: [Appium]
tags: [appium]
---

### 一、命令行正常安装Appium
1. 安装node.js
2. 使用node.js安装Appium

<!--more-->

```
npm install -g appium                                           # -g 全局参数
或者
npm --registry http://registry.cnpmjs.org install -g appium     # 推荐这种,npm的国内镜像
```
3. 修改Appium安装源方法
```
npm config get registry                                         # 查看当前npm的镜像源地址
npm congif set registry=https://registry.npm.taobao.org/        # 替换npm源为淘宝的npm镜像源
npm config get registry                                         # 查看镜像源是否替换成功
```

### 二、异常安装Appium方法
1. 下载[Appium客户端](http://appium.io/)
2. 安装Appium客户端到电脑，查看目录如图：
{% asset_img Appium安装目录结构.png Appium安装目录结构 %}
3. 完整解压其中的node_modules.7z文件，如图所示：
{% asset_img node_modules目录结构.png node_modules目录结构 %}
4. 在node_modules/.bin文件夹中就有可以在CMD中运行的appium批处理文件：
{% asset_img Appium运行批处理文件.png Appium运行批处理文件 %}
5. 在sdk、jdk、python、环境变量设置好的情况下，CMD进入node_modules/.bin下，就可以直接命令行运行appium：
{% asset_img Appium正常运行.png Appium正常运行 %}

### 三、源码安装
1. 下载源代码
2. 编译运行

### 四、安装指定版本的appium
```
npm install -g appium@1.4.16
```
该方法应对ubuntu系统无法安装上appium@1.5.3的问题，问题原因未知

### 五、Appium应用所附加需要的
1. JDK
2. SDK
3. python
4. selenium
```
pip install selenium -i http://pypi.douban.com/simple       # 使用国内地址
```
5. Appium-Python-Client
```
pip install Appium-Python-Client
```
