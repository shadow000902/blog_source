---
title: Appium的几点总结
date: 2016-07-01 00:28:20
categories: [Appium]
tags: [appium]
---

#### 建立session时常用命令
```python
DesiredCapabilities cap = new DesiredCapabilities();
cap.SetCapability("browserName", "");                                                           // web 浏览器名称（'Safari' ,'Chrome'等）。如果对应用进行自动化测试，这个关键字的值应为空。
cap.SetCapability("platformName", "Android");                                                   //你要测试的手机操作系统
cap.SetCapability("platformVersion", "4.4");                                                    //手机操作系统版本
cap.SetCapability("automationName", "selendroid");                                              //你想使用的自动化测试引擎：Appium (默认) 或 Selendroid
cap.SetCapability("deviceName", " Android Emulator");                                           //使用的手机类型或模拟器类型，真机时输入Android Emulator或者手机型号
cap.SetCapability("udid", udid);                                                                //连接的物理设备的唯一设备标识,Android可以不设置

cap.SetCapability("newCommandTimeout", "300");                                                  //设置收到下一条命令的超时时间,超时appium会自动关闭session ,默认60秒
cap.SetCapability("unicodeKeyboard", "True");                                                   //支持中文输入，会自动安装Unicode 输入法。默认值为 false
cap.SetCapability("resetKeyboard", "True");                                                     //在设定了 unicodeKeyboard 关键字的 Unicode 测试结束后，重置输入法到原有状态

cap.SetCapability("'app'", "D:\\AndroidAutomation\\AndroidAutoTest\\app\\zhongchou.apk");       //未安装应用时，设置app的路径

//手机已安装app，直接从手机启动app，上面路径不设置
cap.SetCapability("appPackage", "com.nbbank");                                                  //你要启动的Android 应用对应的Activity名称|比如`MainActivity`, `.Settings`|
cap.SetCapability("appActivity", "com.nbbank.ui.ActivityShow");                                 //你想运行的Android应用的包名
cap.SetCapability("appWaitActivity", "com.nbbank.ui.ActivityLogo");                             //你想要等待启动的Android Activity名称|比如`SplashActivity`|

Uri serverUri = new Uri("http://127.0.0.1:4723/wd/hub");
driver = new AndroidDriver<IWebElement>(serverUri, cap, TimeSpan.FromSeconds(180));
```

  <!--more-->

#### driver常用方法及注意事项
##### 常用方法
```python
driver.HideKeyboard();                                                                  //隐藏键盘
driver.BackgroundApp(60);                                                               //60秒后把当前应用放到后台去
driver.LockDevice(3);                                                                   //锁定屏幕

//在当前应用中打开一个 activity 或者启动一个新应用并打开一个 activity
driver.StartActivity("com.iwobanas.screenrecorder.pro", "com.iwobanas.screenrecorder.RecorderActivity");
driver.OpenNotifications();                                                             //打开下拉通知栏 只能在 Android 上使用
driver.IsAppInstalled("com.example.android.apis-");                                     //检查应用是否已经安装
driver.InstallApp("path/to/my.apk");                                                    //安装应用到设备中去
driver.RemoveApp("com.example.android.apis");                                           //从设备中删除一个应用
driver.ShakeDevice();                                                                   //模拟设备摇晃
driver.CloseApp();                                                                      //关闭应用
driver.LaunchApp();                                                                     //根据服务关键字 (desired capabilities) 启动会话 (session) 。请注意这必须在设定 autoLaunch=false 关键字时才能生效。这不是用于启动指定的 app/activities
driver.ResetApp();                                                                      //应用重置
driver.GetContexts();                                                                   //列出所有的可用上下文
driver.GetContext();                                                                    //列出当前上下文
driver.SetContext("name");                                                              //将上下文切换到默认上下文
driver.GetAppStrings();                                                                 //获取应用的字符串
driver.KeyEvent(176);                                                                   //给设备发送一个按键事件:keycode
driver.GetCurrentActivity();                                                            //获取当前 activity。只能在 Android 上使用
//driver.Pinch(25, 25);                                                                 //捏屏幕 (双指往内移动来缩小屏幕)
//driver.Zoom(100, 200);                                                                //放大屏幕 (双指往外移动来放大屏幕)
driver.PullFile("Library/AddressBook/AddressBook.sqlitedb");                            //从设备中拉出文件
driver.PushFile("/data/local/tmp/file.txt", "some data for the file");                  //推送文件到设备中去

driver.FindElement(By.Name(""));
driver.FindElementById("id");
driver.FindElementByName("text");
driver.FindElementByXPath("//*[@name='62']");
```

