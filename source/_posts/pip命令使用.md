---
title: pip命令使用
date: 2016-08-08 16:38:38
categories: [Tools]
tags: [pip]
---

1. 安装``mitmproxy``
```bash
sudo -H pip install mitmproxy --upgrade --ignore-installed six
```

  <!--more-->

由于``six-1.4.1``无法被卸载，也无法被更新，所以在安装需要更新six的软件时，就会一直报错。
解决办法就是安装软件的时候，忽略``six-1.4.1``，也就是``--ignore-installed six``

2. 列出已经安装的第三方库
  ```bash
  pip list --format=columns
  ```

3. 设置默认的``pip list``显示方式
在``~/.pip/pip.conf``配置文件中，修改默认的``list``访问方式。
添加一个配置项：
  ```bash
  [list]
  format=columns
  ```

4. 修改``pip``镜像源
  ```bash
  [global]
  index-url = http://pypi.douban.com/simple

  [install]
  trusted-host=pypi.douban.com
  ```