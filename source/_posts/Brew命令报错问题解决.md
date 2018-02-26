---
title: Brew命令报错问题解决
date: 2018-01-10 15:33:52
categories: [SolveProblem]
tags: [brew]
---

##### 运行任何``brew``命令，都提示错误
```bash
git: error: unable to find utility "git", not a developer tool or in PATH
```

```bash
clang: error: unable to find utility "clang", not a developer tool or in PATH
```

  <!--more-->

原因主要是因为``xcode-select``的位置错误，需要修改指向的位置：
原来的位置：
```bash
# taoyi @ TaoYi-Mac in ~/Desktop/MySQL-python-1.2.5 [13:27:05] C:72
$ xcode-select --print-path
/Applications/Xcode.app/Contents/Developer
```

修改到另一个位置：
```bash
# taoyi @ TaoYi-Mac in /Applications/Xcode.app/Contents/Developer [13:33:33] C:1
$ sudo xcode-select --switch /Library/Developer/CommandLineTools
Password:

# taoyi @ TaoYi-Mac in /Applications/Xcode.app/Contents/Developer [13:33:52] 
$ xcode-select --print-path                                     
/Library/Developer/CommandLineTools
```

如此操作之后，再执行brew命令，就不会再报上面的错了