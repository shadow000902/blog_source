---
title: docker学习笔记
date: 2016-12-08 10:16:51
categories: [Tools]
tags: [docker]
---
##### 安装docker
官网下载 Docker for Mac

##### 无法删除docker镜像时，处理方法
有依赖该image的container，先删除container再删除image
```bash
docker ps -a | grep "Exited" | awk '{print $1 }'|xargs docker stop
docker ps -a | grep "Exited" | awk '{print $1 }'|xargs docker rm
docker images|grep none|awk '{print $3 }'|xargs docker rmi
```
这样清空掉残余的容器后，再删除images就没有异常的提示了。

  <!--more-->

##### 安装``docker&boot2docker``
```
brew install boot2docker
```

##### ``Docker images``存放位置
``Docker for Mac``版本，所有的docker images 保存在下面这个文件里：
```bash
/Users/{YourUserName}/Library/Containers/com.docker.docker/Data/com.docker.driver.amd64-linux/Docker.qcow2
```
到目前为止，还是没有办法指定``images``和``Container``的保存路径，你只能任由``docker``吃掉你的主盘。

##### docker镜像的常用操作
1. 获取镜像
```bash
docker pull <域名>/<namespace>/<repo>:<tag>
```
```bash
docker pull redis											# 不指定别的信息，默认从官方库下载latest标签的内容
```
	返回结果：
```bash
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 12:25:35
╰─○ docker pull redis
Using default tag: latest
latest: Pulling from library/redis
f5cc0ee7a6f6: Pull complete 														# f5cc0ee7a6f6是redis镜像的层ID，一个镜像由多层组成
5fc25ed18e87: Pull complete 
e025bc8872f6: Pull complete 
0d8edb7c8bd1: Pull complete 
654cb9d60232: Pull complete 
44888ef53075: Pull complete 														# redis镜像一共有6层
Digest: sha256:4e2af5470298aa3c79fba07216f0245fff5278b66f40681cf448eabca0bb966b
Status: Downloaded newer image for redis:latest
```

2. 查看镜像列表
```bash
docker images
```
	返回结果：
```bash
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 12:27:31
╰─○ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
jenkins             latest              0b4d4d677a26        2 days ago          681 MB
redis               latest              4e482b286430        2 days ago          99 MB
```
	查看镜像的详细信息：
```bash
docker inspect redis
```
	返回结果：
