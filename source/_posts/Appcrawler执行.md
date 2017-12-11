---
title: Appcrawler执行
date: 2016-07-19 16:38:41
categories: [Tools]
tags: [appcrawler]
---

##### 启动Appium服务器
```bash
TaoYi-Mac:~ taoyi$  appium --session-override -p 4730 --no-reset
```

  <!--more-->

##### 运行appcrawler，执行测试
```bash
TaoYi-Mac:appcrawler taoyi$ java -jar appcrawler-1.2.1.jar -a /usr/local/TestGroupCode/appcrawler/fengche.apk
```

如果APP的包名和启动时的Activity无法自动识别的话，需要手动指定
```bash
TaoYi-Mac:appcrawler taoyi$ java -jar appcrawler-1.2.1.jar -a /usr/local/TestGroupCode/appcrawler/fengche.apk --capability appPackage=com.souche.fengche,appActivity=com.souche.fengche.ui.activity.SplashActivity
```

使用配置文件
```bash
-c /usr/local/TestGroupCode/appcrawler/fengche_profile.yml
```

帮助文档
```bash
Usage: appcrawler [options]

  -a, --app <value>        Android或者iOS的文件地址, 可以是网络地址, 赋值给appium的app选项
  -c, --conf <value>       配置文件地址
  -p, --platform <value>   平台类型android或者ios, 默认会根据app后缀名自动判断
  -t, --maxTime <value>    最大运行时间. 单位为秒. 超过此值会退出. 默认最长运行3个小时
  -u, --appium <value>     appium的url地址
  -o, --output <value>     遍历结果的保存目录. 里面会存放遍历生成的截图, 思维导图和日志
  --capability k1=v1,k2=v2...
                           appium capability选项, 这个参数会覆盖-c指定的配置模板参数, 用于在模板配置之上的参数微调
  -r, --report <value>     输出html和xml报告
  --template <value>       输出代码模板
  --master <value>         master的diff.yml文件地址
  --candidate <value>      candidate环境的diff.yml文件
  --diff                   执行diff对比
  -vv, --verbose           是否展示更多debug信息
  --help                   
示例
appcrawler -a xueqiu.apk
appcrawler -a xueqiu.apk --capability noReset=true
appcrawler -c conf/xueqiu.json -p android -o result/
appcrawler -c xueqiu.json --capability udid=[你的udid] -a Snowball.app
appcrawler -c xueqiu.json -a Snowball.app -u 4730
appcrawler -c xueqiu.json -a Snowball.app -u http://127.0.0.1:4730/wd/hub

#启动已经安装过的app
appcrawler --capability appPackage=com.xueqiu.android,appActivity=.welcomeActivity

#从已经结束的结果中重新生成报告
appcrawler --report result/

#新老版本对比
appcrawler --candidate result/ --master pre/ --report ./

#自动生成Page Object代码模板文件
appcrawler --template PageObjectDemo.ssp --output result/

#根据wda的inspector生成测试用例代码
appcrawler --template PageObjectDemo.ssp -u http://localhost:8100

```