---
title: Mac上MySQL的简单使用
date: 2017-06-03 17:20:13
categories: [Database]
tags: [mysql]
---

1. 启动、停止、重启MySQL服务
```mysql
sudo /usr/local/MySQL/support-files/mysql.server start
sudo /usr/local/mysql/support-files/mysql.server stop
sudo /usr/local/mysql/support-files/mysql.server restart
```

  <!--more-->

2. 登录MySQL数据库
```mysql
mysql -h 地址 -P 端口 -u 用户名 -p 密码
```

3. 查看数据库
```mysql
show databases;
```

4. 查看当前库的所有表
```mysql
show tables;
```

5. 字符匹配查询
```mysql
select * from database where Attributes like "%SQL%";								# 查询 Attributes 中包含 SQL 字符的数据
select * from database where Attributes like "a%b";									# 查询 Attributes 中以 a 开头以 b 结尾的字符串数据
select * from database where Attributes like "m_n";									# 查询 Attributes 中以 m 开头以 n 结尾的3个字符的数据，中间 _ 只能代表一个字符
```

6. 多条件查询
```mysql
select * from database where Attributes1=a and Attributes2 like "My_SQL";
select * from database where Attributes1=a or Attributes2 like "My_SQL";
```

7. 去除结果中的重复行
```mysql
select distinct Attributes from database;
```

8. 对查询结果进行排序
```mysql
select * from database orderby id desc;												# 倒叙排列
select * from database orderby id asc;												# 正序排列
```

9. 分组查询
```mysql
select name,id from database GROUP BY id;
select name,id from database GROUP BY name,id;										# 当id字段的值相等时，再按照name字段分组
```

10. 限制查询结果的数量
```mysql
select * from database orderby id asc limit 2,3;									# 取两条数据，正序，从第三条开始
select * from database orderby id desc limit 2,3;									# 取两条数据，倒序，从倒数第三条结束，只显示倒数前两条
```