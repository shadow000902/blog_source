---
title: Python基础知识整理
date: 2018-02-14 18:40:37
categories: [Python]
tags: [python]
---

#### 基础方法
  字符串大小写转换
```python
text.title()                # 首字母转大写
text.upper()                # 字符串转大写
text.lower()                # 字符串转小写
```

  <!--more-->

 对list进行排序
```python
cars = ['bmw', 'audi', 'toyota', 'subaru']
print(sorted(cars))                             # 临时性字母正序排列
print(sorted(cars, reverse=True)                # 临时性字母倒叙排列
cars.sort()                                     # 永久性字母正序排列
cars.sort(reverse=True)                         # 永久性字母倒叙排列
print(cars)                                     # 默认排序
```

  访问list元素
```python
cars = ['bmw', 'audi', 'toyota', 'subaru']
print(cars[0])                                  # 访问第一个元素
# 当访问的list长度总是会变的情况下，可以使用这种方式访问list最后一个元素
print(cars[-1])                                 # 访问倒数第一个元素，即list最后一个元素
```

  list中增删元素
```python
motorcycles = ['honda', 'yamaha', 'suzuki', 'ducati']
too_expensive = 'ducati'
motorcycles.remove(too_expensive)               # 根据值删除元素
motorcycles.append(too_expensive)               # 增加元素，元素增加到末尾
motorcycles.insert(0, too_expensive)            # 指定位置插入元素
del motorcycles[1]                              # 删除指定位置元素
motorcycles.pop()                               # 取出list中的最后一个元素
print(motorcycles)
```

  获取list长度
```python
len(cars)
```

  复制list
```python
my_foods = ['pizza', 'falafel', 'carrot cake'] 
friend_foods = my_foods[:]                      # 复制整个列表以 [:] 来表示
```

  检查特定值是否在list中
```python
banned_users = ['andrew', 'carolina', 'david']
user1 = 'andrew'
user2 = 'and'
print(user1 in banned_users)                    # 返回true
print(user2 not in banned_users)                # 返回true
print(user1 not in banned_users)                # 返回false
print(user2 in banned_users)                    # 返回false
```

  ``if``判断条件为``list``注意点
在判断条件为``list``时，如果``list``为空，即记过为``false``，只有在``list``有一个元素时，才为``true``。
```python
requested_toppings = []

if requested_toppings:
    print('requested_toppings not empty')
else:
    print('requested_toppings is empty')
```
这里实际执行的就是``else``中的语句，因为``requested_toppings``是空的，返回的``false``。

  多个``list``判断
```python
available_toppings = ['mushrooms', 'olives', 'green peppers', 'pepperoni', 'pineapple', 'extra cheese']
requested_toppings = ['mushrooms', 'french fries', 'extra cheese']

for requested_topping in requested_toppings:
    if requested_topping in available_toppings:
        print("Adding " + requested_topping + ".")
    else:
        print("Sorry, we don't have " + requested_topping + ".")
    print("\nFinished making your pizza!")
```

  使用函数``range()``
```python
for value in range(1, 5):                       # 生成有序数值
    print(value)                                # 它只会打印4个数值，最后一个数值不会打印
num = list(range(1, 6))                         # 创建数值列表
print(num)                                      # 结果：[1, 2, 3, 4, 5]

even_num = list(range(2, 11, 2))                # 使用range()还可以指定步长
print(even_num)                                 # 结果：[2, 4, 6, 8, 10]
```

  对数值列表执行简单的统计计算
```python
digits = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
min(digits)                                     # 取最小值
max(digits)                                     # 取最大值
sum(digits)                                     # 求总和
```

  **列表解析**
# 复杂模式1
```python
squares = []
for value in range(1, 11):
    square = value**2
    squares.append(square)
print(squares)
```
# 较复杂模式2
```python
squares = []
for value in range(1, 11):
    squares.append(value**2)
print(squares)
```
# 列表解析
```python
squares = [value**2 for value in range(1,11)]
print(squares)
```
要使用这种语法，首先指定一个描述性的列表名，如``squares``；然后，指定一个左方括号，并定义一个表达式，用于生成你要存储到列表中的值。在这个示例中，表达式为``value**2``，它计算平方值。接下来，编写一个``for``循环，用于给表达式提供值，再加上右方括号。在这个示例中，``for``循环为``for value in range(1,11)``，它将值1~10提供给表达式``value**2``。请注意，这里的``for``语句末尾没有冒号。

  使用列表的一部分



  ``tuple``

  ``dict``

  grades['']

13. 是否可迭代``Iterable``

14. 类似一个概念，实例才是可被CPU操作的，真实存在的东西。

```python
class People():
    def __init__(self):
        pass
    def have_some_food(self):
        print('Delicious!')
        
    def hava_a_drink(self):
        print('Thanks!')

if __name__ == '__main__':
    me = People()
    you = People()
    me.have_some_food()
    me.hava_a_drink()
```

15. 封装  访问限制

强制__init__(self, name, come_from)的属性不能被修改：
    __name
    __come_from
    
16. 封装 将类的属性私有化

17. 继承 

18. 多态 多种状态，接口多种不同实现方式即为多态


