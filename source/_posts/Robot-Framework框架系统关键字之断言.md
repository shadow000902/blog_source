---
title: Robot-Framework框架系统关键字之断言
date: 2017-08-28 01:07:24
categories: [RobotFramework]
tags: [robot-framework]
---

##### 准备数据
```bash
# 三个list变量：list_a、list_b、list_c；
@{list_a}    create list    1    a    ${21}    21    12
@{list_b}    set variable    1.0    a    ${21}    21    21
@{list_c}    create list
# 两个scalar变量：string和name
${string}    set variable    taoyi is in hangzhou
${name}    set variable    ty
```

  <!--more-->

##### 断言实例
1. ``should contain``、``should not contain``、``should contain x times``
```bash
should contain    ${list_b}    1.0
should not contain    ${list_b}    1
should contain x times    ${list_b}    21    2
# 变量${list_b}包含对象1.0而不包含对象1，且对象21在变量${lst_b}出现了两次
```
2. ``should be empty``、``should not be empty``
```bash
should be empty    ${list_c}
should not be empty    ${list_a}
# 变量${list_c}没有赋值，所以为空；相反，变量${list_a}有赋初始值，故为非空
```
3. ``should be equal``、``should not be equal``
```bash
should be equal    ${list_a[1]}    ${list_b[1]}
should not be equal    ${list_a}    ${list_b}
# ${list_a[1]}=a，${list_b[1]}=a故两个对象相等;而${list_a}和${list_b}有元素不一致，这两个对象不相等
```
4. ``should be equal as numbers``、``should not be equal as numbers``
```bash
should be equal as numbers    ${list_b[0]}    1.0000
should not be equal as number    ${list_b[0]}    1.1
# ${list_b[0]}=1，忽略精度，故与1.0000相等；而即使是忽略精度，1与1.1还是不相等的
```
5. ``should be equal as integers``、``should not be equal as integers``
```bash
should be equal as integers    ${list_a[3]}    ${list_b[3]}
should not be equal as integers    ${list_a[4]}    ${list_b[4]}
# ${list_a[3]}=21，${list_b[3]}=21，而系统默认为字符串格式的“21”,故需要转化为整数类型，转化为整数后两个对象相等
# ${list_a[4]}=12，${list_b[4]}=21，即使转化为整数后两个对象依旧是不相等
```
6. ``should be equal as strings``、``should not be equal as strings``
```bash
should be equal as strings    ${list_a[2]}    ${list_b[2]}
should not be equal as strings    ${list_a[0]}    ${list_b[0]}
# ${list_a[2]}=${21}，${list_b[2]}=${21}，而均为数值型的21,故需要转化为字符串类型，转化为字符串后两个对象相等
```
7. ``should be true``、``should not be true``
```bash
should be true    ${list_a[0]} < 10
should not be true    ${list_a[0]} < 1
# ${list_a[0]}=1（字符串类型），其ASCII值比字符串10的ASCII值小
```
8. ``should start with``、``should not start with``
```bash
should start with    ${string}    tao
should not start with    ${string}    h
# ${string}="taoyi is in hangzhou"是以sha开头，而非以h开头
```
9. ``should end with``、``should not end with``
```bash
should end with    ${string}    hangzhou
should not end with    ${string}    taoyi
# ${string}="taoyi is in hangzhou"是以hangzhou结尾，而非以taoyi结尾
```
10. ``should match``、``should not match``
```bash
should match    ${name}    t?
should not match    ${string}    h?*
# 模式匹配和shell中的通配符类似，它区分大小写，'*'匹配0~无穷多个字符，“？”单个字符
# ${name}=ty,由以t开头的两个字母组成
```
11. ``should match regexp``、``should not match regexp``
```bash
should match regexp    ${name}    ^\\w{2}$
should not match regexp    ${name}    ^\\d{2}$
# 反斜杠在测试数据是转义字符，因此模式中要使用双重转义；'^'和'$'字符可以用来表示字符串的开头和结尾
# ${name}=ty，是有两个字母--w{2}组成，而不是由两个数字--d{2}组成
```


[转载](http://blog.sina.com.cn/s/blog_7f66d4ea0101k3fl.html)