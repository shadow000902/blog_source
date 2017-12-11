---
title: MarkDown语法学习
date: 2016-03-12 21:38:45
categories: [Tools]
tags: [markdown]
---

### 一、标题
# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题

  <!--more-->

### 二、有序列表
1. 文本1
2. 文本2
3. 文本3

### 三、无序列表
- 文本1
- 文本2
- 文本3



### 四、链接和图片
[简书](www.jianshu.com)
![This is an example image](http://o6lw1c1bf.bkt.clouddn.com/tree.jpg)

### 五、引用
> 一盏灯， 一片昏黄； 一简书， 一杯淡茶。 守着那一份淡定， 品读属于自己的寂寞。 保持淡定， 才能欣赏到最美丽的风景！ 保持淡定， 人生从此不再寂寞。

### 六、诗的引用
>朝辞白帝彩云间
>千里江陵一日还
>两岸猿声啼不住
>轻舟已过万重山

### 七、斜体和粗体
*一盏灯*， 一片昏黄；**一简书**， 一杯淡茶。 守着那一份淡定， 品读属于自己的寂寞。 保持淡定， 才能欣赏到最美丽的风景！ 保持淡定， 人生从此不再寂寞。

### 八、表格
```
| Tables        | Are           | Cool  |
| ------------- |:-------------:| -----:|
| col 3 is      | right-aligned | $1600 |
| col 2 is      | centered      | $12   |
| zebra stripes | are neat      | $1    |
```

| Tables | Are | Cool |
| ------------- |:-------------:| -----:|
| col 3 is | right-aligned | $1600 |
| col 2 is | centered | $12 |
| zebra stripes | are neat | $1 |

```
dog | bird | cat
----|------|----
foo | foo  | foo
bar | bar  | bar
baz | baz  | baz
```

dog | bird | cat
----|------|----
foo | foo  | foo
bar | bar  | bar
baz | baz  | baz

### 九、显示链接中带括号的图片
![][1]
[1]: http://latex.codecogs.com/gif.latex?\prod%20\(n_{i}\)+1

### 十、分割线
* * *
***
___

### 十一、代码区块
```java
		print ("I like jianshu! ")
```
###### 正常代码

```java
	// 是否有手势密码
	private boolean isHasGesture() {
		if (HiApplcation.getInstance().getUser() == null
				|| StringUtil.isEmpty(HiApplcation.getInstance().getUser()
						.getId()))
			return false;
		String gesture = SharedPreferencesUtil.getInstance(this)
				.loadStringSharedPreference(
						HiConfig.GESTURE_PWD
								+ HiApplcation.getInstance().getUser().getId());
		if (StringUtil.isNotEmpty(gesture)) {
			return true;
		} else
			return false;
	}
```
