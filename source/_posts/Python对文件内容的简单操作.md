---
title: Python对文件内容的简单操作
date: 2018-01-11 00:08:41
categories: [Python]
tags: [python]
---

#### 打开文件
```python
#打开文件    w会新建文件，有写的权限   r读   r+读写

#fo =open("file1.txt","w")
fo =open("file1.txt","r+")
print(fo)
print(fo.read)

fo.write("bbbbbbbbbbbbbb")

print(open("file1.txt"))
fo.close() #关闭之后数据才写到文件 中
```

  <!--more-->

#### 读文件
```python
##读文件

f1=open("file1.txt")
#txt=f1.read();
#print(txt)

#读取所有行 []
# print(f1.readlines());
#读取一行    超出 会读空
line=f1.readline();
print(line);
print(f1.readline());
print(f1.readline());

#f1.next() 超出范围会停止
```

#### 写文件
```python
###写文件
l=["one\n","two\n","three\n","four\n"]
#f2=open("file2.txt","a")
#f2.writelines(l) #换行的形式写到文件后面
#f2.close();


f2=open("file2.txt","r+") #是以指针的形式
#f2.read() #先读出 在写 不会被覆盖
#f2.writelines(l) #换行的形式写到文件后面
#f2.close();

print("1:",f2.read())
print("2:",f2.read()) #读完后 指针移到尾部了 就读不出来了 可以移动指针
f2.seek(0,0) ##指针移动   0=头部  1=向后移动
print("3:",f2.read())
f2.seek(0,0) 
f2.seek(0,2) ##指针移动  结尾  可以在结尾追加数据
print("4:",f2.read())

f2.writelines(l) #在写一次 不关闭是不保存的
f2.flush() #提交更新  没关闭 先把写入的数据保存
```

#### 查找文件中的内容
```python
import re
#查找文件中有多少个hello

fp=open("file3.txt","r")
count=0;
for s in fp.readlines():
    li=re.findall("hello", s)
    if len(li)>0:
        count=count+len(li)
print("search:",count,">>>hello")
fp.close()
```

#### 替换文件内容
```python
#把文件内容替换
#把file3.txt 的 hello 替换为 good,并保存到file3Back.txt
import re

fp3=open("file3.txt","r")
fp4=open("file4.txt","w")

for s in fp3.readlines():#先读出来
    fp4.write(s.replace("hello","goood")) #替换 并写入

fp3.close()
fp4.close()
```

#### 在原文件中替换文件内容
```python
#写在原文件中
fp3=open("file3.txt","r+") #不用w w会清空数据
s=fp3.read()#读出
fp3.seek(0,0) #指针移到头  原来的数据还在 是替换 会存在一个问题 如果少   会替换不了全部数据，自已思考解决!!!
#从头写入
fp3.write(s.replace("hello","good"))
fp3.close()
```

```python
import fileinput
for line in fileinput.input("test0", inplace=1):
    line = line.replace("..", "C:")
    print line
```

| 模式 | 描述                                                                                                       |
| ---- | ---------------------------------------------------------------------------------------------------------- |
| r    | 以读方式打开文件，可读取文件信息。                                                                         |
| w    | 以写方式打开文件，可向文件写入信息。如文件存在，则清空该文件，再写入新内容                                 |
| a    | 以追加模式打开文件（即一打开文件，文件指针自动移到文件末尾），如果文件不存在则创建                         |
| r+   | 以读写方式打开文件，可对文件进行读和写操作。                                                               |
| w+   | 消除文件内容，然后以读写方式打开文件。                                                                     |
| a+   | 以读写方式打开文件，并把文件指针移到文件尾。                                                               |
| b    | 以二进制模式打开文件，而不是以文本模式。该模式只对Windows或Dos有效，类Unix的文件是用二进制模式进行操作的。 |

| 方法                   | 描述                                                                                                         |
| ---------------------- | ------------------------------------------------------------------------------------------------------------ |
| f.close()              | 关闭文件，记住用open()打开文件后一定要记得关闭它，否则会占用系统的可打开文件句柄数。                         |
| f.fileno()             | 获得文件描述符，是一个数字                                                                                   |
| f.flush()              | 刷新输出缓存                                                                                                 |
| f.isatty()             | 如果文件是一个交互终端，则返回True，否则返回False。                                                          |
| f.read([count])        | 读出文件，如果有count，则读出count个字节。                                                                   |
| f.readline()           | 读出一行信息。                                                                                               |
| f.readlines()          | 读出所有行，也就是读出整个文件的信息。                                                                       |
| f.seek(offset[,where]) | 把文件指针移动到相对于where的offset位置。where为0表示文件开始处，这是默认值 ；1表示当前位置；2表示文件结尾。 |
| f.tell()               | 获得文件指针位置。                                                                                           |
| f.truncate([size])     | 截取文件，使文件的大小为size。                                                                               |
| f.write(string)        | 把string字符串写入文件。                                                                                     |
| f.writelines(list)     | 把list中的字符串一行一行地写入文件，是连续写入文件，没有换行。                                               |