##### 注意事项
使用driver.Sendkeys(string str)向文本框输入内容前，最好先element.Click( )一下，否则某些情况下,输入的内容会请不掉，文本框提示的内容也会在 输入的文本前显示出来。sendkey方法在发送数据之前会清空一下文本框，一般不需要Clear，如前面的情况Clear后仍是存在的，click后正常

#### 等待页面加载策略
##### 显性等待：调用selenium的方法， 需要添加WebDriver.Support引用
    显性等待是指在代码进行下一步操作之前等待某一个条件的发生。最不好的情况是使用Thread.sleep()去设置一段确认的时间去等待。但为什么说最不好呢？因为一个元素的加载时间有长有短，你在设置sleep的时间之前要自己把握长短，太短容易超时，太长浪费时间。selenium webdriver提供了一些方法帮助我们等待正好需要等待的时间
```python
        WebDriverWait wait = new WebDriverWait(driver, TimeSpan.FromSeconds(10));
        element = wait.Until<IWebElement>((d) =>
        {
            return driver.FindElement(By.Id("userName"));
        });
```

##### 隐性等待：设置时间不易过长，设置为500或1000即可
    隐性等待是指当要查找元素，而这个元素没有马上出现时，告诉WebDriver查询Dom一定时间。默认值是0,但是设置之后，这个时间将在WebDriver对象实例整个生命周期都起作用。
```python
driver.Manage().Timeouts().ImplicitlyWait(TimeSpan.FromSeconds(1));
```

#### drive.KeyEvent(int )的使用：
可使用KeyEvent发送键盘数据，比如退格，Enter键等
```python
driver.KeyEvent(3);         //KEYCODE_HOME 按键Home 3
driver.KeyEvent(26);        //KEYCODE_POWER 电源键 26
driver.KeyEvent(67);        //KEYCODE_DEL 退格键 67
driver.KeyEvent(66);        //KEYCODE_ENTER 回车键
driver.KeyEvent(122);       //KEYCODE_MOVE_HOME 光标移动到开始
driver.KeyEvent(123);       //KEYCODE_MOVE_END 光标移动到末尾
```

#### 坐标操作
为防止不同手机分辨率不同带来的影响，要避免使用固定的坐标，可以用以下方式获取元素的坐标
```python
double Screen_X = driver.Manage().Window.Size.Width;                    //获取手机屏幕宽度
double Screen_Y = driver.Manage().Window.Size.Height;                   //获取手机屏幕高度
double startX = element.Location.X;                                     //获取元素的起点坐标，即元素最左上角点的横坐标
double startY = element.Location.Y;                                     //获取元素的起点坐标，即元素最左上角点的纵坐标
double elementWidth = element.Size.Width;                               //获取元素的宽度
double elementHight = element.Size.Height;                              //获取元素的宽度
```

在封装“滑动”、“ TouchAction”等操作时可以用以上方法来获取坐标进行操作。

