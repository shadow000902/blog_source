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

{% asset_img string-immutability.jpeg string-immutability %}

#### The equals() and hashCode() Contract【equals()方法、hashCode()方法的区别】
HashCode is designed to improve performance. The contract between equals() and hasCode() is that:
1. If two objects are equal, then they must have the same hash code.
2. If two objects have the same hashcode, they may or may not be equal.
{% asset_img java-hashcode.jpeg java-hashcode %}

#### Java Exception Class Hierarchy【Java异常类的层次结构】
Red colored are checked exceptions which must either be caught or declared in the method’s throws clause.
{% asset_img Exception-Hierarchy-Diagram.jpeg Exception-Hierarchy-Diagram %}

#### Collections Class Hierarchy【集合类的层次结构】
Note the difference between Collections and Collection.
{% asset_img Collections.jpeg Collections %}
{% asset_img java-collection-hierarchy.jpeg java-collection-hierarchy %}

#### Java synchronization【Java同步】
Java synchronization mechanism can be illustrated by an analogy to a building.
{% asset_img Java-Monitor.jpg Java-Monitor %}

#### Aliasing【别名】
Aliasing means there are multiple aliases to a location that can be updated, and these aliases have different types.
{% asset_img JavaAliasing.jpeg JavaAliasing %}

#### Stack and Heap【堆和栈】
This diagram shows where methods and objects are in run-time memory.
{% asset_img Java-array-in-memory.png Java-array-in-memory %}

#### JVM Run-Time Data Areas【Java虚拟机运行时数据区域】
{% asset_img JVM-runtime-data-area.jpg JVM-runtime-data-area %}

***

*原文链接： programcreek 翻译： ImportNew.com - era_misa*
*译文链接： http://www.importnew.com/11725.html*
