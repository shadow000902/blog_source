---
title: 利用Hexo在Github Page上部署个人博客
date: 2016-03-18 00:06:40
categories: [Hexo]
tags: [hexo, github]
---

#### 准备工作
1. 安装node.js
2. 安装git客户端
3. 安装github for windows客户端
4. 安装hexo框架

<!--more-->

#### 开始安装
##### 创建一个hexo安装目录，比如：E:/hexo
##### 安装hexo框架
``` bash
npm install -g hexo
cd E:/hexo
hexo init
npm install
```
##### 在本地查看博客
``` bash
hexo server
```
现在用浏览器访问：http://localhost:4000/，效果如下图

{% asset_img 默认模板效果.jpg 默认模板效果 %}

如果要停止 hexo 服务：在 Git Bash 下按 Ctrl + C 即可

##### 安装next主题
在E:/hexo下，打开git bash，
``` bash
git clone https://github.com/MOxFIVE/hexo-theme-next.git themes/next
```
##### 应用next主题
在E:/hexo下，打开_config.yml，修改：
``` bash
theme: landscape    ->
theme: next
```
##### 重新生成静态网页
``` bash
hexo generate
```
#### 创建 Github pages 并 SSH 授权
1. 创建名为 **shadow000902**.github.io的新的仓库（repository），**shadow000902** 必须为自己的用户名
2. 在本地生成SSH密钥，用于提交本地代码到github上：
``` bash
ssh-keygen -t rsa -C "shadow000902@gmail.com"
```
3. 默认密钥生成后,存放于C:/Users/shadow/.ssh/中，打开id_rsa.pub文件，复制其中的所有内容
4. 在自己创建的shadow000902.github.io仓库的setting中，打开Deploy keys, 点击add deploy key，把刚才复制的内容黏贴进去保存，Title任意取

#### 上传本地博客内容到github上
``` bash
npm install hexo -server --save
npm install hexo-deployer-git --save
```

#### 更新博客
``` bash
hexo clean          # 清楚本地静态网页public文件夹
hexo generate       # 重新生成静态网页
hexo deploy         # 部署本地静态网页到github上，以便在shadow000902.github.io域名下访问
```

