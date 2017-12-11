---
title: Appium-Python各种元素定位及操作方法解析
date: 2016-03-27 16:39:50
categories: [Appium]
tags: [appium, python]
---

#### 元素定位方法    # /site-packages/selenium/webdriver/remote/webdriver.py

##### 通过id定位元素
```python
find_element_by_id(self, id_)                       # Usage: driver.find_element_by_id('foo')
find_elements_by_id(self, id_)                      # Usage: driver.find_elements_by_id('foo')
```

  <!--more-->

##### 通过xpath(相对路径)定位元素
```python
find_element_by_xpath(self, xpath)                  # Usage: driver.find_element_by_xpath('//div/td[1]')
find_elements_by_xpath(self, xpath)                 # Usage: driver.find_elements_by_xpath("//div[contains(@class, 'foo')]")
```
##### 通过link_text定位元素
```python
find_element_by_link_text(self, link_text)          # Usage: driver.find_element_by_link_text('Sign In')
find_elements_by_link_text(self, link_text)         # Usage: driver.find_elements_by_link_text('Sign In')
```
##### 通过partial_link_text定位元素
```python
find_element_by_partial_link_text(self, link_text)  # Usage: driver.find_element_by_partial_link_text('Sign')
find_elements_by_partial_link_text(self, link_text) # Usage: driver.find_elements_by_partial_link_text('Sign')
```
##### 通过name定位元素（被accessibility_id替代）
```python
find_element_by_name(self, name)                    # Usage: driver.find_element_by_name('foo')
find_elements_by_name(self, name)                   # Usage: driver.find_elements_by_name('foo')
```
##### 通过accessibility_id定位元素
```python
find_element_by_accessibility_id(self, id)          # Usage: driver.find_element_by_accessibility_id('id')
find_elements_by_accessibility_id(self, id)         # Usage: driver.find_elements_by_accessibility_id('id')
```
##### 通过tag_name定位元素（被class_name替代）
```python
find_element_by_tag_name(self, name)                # Usage: driver.find_element_by_tag_name('foo')
find_elements_by_tag_name(self, name)               # Usage: driver.find_elements_by_tag_name('foo')
```
##### 通过class_name定位元素
```python
find_element_by_class_name(self, name)              # Usage: driver.find_element_by_class_name('foo')
find_elements_by_class_name(self, name)             # Usage: driver.find_elements_by_class_name('foo')
```
##### 通过css_selector定位元素
```python
find_element_by_css_selector(self, css_selector)    # Usage: driver.find_element_by_css_selector('#foo')
find_elements_by_css_selector(self, css_selector)   # Usage: driver.find_elements_by_css_selector('#foo')
```
##### 截取当前窗口的截图，如果有写入错误会返回False，其它返回True
```python
get_screenshot_as_file(self, filename)              # Usage: driver.get_screenshot_as_file('c:/foo.png')
```
##### 获取当前屏幕的分辨率（长和宽）
```python
get_window_size(self, windowHandle='current')       # Usage: driver.get_window_size()
```
##### 获取当前页面的网址
```python
current_url(self)                                   # Usage: driver.current_url
```
##### 获取当前页面的源
```python
page_source(self)                                   # driver.page_source
```
##### 关闭当前窗口
```python
close(self)                                         # driver.close()
```
##### 退出脚本运行并关闭每个相关的窗口连接
```python
quit(self)                                          # driver.quit()
```
##### 切换webview与native
```python
driver.switch_to.context("WEBVIEW")
```

