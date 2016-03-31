---
title: Appium安装
date: 2016-03-31 18:19:45
categories: [Appium]
tags: [appium]
---

1. 下载[Appium客户端](http://appium.io/)
2. 安装Appium客户端到电脑，查看目录如图：

<!--more-->

{% asset_img Appium安装目录结构.png Appium安装目录结构 %}
3. 完整解压其中的node_modules.7z文件，如图所示：
{% asset_img node_modules目录结构.png node_modules目录结构 %}
4. 在node_modules/.bin文件夹中就有可以在CMD中运行的appium批处理文件：
{% asset_img Appium运行批处理文件.png Appium运行批处理文件 %}
5. 在sdk、jdk、python、环境变量设置好的情况下，CMD进入node_modules/.bin下，就可以直接命令行运行appium：
{% asset_img Appium正常运行.png Appium正常运行 %}