---
title: web.py数据库操作介绍
date: 2017-01-11 20:35:36
categories: [Python]
tags: [web.py, 数据库]
---

#### 安装MySQL数据库

##### 本地数据库的安装[MySQL](http://dev.mysql.com/downloads/mysql/)
安装完后，会给出一个默认密码：

  <!--more-->

{% asset_img 初始化密码.png 初始化密码 %}

##### 启动本机上的MySQL
{% asset_img 启动MySQL-1.png 启动MySQL-1 %}
{% asset_img 启动MySQL-2.png 启动MySQL-2 %}
{% asset_img 启动MySQL-3.png 启动MySQL-3 %}

##### 修改MySQL默认密码

```bash
➜  ~ mysql -u root -p       
Enter password:         # 输入刚才安装后生成的密码
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 18
Server version: 5.7.17 MySQL Community Server (GPL)

Copyright (c) 2000, 2016, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SET PASSWORD = PASSWORD('123456');           # 重置密码
```
这样就把MySQL的登录密码设置成了``123456``

#### 安装Web.py及相关数据库操作模块

1. 安装``web.py``
```bash
easy_install web.py
```
2. 安装``MySQLdb``
```bash
easy_install MySQLdb
```
3. 安装``psycopg2``
```bash
easy_install psycopg2
```
4. 安装``DBUtils``，用于连接池``database pool``功能
```bash
easy_install DBUtiles
```

#### web.py操作数据库

##### 导入模块，定义数据库连接``db``
```bash
import web
db = web.database(dbn = 'mysql', db = 'mytable', user = 'root', pw = '123456')
# dbn 用于指定数据库类型
```

##### ``select``查询
```python
# 查询表
entries = db.select('mytable')

# where 条件
myvar = dict(name = "Bob")
results = db.select('mytable', myvar, where = "name = $name")
results = db.select('mytable', where = "id>100")

# 查询具体列
results = db.select('mytable', what = "id, name")

# order by
results = db.select('mytable', order = "post_date DESC")

# group
results = db.select('mytable', group = "color")

# limit
results = db.select('mytable', limit = 10)

# offset
results = db.select('mytable', offset = 10)
```

##### 插入
```python
db.insert('user', name = 'TY', age = 28, passwd = '123456', email = '526077432@qq.com')
# 插入利用了Python的**kw提供字段值，非常方便
```

##### 更新
```python
db.update('mytable', where = "id = 10", value1 = "foo")
db.update('user', where = 'id = $id', vars = {'id' : 100}, name = 'TY001', age = 29)
# update也充分利用了Python的**kw参数，只有传入的**kw才被update，其他字段保持不变。
# where和vars负责where语句的生成和绑定参数
```

##### 删除
```python
db.delete('mytable', where = "id = 10")
db.delete('user', where = 'id = $id', vars = {'id':100})
```

##### 复杂查询
```python
# count
results = db.query("SELECT COUNT(*) AS total_users FROM users")
print results[0].total_users

# join
results = db.query("SELECT * FROM entries JOIN users WHERE entries.author_id = users.id")

# 防止SQL注入
results = db.query("SELECT * FROM entries WHERE id = $id", vars = {'id':10})
```

##### 多数据库操作（web.py大于0.3）
```python
db1 = web.database(dbn = 'mysql', db = 'dbname1', user = 'foo')
db2 = web.database(dbn = 'mysql', db = 'dbname2', user = 'foo')

print db1.select('foo', where = 'id = 1')
print db2.select('bar', where = 'id = 5')
```

##### 事务
```python
t = db.transaction()
try:
    db.insert('person', name = 'foo')
    db.insert('person', name = 'bar')
except:
    t.rollback()
    raise
else:
    t.commit()

# Python 2.5+ 可以用with
from __future__ import with_statement
with db.transaction():
    db.insert('person', name = 'foo')
    db.insert('person', name = 'bar')
```

和Java比，web.py的db操作非常简单，这主要得益于python的**kw参数和内建的dict支持（对应Java的Map）。
