---
title: MAC系统导入HTMLTestRunner
date: 2016-06-19 17:07:36
categories: [Tips]
tags: [python, 自动化测试报告]
---

1. 下载：[HTMLTestRunner.py](http://tungwaiyip.info/software/HTMLTestRunner_0_8_2/HTMLTestRunner.py) & [test_HTMLTestRunner.py](http://tungwaiyip.info/software/HTMLTestRunner_0_8_2/test_HTMLTestRunner.py)

2. HTMLTestRunner放入Python环境中
```python
sudo cp ~/Downloads/HTMLTestRunner.py /Library/Python/2.7/site-packages
sudo cp ~/Downloads/test_HTMLTestRunner.py /Library/Python/2.7/site-packages
```

  <!--more-->

3. 执行 ``import HTMLTestRunner``， 如果没有报错，则导入成功。

4. 通过 ``dir(HTMLTestRunner)``， 查看HTMLTestRunner包含方法：
```python
['HTMLTestRunner', 'OutputRedirector', 'StringIO', 'Template_mixin', 'TestProgram', 'TestResult', '_TestResult', '__author__', '__builtins__', '__doc__', '__file__', '__name__', '__package__', '__version__', 'datetime', 'main', 'saxutils', 'stderr_redirector', 'stdout_redirector', 'sys', 'time', 'unittest']
```