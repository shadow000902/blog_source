---
title: Python基础知识整理
date: 2018-02-14 18:40:37
categories: [Python]
tags: [python]
---

#### 基础方法
1. 字符串大小写转换
```python
# 首字母转大写
text.title()
# 字符串转大写
text.upper()
# 字符串转小写
text.lower()
```

  <!--more-->

2. 对list进行排序
```python
cars = ['bmw', 'audi', 'toyota', 'subaru']
# 临时性字母正序排列
print(sorted(cars))
# 临时性字母倒叙排列
print(sorted(cars, reverse=True)
# 永久性字母正序排列
cars.sort()
# 永久性字母倒叙排列
cars.sort(reverse=True)
# 默认排序
print(cars)
```

3. 访问list元素
```python
cars = ['bmw', 'audi', 'toyota', 'subaru']
# 访问第一个元素
print(cars[0])
# 访问倒数第一个元素，即list最后一个元素
# 当访问的list长度总是会变的情况下，可以使用这种方式访问list最后一个元素
print(cars[-1])
```

4. list中增删元素
```python
motorcycles = ['honda', 'yamaha', 'suzuki', 'ducati']
# 根据值删除元素
too_expensive = 'ducati'
motorcycles.remove(too_expensive)
# 增加元素，元素增加到末尾
motorcycles.append(too_expensive)
# 指定位置插入元素
motorcycles.insert(0, too_expensive)
# 删除指定位置元素
del motorcycles[1]
# 取出list中的最后一个元素
motorcycles.pop()
print(motorcycles)
```

5. 获取list长度
```python
len(cars)
```

6. 复制list
```python
my_foods = ['pizza', 'falafel', 'carrot cake'] 
# 复制整个列表以 [:] 来表示
friend_foods = my_foods[:]
```

7. 检查特定值是否在list中
```python
banned_users = ['andrew', 'carolina', 'david']
user1 = 'andrew'
user2 = 'and'
# 返回true
print(user1 in banned_users)
print(user2 not in banned_users)
# 返回false
print(user1 not in banned_users)
print(user2 in banned_users)
```

8. ``if``判断条件为``list``注意点
在判断条件为``list``时，如果``list``为空，即记过为``false``，只有在``list``有一个元素时，才为``true``。
```python
requested_toppings = []

if requested_toppings:
    print('requested_toppings not empty')
else:
    print('requested_toppings is empty')
```
这里实际执行的就是``else``中的语句，因为``requested_toppings``是空的，返回的``false``。

9. 多个``list``判断
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