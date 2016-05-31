---
title: Appium踩过的坑
date: 2016-05-31 17:55:19
categories: [Appium]
tags: [appium]
---

1. 每次运行测试，app都会重新安装
1.1 在case里不要设置app的安装路径，只要设置``desired_caps['appPackage']``（app的包名）和``desired_caps['appActivity']``（启动时的activity）即可
1.2 在启动appium的时候，加上``--no-reset``参数

2. 等待操作
2.1 尽量不要使用sleep方法
2.2 使用``implicitly_wait(1000)``方法，**隐性等待/如果一个无素没有出现都会默认等待你所设定的时间，直到超时或者元素出现**

3. 元素无法定位
3.1 使用元素坐标点定位，有两种点击方法，一种是``tap([(100, 20), (100, 60), (100, 100)], 500)``，还有一种是使用``swipe(630, 320, 630, 320, 500)``方法
3.2 使用``class_name``来定位：
``` python
checkboxes = self.driver.find_elements_by_class_name('android.widget.CheckBox')     # 获取页面class_name为android.widget.CheckBox的所有元素，形成一个list
checkboxes[0].click()                                                               # 指定元素进行操作
checkboxes[1].click()                                                               # 指定元素进行操作
```

4. 长按操作
```
action1 = TouchAction(self.driver)
el_3 = self.driver.find_element_by_id('cn.highing.hichat:id/topic_voice_send')
action1.long_press(el_3).wait(10000).perform()
```

```
action2 = TouchAction(self.driver)
el_3 = self.driver.find_element_by_id('cn.highing.hichat:id/topic_voice_send')
action2.moveTo(el_3).release().perform()
```

5. 异常处理
```
if self.driver.current_activity == ".ui.GuideActivity":
    try:
        做x这件事
    except:
        x失败的话，做这里的事
```
