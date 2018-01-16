---
title: Python中正则表达式的应用
date: 2018-01-11 17:36:53
categories: [Python]
tags: [正则表达式]
---

#### 简单字符串替换
```python
import re  
urlp = "http://www.mypcera.com/star/mm/jiepaimeinv/942{_page}.html&{what}&&{come}"
# 匹配出所有 {.*?} 的值，并取第一个匹配到的值
pageParam = re.findall('{.*?}', urlp)[0]  
# 输出结果：{_page}
print(pageParam)
# 匹配结果中的 page 替换为 3，并剔除匹配结果中的 {}
pageParam = pageParam.replace("page", "3").strip("{}")  
# 输出结果：_3
print(pageParam)  
# 对所有匹配到的结果进行替换操作
result = re.sub('{.*?}', pageParam, urlp)  
# 打印最后的结果：http://www.mypcera.com/star/mm/jiepaimeinv/942_3.html&_3&&_3
print(result)  
```

