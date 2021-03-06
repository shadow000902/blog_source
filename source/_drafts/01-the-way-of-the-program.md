---
title: 第一章：程序之道
date: 2016-05-02 18:20:00
categories: [Think Python 2E]
tags: [python]
---

本书的目标是教你像计算机科学家一样思考。这一思考方式集成了数学、工程以及自然科学的一些最好的特点。像数学家一样，计算机科学家使用形式语言表示思想（具体来说是计算）。像工程师一样，计算机科学家设计东西，将零件组成系统，在各种选择之间寻求平衡。像科学家一样，计算机科学家观察复杂系统的行为，形成假设并且对预测进行检验。

对于计算机科学家，最重要的技能是 **解决问题的能力** 。解决问题（problem solving）意味着对问题进行形式化，寻求创新型的解决方案，并且清晰、准确地表达解决方案的能力。事实证明，学习编程的过程是锻炼问题解决能力的一个绝佳机会。这就是为什么本章被称为“程序之道”。

一方面，你将学习如何编程，这本身就是一个有用的技能。另一方面，你将把编程作为实现自己目的的手段。随着学习的深入，你会更清楚自己的目的。


  <!--more-->

什么是程序？
----------------

**程序** 是一系列说明如何执行计算（computation）的指令。计算可以是数学上的计算，例如寻找公式的解或多项式的根，也可以是一个符号计算（symbolic computation），例如在文档中搜索并替换文本或者图片，就像处理图片或播放视频。

不同编程语言中，程序的具体细节也不一样，但是有一些基本的指令几乎出现在每种语言当中：

*输入（input）：*
    从键盘、文件、网络或者其他设备获取数据。

*输出（output）：*
    在屏幕上显示数据，将数据保存至文件，通过网络传送数据，等等。

*数学（math）：*
    执行基本的数学运算，如加法和乘法。

*有条件执行（conditional execution）：*
    检查符合某个条件后，执行相应的代码。

*重复（repetition）：*
    重复执行某个动作，通常会有一些变化。

无论你是否相信，这几乎是程序的全部指令了。每个你曾经用过的程序，无论多么复杂，都是由跟这些差不多的指令构成的。因此，你可以认为编程就是将庞大、复杂的任务分解为越来越小的子任务，直到这些子任务简单到可以用这其中的一个基本指令执行。

运行Python
--------------------

Python入门的一个障碍，是你可能需要在电脑上安装Python和相关软件。如果你熟悉电脑的操作系统，特别是如果你能熟练使用命令行（command-line interface），安装Python对你来说就不是问题了。但是对于初学者，同时学习系统管理（system administration）和编程这两方面的知识是件痛苦的事。

为了避免这个问题，我建议你首先在浏览器中运行Python。等你对Python更加了解之后，我会建议你在电脑上安装Python。

网络上有许多网页可以让你运行Python。如果你已经有最喜欢的网站，那就打开网页运行Python吧。如果没有，我推荐PythonAnywhere。我在 http://tinyurl.com/thinkpython2e 给出了详细的使用指南。

目前Python有两个版本，分别是Python 2和Python 3。二者十分相似，因此如果你学过某个版本，可以很容易地切换到另一个版本。事实上，作为初学者，你只会接触到很少数的不同之处。本书采用的是Python 3，但是我会加入一些关于Python 2的说明。

Python的 **解释器** 是一个读取并执行Python代码的程序。根据你的电脑环境不同，你可以通过双击图标，或者在命令行输入\ ``python``\ 的方式来启动解释器。解释器启动后，你应该看到类似下面的输出：



    Python 3.4.0 (default, Jun 19 2015, 14:20:21)
    [GCC 4.8.2] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>>

前三行中包含了关于解释器及其运行的操作系统的信息，因此你看到的内容可能不一样。但是你应该检查下版本号是否以3开头，上面示例中的版本号是3.4.0。如果以3开头，那说明你正在运行Python 3。如果以2开头，那说明你正在运行（你猜对了）Python 2。

最后一行是一个提示符（prompt），表明你可以在解释器中输入代码了。如果你输入一行代码然后按回车（Enter），解释器就会显示结果： 



    >>> 1 + 1
    2

