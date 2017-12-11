---
title: Postman测试
date: 2016-04-18 15:29:14
categories: [Tools]
tags: [postman]
---

#### postman录制web接口请求
1. 在chrome中安装插件Interceptor，设置如图：

{% asset_img chrome中Interceptor设置.png chrome中Interceptor设置 %}

  <!--more-->

2. 在postman中设置如图：
{% asset_img Postman中Interceptor设置.png Postman中Interceptor设置 %}

3. 设置好之后，在chrome中请求接口，就会录制到postman的history中，如图：
{% asset_img 录制下的web请求.png 录制下的web请求 %}
录制好的请求就可以“save to collection”，以便后续测试使用。

#### postman基本功能
{% asset_img postman界面介绍.png postman界面介绍 %}
1. Collections：在Postman中，Collection类似文件夹，可以把同一个项目的请求放在一个Collection里方便管理和分享，Collection里面也可以再建文件夹。如果做API文档的话，可以每个API对应一条请求，如果要把各种输入都测到的话，就需要每条测试一条请求了。这里我新建了一个example用于介绍整个流程，五个API对应五条请求。这个Collection可以通过https://www.getpostman.com/collections/96b64a7c604072e1e4ee导入你自己的Postman中。
2. 上面的黑字注册是请求的名字，如果有Request description的话会显示在这下面。下面的蓝字是保存起来的请求结果，点击可以载入某次请求的参数和返回值。我会用这个功能给做客户端的同事展示不同情况下的各种返回值。保存请求的按钮在15.
3. 选择HTTP Method的地方，各种常见的不常见的非常全。
4. 请求URL，两层大括号表示这是一个环境变量，可以在16的位置选择当前的environment，环境变量就会被替换成该environment里variable的值。
5. 点击可以设置URL参数的key和value
6. 点击发送请求
7. 点击保存请求到Collection，如果要另存为的话，可以点击右边的下箭头
8. 设置鉴权参数，可以用OAuth之类的
9. 自定义HTTP Header，有些因为Chrome愿意不能自定义的需要另外装一个插件Interceptor，在16上面一行的卫星那里
10. 设置Request body，13那里显示的就是body的内容
11. 在发起请求之前执行的脚本，例如request body里的那两个random变量，就是每次请求之前临时生成的。
12. 在收到response之后执行的测试，测试的结果会显示在17的位置
13. 有四种形式可以选择，form-data主要用于上传文件。x-www-form-urlencoded是表单常用的格式。raw可以用来上传JSON数据
14. 返回数据的格式，Pretty可以看到格式化后的JSON，Raw就是未经处理的数据，Preview可以预览HTML页面
15. 点击这里把请求保存到2的位置
16. 设置environment variables和global variables，点击右边的x可以快速查看当前的变量。
17. 测试执行的结果，一共几个测试，通过几个。
这个界面就是免费版的主要内容，和其他API测试工具相比，已经足够好用。如果要使用自动化测试，需要购买9.99美金的Jetpacks，暂时不想购买的话可以试一下Team版Postman。现在是可以免费试用的，不但拥有Jetpacks的功能，还能与其他账户同步Collection。

#### 测试工具
测试工具主要包括三部分，在发起请求之前运行的Pre-request，在收到应答之后运行的Test，和一次运行所有请求的Collection Runner

##### Pre-request
{% asset_img Pre-request界面.png Pre-request界面 %}

Pre-request和Test用的语言都是JavaScript，Postman在一个沙盒里执行代码，提供给用户的库和函数可以在这里查看。而常用的功能都可以通过右边的Code Snippets实现，点击就可以插入到代码区域。
可以看到Pre-request里常用的功能就两种，（设置/清除）环境变量和全局变量。这条请求的pre-request就是在注册之前生成一个字符串作为随机用户名。
postman.setEnvironmentVariable("random_username", ("0000" + (Math.random()\*Math.pow(36,4) << 0).toString(36)).slice(-4));
其他用法还包括在发起请求之前获取当前的时间戳放在参数里：
postman.setEnvironmentVariable("unixtime_now", Math.round(newDate().getTime()/1000));
当然也可以用来生成校验串。总之，在发请求之前需要手动修改的东西，都可以考虑用脚本自动实现。

##### Test
{% asset_img Test界面.png Test界面 %}

和Pre-request相比，Test的Snippets就丰富多了，例如检查状态码、检查响应串、验证JSON、检查header、限制应答时间。
如果需要将服务器响应的数据保存下来，用在后面的请求里，也需要在这一步做。
在图中的Test里，我首先检查了状态码为200，然后解析返回的JSON，把环境变量里的token设为JSON里的token。

##### Collection Runner
当编写了很多测试之后，就可以使用Collection Runner来自动运行整个Collection了，入口就在主界面最上面一行的Runner。选好Collection、Environment，如果有需要还可以载入JSON和CSV作为数据源。点击Start Test Run，就可以看到结果了。
{% asset_img Collection-Runner界面.png Collection-Runner界面 %}

这里可以看到一共发起了5次请求，每个请求各有一个Test，全部Pass。（虽然最后一个请求的返回是403，但是这个请求的期望返回值就是403，所以也是Pass的）
***
P.S.postmanexample.sinaapp.com这个网站是真实存在的，可以Import我上传的Collection(https://www.getpostman.com/collections/96b64a7c604072e1e4ee)到你自己的Postman中，并设置环境变量url为http://postmanexample.sinaapp.com/index.php，就能运行这个Collection看效果了。

#### 导入及导出collection
postman中生成的测试用例集可以进行导入和导出操作，还能从别人分享的链接导入测试用例集。
##### 导出collection
在测试集文件夹的菜单按钮里，可以看到下载的按钮，还有分享按钮，分享会生成一条链接（https://www.getpostman.com/collections/6a0bf29198d978afa069）

##### 导入collection
{% asset_img 导入collection.png 导入collection %}
可以从文件导入，也可以从别人分享的链接导入测试用例集。
