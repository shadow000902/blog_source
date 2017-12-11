---
title: Charles常用的九大功能
date: 2017-04-25 17:57:15
categories: [Tools]
tags: [charles]
---

##### 过滤网络请求
###### 方法一
在主界面的中部的 Filter 栏中填入需要过滤出来的关键字。
###### 方法二
在 Charles 的菜单栏选择 ``“Proxy”->”Recording Settings”``，然后选择 Include 栏，选择添加一个项目，然后填入需要监控的协议，主机地址，端口号。这样就可以只截取目标网站的封包了。

  <!--more-->

{% asset_img 过滤网络请求.png 过滤网络请求 %}

通常情况下，我们使用方法一做一些临时性的封包过滤，使用方法二做一些经常性的封包过滤。
###### 方法三
在想过滤的网络请求上右击，选择 “Focus”，之后在 Filter 一栏勾选上 Focussed 一项，这种方式可以临时性的，快速地过滤出一些没有通过关键字的一类网络请求。

##### 截取客户端上的网络请求
###### Charles上的设置
打开Charles代理功能。在 Charles 的菜单栏上选择 “Proxy”->”Proxy Settings”，填入代理端口 8888，并且勾上 “Enable transparent HTTP proxying” 就完成了在 Charles 上的设置
{% asset_img 打开Charles代理功能.png 打开Charles代理功能 %}

###### 客户端上设置网络代理
{% asset_img 客户端上代理设置.png 客户端上代理设置 %}

设置好之后，我们打开 客户端 上的任意需要网络通讯的程序，就可以看到 Charles 弹出 客户端 请求连接的确认菜单（如下图所示），点击 “Allow” 即可完成设置。
{% asset_img 同意请求.png 同意请求 %}

##### 抓取 Https 请求
###### 客户端安装证书
点击 Charles 的顶部菜单，选择 “Help” -> “SSL Proxying” -> “Install Charles Root Certificate on a Mobile Device or Remote Browser”
{% asset_img 安装证书链接.png 安装证书链接 %}
按照我们之前说的教程，在设备上设置好 Charles 为代理后，在手机浏览器中访问地址：chls.pro/ssl，即可打开证书安装的界面，安装完证书后，就可以截取手机上的 Https 通讯内容了。不过同样需要注意，默认情况下 Charles 并不做截取，你还需要在要截取的网络请求上右击，选择 SSL proxy 菜单项。
{% asset_img 要抓取HTTPS请求的域名.png 要抓取HTTPS请求的域名 %}
还可以直接在对应的 HTTPS 请求上右键，选择``Enable SSL Proxying``。


##### 模拟慢速网络
在做移动开发的时候，我们常常需要模拟慢速网络或者高延迟的网络，以测试在移动网络下，应用的表现是否正常。Charles 对此需求提供了很好的支持。
在 Charles 的菜单上，选择 “Proxy”->”Throttle Setting” 项，在之后弹出的对话框中，我们可以勾选上 “Enable Throttling”，并且可以设置 Throttle Preset 的类型。如下图所示：
{% asset_img 慢速网络设置.png 慢速网络设置 %}
如果我们只想模拟指定网站的慢速网络，可以再勾选上图中的 “Only for selected hosts” 项，然后在对话框的下半部分设置中增加指定的 hosts 项即可。

##### 压力测试
我们可以使用 Charles 的 Repeat 功能来简单地测试服务器的并发处理能力，方法如下。
我们在想打压的网络请求上（POST 或 GET 请求均可）右击，然后选择 「Repeat Advanced」菜单项，接着我们就可以在弹出的对话框中，选择打压的并发线程数以及打压次数，确定之后，即可开始打压。
{% asset_img 压力测试.png 压力测试 %}

##### 修改服务器返回内容
有些时候我们想让服务器返回一些指定的内容，方便我们调试一些特殊情况。例如列表页面为空的情况，数据异常的情况，部分耗时的网络请求超时的情况等。如果没有 Charles，要服务器配合构造相应的数据显得会比较麻烦。这个时候，使用 Charles 相关的功能就可以满足我们的需求。
根据具体的需求，Charles 提供了 Map 功能、 Rewrite 功能以及 Breakpoints 功能，都可以达到修改服务器返回内容的目的。这三者在功能上的差异是：
Map 功能适合长期地将某一些请求重定向到另一个网络地址或本地文件。
Rewrite 功能适合对网络请求进行一些正则替换。
Breakpoints 功能适合做一些临时性的修改。

##### Map 重定向功能
Charles 的 Map 功能分 Map Remote 和 Map Local 两种，顾名思义，Map Remote 是将指定的网络请求重定向到另一个网址请求地址，Map Local 是将指定的网络请求重定向到本地文件。
在 Charles 的菜单中，选择 “Tools”->”Map Remote” 或 “Map Local” 即可进入到相应功能的设置页面。
###### Map Remote
对于 Map Remote 功能，我们需要分别填写网络重定向的源地址和目的地址，对于不需要限制的条件，可以留空。
{% asset_img MapRemote.png MapRemote %}
###### Map Local
对于 Map Local 功能，我们需要填写的重定向的源地址和本地的目标文件。对于有一些复杂的网络请求结果，我们可以先使用 Charles 提供的 “Save Response…” 功能，将请求结果保存到本地（如下图所示），然后稍加修改，成为我们的目标映射文件。

##### Rewrite 功能
Rewrite 功能功能适合对某一类网络请求进行一些正则替换，以达到修改结果的目的。
{% asset_img RewriteRule.png RewriteRule %}
设置完后，每次请求到对应的值就会被替代。

##### Breakpoints 功能
上面提供的 Rewrite 功能最适合做批量和长期的替换，但是很多时候，我们只是想临时修改一次网络请求结果，这个时候，使用 Rewrite 功能虽然也可以达到目的，但是过于麻烦，对于临时性的修改，我们最好使用 Breakpoints 功能。
Breakpoints 功能类似我们在 Xcode 中设置的断点一样，当指定的网络请求发生时，Charles 会截获该请求，这个时候，我们可以在 Charles 中临时修改网络请求的返回内容。

###### breakpoints⭐️ 方法实践过程
在charless上要mock数据的url上右点击，弹出的列表选中breakpoint，要点击两次 Excute 才能完成一次 HTTP 请求，原因是，Charles 的断点功能分别提供了修改 HTTP Request 和 Response 的机会映射本地文件。
{% asset_img EditRequest.png EditRequest %}
{% asset_img EditResponse.png EditResponse %}
通过修改 response 就可以修改请求的结果成为自己想要的结果，从而在客户端上查看效果。