现在你已经做好了开始学习的准备。接下来，我将默认你已经知道如何启动Python解释器和执行代码。

第一个程序
----------------

根据传统，你用一门新语言写的第一个程序叫做“Hello, World!”，因为它的功能只不过是显示单词“Hello, World!”。在Python中，它看起来是这样： 



    >>> print('Hello, World!')

这是一个 ``print`` 函数的示例，尽管它并不会真的在纸上打印。它将结果显示在屏幕上。在此例中，结果是单词： 



    Hello, World!

程序中的单引号标记了被打印文本的首尾；它们不会出现在结果中。

括号说明 ``print`` 是一个函数。我们将在第三章介绍函数。在Python 2中， print是一个语句；不是函数，所以不需要使用括号。



    >>> print 'Hello, World!'

很快你就会明白二者之间的区别，现在知道这些就足够了。

    译者注：Python核心开发者Brett Cannon详细解释了 `为什么print在Python 3中变成了函数 <http://codingpy.com/article/why-print-became-a-function-in-python-3/>`_。      

算术运算符
--------------------

接下来介绍算术。Python提供了许多代表加法和乘法等运算的特殊符号，叫做 **运算符** （operators）。

运算符 ``+`` 、``-`` 和 ``*`` 分别执行加法、减法和乘法，详见以下示例：



    >>> 40 + 2
    42
    >>> 43 - 1
    42
    >>> 6 * 7
    42

运算符 ``/`` 执行除法运算：



    >>> 84 / 2
    42.0

你可能会问，为什么结果是42.0，而不是42。在下节中，我会进行解释。

最后，运算符 ``*`` 执行乘方运算；也就是说，它将某个数字乘以自身相应的次数：



    >>> 6**2 + 6
    42

某些语言使用 ``^`` 运算符执行乘方运算，但是在Python中，它却属于一种位运算符，叫做XOR。如果你对位运算符不太了解，那么下面的结果会让你感到惊讶：



    >>> 6 ^ 2
    4

我不打算在本书中介绍位运算符，但是你可以阅读 `Python官方百科 <http://wiki.python.org/moin/BitwiseOperators>`_ ，了解相关内容。

值和类型
----------------

**值（value）** 是程序处理的基本数据之一，比如说一个单词或一个数字。我们目前已经接触到的值有：2，42.0，和 ``'Hello World!'`` 。

这些值又属于不同的 **类型（types）** ：2是一个 **整型数（integer）**，42.0 是一个 **浮点数（floating point number）**，而 ``'Hello, World!'`` 则是一个 **字符串（string）**，之所以这么叫是因为其中的字符被串在了一起（strung together）。

如果你不确定某个值的类型是什么，解释器可以告诉你：



    >>> type(2)
    <class 'int'>
    >>> type(42.0)
    <class 'float'>
    >>> type('Hello, World!')
    <class 'str'>

“class”一词在上面的输出结果中，是类别的意思；一个类型就是一个类别的值。

不出意料，整型数属于 ``int`` 类型，字符串属于 ``str`` 类型，浮点数属于 ``float`` 类型。

那么像 ``'2'`` 和 ``'42.0'`` 这样的值呢？它们看上去像数字，但是又和字符串一样被引号括在了一起？



    >>> type('2')
    <class 'str'>
    >>> type('42.0')
    <class 'str'>

它们其实是字符串。

当你输入一个大数值的整型数时，你可能会想用逗号进行区分，比如说像这样：1,000,000。在Python中，这不是一个合法的 *整型数*，但是确实合法的值。



    >>> 1,000,000
    (1, 0, 0)

结果和我们预料的完全不同！Python把1,000,000当作成了一个以逗号区分的整型数序列。在后面的章节中，我们会介绍更多有关这种序列的知识。

形式语言和自然语言
----------------------------

**自然语言（natural language）** 是人们交流所使用的语言，例如英语、西班牙语和法语。它们不是人为设计出来的（尽管有人试图这样做）；而是自然演变而来。