#### 操作        # python-client/appium/webdriver/webdriver.py
##### 从元素origin_el滚动至元素destination_el
```python
scroll(self, origin_el, destination_el)                                 # Usage: driver.scroll(el1, el2)
```
##### 将元素origin_el拖到目标元素destination_el
```python
drag_and_drop(self, origin_el, destination_el)                          # Usage: driver.drag_and_drop(el1,el2)
```
##### 模拟手指点击（最多五个手指），可设置按住时间长度（毫秒）
```python
tap(self, positions, duration=None)                                     # Usage: driver.tap([(x,y),(x1,y1),(x2,y2)],500)
```
##### 从A点滑动至B点，滑动时间为毫秒
```python
swipe(self, start_x, start_y, end_x, end_y, duration=None)              # Usage: driver.swipe(x1,y1,x2,y2,500)
```
##### 按住A点后快速滑动至B点
```python
flick(self, start_x, start_y, end_x, end_y)                             # Usage: driver.flick(100, 100, 100, 400)
```
##### 在元素上执行模拟双指捏（缩小操作）
```python
pinch(self, element=None, percent=200, steps=50)                        # Usage: driver.pinch(element)
```
##### 在元素上执行放大操作
```python
zoom(self, element=None, percent=200, steps=50)                         # Usage: driver.zoom(element)
```
##### 重置应用（类似删除应用数据）
```python
reset(self)                                                             # Usage: driver.reset()
```
##### 隐藏键盘,iOS使用key_name隐藏，安卓不使用参数
```python
hide_keyboard(self, key_name=None, key=None, strategy=None)             # Usage: driver.hide_keyboard()
```
##### 发送按键码（安卓仅有），按键码可以上[网址](http://developer.android.com/reference/android/view/KeyEvent.html)中找到
```python
keyevent(self, keycode, metastate=None)                                 # Usage: driver.keyevent('4')
```
##### 发送按键码（安卓仅有），按键码可以上[网址](http://developer.android.com/reference/android/view/KeyEvent.html)中找到
```python
press_keycode(self, keycode, metastate=None)                            # Usage: driver.press_keycode('4')
```
##### 发送一个长按的按键码（长按某键）
```python
long_press_keycode(self, keycode, metastate=None)                       # Usage: driver.long_press_keycode(4)
```
##### 获取当前的activity
```python
current_activity(self)                                                  # Usage: print(driver.current_activity)
```
##### 等待指定的activity出现直到超时，interval为扫描间隔1秒；即每隔几秒获取一次当前的activity；返回的True 或 False
```python
wait_activity(self, activity, timeout, interval=1)                      # Usage: driver.wait_activity('.activity.xxx',5,2)
```
##### 后台运行app多少秒
```python
background_app(self, seconds)                                           # Usage: driver.background_app(5)   置后台5秒后再运行
```
##### 检查app是否有安装
```python
is_app_installed(self, bundle_id)                                       # Usage: driver.is_app_installed("com.xxxx")
```
##### 安装app,app_path为安装包路径
```python
install_app(self, app_path)                                             # Usage: driver.install_app(app_path)
```
##### 删除app
```python
remove_app(self, app_id)                                                # Usage: driver.remove_app("com.xxx.")
```
##### 启动app
```python
launch_app(self)                                                        # Usage: driver.launch_app()
```
##### 关闭app
```python
close_app(self)                                                         # Usage: driver.close_app()
```
##### 在测试过程中打开任意活动。如果活动属于另一个应用程序，该应用程序的启动和活动被打开。
```python
start_activity(self, app_package, app_activity, **opts)                 # Usage: driver.start_activity(app_package, app_activity)
```
##### 摇一摇手机
```python
shake(self)                                                             # Usage: driver.shake()
```
##### 打系统通知栏（仅支持API 18 以上的安卓系统）
```python
open_notifications(self)                                                # Usage: driver.open_notifications()
```
##### 返回网络类型  数值
```python
network_connection(self)                                                # Usage: driver.network_connection
```
##### 设置网络类型
```python
set_network_connection(self, connectionType)                            # Usage: dr.set_network_connection(ConnectionType.WIFI_ONLY)  //from appium.webdriver.connectiontype import ConnectionType
```
##### 打开安卓设备上的位置定位设置
```python
toggle_location_services(self)                                          # Usage: driver.toggle_location_services()
```
##### 设置设备的经纬度
```python
set_location(self, latitude, longitude, altitude)                       # Usage: driver.set_location(纬度，经度，高度)
```

#### 安卓输入法操作
##### 返回安卓设备可用的输入法
```python
available_ime_engines(self)                                             # Usage: print(driver.available_ime_engines)
```
##### 检查设备是否有输入法服务活动。返回真/假。
```python
is_ime_active(self)                                                     # Usage: print(driver.is_ime_active())
```
##### 激活安卓设备中的指定输入法，设备可用输入法可以从“available_ime_engines”获取
```python
activate_ime_engine(self, engine)                                       # Usage: driver.activate_ime_engine(“com.android.inputmethod.latin/.LatinIME”)
```
##### 关闭安卓设备当前的输入法
```python
deactivate_ime_engine(self)                                             # Usage: driver.deactivate_ime_engine()
```
##### 返回当前输入法的包名
```python
active_ime_engine(self)                                                 # Usage: driver.active_ime_engine
```
