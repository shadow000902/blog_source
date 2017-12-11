---
title: Mac下删除安装的pkg
date: 2017-08-06 13:10:45
categories: [Tips]
tags: [mac]
---

##### 使用``pkg_uninstaller``来卸载``pkg``安装的软件
1. 安装
```bash
cd ~
[sudo] bash < <(curl -sL https://raw.github.com/mpapis/pkg_uninstaller/master/pkg-install)
```

  <!--more-->

2. 加入到环境变量
```bash
echo 'PATH=$PATH:$HOME/.pkg_uninstaller' >> $HOME/.bash_profile
```

3. 列出包含某字符串的包名
```bash
pkg-list [name]
pkgutil --pkgs | grep -i [name]
```

4. 列出``pkg``软件的所有安装文件
```bash
pkg-util --files [pkg_name]
```
5. 卸载``pkg``软件
```bash
[sudo] pkg-uninstall [pkg_name]
```
	不论是手动还是使用命令全自动删除，最终你还得告诉系统你删了这个包
```bash
[sudo] pkgutil --forget [pkg_name]
```

##### 使用``pkg``管理软件来卸载
1. 下载地址
[破解版地址](https://pan.baidu.com/s/1hsxMhHM)
[官网地址](https://www.corecode.io/uninstallpkg/)
