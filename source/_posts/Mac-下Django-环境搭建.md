---
title: Mac 下Django 环境搭建
date: 2016-11-03 17:02:10
categories: [Django]
tags: [django, python, postgresql]
---

1. 安装``Homebrew``
```
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```
2. 安装``PostgreSQL``
```
brew install postgresql -v
```

<!--more-->

2.1 初始化数据库
```
initdb /usr/local/var/postgres -E utf8
```
2.2 设成开机启动``PostgreSQL``
```
ln -sfv /usr/local/opt/postgresql/*.plist ~/Library/LaunchAgents
launchctl load ~/Library/LaunchAgents/homebrew.mxcl.postgresql.plist
```
2.3 启动``PostgreSQL``
```
pg_ctl -D /usr/local/var/postgres -l /usr/local/var/postgres/server.log start
```
2.4 关闭``PostgreSQL``
```
pg_ctl -D /usr/local/var/postgres stop -s -m fast
```
2.5 创建一个``PostgreSQL``用户
```
createuser username -P
#Enter password for new role:
#Enter it again:
```
2.6 创建数据库
```
createdb dbname -O username -E UTF8 -e
```
2.7 连接数据库
```
psql -U username -d dbname -h 127.0.0.1
```
2.8 ``PostgreSQL``数据库操作

显示已创建的数据库：
```
\l  
```
在不连接进 PostgreSQL 数据库的情况下，也可以在终端上查看显示已创建的列表：
```
psql -l
```
连接数据库
```
\c dbname
```
显示数据库表
```
\d  
```
创建一个名为 test 的表
```
CREATE TABLE test(id int, text VARCHAR(50));
```
插入一条记录
```
INSERT INTO test(id, text) VALUES(1, 'sdfsfsfsdfsdfdf');
```
查询记录

1
SELECT * FROM test WHERE id = 1;
更新记录
```
UPDATE test SET text = 'aaaaaaaaaaaaa' WHERE id = 1;
```
删除指定的记录
```
DELETE FROM test WHERE id = 1;
```
删除表
```
DROP TABLE test;
```
删除数据库
```
DROP DATABASE dbname;
```
或者利用 dropdb 指令，在终端上删除数据库
```
dropdb -U user dbname
```

3. 安装``virtualenv``
```
pip install virtualenv
virtualenv myenv
cd myenv
. bin/activate
```

4. 安装``Django``
```
pip install django
export CFLAGS=-Qunused-arguments
export CPPFLAGS=-Qunused-arguments
sudo pip install psycopg2                   # 安装 psycopg2 前需要执行上面两条 export 命令
pip install djangorestframework
```

5. 启动服务
```
cd AndroidTools
python ./manage.py runserver 0.0.0.0:9999
```