**形式语言（formal languages）**\ 是人类为了特殊用途而设计出来的。例如，数学家使用的记号（notation）就是形式语言，特别擅长表示数字和符号之间的关系。化学家使用形式语言表示分子的化学结构。 最重要的是：

    **编程语言是被设计用于表达计算的形式语言。**

形式语言通常拥有严格的 **语法** 规则，规定了详细的语句结构。例如，\ :math:`3 + 3 = 6`\ 是语法正确的数学表达式，而\ :math:`3 + = 3 \$ 6`\ 则不是；:math:`H_2O`\ 是语法正确的化学式，而\ :math:`_2Zz`\ 则不是。

语法规则有两种类型，分别涉及\ **记号（tokens）**\ 和结构。记号是语言的基本元素，例如单词、数字和化学元素。
:math:`3 + = 3 \$ 6`\ 这个式子的问题之一，就是 $ 在数学中不是一个合法的记号
（至少据我所知）。类似的，:math:`_2Zz` 也不合法，因为没有一个元素的简写是 :math:`Zz`。

第二种语法规则与标记的组合方式有关。\ :math:`3 + = 3`\ 这个方程是非法的，因为即使\ :math:`+`\ 和\ :math:`=`\ 都是合法的记号，但是你却不能把它们俩紧挨在一起。类似的，在化学式中，下标位于元素之后，而不是之前。

This is @ well-structured Engli$h sentence with invalid t\*kens in it.
This sentence all valid tokens has, but invalid structure with.

    译者注：上面两句英文都是不符合语法的，一个包含非法标记，另一个结构不符合语法。

当你读一个用英语写的句子或者用形式语言写的语句时，你都必须要理清各自的结构（尽管在阅读自然语言时，你是下意识地进行的）。这个过程被称为 **解析（parsing）**。

虽然形式语言和自然语言有很多共同点——标记、结构和语法，它们也有一些不同：

*歧义性*：
    自然语言充满歧义，人们使用上下文线索以及其它信息处理这些歧义。形式语言被设计成几乎或者完全没有歧义，这意味着不管上下文是什么，任何语句都只有一个意义。

*冗余性*：
    为了弥补歧义性并减少误解，自然语言使用很多冗余。结果，自然语言经常很冗长。形式语言则冗余较少，更简洁。

*字面性*：
    自然语言充满成语和隐喻。如果我说“The penny dropped”，可能根本没有便士、也没什么东西掉下来（这个成语的意思是，经过一段时间的困惑后终于理解某事）。形式语言的含义，与它们字面的意思完全一致。

由于我们都是说着自然语言长大的，我们有时候很难适应形式语言。形式语言与自然语言之间的不同，类似诗歌与散文之间的差异，而且更加明显：

*诗歌*：
    单词的含义和声音都有作用，
    整首诗作为一个整理，会对人产生影响，或是引发情感上的共鸣。
    歧义不但常见，而且经常是故意为之。

*散文*：
    单词表面的含义更重要，句子结构背后的寓意更深。
    散文比诗歌更适合分析，但仍然经常有歧义。

*程序*：
    计算机程序的含义是无歧义、无引申义的，
    通过分析程序的标记和结构，即可完全理解。

形式语言要比自然语言更加稠密，因此阅读起来花的时间会更长。另外，形式语言的结构也很重要，所以从上往下、从左往右阅读，并不总是最好的策略。相反，你得学会在脑海里分析一个程序，识别不同的标记并理解其结构。最后，注重细节。拼写和标点方面的小错误在自然语言中无伤大雅，但是在形式语言中却会产生很大的影响。


调试
------

程序员都会犯错。由于比较奇怪的原因，编程错误被称为 **故障（译者注：英文为bug，一般指虫子）**，追踪错误的过程被称为 **调试（debugging）**。

编程，尤其是调试，有时会让人动情绪。如果你有个很难的bug解决不了，你可能会感到愤怒、忧郁抑或是丢人。

有证据表明，人们很自然地把计算机当人来对待。当计算机表现好的时候，我们认为它们是队友，而当它们固执或无礼的时候，我们也会像对待固执或无礼人的一样对待它们（Reeves and Nass, *The Media Equation:
How People Treat Computers, Television, and New Media Like Real People
and Places*）。

