---
title: git常用命令
date: 2016-05-26 01:09:12
categories: [Git]
tags: [git]
---

### 一、初始配置

``` bash
mkdir d:\git_test
git config -global user.name "Your name"
git config -global user.email "you@example.com"
```

<!--more-->

### 二、使用

``` bash
git init                        # 初始化当前所在目录的这个项目
git status                      # 查看项目状态
git add .                       # 给目前的项目制作一个快照snapshot（快照只是登记留名，快照不等于记录在案，git管快照叫做索引index）
git commit                      # 将快照里登记的内容永久写入git仓库
git commit -a                   # 直接提交所有修改，省去了``git add``和``git diff``和``git commit``的工序
                                # 无法把新增文件或文件夹加入进来，所以，如果你新增了文件或文件夹，那么就要老老实实的先``git add ..``，再``git commit``
git push                        # 把更新推送到远程分支
git log -p                      # git不但会给出开发日志，而且会显示每个开发版本的代码区别所在
```
总结：先``git add``修改过的文件，再``git diff``并``git status``查看确认，然后``git commit``提交，然后输入开发日志，然后``git push``推送到远程分支，最后``git log``再次确认。

### 三、创建分支

``` bash
git branch                      # 查看分支列表
git branch experiment           # 创建experiment分支
git checkout experiment         # 切换到experiment分支
git commit -a                   # 在分支上提交工作
git checkout master             # 切换到主干道
git merge experiment            # 合并分支到主干道
git branch -d experiment        # -d，表示“在分支已经合并到主干后删除分支”。如果使用大写的-D的话，则表示“不论如何都删除分支”
```

### 四、撤销一次已经提交到Github的内容
```
git reset --hard HEAD~1
git push --force
```
该命令执行后，会隐藏掉Github库中的被撤销掉的记录，但是指定到该被隐藏掉的记录来访问，依旧可以访问。
