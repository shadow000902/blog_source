---
title: Linux常用命令
date: 2016-05-15 16:31:42
categories: [Linux]
tags: [linux]
---

1. mv

2. cp(copy)

3. ps(process status)

<!--more-->

4. kill

5. shutdown

6. swatch(simple watcher)

7. top

8. grep

9. unzip

10. tar(tape archive)

11. diff

12. git

13. cat

14. chmod(change mode)    # 更改文件／文件夹权限

15. chown(change owner)   # 更改文件／文件夹所有者

16. cd(change directory)  # 进入某目录

17. df(disk free)

18. dirs

19. du(disk usage)

20. ls(list)

21. mkdir(make directories)

22. rmdir(remove directory) －R

23. fdisk

24. telnet

25. ifconfig

26. tail
```
tail -f catalina.out | grep request      # 查看Linux服务器实时日志，catalina.out为服务器实时记录日志的文件
```
27. scp     # 本地文件传输到服务器
```
scp -P 22 /opt/appium1.5.3.zip username@IP:/opt/
```
28. sed     #
```
[root@www ~]# sed [-nefr] [动作]
选项与参数：
-n ：使用安静(silent)模式。在一般 sed 的用法中，所有来自 STDIN 的数据一般都会被列出到终端上。但如果加上 -n 参数后，则只有经过sed 特殊处理的那一行(或者动作)才会被列出来。
-e ：直接在命令列模式上进行 sed 的动作编辑；
-f ：直接将 sed 的动作写在一个文件内， -f filename 则可以运行 filename 内的 sed 动作；
-r ：sed 的动作支持的是延伸型正规表示法的语法。(默认是基础正规表示法语法)
-i ：直接修改读取的文件内容，而不是输出到终端。

动作说明： [n1[,n2]]function
n1, n2 ：不见得会存在，一般代表『选择进行动作的行数』，举例来说，如果我的动作是需要在 10 到 20 行之间进行的，则『 10,20[动作行为] 』

function：
a ：新增， a 的后面可以接字串，而这些字串会在新的一行出现(目前的下一行)～
c ：取代， c 的后面可以接字串，这些字串可以取代 n1,n2 之间的行！
d ：删除，因为是删除啊，所以 d 后面通常不接任何咚咚；
i ：插入， i 的后面可以接字串，而这些字串会在新的一行出现(目前的上一行)；
p ：列印，亦即将某个选择的数据印出。通常 p 会与参数 sed -n 一起运行～
s ：取代，可以直接进行取代的工作哩！通常这个 s 的动作可以搭配正规表示法！例如 1,20s/old/new/g 就是啦！
```
28.1 以行为单位删除
```
nl ~/test.txt | sed '2,5d'                         # 删除2～5行
nl ~/test.txt | sed '2d'                           # 删除第2行
nl ~/test.txt | sed '3,$d'                         # 删除3到最后一行
```
28.2 以行为单位新增
```
nl ~/test.txt | sed '2a drink tea'                 # 在第二行后即第三行加上“drink tea”
nl ~/test.txt | sed '2i drink tea'                 # 在第二行前即第二行加上“drink tea”
nl ~/test.txt | sed '2a drink tea or ......\'      # 在第二行后加上两行，每一行之间都必须要以反斜杠『 \ 』来进行新行的添加
```
28.3 以行为单位替换
```
nl ~/test.txt | sed '2,5c No 2-5 number'           # 将第2-5行的内容取代成为『No 2-5 number
nl ~/test.txt | sed -n '5,7p'                      # 列出 ~/test.txt 文件内的第 5-7 行
```
28.4 数据的搜索并显示
```
nl ~/test.txt | sed '/root/p'                      # 如果root找到，除了输出所有行，还会输出匹配行
nl ~/test.txt | sed -n '/root/p'                   # 只打印包含root的行
```
28.5 数据的搜索并删除
```
nl ~/test.txt | sed '/root/d'                      # 删除包含root的行，其他行输出
```
28.6 数据的搜索并执行命令
```
nl ~/test.txt | sed -n '/root/{s/bash/blueshell/;p}'       # 找到root对应的行，执行后面花括号中的一组命令，每个命令之间用分号分隔，这里把bash替换为blueshell，再输出这行
nl ~/test.txt | sed -n '/root/{s/bash/blueshell/;p;q}'     # 最后的q是退出
```
28.7 **数据的搜索并替换**
```
sed 's/要被取代的字串/新的字串/g'
```
28.8 多点编辑
```
nl ~/test.txt | sed -e '3,$d' -e 's/bash/blueshell/'       # -e表示多点编辑，一条sed命令，删除/etc/passwd第三行到末尾的数据，并把bash替换为blueshell
```
28.9 **直接修改文件内容**
``sed``可以直接修改文件的内容，不必使用管道命令或数据流重导向
```
sed -i 's/\.$/\!/g' test.txt                               # 将 test.txt 内每一行结尾若为 . 则换成 ! sed 的『 -i 』选项可以直接修改文件内容
sed -i '$a # This is a test' test.txt                      # 在 test.txt 最后一行加入『# This is a test』 $代表的是最后一行，而a的动作是新增
```
