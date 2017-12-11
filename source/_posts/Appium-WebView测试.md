---
title: Appium-WebView测试
date: 2016-11-21 01:07:09
categories: [Appium]
tags: [appium, webview]
---
现在多数App都是混合型的，有原生的也包含WebView的，appium测试的时候就需要在原生和WebView之间切换才能完成测试。

##### 查看所有context
```java
Set<String> contextNames = driver.getContextHandles();
System.print(contextNames);
```

  <!--more-->

结果包含目前所有打开的app
```java
[NATIVE_APP, WEBVIEW_com.test.android, WEBVIEW_com.estrongs.android.pop, WEBVIEW_com.xxxxx.sjj]
```

NATIVE_APP就是我的被测应用原生界面
WEBVIEW_com.test.android 是我的被测应用打开的WebView
另外两个一个是ES， 一个其他的应用（混合型的）

##### 切换到WebView
我们可以通过context方法切换到指定的应用
```java
<pre name="code" class="java">driver.context("WEBVIEW_com.test.android");
driver.findElementByID("wd");
```
切换完成后就可以像测试web应用一样测试了，所有的定位和web相同。

##### 切换到NativeApp
测试完web应用，需要操作原生应用的时候就需要切换回NATIVE_APP
我们可以通过context方法切换到原生应用
```java
<pre name="code" class="java">driver.context("NATIVE_APP");
```
这样之后的操作就都是原生应用的操作了

##### DEMO
```java
    /**
     * Switch to NATIVE_APP or WEBVIEW
     * @param sWindow window name
     */
    private void switchToWindow(String sWindow) {
        LogManager.getLogger(this.getClass()).info("Swith to window: " + sWindow);
        Set<String> contextNames = driver.getContextHandles();
        LogManager.getLogger(this.getClass()).info("Exists windows: " + contextNames.toString());
        for (String contextName : contextNames) {
            if (contextName.contains(sWindow)) {
                driver.context(contextName);
                break;
            }
        }
    }

switchToWindow("WEBVIEW_com.test.android");
switchToWindow("NATIVE_APP");
```
