---
title: Top 8 Diagrams for Understanding Java
date: 2017-03-14 17:10:45
categories: [Java]
tags: [java]
---

#### String Immutability【字符串不变性】
The following diagram shows what happens for the following code:
```java
String s = "abcd";
s = s.concat("ef");
```
<!--more-->

![](http://o6lw1c1bf.bkt.clouddn.com/string-immutability.jpeg)

#### The equals() and hashCode() Contract【equals()方法、hashCode()方法的区别】
HashCode is designed to improve performance. The contract between equals() and hasCode() is that:
1. If two objects are equal, then they must have the same hash code.
2. If two objects have the same hashcode, they may or may not be equal.
![](http://o6lw1c1bf.bkt.clouddn.com/java-hashcode.jpeg)

#### Java Exception Class Hierarchy【Java异常类的层次结构】
Red colored are checked exceptions which must either be caught or declared in the method’s throws clause.
![](http://o6lw1c1bf.bkt.clouddn.com/Exception-Hierarchy-Diagram.jpeg)

#### Collections Class Hierarchy【集合类的层次结构】
Note the difference between Collections and Collection.
![](http://o6lw1c1bf.bkt.clouddn.com/Collections.jpeg)
![](http://o6lw1c1bf.bkt.clouddn.com/java-collection-hierarchy.jpeg)

#### Java synchronization【Java同步】
Java synchronization mechanism can be illustrated by an analogy to a building.
![](http://o6lw1c1bf.bkt.clouddn.com/Java-Monitor.jpg)

#### Aliasing【别名】
Aliasing means there are multiple aliases to a location that can be updated, and these aliases have different types.
![](http://o6lw1c1bf.bkt.clouddn.com/JavaAliasing.jpeg)

#### Stack and Heap【堆和栈】
This diagram shows where methods and objects are in run-time memory.
![](http://o6lw1c1bf.bkt.clouddn.com/Java-array-in-memory.png)

#### JVM Run-Time Data Areas【Java虚拟机运行时数据区域】
![](http://o6lw1c1bf.bkt.clouddn.com/JVM-runtime-data-area.jpg)

***

*原文链接： programcreek 翻译： ImportNew.com - era_misa*
*译文链接： http://www.importnew.com/11725.html*
