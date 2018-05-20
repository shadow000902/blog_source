---
title: python小程序
date: 2018-05-19 17:53:52
categories: [Python]
tags: [python]
---

1. 修改文件内容，并存入原文件
```python
import fileinput
for line in fileinput.input("test0", inplace=1):
    line = line.replace("..", "C:")
    print line
```

  <!--more-->

2. 比较两个文件的差异，并输出HTML对比结果
```python
# -*- coding: utf-8 -*-
"""
1.difflib的HtmlDiff类创建html表格用来展示文件差异，通过make_file方法
2.make_file方法使用
make_file(fromlines, tolines [, fromdesc][, todesc][, context][, numlines])
用来生成一个包含表格的html文件，其内容是用来展示差异。
fromlines和tolines,用于比较的内容，格式为字符串组成的列表
fromdesc和todesc，可选参数，对应的fromlines,tolines的差异化文件的标题，默认为空字符串
context 和 numlines，可选参数，context 为True时，只显示差异的上下文，为false，显示全文，numlines默认为5，
当context为True时，控制展示上下文的行数，当context为false时,控制不同差异的高亮之间移动时“next”的开始位置
3.使用argparse传入两个需要对比的文件
"""
import difflib
import argparse
import sys

# 创建打开文件函数，并按换行符分割内容
def readfile(filename):
    try:
        with open(filename, 'r') as fileHandle:
            text = fileHandle.read().splitlines()
        return text
    except IOError as e:
        print("Read file Error:", e)
        sys.exit()

# 比较两个文件并输出到html文件中
def diff_file(filename1, filename2):
    text1_lines = readfile(filename1)
    text2_lines = readfile(filename2)
    d = difflib.HtmlDiff()
    # context=True时只显示差异的上下文，默认显示5行，由numlines参数控制，context=False显示全文，差异部分颜色高亮，默认为显示全文
    result = d.make_file(text1_lines, text2_lines, filename1, filename2, context=True)
    # 内容保存到result.html文件中
    with open('result.html', 'w') as resultfile:
        resultfile.write(result)
    # print(result)

if __name__ == '__main__':
    # 定义必须传入两个参数，使用格式-f1 filename1 -f2 filename
    parser = argparse.ArgumentParser(description="传入两个文件参数")
    parser.add_argument('-f1', action='store', dest='filename1', required=True)
    parser.add_argument('-f2', action='store', dest='filename2', required=True)
    given_args = parser.parse_args()
    filename1 = given_args.filename1
    filename2 = given_args.filename2
    diff_file(filename1, filename2)
```

3. 金额数值转大写
```python
# -*- coding: utf-8 -*-

import math

def convertNumToChinese(totalPrice):
    dictChinese = [u'零', u'壹', u'贰', u'叁', u'肆', u'伍', u'陆', u'柒', u'捌', u'玖']
    unitChinese = [u'', u'拾', u'佰', u'仟', '', u'拾', u'佰', u'仟']
    # 将整数部分和小数部分区分开
    partA = int(math.floor(totalPrice))
    partB = round(totalPrice - partA, 2)
    strPartA = str(partA)
    strPartB = ''
    if partB != 0:
        strPartB = str(partB)[2:]

    singleNum = []
    if len(strPartA) != 0:
        i = 0
        while i < len(strPartA):
            singleNum.append(strPartA[i])
            i = i + 1
    # 将整数部分先压再出，因为可以从后向前处理，好判断位数
    tnumChinesePartA = []
    numChinesePartA = []
    j = 0
    bef = '0';
    if len(strPartA) != 0:
        while j < len(strPartA):
            curr = singleNum.pop()
            if curr == '0' and bef != '0':
                tnumChinesePartA.append(dictChinese[0])
                bef = curr
            if curr != '0':
                tnumChinesePartA.append(unitChinese[j])
                tnumChinesePartA.append(dictChinese[int(curr)])
                bef = curr
            if j == 3:
                tnumChinesePartA.append(u'萬')
                bef = '0'
            j = j + 1

        for i in range(len(tnumChinesePartA)):
            numChinesePartA.append(tnumChinesePartA.pop())
    A = ''
    for i in numChinesePartA:
        A = A + i
    # 小数部分很简单，只要判断下角是否为零
    B = ''
    if len(strPartB) == 1:
        B = dictChinese[int(strPartB[0])] + u'角'
    if len(strPartB) == 2 and strPartB[0] != '0':
        B = dictChinese[int(strPartB[0])] + u'角' + dictChinese[int(strPartB[1])] + u'分'
    if len(strPartB) == 2 and strPartB[0] == '0':
        B = dictChinese[int(strPartB[0])] + dictChinese[int(strPartB[1])] + u'分'

    if len(strPartB) == 0:
        S = A + u'圆整'
    if len(strPartB) != 0:
        S = A + u'圆' + B
    return S


print convertNumToChinese(23001231.041)
```