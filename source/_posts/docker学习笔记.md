---
title: docker学习笔记
date: 2016-12-08 10:16:51
categories: [Docker]
tags: [docker]
---
1. 无法删除docker镜像时，处理方法
有依赖该image的container，先删除container再删除image
```
docker ps -a | grep "Exited" | awk '{print $1 }'|xargs docker stop
docker ps -a | grep "Exited" | awk '{print $1 }'|xargs docker rm
docker images|grep none|awk '{print $3 }'|xargs docker rmi
```
这样清空掉残余的容器后，再删除images就没有异常的提示了。

2. 安装``docker&boot2docker``
```
brew install boot2docker
```

3. ``Docker images``存放位置
``Docker for Mac``版本，所有的docker images 保存在下面这个文件里：
```
/Users/{YourUserName}/Library/Containers/com.docker.docker/Data/com.docker.driver.amd64-linux/Docker.qcow2
```
到目前为止，还是没有办法指定``images``和``Container``的保存路径，你只能任由``docker``吃掉你的主盘。
