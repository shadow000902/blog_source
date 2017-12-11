---
title: IOS打包命令
date: 2016-09-22 18:01:49
categories: [Tips]
tags: [IOS, 打包]
---

##### IOS构建方式
对IOS源码的构建方式主要有两种，最后的目标都是生成``.ipa``文件

- ``源码`` -> ``.archive文件`` -> ``.ipa文件``
- ``源码`` -> ``.app文件`` -> ``.ipa文件``

  <!--more-->

主要差异在于中间产物的不一样

	``源码`` -> ``.archive`` -> ``.ipa``
```bash
# build archive file from source code
xcodebuild \    # xctool
  -workspace ${WORKSPACE_PATH} \
  -scheme ${SCHEME} \
  -configuration ${CONFIGURATION} \
  -sdk ${SDK}
  -archivePath ${archive_path}
  archive
```

``archive``：对编译结果进行归档，会生成一个``.xcarchive``的文件，位于``-archivePath``指定的目录中。需要注意的是，对模拟器类型的``sdk``无法使用``archive``命令。

```bash
# export ipa file from .archive
xcodebuild -exportArchive \
  -exportFormat format \
  -archivePath xcarchivepath \
  -exportPath destinationpath \
  -exportProvisioningProfile profilename \
  [-exportSigningIdentity identityname]
  [-exportInstallerIdentity identityname]
```

	``源码`` -> ``.app`` -> ``.ipa``
```bash
# build .app file from source code
xcodebuild \    # xctool
  -workspace ${WORKSPACE_PATH} \
  -scheme ${SCHEME} \
  -configuration ${CONFIGURATION} \
  -sdk ${SDK} \
  -derivedDataPath ${OUTPUT_FOLDER} \
  clean build
```

```bash
# convert .app file to ipa file
xcrun \
  -sdk iphoneos \
  PackageApplication \
  -v ${OUTPUT_FOLDER}/Release-iphoneos/xxx.app \
  -o ${OUTPUT_FOLDER}/Release-iphoneos/xxx.ipa
```

##### 参数说明
- ``-workspace``：需要打包的workspace，后面接的文件一定要是``.xcworkspace``结尾的；
- ``-scheme``：需要打包的Scheme，一般与``$project_name``相同；
- ``-sdk``：区分iphone device和Simulator，可通过``xcodebuild -showsdks``获取，例如``iphoneos``和``iphonesimulator10.3.2``；
- ``-configuration``：需要打包的配置文件，我们一般在项目中添加多个配置，适合不同的环境，``Release/Debug``；
- ``-exportFormat``：导出的格式，通常填写为``ipa``；
- ``-archivePath``：``.xcarchive``文件的路径；
- ``-exportPath``：导出文件``.ipa``的路径；
- ``-exportProvisioningProfile``：``profile``文件证书；
- ``-derivedDataPath``：指定编译结果文件的存储路径；例如，指定``-derivedDataPath ${OUTPUT_FOLDER}``时，将在项目根目录下创建一个``${OUTPUT_FOLDER}``文件夹，生成的``.app``文件将位于``${OUTPUT_FOLDER}/Build/Products/${CONFIGURATION}-iphoneos``中。
- ``-v``：指定``.app``文件的路径；
- ``-o``：指定``.ipa``文件的路径

##### 获取打包必要信息
在填写``target``/``workspace``/``scheme``/``configuration``等参数时，如果不知道该怎么填写，可以在项目根目录下执行``xcodebuild -list``命令，它会列出当前项目的所有可选参数。
```bash
╭─taoyi at TaoYi-Mac in /opt/Jenkins/Home/workspace/Coding-iOS on 89d7084✘✘✘ using ‹› 17-08-18 - 1:08:10
╰─⠠⠵ xcodebuild -list
Information about project "Coding_iOS":
    Targets:
        Coding_iOS

    Build Configurations:
        Debug
        Release

    If no build configuration is specified and -scheme is not passed then "Release" is used.

    Schemes:
        Coding_iOS
```

##### 处理``Cocoapod``依赖库
另外一个需要注意的是，若项目是采用``Cocoapod``管理项目依赖，每次拉取最新代码后直接编译可能会报错。这往往是因为其他同事更新了依赖库（新增了第三方库或升级了某些库），而本地还采用之前的第三方库进行编译，从而会出现依赖库缺失或版本不匹配等问题。
应对的做法是，在每次``build``之前都更新一下``Cocoapod``。
```bash
# Update pod repository
pod repo update
# Install pod dependencies
pod install
```
