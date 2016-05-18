---
title: git放弃本地修改直接拉取服务器更新
date: 2016-05-19 00:44:43
categories: [Git]
tags: [git]
---

``` git
git fetch --all
git reset --hard origin/master
```

OR If you are on some other branch

<!--more-->

``` git
git reset --hard origin/your_branch
```

The `--hard` option changes all the files in your working tree to match the files in `origin/master`

git fetch 只是下载远程的库的内容，不做任何的合并git reset
把HEAD指向刚刚下载的最新的版本


[参考链接](http://stackoverflow.com/questions/1125968/force-git-to-overwrite-local-files-on-pull)