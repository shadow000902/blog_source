---
title: git常用命令
date: 2016-05-26 01:09:12
categories: [TOOLS]
tags: [git]
---

#### 初始配置

``` bash
mkdir d:\git_test
git config -global user.name "Your name"
git config -global user.email "you@example.com"
```

<!--more-->

#### 使用

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

#### 创建分支

``` bash
git branch                      # 查看分支列表
git branch experiment           # 创建experiment分支
git checkout experiment         # 切换到experiment分支
git commit -a                   # 在分支上提交工作
git checkout master             # 切换到主干道
git merge experiment            # 合并分支到主干道
git branch -d experiment        # -d，表示“在分支已经合并到主干后删除分支”。如果使用大写的-D的话，则表示“不论如何都删除分支”
```

#### 撤销一次已经提交到Github的内容
```
git reset --hard HEAD~1
git push --force
```
该命令执行后，会隐藏掉Github库中的被撤销掉的记录，但是指定到该被隐藏掉的记录来访问，依旧可以访问。

#### GitHub更新自己fork的代码
1. ``clone``已经``fork``到自己账号的代码
```bash
git clone https://github.com/shadow000902/ApiTestEngine.git
cd ApiTestEngine
```
2. 查看远程分支列表
```bash
╭─taoyi at TaoYi-Mac in ~/git_projects/GitHub/ApiTestEngine on master✔ using ‹› 17-08-23 - 15:01:23
╰─○ git remote -v
debugtalk	https://github.com/debugtalk/ApiTestEngine.git (fetch)
debugtalk	https://github.com/debugtalk/ApiTestEngine.git (push)
origin	https://github.com/shadow000902/ApiTestEngine.git (fetch)
origin	https://github.com/shadow000902/ApiTestEngine.git (push)
```
3. ``fetch``原始源代码的新版本到本地
```bash
git fetch debugtalk
```
4. 合并两个版本的代码
```bash
git merge debugtalk/master
```
5. 如果合并代码后有冲突，解决冲突
6. 把合并好的最新的代码提交到自己的``GitHub``账号上
```bash
git push origin master
```

#### git撤销最后一次commit
1. 使用``git log``查看``commit``记录
```bash
commit-id1
commit-id2
commit-id3
```
如果想要撤销``commit-id1``的话，就要选择``commit-id2``

2. 使用命令撤销提交
```bash
git reset commit-id2				# 只是撤销提交，修改的内容不变
```

```bash
git reset --hard commit-id2			# 撤销提交，并撤销修改的内容
git push origin HARD --force		# 撤销后，强制提交并push到远程分支
```