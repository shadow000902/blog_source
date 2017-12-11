---
title: 反编译工具介绍
date: 2016-10-25 11:41:32
categories: [Tools]
tags: [aapt, apktool]
---


#### 官方网站
[Apktool](https://ibotpeaches.github.io/Apktool/)

#### aapt
##### ``Androidmanifest.xml``文件解析
```
./aapt dump xmltree  /Users/taoyi/Downloads/de4aa7e390346478bd6a54549d27787b.apk AndroidManifest.xml
```

  <!--more-->

##### ``apk`` 包信息获取
```
./aapt dump badging /Users/taoyi/Downloads/fengche.apk
```
##### 搜索当前目录下所有文件中包含``XXX``的语句和所在文件
```
grep -R "百度贴吧" .
```
##### 解压 ``apk``
```
unzip /Users/taoyi/Downloads/fengche.apk
```



#### Apktool
##### 使用教程（ MAC 下）
1). 下载[脚本](https://raw.githubusercontent.com/iBotPeaches/Apktool/master/scripts/osx/apktool)，保存到 apktool 文件
2). 下载[apktool_x.jar](https://bitbucket.org/iBotPeaches/apktool/downloads)，目前最新的为2.2.1版本，重命名为 ``apktool.jar``
3). 将两个文件移动到``/usr/local/bin``目录下
4). 给两个文件赋予可执行权限
    ```
    sudo chmod a+x apktool
    sudo chmod a+x apktool.jar
    ```
5). 执行反编译命令
    ```
    apktool d XXX.apk
    ```

    ```
    ➜  ./apktool d XXX.apk
    I: Using Apktool 2.2.1 on XXX.apk
    I: Loading resource table...
    I: Decoding AndroidManifest.xml with resources...
    I: Loading resource table from file: /Users/taoyi/Library/apktool/framework/1.apk
    I: Regular manifest package...
    I: Decoding file-resources...
    I: Decoding values */* XMLs...
    I: Baksmaling classes.dex...
    I: Copying assets and libs...
    I: Copying unknown files...
    I: Copying original files...
    ```
6). 重新编译回 apk
    ```
    apktool b XXX
    ```

    ```
    ➜  ./apktool b XXX
    I: Using Apktool 2.2.1
    I: Checking whether sources has changed...
    I: Smaling smali folder into classes.dex...
    I: Checking whether resources has changed...
    I: Building resources...
    I: Copying libs... (/lib)
    I: Building apk file...
    I: Copying unknown files/dir...
    ```

##### 反编译失败解决方法
1). 删除 ``/Users/your user/Library/apktool/framework/1.apk``
2). 导出手机 ``/system/framework/framework-res.apk`` 放入上面目录
3). 重新反编译
