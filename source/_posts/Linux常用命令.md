---
title: Linux常用命令
date: 2016-05-15 16:31:42
categories: [Linux]
tags: [linux]
---

1. mv
1.1 Moving files
```bash
mv test0001.txt /opt/
```
1.2 Moving multiple files
```bash
mv test0001.txt test0002.txt /opt/
mv *.txt /opt/
```
1.3 Moving directory
```bash
mv /tmp/test0001 /opt/
```

  <!--more-->

1.4 Renaming files or directory
```bash
mv test0001.txt test0002.txt
```
1.5 Renaming directory
```bash
mv test0001 test0002
```
1.6 Print what happen
```bash
mv -v *.txt /opt/
```
1.7 Using interactive mode
```bash
mv -i *.txt /opt/
```
1.8 Using update option
```bash
mv -uv *.txt /opt/
```
1.9 Do not overwrite any existing file
```bash
mv -vn *.txt /opt/
```
1.10 Create backup when copying
```bash
mv -bv *.txt /opt/
```
[10 Practical mv Command Examples](https://linoxide.com/linux-command/mv-command-linux/)



2. cp(copy)
```bash
cp -r /opt/android/tools /opt/      # -r 复制文件夹
```

3. ps(process status)
```bash
ps -ef | grep tomcat
```

4. kill

5. shutdown

6. swatch(simple watcher)

7. top

8. grep
8.1 在文件中查找单词
```bash
grep shadow /etc/hosts
```
8.2 在多个文件中查找单词
```bash
grep shadow /etc/hosts /etc/hosts1
```
8.3 列出包含指定单词的文件的文件名
```bash
grep -l shadow /etc/hosts /etc/hosts1 /etc/hosts2 /etc/hosts3
```
8.4 在文件中查找指定单词并显示匹配行的行号
```bash
grep -n shadow /etc/hosts /etc/hosts1
```
8.5 输出不包含指定单词的行
```bash
grep -v shadow /etc/hosts
```
8.6 输出所有以指定单词开头的行
```bash
grep ^ shadow /etc/hosts
```
8.7 输出所有以指定单词结尾的行
```bash
grep shadow$ /etc/hosts
```
8.8 参数递归地查找指定单词
```bash
grep -r shadow /etc/hosts
```
8.9 查找文件中所有的空行
```bash
grep ^$ /etc/hosts
```
8.10 同时查找多个单词
```bash
grep -e shadow -e shadows /etc/hosts
```
8.11 计算匹配到的单词的数量
```bash
grep -c -f shadow /etc/hosts
```
8.12
```bash
grep -irn "SyncWriteStream" ./node_modules/hexo-deployer-git/
```

9. unzip

10. tar(tape archive)

11. diff

12. git

13. cat
```bash
一次显示整个文件:cat filename
从键盘创建一个文件:cat > filename 只能创建新文件,不能编辑已有文件.
将几个文件合并为一个文件:cat file1 file2 > file
```
13.1 *合并文件*
```bash
cat *.csv > all-in-one.csv														# 合并多个CSV文件，不考虑顺序
cat file1.csv file2.csv file3.csv ... file[n].csv > all-in-one.csv				# 合并多个CSV文件，考虑顺序
```

14. chmod(change mode)    # 更改文件／文件夹权限

15. chown(change owner)   # 更改文件／文件夹所有者

16. cd(change directory)  # 进入某目录

17. df(disk free)

18. dirs

19. du(disk usage)
```bash
du -d 1 -h          # 命令查看当前目录下所有文件夹的大小 -d 指深度，后面加一个数值
```



20. ls(list)

21. mkdir(make directories)

22. rm
```bash
rm -f 					# 直接删除文件，无需确认
rm -r 					# 删除文件夹，需要确认
rm -rf 					# 直接删除目录及其中的全部文件，无需确认
```

23. fdisk

24. telnet

25. ifconfig

26. tail
```bash
tail -f catalina.out | grep request      # 查看Linux服务器实时日志，catalina.out为服务器实时记录日志的文件
```
27. scp     # 本地文件与服务器文件交互
```bash
# 从服务器下载文件
scp username@servername:/remote_path/filename ~/local_destination
# 上传本地文件到服务器
scp ~/local_path/local_filename username@servername:/remote_path
# 从服务器下载整个目录
scp -r username@servername:/remote_path/remote_dir/ ~/local_destination
# 上传目录到服务器
scp  -r ~/local_dir username@servername:/remote_path/remote_dir
```

28. sed     #
```markdown
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
```bash
nl ~/test.txt | sed '2,5d'                         # 删除2～5行
nl ~/test.txt | sed '2d'                           # 删除第2行
nl ~/test.txt | sed '3,$d'                         # 删除3到最后一行
```
28.2 以行为单位新增
```bash
nl ~/test.txt | sed '2a drink tea'                 # 在第二行后即第三行加上“drink tea”
nl ~/test.txt | sed '2i drink tea'                 # 在第二行前即第二行加上“drink tea”
nl ~/test.txt | sed '2a drink tea or ......\'      # 在第二行后加上两行，每一行之间都必须要以反斜杠『 \ 』来进行新行的添加
```
28.3 以行为单位替换
```bash
nl ~/test.txt | sed '2,5c No 2-5 number'           # 将第2-5行的内容取代成为『No 2-5 number
nl ~/test.txt | sed -n '5,7p'                      # 列出 ~/test.txt 文件内的第 5-7 行
```
28.4 数据的搜索并显示
```bash
nl ~/test.txt | sed '/root/p'                      # 如果root找到，除了输出所有行，还会输出匹配行
nl ~/test.txt | sed -n '/root/p'                   # 只打印包含root的行
```
28.5 数据的搜索并删除
```bash
nl ~/test.txt | sed '/root/d'                      # 删除包含root的行，其他行输出
```
28.6 数据的搜索并执行命令
```bash
nl ~/test.txt | sed -n '/root/{s/bash/blueshell/;p}'       # 找到root对应的行，执行后面花括号中的一组命令，每个命令之间用分号分隔，这里把bash替换为blueshell，再输出这行
nl ~/test.txt | sed -n '/root/{s/bash/blueshell/;p;q}'     # 最后的q是退出
```
28.7 **数据的搜索并替换**
```bash
sed 's/要被取代的字串/新的字串/g'
```
28.8 多点编辑
```bash
nl ~/test.txt | sed -e '3,$d' -e 's/bash/blueshell/'       # -e表示多点编辑，一条sed命令，删除/etc/passwd第三行到末尾的数据，并把bash替换为blueshell
```
28.9 **直接修改文件内容**
``sed``可以直接修改文件的内容，不必使用管道命令或数据流重导向
```bash
sed -i 's/\.$/\!/g' test.txt                               # 将 test.txt 内每一行结尾若为 . 则换成 ! sed 的『 -i 』选项可以直接修改文件内容
# 如果 -i 参数不生效的话，需要使用 -ig 参数
sed -ig's/要被取代的字串/新的字串/g' test.txt
sed -i '$a # This is a test' test.txt                      # 在 test.txt 最后一行加入『# This is a test』 $代表的是最后一行，而a的动作是新增
```
29. touch           # 创建文件（夹）命令

29.1 使用文件名作为参数，可以同时创建多个文件。当目标文件已经存在时，将更新该文件的时间标记，否则将创建指定名称的空文件。
```bash
touch file1 file2
```
29.2 创建新的目录
```bash
[root@localhost home]# mkdir dir1
[root@localhost home]# mkdir dir2/dir
mkdir: 无法创建目录"dir2/dir": 没有那个文件或目录
[root@localhost home]# mkdir -p dir2/dir                    # -p 确保目录名称存在，不存在的就建一个
[root@localhost home]#
```
29.3 同时创建多级目录
```bash
[root@localhost home]# ls
justin lost+found t
[root@localhost home]# mkdir -p {dir1,dir2/{dir3,dir4}}
[root@localhost home]# ls
dir1 dir2 justin lost+found t
[root@localhost home]# ls dir2
dir3 dir4
[root@localhost home]#
```

30. rmdir            # 删除文件（夹）命令
```bash
[root@localhost home]# mkdir -p {dir1,dir2/dir3}            # -p 当子目录被删除后也成为空目录的话，则顺便一并删除
[root@localhost home]# ls
dir1 dir2 justin lost+found t
[root@localhost home]# rmdir dir1
[root@localhost home]# rmdir dir2
rmdir: 删除 "dir2"失败: 目录非空
[root@localhost home]# rmdir -p dir2/dir3/
[root@localhost home]# ls
justin lost+found t
[root@localhost home]#
```

31. 更改文件（夹）权限
31.1 更改所有者权限
```bash
sudo chmod 600 ××× #（只有所有者有读和写的权限）
sudo chmod 644 ××× #（所有者有读和写的权限，组用户只有读的权限）
sudo chmod 700 ××× #（只有所有者有读和写以及执行的权限）
sudo chmod 666 ××× #（每个人都有读和写的权限）
sudo chmod 777 ××× #（每个人都有读和写以及执行的权限）
```
```markdown
sudo chmod -（代表类型）[×××（所有者）×××（组用户）×××（其他用户）]           # xxx为一个二进制组合
```
其中×××指文件名（也可以是文件夹名，不过要在chmod后加-ld）。
三位数的每一位都表示一个用户类型的权限设置。取值是0～7，即二进制的[000]~[111]。
这个三位的二进制数的每一位分别表示读、写、执行权限。
如000表示三项权限均无，而100表示只读。这样，我们就有了下面的对应：
```bash
0 [000] 无任何权限
4 [100] 只读权限
6 [110] 读写权限
7 [111] 读写执行权限
```
31.2 更改文件（夹）权限
```bash
chmod [-cfvR] [--help] [--version] mode file...
mode : 权限设定字串, 格式如下 : [ugoa...][[+-=][rwxX]...][,...]
```
```markdown
u 表示该档案的拥有者，
g 表示与该档案的拥有者属于同一个群体(group)者，
o 表示其他以外的人，
a 表示这三者皆是。 
+ 表示增加权限、- 表示取消权限、= 表示唯一设定权限。 
r 表示可读取，w 表示可写入，x 表示可执行，X 表示只有当该档案是个子目录或者该档案已经被设定过为可执行。 
-c : 若该档案权限确实已经更改，才显示其更改动作 
-f : 若该档案权限无法被更改也不要显示错误讯息 
-v : 显示权限变更的详细资料 
-R : 对目前目录下的所有档案与子目录进行相同的权限变更(即以递回的方式逐个变更) 
--help : 显示辅助说明 
--version : 显示版本 
```
31.3 文件（夹）的权限
```markdown
-rw------- (600) -- 只有属主有读写权限。 
-rw-r--r-- (644) -- 只有属主有读写权限；而属组用户和其他用户只有读权限。 
-rwx------ (700) -- 只有属主有读、写、执行权限。 
-rwxr-xr-x (755) -- 属主有读、写、执行权限；而属组用户和其他用户只有读、执行权限。 
-rwx--x--x (711) -- 属主有读、写、执行权限；而属组用户和其他用户只有执行权限。 
-rw-rw-rw- (666) -- 所有用户都有文件读、写权限。这种做法不可取。 
-rwxrwxrwx (777) -- 所有用户都有读、写、执行权限。更不可取的做法。 
```
以下是对目录的两个普通设定: 
```markdown
drwx------ (700) - 只有属主可在目录中读、写。 
drwxr-xr-x (755) - 所有用户可读该目录，但只有属主才能改变目录中的内容。
```

32. 查看目录剩余空间大小
32.1 df -hl             # 查看磁盘剩余空间
```bash
文件系统       容量    已用   可用                      已用%          挂载点
Filesystem   Size   Used  Avail Capacity iused      ifree %iused  Mounted on
/dev/disk1  112Gi   91Gi   21Gi    82% 1900939 4293066340    0%   /
```
32.2 
```bash
df -h              # 命令查看整个硬盘的大小 ，-h表示人可读的
du -sh [目录名]     # 返回该目录的大小
du -sm [文件夹]     # 返回该文件夹总M数
df --help          # 查看更多功能
du --help          # 查看更多功能
```
32.3
```bash
du -sh xmldb/
du -sm * | sort -n      # 统计当前目录大小并按大小排序
du -sk * | grep taoyi   # 查看一个人的大小
du -m | cut "/" -f 2    # 查看第二个/字符前的文字
wc [-lmw]               # -l: 多少行；-m: 多少字符；-w: 多少字
```
32.4 查看当前目录下各文件夹的大小
```bash
du -h --max-depth=1
```
``--max-depth=n``表示深入到第``n``层目录，此处设置为``1``，即表示深入``1``层，即查看当前目录下各个文件夹的大小；如果设置为``0``，表示不深入到子目录，那得出的就是当前目录的总大小。

32.5 du命令参数
```bash
du [-abcDhHklmsSx] [-L <符号连接>][-X <文件>][--block-size][--exclude=<目录或文件>] [--max-depth=<目录层数>][--help][--version][目录或文件]
```
- ``-a或-all``：为每个指定文件显示磁盘使用情况，或者为目录中每个文件显示各自磁盘使用情况。
- ``-b或-bytes``：显示目录或文件大小时，以byte为单位。
- ``-c或–total``：除了显示目录或文件的大小外，同时也显示所有目录或文件的总和。
- ``-D或–dereference-args``：显示指定符号连接的源文件大小。
- ``-h或–human-readable``：以K，M，G为单位，提高信息的可读性。
- ``-H或–si``：与-h参数相同，但是K，M，G是以1000为换算单位,而不是以1024为换算单位。
- ``-k或–kilobytes``：以1024 bytes为单位。
- ``-l或–count-links``：重复计算硬件连接的文件。
- ``-L<符号连接>或–dereference<符号连接>``：显示选项中所指定符号连接的源文件大小。
- ``-m或–megabytes``：以1MB为单位。
- ``-s或–summarize``：仅显示总计，即当前目录的大小。
- ``-S或–separate-dirs``：显示每个目录的大小时，并不含其子目录的大小。
- ``-x或–one-file-xystem``：以一开始处理时的文件系统为准，若遇上其它不同的文件系统目录则略过。
- ``-X<文件>或–exclude-from=<文件>``：在<文件>指定目录或文件。
- ``–exclude=<目录或文件>``：略过指定的目录或文件。
- ``–max-depth=<目录层数>``：超过指定层数的目录后，予以忽略。
- ``–help``：显示帮助。
- ``–version``：显示版本信息。
- ``-0``：（杠零）表示每列出一个目录的信息，不换行，而是直接输出下一个目录的信息。

33. 修改root密码
```bash
[root@shadow000902 /]# passwd								# 修改密码命令
Changing password for user root.
New password: 												# 输入新的密码
Retype new password: 										# 确认新的密码
passwd: all authentication tokens updated successfully.		# 成功修改密码提示
```