对这些反应做好准备有助于你对付它们。
一种方法是将计算机看做是一个雇员，拥有特定的长处，
例如速度和精度，也有些特别的缺点，像缺乏沟通以及不善于把握大局。

你的工作是当一个好的管理者：找到充分利用优点、摒弃弱点的方法。
并且找到使用你的情感来解决问题的方法，
而不是让你的情绪干扰你有效工作的能力。

学习调试可能很令人泄气，
但是它对于许多编程之外的活动也是一个非常有价值的技能。
在每一章的结尾，我都会花一节内容介绍一些调试建议，比如说这一节。希望能帮到你！


术语表
--------

*解决问题*：
    将问题形式化、寻找并表达解决方案的过程。

*高级语言（high-level language）*：
    像Python这样被设计成人类容易阅读和编写的编程语言。

*低级语言(low-level language)*：
    被设计成计算机容易运行的编程语言；也被称为“机器语言”或“汇编语言（assembly language）”。
    
*可移植性*：
    程序能够在多种计算机上运行的特性。

*解释器*：
    读取另一个程序并执行该程序的程序。

*提示符*：
    解释器所显示的字符，表明已准备好接受用户的输入。

*程序*：
    说明一个计算的一组指令。

*打印语句*：
    使Python解释器在屏幕上显示某个值的指令。

*运算符*：
    代表类似加法、乘法或者字符串连接（string concatenation）等简单计算的特殊符号。

*值*：
    程序所处理数据的基本元素之一，例如数字或字符串。

*类型*：
    值的类别。我们目前接触的类型有整型数（类型为 ``int``）、浮点数（类型为 ``float`` ）和字符串（类型为 ``str`` ）

*整型数*：
    代表整数的类型。

*浮点数*：
    代表一个有小数点的数字的类型。

*字符串*：
    代表一系列字符的类型。

*自然语言*：
    任意一种人们日常使用的、自然演变而来的语言。

*形式语言*：
    任意一种人类为了某种目的而设计的语言，例如用来表示数学概念或者电脑程序；所有的编程语言都是形式语言。

*记号*：
    程序语法结构中的基本元素之一，与自然语言中的单词类似。

*语法*：
    规定了程序结构的规则。

*解析*：
    阅读程序，并分析其语法结构的过程

*故障*：
    程序中的错误。

*调试*：
    寻找并解决错误的过程。
    


练习题
------

习题 1-1
^^^^^^^^^^^^^^^

你最好在电脑前阅读此书，因为你可以随时测试书中的示例。

每当你试验一个新特性的时候，你应该试着去犯错。举个例子，在“Hello, World!”程序中，如果你漏掉一个引号会发生什么情况？如果你去掉两个引号呢？如果你把print写错了呢？

这类试验能帮助你记忆读过的内容；对你平时编程也有帮助，因为你可以了解不同的错误信息代表的意思。现在故意犯错误，总胜过以后不小心犯错。

#. 在打印语句中，如果你去掉一个或两个括号，会发生什么？

#. 你想打印一个字符串，如果你去掉一个或两个引号，会发生什么？

#. 你可以使用减号创建一个负数，如-2。如果你在一个数字前再加上个加号，会发生什么？2++2会得出什么结果？

#. 在数学标记中，前导零（leading zeros）没有问题，如02。如果我们在Python中这样做，会发生什么？

#. 如果两个值之间没有运算符，又会发生什么？

习题 1-2
^^^^^^^^^^^^^^^

启动Python解释器，把它当计算器使用。

#. 42分42秒一共有多少秒？

#. 10公里可以换算成多少英里？提示：一英里等于1.61公里。

#. 如果你花42分42秒跑完了10公里，你的平均配速（pace）是多少（每英里耗时，分别精确到分和秒）？你每小时平均跑了多少英里（英里/时）？

    译者注：配速（pace）是在马拉松运动的训练中常使用的一个概念，配速是速度的一种，是每公里所需要的时间。配速=时间/距离。

**贡献者**

#. 翻译：[@iphyer](https://github.com/iphyer)
#. 校对：[@bingjin](https://github.com/bingjin)
#. 参考：[@carfly](https://github.com/carfly)

