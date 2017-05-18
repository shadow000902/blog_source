---
title: Mac切换Terminal为zsh
date: 2017-05-18 17:17:39
categories: [Terminal]
tags: [terminal]
---

##### 下载一个 .oh-my-zsh 配置
```bash
git clone git://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh
```

<!--more-->

##### 创建新的配置
```bash
cp ~/.zshrc ~/.zshrc.orig                                   # 如果已经有一个 .zshrc 文件，备份一下
cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc
```

##### 更新新的配置文件
如果有些环境变量配置在``~/.bash_profile``的话，需要在新的配置里进行刷新
```bash
...
export ZSH=~/.oh-my-zsh/
...
...
source $ZSH/oh-my-zsh.sh
source ~/.bash_profile
...
```

##### 优化 terminal 样式
![](http://o6lw1c1bf.bkt.clouddn.com/终端样式修改.png)

##### 切换 Terminal 到 zsh
```bash
chsh -s /bin/zsh
```
重启一下 Terminal 之后，就生效了。
