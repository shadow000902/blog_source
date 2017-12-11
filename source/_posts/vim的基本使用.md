---
title: vim的基本使用
date: 2017-03-14 23:22:02
categories: [Tools]
tags: [vim]
---
#### 基本使用
```markdown
i                        # 进入插入模式  
:q                       # 退出vim  
:w                       # 保存  
:wq                      # 保存并退出  
:set syn=c               # 设置c风格的语法高亮
```

  <!--more-->

#### vim编辑器配置
配置vim的配置文件【Mac】
```bash
~> vim ~/.vimrc                     # 默认不存在该文件，需要新建。该文件中不允许出现中文的空格和符合
```
添加如下内容
```markdown
syntax on                           "开启语法高亮  
set tabstop=4                       "设置tab为4个字符
set softtabstop=4
set shiftwidth=4                    "缩进宽度  
set autoindent                      "自动缩进  
set cindent                         "c风格缩进  
set nu                              "显示行号  
set vb t_vb=  "close the bell       "关闭vim响铃
```

#### 移动光标类命令
```markdown
h                        # 光标左移一个字符
l                        # 光标右移一个字符
space                    # 光标右移一个字符
Backspace                # 光标左移一个字符
k或Ctrl+p                 # 光标上移一行 
j或Ctrl+n                 # 光标下移一行 
Enter                    # 光标下移一行 
w或W                      # 光标右移一个字至字首 
b或B                      # 光标左移一个字至字首 
e或E                     # 光标右移一个字至字尾 
)                       # 光标移至句尾 
(                       # 光标移至句首 
}                       # 光标移至段落开头 
{                       # 光标移至段落结尾 
nG                      # 光标移至第n行首 
n+                      # 光标下移n行 
n-                      # 光标上移n行 
n$                      # 光标移至第n行尾 
H                       # 光标移至屏幕顶行 
M                       # 光标移至屏幕中间行 
L                       # 光标移至屏幕最后行 
0                       # （注意是数字零）光标移至当前行首 
$                       # 光标移至当前行尾 
```

#### 删除命令
```markdown
x                        # 删除一个字符
dd                       # 删除一行
ndd                      # 删除光标所在行向下 n 行
d1G                      # 删除光标所在行到第一行的所有数据
dG                       # 删除光标所在行到最后一行的所有数据
ctrl+v                   # 移动键盘上的“上下左右”键，将要删除的字符串选中，然后使用d就删除了
```

#### 撤销命令
```markdown
u                        # 恢复一次删除，恢复多次可以按多次u
ctrl+r                   # 恢复后又想删除
```

#### 复制命令
```markdown
yy                       # 复制光标所在的那一行
nyy                      # 复制光标所在行向下 n 行
y1G                      # 复制光标所在行到第一行的所有数据
yG                       # 复制光标所在行到最后一行的所有数据
```
