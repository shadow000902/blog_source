---
title: Mac切换Terminal为zsh
date: 2017-05-18 17:17:39
categories: [Tips]
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
vim ~/.zshrc
```

```bash
...
export ZSH=~/.oh-my-zsh/
...
ZSH_THEME="ys"                   # 设置选择的主题。默认是robbyrussell
...
...
source $ZSH/oh-my-zsh.sh
source ~/.bash_profile
...
```

##### 优化 terminal 样式
{% asset_img 终端样式修改.png 终端样式修改 %}

##### 切换 Terminal 到 zsh
```bash
chsh -s /bin/zsh
```
重启一下 Terminal 之后，就生效了。

##### 效果如图
{% asset_img Terminal效果图.png Terminal效果图 %}

##### 如果使用 fino-time 主题
如果使用该主题的话，会遇到一个错误：
```bash
zsh: command not found: rvm-prompt
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-05-18 - 20:44:28
╰─○ 
```
每次一条命令前都会有这条报错。
主要原因就是该主题依赖于``rvm-prompt``，这样的话，就需要安装上该组件。
安装步骤：
```bash
brew install gnupg gnupg2
```

```bash
gpg --keyserver hkp://keys.gnupg.net --recv-keys 409B6B1796C275462A1703113804BB82D39DC0E3
\curl -sSL https://get.rvm.io | bash -s stable
```
在``~/.zshrc``文件中加入支持：
```bash
alias rvm-prompt=$HOME/.rvm/bin/rvm-prompt
```
这样后，就完美了，不会再有这个报错了。

##### 安装第三方插件
1. 安装``zsh-syntax-highlighting``插件
```bash
cd ~/.oh-my-zsh/
git clone git://github.com/zsh-users/zsh-syntax-highlighting.git
```
然后编辑环境变量文件``~/.zshrc``，在其中加入插件名称
```bash
# plugins=(git)
plugin=(git zsh-syntax-highlighting)
```