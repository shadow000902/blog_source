---
title: Maven常用命令介绍
date: 2016-09-18 15:03:14
categories: [Tools]
tags: [maven]
---

1. ``mvn clean``
清除产生的项目
2. ``mvn compile``
编译源代码,生成对应的CLASS文件
3. ``mvn package``
打包,生成JAR文件，只能本程序用，或者拷贝到其它项目使用
  <!--more-->


4. ``mvn install -Dmaven.test.skip=ture``
给任何目标添加maven.test.skip 属性就能跳过测试
5. ``mvn test``
运行测试,生成对应的CLASS文件
6. ``mvn site``
生成项目相关信息的网站
7. ``mvn site-deploy``
生成项目相关信息的网站并部署
8. ``mvn install``
打包,生成JAR文件，并在本地仓库生成JAR和POM文件，供其它Maven项目共享
9. ``mvn help:effective-pom``
看这个“有效的 (effective)”POM，它暴露了 Maven的默认设置
10. ``mvn dependency:analyze`` 或 ``mvn dependency:tree``

11.
