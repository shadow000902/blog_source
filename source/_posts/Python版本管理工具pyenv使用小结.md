---
title: Python版本管理工具pyenv使用小结
date: 2018-04-10 20:31:28
categories: [Python]
tags: [pyenv]
---

##### 安装``brew``
```bash
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

  <!--more-->

##### 安装``pyenv``
```bash
brew install pyenv
```

##### 把``pyenv``加入环境变量
如果使用的终端是``bash``，则编辑``~/.bashrc``，如果使用的终端是``zsh``，则编辑``~/.zshrc``，在该文件的最开头加入语句：
```bash
eval "$(pyenv init -)"
```

##### ``pyenv``常用基本命令
```bash
pyenv install --list                            # List all available versions
pyenv install <version>                         # install python
pyenv global <version>                          # 全局设置python版本为指定版本
pyenv global 2.7.14 3.6.4                       # 指定多个python版本为全局版本，有顺序
pyenv local <version>                           # 设置当前路径下python版本为指定版本
pyenv shell <version>                           # 设置当前shell窗口使用的python版本为指定版本
pyenv versions                                  # 列举所有版本的python，打``*``的为当前指定的全局版本
pyenv version                                   # 列举已经安装的版本
```