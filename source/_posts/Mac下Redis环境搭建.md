---
title: Mac下Redis环境搭建
date: 2017-06-18 18:08:44
categories: [Tools]
tags: [redis]
---

##### 下载安装包
下载稳定版本的安装包[redis-stable](http://download.redis.io/redis-stable.tar.gz)

##### 安装Redis
```bash
tar -xvf redis-stable.tar.gz
cp ./redis-stable /opt/
cd /opt/redis-stable
sudo make test
sudo make install
```

  <!--more-->


##### 配置Redis
1. 创建需要的目录
```bash
mkdir bin
mkdir etc
mkdir db
```
2. 拷贝安装好的``redis``文件到创建的``bin``目录下
```bash
cp /usr/bin/redis-* /opt/redis-stable/bin/
```
	结果``/opt/redis-stable/bin/``目录下的内容如下
```bash
╭─taoyi at TaoYi-Mac in /opt/redis-stable/bin using ‹› 17-06-18 - 18:06:48
╰─○ ll
total 6648
-rwxr-xr-x  1 taoyi  staff    98K  6 18 18:06 redis-benchmark
-rwxr-xr-x  1 taoyi  staff    14K  6 18 18:06 redis-check-aof
-rwxr-xr-x  1 taoyi  staff   1.0M  6 18 18:06 redis-check-rdb
-rwxr-xr-x  1 taoyi  staff   159K  6 18 18:06 redis-cli
-rwxr-xr-x  1 taoyi  staff   1.0M  6 18 18:06 redis-sentinel
-rwxr-xr-x  1 taoyi  staff   1.0M  6 18 18:06 redis-server
```

3. 拷贝安装目录``src``目录下的``mkreleasehdr.sh``到安装目录下
```bash
cp /opt/redis-stable/src/mkreleasehdr.sh /opt/redis-stable/
```

4. 拷贝安装目录下的``redis.conf``到创建的``etc``目录下
```bash
cp /opt/redis-stable/redis.conf /opt/redis-stable/etc/
```

5. 修改``redis.conf``
```bash
#修改为守护模式
daemonize yes
#设置进程锁文件
pidfile /opt/redis-stable/redis.pid
#端口
port 6379
#客户端超时时间
timeout 300
#日志级别
loglevel debug
#日志文件位置
logfile /opt/redis-stable/log-redis.log
#设置数据库的数量，默认数据库为0，可以使用SELECT <dbid>命令在连接上指定数据库id
databases 8
##指定在多长时间内，有多少次更新操作，就将数据同步到数据文件，可以多个条件配合
#save <seconds> <changes>
#Redis默认配置文件中提供了三个条件：
save 900 1
save 300 10
save 60 10000
#指定存储至本地数据库时是否压缩数据，默认为yes，Redis采用LZF压缩，如果为了节省CPU时间，
#可以关闭该#选项，但会导致数据库文件变的巨大
rdbcompression yes
#指定本地数据库文件名
dbfilename dump.rdb
#指定本地数据库路径
dir /opt/redis-stable/db/
#指定是否在每次更新操作后进行日志记录，Redis在默认情况下是异步的把数据写入磁盘，如果不开启，可能
#会在断电时导致一段时间内的数据丢失。因为 redis本身同步数据文件是按上面save条件来同步的，所以有
#的数据会在一段时间内只存在于内存中
appendonly no
#指定更新日志条件，共有3个可选值：
#no：表示等操作系统进行数据缓存同步到磁盘（快）
#always：表示每次更新操作后手动调用fsync()将数据写到磁盘（慢，安全）
#everysec：表示每秒同步一次（折衷，默认值）
appendfsync everysec
```

8. 修改``redis``目录的所有者
```bash
chown -R taoyi /opt/redis-stable
```

##### 启动Redis服务
```bash
./opt/redis-stable/bin/redis-server ./opt/redis-stable/etc/redis.conf
```

##### 访问Redis服务
```bash
./opt/redis-stable/bin/redis-cli
```