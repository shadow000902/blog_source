---
title: MAC下微信备份文件管理
date: 2018-02-21 12:59:56
categories: [Tips]
tags: [微信]
---

#### 备份文件位置
{% asset_img 备份与恢复.png 备份与恢复 %}

  <!--more-->

默认情况下，手机端聊天记录在备份后，备份记录会被储存在如下目录：
```bash
/Users/taoyi/Library/Containers/com.tencent.xinWeChat/Data/Library/Application\ Support/com.tencent.xinWeChat/2.0b4.0.9/Backup/
```
后面首先会是一个随机目录，比如：``98042dacf91c160514728c899d359b0c``，这个算是备份文件的主目录。
然后是第二级的一个随机目录，比如：``1F28B05B-D186-483D-AC39-23F54CC80811``，这里面就存放着备份文件，目录如下：
```bash
-rw-r--r--@ 1 taoyi  staff   177M  2 21 12:42 BAK_0_MEDIA
-rw-r--r--@ 1 taoyi  staff   5.0M  2 21 12:41 BAK_0_TEXT
-rw-r--r--@ 1 taoyi  staff   804K  2 21 12:42 Backup.db
```
微信备份只有这一份数据，还原也只能从这一份数据还原。

#### 同一微信账号，多个备份管理
比如首先我们备份了一个比较重要的人的聊天记录出来，这时就可以把这一份备份记录剪切出来，放起来，然后这样直接在恢复里就看不到。
如果需要恢复，可以通过把这一份备份文件重新放回``Backup``目录中对应的位置，然后就又可以在备份文件管理里找到了，这样就可以单独恢复一个人的聊天记录。

#### 不同微信账号
猜想不同微信账号，会在``Backup``目录下多一个随机目录，用来区分不同微信账号的备份记录。