**示例：分装两个元素之间的滑动**
```python
        IWebElement elmentA = null;
        IWebElement elmentB = null;
        int startX = 0, startY = 0, endX = 0, endY = 0;
        int duration=0,time=0;
        /// <summary>
        /// 从元素A的位置滑动到元素B的位置
        /// </summary>
        /// <param name="A">元素A的名称</param>
        /// <param name="B">元素B的名称</param>
        /// <param name="sDuration">滑动持续时间</param>
        /// <param name="sTime">滑动次数</param>
        public void SwipeAToB(string A, string B,string sDuration,string sTime)
        {
            startX = elmentA.Location.X + elmentA.Size.Width / 2;                           //元素A的中心横坐标
            startY = elmentA.Location.Y + elmentA.Size.Height / 2;                          //元素A的中心纵坐标
            endX = elmentB.Location.X + elmentB.Size.Width / 2;                             //元素B的中心横坐标
            endY = elmentB.Location.Y + elmentB.Size.Height / 2;                            //元素B的中心纵坐标

            duration = string.IsNullOrEmpty(sDuration) ? 1500 : int.Parse(sDuration);       //持续时间为空时，默认设置为1500毫秒
            time = string.IsNullOrEmpty(sTime) ? 1500 : int.Parse(sTime);                   //滑动次数为空时，默认设置为滑动1次

            for (int i = 0; i < time; i++)
            {
                driver.Swipe(startX, startY, endX, endY, duration);
            }
        }
```
注意：element.Loaction和element.Size,每次获取时都会重新去手机里获取，为节省时间如果有获取相同值的，建议储存成变量。

#### 取消重新安装unlock和setting
注销如下代码：
```python
Appium\node_modules\appium\lib\devices\android\android.js
```

```python
async.series([
    this.initJavaVersion.bind(this),
    this.initAdb.bind(this),
    this.packageAndLaunchActivityFromManifest.bind(this),
    this.initUiautomator.bind(this),
    this.prepareDevice.bind(this),
    this.checkApiLevel.bind(this),
    this.pushStrings.bind(this),
    this.processFromManifest.bind(this),
    this.uninstallApp.bind(this),
    this.installAppForTest.bind(this),
    this.forwardPort.bind(this),
    this.pushAppium.bind(this),
    this.initUnicode.bind(this),

    // DO NOT push settings app and unlock app
    //this.pushSettingsApp.bind(this),
    //this.pushUnlock.bind(this),

    function (cb) {this.uiautomator.start(cb);}.bind(this),
    this.wakeUp.bind(this),
    this.unlock.bind(this),
    this.getDataDir.bind(this),
    this.setupCompressedLayoutHierarchy.bind(this),
    this.startAppUnderTest.bind(this),
    this.initAutoWebview.bind(this),
    this.setActualCapabilities.bind(this)
  ])
```

#### 一台Mac电脑同时跑多个IOS appium服务

```python
iOS appium A服务：appium -p 4723 --tmp /tmp/tmp4723
iOS appium B服务：appium -p 4724 --tmp /tmp/tmp4724
```
注意：tmp参数必不可少，否则会出现跑脚本时不断切换服务器切换不到另外一台服务器的问题

#### Android appium服务器执行自动化脚本一个多小时总是报FATAL ERROR: CALL_AND_RETRY_LAST Allocation failed - process out of memory内存溢出
通过调整\Appium\node_modules.bin\appium.cmd中的--max-old-space-size内存限制大小参数值
```
@IF EXIST "%~dp0\node.exe" (
  "%~dp0\node.exe"  "%~dp0\..\appium\bin\appium.js" %*
) ELSE (
  node --max-old-space-size=2047 --gc-global  "%~dp0\..\appium\bin\appium.js" %*
)
```
注：--max-old-space-size参数值设置超过2047，如2048启动appium服务器也会报FATAL ERROR: CALL_AND_RETRY_LAST Allocation failed - process out of memory
查看了相关资料，原来是Node V8做了内存限制，限制了JavaScript所能使用的内存（64位为1.9GB，32位为1GB），暂时还不明白它为啥要做此限制。
