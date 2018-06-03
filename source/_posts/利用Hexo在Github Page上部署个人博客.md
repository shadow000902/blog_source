---
title: 利用Hexo在Github Page上部署个人博客
date: 2016-03-18 00:06:40
categories: [Tools]
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

##### ``hexo generate``报错处理
```bash
# taoyi @ taoyi-mac in ~/git_projects/GitHub/blog_source on git:master x [18:11:36] 
$ hexo generate
(node:51431) [DEP0061] DeprecationWarning: fs.SyncWriteStream is deprecated.
INFO  Start processing
FATAL Something's wrong. Maybe you can find the solution here: http://hexo.io/docs/troubleshooting.html
Error: Cannot find module 'highlight.js/lib/languages/shell'
    at Function.Module._resolveFilename (module.js:555:15)
    at Function.Module._load (module.js:482:25)
    at Module.require (module.js:604:17)
    at require (internal/module.js:11:18)
    at loadLanguage (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/hexo/node_modules/hexo-util/lib/highlight.js:93:31)
    at tryLanguage (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/hexo/node_modules/hexo-util/lib/highlight.js:100:3)
    at highlight (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/hexo/node_modules/hexo-util/lib/highlight.js:136:8)
    at highlightUtil (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/hexo/node_modules/hexo-util/lib/highlight.js:22:14)
    at /Users/taoyi/git_projects/GitHub/blog_source/node_modules/hexo/lib/plugins/filter/before_post_render/backtick_code_block.js:62:15
    at String.replace (<anonymous>)
    at Hexo.backtickCodeBlock (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/hexo/lib/plugins/filter/before_post_render/backtick_code_block.js:15:31)
    at Hexo.tryCatcher (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/util.js:16:23)
    at Hexo.<anonymous> (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/method.js:15:34)
    at /Users/taoyi/git_projects/GitHub/blog_source/node_modules/hexo/lib/extend/filter.js:68:35
    at tryCatcher (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/util.js:16:23)
    at Object.gotValue (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/reduce.js:145:18)
    at Object.gotAccum (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/reduce.js:134:25)
    at Object.tryCatcher (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/util.js:16:23)
    at Promise._settlePromiseFromHandler (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/promise.js:502:31)
    at Promise._settlePromise (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/promise.js:559:18)
    at Promise._settlePromiseCtx (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/promise.js:596:10)
    at Async._drainQueue (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/async.js:143:12)
    at Async._drainQueues (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/async.js:148:10)
    at Immediate.Async.drainQueues [as _onImmediate] (/Users/taoyi/git_projects/GitHub/blog_source/node_modules/bluebird/js/release/async.js:17:14)
    at runCallback (timers.js:773:18)
    at tryOnImmediate (timers.js:734:5)
    at processImmediate [as _immediateCallback] (timers.js:711:5)
```

解决方法：安装``highlight.js``
```bash
npm install highlight.js
```

