---
title: Appium踩过的坑
date: 2016-05-31 17:55:19
categories: [Appium]
tags: [appium]
---

##### 每次运行测试，app都会重新安装
1.1 在case里不要设置app的安装路径，只要设置``desired_caps['appPackage']``（app的包名）和``desired_caps['appActivity']``（启动时的activity）即可
1.2 在启动appium的时候，加上``--no-reset``参数

  <!--more-->

##### 等待操作
2.1 尽量不要使用sleep方法
2.2 使用``implicitly_wait(1000)``方法，**隐性等待/如果一个无素没有出现都会默认等待你所设定的时间，直到超时或者元素出现**
2.3 ``WebDriverWait()``，同样也是 webdirver 提供的方法。**在设置时间内，默认每隔一段时间检测一次当前。页面元素是否存在，如果超过设置时间检测不到则抛出异常。**
```python
from selenium.webdriver.support.ui import WebDriverWait
element = WebDriverWait(driver, 10).until(lambda x: x.find_element_by_id(“someId”))
is_disappeared = WebDriverWait(driver, 30, 1, (ElementNotVisibleException)).
until_not(lambda x: x.find_element_by_id(“someId”).is_displayed())
```

##### 元素无法定位
3.1 使用元素坐标点定位，有两种点击方法，一种是``tap([(100, 20), (100, 60), (100, 100)], 500)``，还有一种是使用``swipe(630, 320, 630, 320, 500)``方法
3.2 使用``class_name``来定位：
```python
checkboxes = self.driver.find_elements_by_class_name('android.widget.CheckBox')     # 获取页面class_name为android.widget.CheckBox的所有元素，形成一个list
checkboxes[0].click()                                                               # 指定元素进行操作
checkboxes[1].click()                                                               # 指定元素进行操作
```

##### 长按操作
```python
action1 = TouchAction(self.driver)
el_3 = self.driver.find_element_by_id('cn.highing.hichat:id/topic_voice_send')
action1.long_press(el_3).wait(10000).perform()
```

```python
action2 = TouchAction(self.driver)
el_3 = self.driver.find_element_by_id('cn.highing.hichat:id/topic_voice_send')
action2.moveTo(el_3).release().perform()
```

##### 异常处理
```python
if self.driver.current_activity == ".ui.GuideActivity":
    try:
        做x这件事
    except:
        x失败的话，做这里的事
```
##### 断言


##### appium运行结果报告


##### ``appium``设置不使用``appium``只带的输入法
```python
des.setCapability("unicodeKeyboard", "True")
des.setCapability("resetKeyboard", "True")
```

##### 一定不要搞错启动``activity``
启动时的``activity``一般都是叫``SplashActivity``
```python
def setUp(self):
    desired_caps = {}
    desired_caps['platformName'] = 'Android'
    desired_caps['platformVersion'] = '6.0'
    desired_caps['deviceName'] = 'Nexus 5'
    desired_caps['appPackage'] = 'com.souche.fengche'  # 被测App的包名
    desired_caps['appActivity'] = 'com.souche.fengche.ui.activity.SplashActivity'  # 启动时的Activity
    # desired_caps['app'] = PATH('/Users/taoyi/Downloads/dasouche.apk')
```

##### 拖动操作解析
```java
public void DragAndDrop(By dragElement, By dropElement)
```
``dragElement`` *起点元素，不要用输入框，尽量用不可点击的显示型元素*
``dropElement`` *终点元素，不要用输入框，尽量用不可点击的显示型元素*

##### 滑动操作
```python
def swipe_to_up(self):
    """
    从下往上滑动
    :return: None
    """
    window_size = self.get_size()
    width = window_size.get("width")
    height = window_size.get("height")
    self.driver.swipe(width / 2, height * 3 / 4, width / 2, height / 4, 500)
```

```java
public void SwipeToUp(int during) {
	int width = driver.manage().window().getSize().width;
	int height = driver.manage().window().getSize().height;
	driver.swipe(width / 2, height * 3 / 4, width / 2, height / 4, during);
	logger.info("向上滑动屏幕的3/4");
}
```

##### ``Appium``（客户端版）解决每次运行``Android``，都安装``Appium Setting``和``Unlock``的方法
同 “Appium的几点总结” 的``六``
``Appium Setting``安装包路径：
```
/usr/local/lib/node_modules/appium/node_modules/appium-android-driver/node_modules/io.appium.settings/bin/settings_apk-debug.apk
```
``Unlock``安装包路径：
```
/usr/local/lib/node_modules/appium/node_modules/appium-android-driver/node_modules/appium-unlock/bin/unlock_apk-debug.apk
```
解决方法，修改下面两个文件
文件1地址：
``` bash
/usr/local/lib/node_modules/appium/node_modules/appium-android-driver/lib/android-helpers.js
```
文件位置：
``` js
helpers.initDevice = async function (adb, opts) {
  await adb.waitForDevice();

  await helpers.ensureDeviceLocale(adb, opts.language, opts.locale);
  await adb.startLogcat();
  let defaultIME;
  if (opts.unicodeKeyboard) {
    defaultIME = await helpers.initUnicodeKeyboard(adb);
  }
//  await helpers.pushSettingsApp(adb);                                         # 注释掉
//  await helpers.pushUnlock(adb);                                              # 注释掉
  return defaultIME;
};
```
文件2地址：
``` bash
/usr/local/lib/node_modules/appium/node_modules/appium-android-driver/build/lib/android-helpers.js
```
文件位置：
``` js
helpers.initDevice = function callee$0$0(adb, opts) {
  var defaultIME;
  return _regeneratorRuntime.async(function callee$0$0$(context$1$0) {
    while (1) switch (context$1$0.prev = context$1$0.next) {
      case 0:
        context$1$0.next = 2;
        return _regeneratorRuntime.awrap(adb.waitForDevice());

      case 2:
        context$1$0.next = 4;
        return _regeneratorRuntime.awrap(helpers.ensureDeviceLocale(adb, opts.language, opts.locale));

      case 4:
        context$1$0.next = 6;
        return _regeneratorRuntime.awrap(adb.startLogcat());

      case 6:
        defaultIME = undefined;

        if (!opts.unicodeKeyboard) {
          context$1$0.next = 11;
          break;
        }

        context$1$0.next = 10;
        return _regeneratorRuntime.awrap(helpers.initUnicodeKeyboard(adb));

      case 10:
        defaultIME = context$1$0.sent;

      case 11:
        context$1$0.next = 13;
        return _regeneratorRuntime.awrap(helpers.pushSettingsApp(adb));
        // return context$1$0.abrupt('return', defaultIME);                     # 添加新的 return，相当于跳过该步骤

      case 13:
        context$1$0.next = 15;
        return _regeneratorRuntime.awrap(helpers.pushUnlock(adb));
        // return context$1$0.abrupt('return', defaultIME);                     # 添加新的 return，相当于跳过该步骤

      case 15:
        return context$1$0.abrupt('return', defaultIME);

      case 16:
      case 'end':
        return context$1$0.stop();
    }
  }, null, this);
};
```