```bash
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 12:32:43
╰─○ docker inspect redis
[
    {
        "Id": "sha256:4e482b286430fc5abed4cd26965ef200c59b727739919489d9ba42d5c361576c",
        "RepoTags": [
            "redis:latest"
        ],
        "RepoDigests": [
            "redis@sha256:4e2af5470298aa3c79fba07216f0245fff5278b66f40681cf448eabca0bb966b"
        ],
        "Parent": "",
        "Comment": "",
        "Created": "2017-06-23T05:48:12.360604857Z",
        "Container": "8192875e4177261796f2e1ade286f9ace2f2ec3cd0a306737c8b2df840c255bc",
        "ContainerConfig": {
            "Hostname": "40a0c0f8b2f7",
            "Domainname": "",
            "User": "",
            "AttachStdin": false,
            "AttachStdout": false,
            "AttachStderr": false,
            "ExposedPorts": {
                "6379/tcp": {}
            },
            "Tty": false,
            "OpenStdin": false,
            "StdinOnce": false,
            "Env": [
                "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
                "GOSU_VERSION=1.10",
                "REDIS_VERSION=3.2.9",
                "REDIS_DOWNLOAD_URL=http://download.redis.io/releases/redis-3.2.9.tar.gz",
                "REDIS_DOWNLOAD_SHA=6eaacfa983b287e440d0839ead20c2231749d5d6b78bbe0e0ffa3a890c59ff26"
            ],
            "Cmd": [
                "/bin/sh",
                "-c",
                "#(nop) ",
                "CMD [\"redis-server\"]"
            ],
            "ArgsEscaped": true,
            "Image": "sha256:d5b0d131d2b9f60cf036f54e27c97de3cbda19979b6ef039061df7b11e80b9cc",
            "Volumes": {
                "/data": {}
            },
            "WorkingDir": "/data",
            "Entrypoint": [
                "docker-entrypoint.sh"
            ],
            "OnBuild": [],
            "Labels": {}
        },
        "DockerVersion": "17.03.1-ce",
        "Author": "",
        "Config": {
            "Hostname": "40a0c0f8b2f7",
            "Domainname": "",
            "User": "",
            "AttachStdin": false,
            "AttachStdout": false,
            "AttachStderr": false,
            "ExposedPorts": {
                "6379/tcp": {}
            },
            "Tty": false,
            "OpenStdin": false,
            "StdinOnce": false,
            "Env": [
                "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
                "GOSU_VERSION=1.10",
                "REDIS_VERSION=3.2.9",
                "REDIS_DOWNLOAD_URL=http://download.redis.io/releases/redis-3.2.9.tar.gz",
                "REDIS_DOWNLOAD_SHA=6eaacfa983b287e440d0839ead20c2231749d5d6b78bbe0e0ffa3a890c59ff26"
            ],
            "Cmd": [
                "redis-server"
            ],
            "ArgsEscaped": true,
            "Image": "sha256:d5b0d131d2b9f60cf036f54e27c97de3cbda19979b6ef039061df7b11e80b9cc",
            "Volumes": {
                "/data": {}
            },
            "WorkingDir": "/data",
            "Entrypoint": [
                "docker-entrypoint.sh"
            ],
            "OnBuild": [],
            "Labels": {}
        },
        "Architecture": "amd64",
        "Os": "linux",
        "Size": 98969736,
        "VirtualSize": 98969736,
        "GraphDriver": {
            "Name": "overlay2",
            "Data": {
                "LowerDir": "/var/lib/docker/overlay2/2a988e8e8467a83cc2e5947dd7ee8edea6718aa01bcee44825baa2fe726dbab1/diff:/var/lib/docker/overlay2/bba45f5b1aa9fcb7d72bc8c8746ba1819c970815f3a852f978b5becbfcbcad5d/diff:/var/lib/docker/overlay2/82c9bcce7485cbd0cc5e6d9b2081451d34d6e93a8035835e66d48c30ad32acb8/diff:/var/lib/docker/overlay2/e5239d20d683ebfde2f855673710b82d06b3c1088b3c16bd6fce9226786f241d/diff:/var/lib/docker/overlay2/102a35bfaa68de0e2d04b05accf398ad8b0625ec65f054284d47dd6f4df14642/diff",
                "MergedDir": "/var/lib/docker/overlay2/2eda23f85ac044336950781a1f20811346c4bf22032b3ebcc7f9e1a95cb3f1b8/merged",
                "UpperDir": "/var/lib/docker/overlay2/2eda23f85ac044336950781a1f20811346c4bf22032b3ebcc7f9e1a95cb3f1b8/diff",
                "WorkDir": "/var/lib/docker/overlay2/2eda23f85ac044336950781a1f20811346c4bf22032b3ebcc7f9e1a95cb3f1b8/work"
            }
        },
        "RootFS": {
            "Type": "layers",
            "Layers": [
                "sha256:d08535b0996bcfbc19d5cc21f01813115dda20e6fdf43bd29e19a8038bc76cf6",
                "sha256:74072b982a3d85ef4ab02792808db47aec546d972c8cbc564b835c3fc27b1c11",
                "sha256:13964fab05984c7879450d90ce4efa53d19acd19033c80d00a3cc1aee8bef2cf",
                "sha256:6f223f268efe8c0be9e665b65016c3a0f6dd8c1a3a03c40117f3e1ef4e7928ab",
                "sha256:d9fe002e0a416f0c6f231a853a9c8a7bedd2dacf8d0c7190be0ff78691e76d12",
                "sha256:23e630c4c6552a4d166ba35b2b89e3560e7c3822df556238f89106873f46d6d3"
            ]
        }
    }
]
```
	查看镜像的制作操作系统：
```bash
docker inspect -f {{.Os}} 4e482b286430
docker inspect -f {{.Os}} 4e482							# 以前几位可区分的标识也可以获取到信息

```
	返回结果：
```bash
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 12:34:23
╰─○ docker inspect -f {{.Os}} 4e482b286430
linux
```

3. 查找镜像
```bash
docker search redis
```
	返回结果：
```bash
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 12:36:55
╰─○ docker search redis
NAME                      DESCRIPTION                                     STARS     OFFICIAL   AUTOMATED
redis                     Redis is an open source key-value store th...   3889      [OK]       
sameersbn/redis                                                           54                   [OK]
bitnami/redis             Bitnami Redis Docker Image                      50                   [OK]
torusware/speedus-redis   Always updated official Redis docker image...   32                   [OK]
webhippie/redis           Docker images for redis                         7                    [OK]
anapsix/redis             11MB Redis server image over AlpineLinux        6                    [OK]
williamyeh/redis          Redis image for Docker                          3                    [OK]
clue/redis-benchmark      A minimal docker image to ease running the...   3                    [OK]
unblibraries/redis        Leverages phusion/baseimage to deploy a ba...   2                    [OK]
abzcoding/tomcat-redis    a tomcat container with redis as session m...   2                    [OK]
frodenas/redis            A Docker Image for Redis                        1                    [OK]
greytip/redis             redis 3.0.3                                     1                    [OK]
xataz/redis               Light redis image                               1                    [OK]
miko2u/redis              Redis                                           1                    [OK]
nanobox/redis             Redis service for nanobox.io                    0                    [OK]
yfix/redis                Yfix docker redis                               0                    [OK]
cloudposse/redis          Standalone redis service                        0                    [OK]
continuouspipe/redis      Redis                                           0                    [OK]
appelgriebsch/redis       Configurable redis container based on Alpi...   0                    [OK]
maestrano/redis           Redis is an open source key-value store th...   0                    [OK]
trelllis/redis            Redis Primary                                   0                    [OK]
drupaldocker/redis        Redis for Drupal                                0                    [OK]
higebu/redis-commander    Redis Commander Docker image. https://gith...   0                    [OK]
watsco/redis              Watsco redis base                               0                    [OK]
maxird/redis              Redis                                           0                    [OK]
```