##### 解决``fs.SyncWriteStream``报错问题
调试找出问题出现点
```bash
# taoyi @ taoyi-mac in ~/git_projects/GitHub/blog_source on git:master x [18:57:19] 
$ hexo clean --debug                  
10:57:38.353 DEBUG Hexo version: 3.4.4
10:57:38.356 DEBUG Working directory: ~/git_projects/GitHub/blog_source/
10:57:38.577 DEBUG Config loaded: ~/git_projects/GitHub/blog_source/_config.yml
10:57:38.642 DEBUG Plugin loaded: hexo-algolia
10:57:38.644 DEBUG Plugin loaded: hexo-algoliasearch
10:57:38.779 DEBUG Plugin loaded: hexo-clean-css
10:57:38.792 DEBUG Plugin loaded: hexo-deployer-git
(node:55696) [DEP0061] DeprecationWarning: fs.SyncWriteStream is deprecated.
10:57:38.796 DEBUG Plugin loaded: hexo-fs
10:57:38.816 DEBUG Plugin loaded: hexo-cli
10:57:38.824 DEBUG Plugin loaded: hexo-generator-baidu-sitemap
10:57:38.829 DEBUG Plugin loaded: hexo-generator-archive
10:57:38.831 DEBUG Plugin loaded: hexo-generator-category
10:57:38.879 DEBUG Plugin loaded: hexo-generator-feed
10:57:38.881 DEBUG Plugin loaded: hexo-generator-index
10:57:38.882 DEBUG Plugin loaded: hexo-generator-tag
10:57:38.910 DEBUG Plugin loaded: hexo-generator-seo-friendly-sitemap
10:57:38.919 DEBUG Plugin loaded: hexo-html-minifier
10:57:38.922 DEBUG Plugin loaded: hexo-generator-sitemap
10:57:38.924 DEBUG Plugin loaded: hexo-renderer-ejs
10:57:38.948 DEBUG Plugin loaded: hexo-renderer-marked
10:57:38.976 DEBUG Plugin loaded: hexo-renderer-stylus
10:57:39.078 DEBUG Plugin loaded: hexo-server
10:57:39.170 DEBUG Plugin loaded: hexo-wordcount
10:57:39.177 DEBUG Script loaded: themes/next-5/scripts/tags/button.js
10:57:39.180 DEBUG Script loaded: themes/next-5/scripts/merge-configs.js
10:57:39.180 DEBUG Script loaded: themes/next-5/scripts/tags/center-quote.js
10:57:39.183 DEBUG Script loaded: themes/next-5/scripts/merge.js
10:57:39.183 DEBUG Script loaded: themes/next-5/scripts/tags/full-image.js
10:57:39.183 DEBUG Script loaded: themes/next-5/scripts/tags/label.js
10:57:39.184 DEBUG Script loaded: themes/next-5/scripts/tags/lazy-image.js
10:57:39.184 DEBUG Script loaded: themes/next-5/scripts/tags/note.js
10:57:39.185 DEBUG Script loaded: themes/next-5/scripts/tags/group-pictures.js
10:57:39.200 DEBUG Script loaded: themes/next-5/scripts/tags/exturl.js
10:57:39.201 DEBUG Script loaded: themes/next-5/scripts/tags/tabs.js
10:57:39.203 INFO  Deleted database.
10:57:39.205 DEBUG Database saved
```
由此可以看出，问题出现在``hexo-deployer-git``中，在其中搜索：
```bash
# taoyi @ taoyi-mac in ~/git_projects/GitHub/blog_source on git:master x [19:01:51] 
$ grep -irn "SyncWriteStream" ./node_modules/hexo-deployer-git/  
./node_modules/hexo-deployer-git//node_modules/hexo-fs/lib/fs.js:718:// exports.SyncWriteStream = fs.SyncWriteStream;
```
可以看到是``./node_modules/hexo-deployer-git//node_modules/hexo-fs/lib/fs.js``文件的第718行用到，直接编辑文件注释掉该行就可以解决问题，不会再报错了。
hexo命令中，可以通过``--debug``参数看下详细的运行记录，从而定位问题。


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

#### 文章加密
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

#### 文章字数统计
主要代码：
```bash
# 字数统计
<span class="post-count">{{ wordcount(post.content) }}</span>
# 阅读时长预计
<span class="post-count">{{ min2read(post.content) }}</span>
# 总字数统计
<span class="post-count">{{ totalcount(site, '0,0.0a') }}</span>
```

#### 增加文章的宽度
编辑``blog_source/themes/next/source/css/_variables/custom.styl``文件，加入如下代码：

```yaml
// 修改成你期望的宽度
$content-desktop = 800px
// 当视窗超过 1600px 后的宽度
$content-desktop-large = 1000px
```

#### 文本内容上色
```yaml
<span class="inline-span red">red</span>
<span class="inline-span blue">blue</span>
<span class="inline-span yellow">yellow</span>
<span class="inline-span green">green</span>
<span class="inline-span purple">purple</span>
```
示例：<span class="inline-span red">red</span>、<span class="inline-span blue">blue</span>、<span class="inline-span yellow">yellow</span>、<span class="inline-span green">green</span>、<span class="inline-span purple">purple</span>

#### 文本段落上色
编辑``blog_source/themes/next/source/css/_custom/custom.styl``文件，加入如下代码即可：

