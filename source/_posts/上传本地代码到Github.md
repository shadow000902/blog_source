---
title: 上传本地代码到Github
date: 2016-03-18 14:54:16
categories: [Tips]
tags: [github]
---

#### 准备工作
安装github for windows客户端

  <!--more-->

#### 上传代码
1. 在自己的github账户上创建一个新的仓库（repository）
2. 登录github for windows客户端，clone下来刚才创建的repository：
{% asset_img clone刚才创建的repository到本地.png clone刚才创建的repository到本地 %}
3. 复制本地完整代码到clone下来的repository文件夹中
4. github for windows客户端自动检测未上传的文件，勾选需要上传的文件，commit到master或者其他分支中
{% asset_img 上传代码.png 上传代码 %}
5. 点击客户端右上角的Sync按钮

至此，本地的代码就上传到了github上。
