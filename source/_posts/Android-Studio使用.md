---
title: Android-Studio使用
date: 2016-03-13 00:19:58
categories: [Android]
tags: [android-studio, robotium]
---

#### 离线升级Android-Studio

##### 脚本

``` bash
java -classpath 离线安装包位置完整路径 com.intellij.updater.Runner install android-studio安装位置
```

  <!--more-->

##### 示例

``` bash
C:\Users\shadow>java -classpath C:\QMDownload\AI-141.2456560-143.2609919-patch-win.jar  com.intellij.updater.Runner install C:\android-studio
```

#### Gradle sync failed：
Unable to load class 'org.codehaus.groovy.runtime.typehandling.ShortTypeHandling'.
         Consult IDE log for more details (Help | Show Log)
##### 修改build.gradle
``` bash
dependencies {classpath 'com.android.tools.build:gradle:1.2.+'}
```
##### 修改gradle-wrapper.properties
``` bash
distributionUrl=https://services.gradle.org/distributions/gradle-2.3-all.zip
```

#### android studio项目添加robotium测试框架支持
##### robotium-solo-5.4.1.jar文件复制到libs文件夹下

##### 在build.gradle文件中添加：
``` bash
androidTestCompile fileTree(dir: 'libs', include: 'robotium-solo-5.4.1.jar')
```
##### 右键robotium-solo-5.4.1.jar，**“add to library”**