4. 删除镜像
```bash
docker rmi <image>:<tag>
```
	一个镜像有多个tag时，删除tag并不会影响镜像的存在
	镜像有对应容器存在时，也无法正常删除，需要先停止并删除对应的容器，然后才能正常删除镜像
	也可以强制删除镜像，``docker rmi -f <image>:<tag>``，但不建议这么操作，容易造成一些异常

5. 创建镜像
创建镜像的方法有三种：基于已有镜像的容器创建、基于本地模板的导入、基于Dockerfile创建。
基于已有镜像的容器创建：
```bash
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 12:40:17
╰─○ docker ps
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 12:44:55
╰─○ docker ps -a
CONTAINER ID        IMAGE               COMMAND                  CREATED             STATUS                      PORTS               NAMES
eed91a25662b        jenkins             "/bin/tini -- /usr..."   16 hours ago        Exited (130) 16 hours ago                       myJenkins
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 12:57:23
╰─○ docker commit -a "author" -m " " eed91a25662b shadow/testjenkins
sha256:7fdb1ba1c4a59310c61907c574567502fb2b4c9faad6d3fa1cde7ac24a1d7974
```

6. 迁出镜像
```bash
docker save -o <image>.tar <image>:<tag>						# 其中的image可以为标签或ID
```
```bash
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 12:57:45
╰─○ docker images
REPOSITORY           TAG                 IMAGE ID            CREATED             SIZE
shadow/testjenkins   latest              7fdb1ba1c4a5        3 minutes ago       681 MB
jenkins              latest              0b4d4d677a26        2 days ago          681 MB
redis                latest              4e482b286430        2 days ago          99 MB
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 13:01:35
╰─○ docker save -o testjenkins.tar 7fdb1ba1c4a5
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 13:02:41
╰─○ ll
-rw-------   1 taoyi  staff   664M  6 26 13:02 testjenkins.tar					# 镜像被迁出到了当前目录
```

7. 载入镜像
```bash
docker load --input <image>.tar
docker load
```
```bash
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 13:04:54
╰─○ docker images
REPOSITORY           TAG                 IMAGE ID            CREATED             SIZE
shadow/testjenkins   latest              7fdb1ba1c4a5        10 minutes ago      681 MB
jenkins              latest              0b4d4d677a26        2 days ago          681 MB
redis                latest              4e482b286430        2 days ago          99 MB
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 13:08:01
╰─○ docker rmi 7fdb1ba1c4a5
Untagged: shadow/testjenkins:latest
Deleted: sha256:7fdb1ba1c4a59310c61907c574567502fb2b4c9faad6d3fa1cde7ac24a1d7974
Deleted: sha256:ffe123eea6f84d7dc5626bffd1930b23d898ee65d0eb371d2a57da0abdfd5c87
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 13:08:15
╰─○ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
jenkins             latest              0b4d4d677a26        2 days ago          681 MB
redis               latest              4e482b286430        2 days ago          99 MB
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 13:08:24
╰─○ docker load --input testjenkins.tar
57ee77a34bd9: Loading layer [==================================================>]  2.56 kB/2.56 kB
Loaded image ID: sha256:7fdb1ba1c4a59310c61907c574567502fb2b4c9faad6d3fa1cde7ac24a1d7974
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 13:08:54
╰─○ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
<none>              <none>              7fdb1ba1c4a5        11 minutes ago      681 MB
jenkins             latest              0b4d4d677a26        2 days ago          681 MB
redis               latest              4e482b286430        2 days ago          99 MB
```
```bash
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 13:09:05
╰─○ docker tag 7fdb1ba1c4a5 "test0jenkins"											# 给容器命名
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 13:13:50
╰─○ docker images                         
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
test0jenkins        latest              7fdb1ba1c4a5        16 minutes ago      681 MB
jenkins             latest              0b4d4d677a26        2 days ago          681 MB
redis               latest              4e482b286430        2 days ago          99 MB
```

8. 上传镜像
```bash
docker push <域名>/<namespace>/<repo>:<tag>
```
	默认上传到DockerHub官方仓库。
	登录Docker：
```bash
╭─taoyi at TaoYi-Mac in ~ using ‹› 17-06-26 - 13:17:59
╰─○ docker login
Login with your Docker ID to push and pull images from Docker Hub. If you don't have a Docker ID, head over to https://hub.docker.com to create one.
Username: shadow000902
Password: 
Login Succeeded
```