```styl
span.inline-span {
    display:inline;
    padding:.3em .4em;
    font-size:80%;
    font-weight:bold;
    line-height:1;
    color:#fff;
    text-align:center;
    white-space:nowrap;
    vertical-align:baseline;
    border-radius:.2em;
    margin: auto .5em;
}
span.yellow { 
    background-color: #f0ad4e;
}
span.green {
    background-color: #5cb85c;
}
span.blue {
    background-color: #2780e3;
}
span.purple {
    background-color: #9954bb;
}
span.red {
    background-color: #df3e3e;
}
div.div-border {   
    display: block;
    padding: 10px;
    margin: 10px 0;
    border: 1px solid #ccc;
    border-radius: 3px;
}
div.left-red {
    border-left-width: 5px;
    border-left-color: #df3e3e;
}
div.left-yellow {
    border-left-width: 5px;
    border-left-color: #f0ad4e;
}
div.left-green {
    border-left-width: 5px;
    border-left-color: #5cb85c;
}
div.left-blue {
    border-left-width: 5px;
    border-left-color: #2780e3;
}
div.left-purple {
    border-left-width: 5px;
    border-left-color: #9954bb;
}
div.right-red {
    border-right-width: 5px;
    border-right-color: #df3e3e;
}
div.right-yellow {
    border-right-width: 5px;
    border-right-color: #f0ad4e;
}
div.right-green {
    border-right-width: 5px;
    border-right-color: #5cb85c;
}
div.right-blue {
    border-right-width: 5px;
    border-right-color: #2780e3;
}
div.right-purple {
    border-right-width: 5px;
    border-right-color: #9954bb;
}
div.top-red {
    border-top-width: 5px;
    border-top-color: #df3e3e;
}
div.top-yellow {
    border-top-width: 5px;
    border-top-color: #f0ad4e;
}
div.top-green {
    border-top-width: 5px;
    border-top-color: #5cb85c;
}
div.top-blue {
    border-top-width: 5px;
    border-top-color: #2780e3;
}
div.top-purple {
    border-top-width: 5px;
    border-top-color: #9954bb;
}
```
示例：
<div class="div-border left-red">
这是边框带颜色的文本段落
位置可选: left | right | top
颜色可选: red | blue | yellow | green | purple
</div>

实现代码：
```markdown
<div class="div-border left-red">
这是边框带颜色的文本段落
位置可选: left | right | top
颜色可选: red | blue | yellow | green | purple
</div>
```

#### 解决``Hexo``中的``markdown``文档使用HTML标签多出空行的问题
```markdown
# 表格开始前加
{% raw %}
html tags & content
# 表格结尾后加
{% endraw %}
```

#### ``Next``主题使用``Algolia``搜索
Change dir to NexT directory, Install module to ``source/lib`` directory:
```bash
cd themes/next
git clone https://github.com/theme-next/theme-next-algolia-instant-search source/lib/algolia-instant-search
```
Enable module in NexT _config.yml file:
```bash
algolia_search:
  enable: true
```
Update:
```bash
cd themes/next/source/lib/algolia-instant-search
git pull
```

#### ``npm``第三方模块升级
局部模块管理
```bash
npm outdated        # 列出当前目录下的第三方模块
```

```bash
npm install hexo            # 升级当前目录下的hexo
```
该方法只能单个升级模块

``npm``高效升级插件``npm-check-updates``安装：
```bash
npm install -g npm-check-updates
```
使用：
```bash
ncu                         # 同``npm-check-updates``命令
```
返回结果：
```bash
$ ncu
Using /Users/taoyi/git_projects/GitHub/blog_source/package.json
⸨░░░░░░░░░░░░░░░░░░⸩ ⠴ :
 hexo-algolia                          ^0.1.1  →  ^1.2.5
 hexo-algoliasearch                    ^0.2.3  →  ^0.3.0
 hexo-clean-css                         0.0.2  →   0.0.3
 hexo-deployer-git                     ^0.1.0  →  ^0.3.1
 hexo-generator-seo-friendly-sitemap   0.0.19  →  0.0.21
 hexo-html-minifier                     0.0.1  →   0.0.2
 hexo-renderer-ejs                     ^0.2.0  →  ^0.3.1
 hexo-renderer-marked                 ^0.2.10  →  ^0.3.2
 hexo-server                           ^0.2.2  →  ^0.3.2

The following dependencies are satisfied by their declared version range, but the installed versions are behind. You can install the latest versions without modifying your package file by using npm update. If you want to update the dependencies in your package file anyway, run ncu -a.

 hexo-fs                       ^0.2.2  →  ^0.2.3
 hexo-generator-baidu-sitemap  ^0.1.1  →  ^0.1.2

Run ncu with -u to upgrade package.json
```
升级所有的包：
```bash
ncu -a
```