#### 绑定域名
1. 在E:/hexo/source下新建一个CNAME文件，把自己申请的域名（比如我申请的：shadow000902.space）填写在该文件里保存
2. 在[DNSPOD](https://www.dnspod.cn/)网站里，设置域名解析：
{% asset_img 设置域名解析.png 设置域名解析 %}
3. 修改域名提供商下的域名DNS服务器为github提供的DNS：
{% asset_img 修改域名提供商下的域名DNS服务器.jpg 修改域名提供商下的域名DNS服务器 %}

#### 插件
##### 插件基本命令
1.1 安装插件：                                   npm install 插件名 --save
1.2 卸载插件：                                   npm uninstall 插件名 --save
1.3 更新插件和博客框架（需要在 E:\hexo 目录下）：     npm update
它实质上是通过项目根目录下 package.json 文件更新各大组件
##### 必备插件
2.1 支持RSS：			npm install hexo-generator-feed --save
2.2 生成站点地图：		npm install hexo-generator-sitemap --save
2.3 生成百度站点地图：		npm install hexo-generator-baidu-sitemap --save
~~2.4 HTML 压缩：		npm install hexo-html-minifier --save~~
~~2.5 JavaScript 压缩：	npm install hexo-uglify --save~~
~~2.6 CSS 压缩插件：		npm install hexo-clean-css --save~~
2.7 SEO优化：			npm install hexo-generator-seo-friendly-sitemap --save
2.8 文章字数统计			npm install hexo-wordcount --save

#### 统计功能
[为hexo博客添加访问次数统计功能](http://ibruce.info/2015/04/04/busuanzi/)

#### 附加
[Hexo你的博客](http://ibruce.info/2013/11/22/hexo-your-blog/)

#### 问题解决

##### 执行任何一条含``hexo``的命令都会报以下错误：
```
{ Error: Cannot find module './build/Release/DTraceProviderBindings'
    ...
    at Module.load (module.js:458:32) code: 'MODULE_NOT_FOUND' }
```
解决办法：
Try to install ``hexo`` with ``--no-optional`` option.

```
npm install -g hexo --no-optional --registry=https://registry.npm.taobao.org/
```

```
➜  blog_source git:(master) hexo -v
hexo: 3.2.2
hexo-cli: 1.0.2
os: Darwin 16.3.0 darwin x64
http_parser: 2.7.0
node: 6.9.0
v8: 5.1.281.84
uv: 1.9.1
zlib: 1.2.8
ares: 1.10.1-DEV
icu: 57.1
modules: 48
openssl: 1.0.2j
➜  blog_source git:(master)
```

##### 执行每条命令都会报以下错误：
```
➜  blog_source git:(master) ✗ hexo -v
ERROR Plugin load failed: hexo-generator-baidu-sitemap
ReferenceError: hexo is not defined
    at Object.<anonymous> (/usr/local/git_projects/blog_source/node_modules/hexo-generator-baidu-sitemap/baidusitemap.js:4:10)
    at Module._compile (module.js:541:32)
    at Object.Module._extensions..js (module.js:550:10)
    at Module.load (module.js:458:32)
    at tryModuleLoad (module.js:417:12)
    at Function.Module._load (module.js:409:3)
    at Module.require (module.js:468:17)
    at require (/usr/local/git_projects/blog_source/node_modules/hexo/lib/hexo/index.js:213:21)
    at /usr/local/git_projects/blog_source/node_modules/hexo-generator-baidu-sitemap/index.js:6:38
    at /usr/local/git_projects/blog_source/node_modules/hexo/lib/hexo/index.js:229:12
    at tryCatcher (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/util.js:16:23)
    at Promise._settlePromiseFromHandler (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/promise.js:502:31)
    at Promise._settlePromise (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/promise.js:559:18)
    at Promise._settlePromise0 (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/promise.js:604:10)
    at Promise._settlePromises (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/promise.js:683:18)
    at Promise._fulfill (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/promise.js:628:18)
    at Promise._resolveCallback (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/promise.js:423:57)
    at Promise._settlePromiseFromHandler (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/promise.js:514:17)
    at Promise._settlePromise (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/promise.js:559:18)
    at Promise._settlePromise0 (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/promise.js:604:10)
    at Promise._settlePromises (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/promise.js:683:18)
    at Promise._fulfill (/usr/local/git_projects/blog_source/node_modules/bluebird/js/release/promise.js:628:18)
```

解决方法：
``if your hexo version is 2.x.x, you should install as follow:``
```
npm install hexo-generator-baidu-sitemap@0.0.8 --save
```
``if your hexo version is 3.x.x, you should install as follow:``
```
npm install hexo-generator-baidu-sitemap@0.1.1 --save
```
``Maybe response is "hexo is not definded",then you should:``
```
cd node_modules/hexo-generator-baidu-sitemap/
npm install
```

##### ERROR Asset render failed: lib/canvas-ribbon/canvas-ribbon.js
这个错主要是安装了 JS 压缩的插件引起的
所以要做的就是卸载所有相关的插件。

##### 博客部署很慢的问题解决
这个还是 JS 压缩引起的。
所以主要做的还是卸载所有相关的插件：
```bash
npm uninstall hexo-uglify
npm uninstall uglify
npm uninstall uglify-js
```
卸载该插件后，60篇博客，部署时间大概在30s左右，generate时间在10~20s，比之前的5~6min好了不知道多少。

##### 文章加密
```javascript
<script>
	if("123456"==prompt("Please input password"))
	{
		alert("Right"); 
	}
	else
	{
		alert("Wrong"); 
		location="http://shadow000902.space";
	}
</script>
```

##### 文章字数统计
主要代码：
```bash
# 字数统计
<span class="post-count">{{ wordcount(post.content) }}</span>
# 阅读时长预计
<span class="post-count">{{ min2read(post.content) }}</span>
# 总字数统计
<span class="post-count">{{ totalcount(site, '0,0.0a') }}</span>
```
