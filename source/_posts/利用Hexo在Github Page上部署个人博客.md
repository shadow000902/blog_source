---
title: 利用Hexo在Github Page上部署个人博客
date: 2016-03-18 00:06:40
categories: [Hexo]
tags: [hexo, github]
---

### 一、准备工作
1. 安装node.js
2. 安装git客户端
3. 安装github for windows客户端
4. 安装hexo框架

<!--more-->

### 二、开始安装
4.1 创建一个hexo安装目录，比如：E:/hexo
4.2 安装hexo框架
``` bash
npm install -g hexo
cd E:/hexo
hexo init
npm install
```
4.3 在本地查看博客
``` bash
hexo server
```
现在用浏览器访问：http://localhost:4000/，效果如下图

{% asset_img 默认模板效果.jpg 默认模板效果 %}

如果要停止 hexo 服务：在 Git Bash 下按 Ctrl + C 即可

4.4 安装next主题
在E:/hexo下，打开git bash，
``` bash
git clone https://github.com/MOxFIVE/hexo-theme-next.git themes/next
```
4.5 应用next主题
在E:/hexo下，打开_config.yml，修改：
``` bash
theme: landscape    ->
theme: next
```
4.6. 重新生成静态网页
``` bash
hexo generate
```
### 三、创建 Github pages 并 SSH 授权
1. 创建名为 **shadow000902**.github.io的新的仓库（repository），**shadow000902** 必须为自己的用户名
2. 在本地生成SSH密钥，用于提交本地代码到github上：
``` bash
ssh-keygen -t rsa -C "shadow000902@gmail.com"
```
3. 默认密钥生成后,存放于C:/Users/shadow/.ssh/中，打开id_rsa.pub文件，复制其中的所有内容
4. 在自己创建的shadow000902.github.io仓库的setting中，打开Deploy keys, 点击add deploy key，把刚才复制的内容黏贴进去保存，Title任意取

### 四、上传本地博客内容到github上
``` bash
npm install hexo -server --save
npm install hexo-deployer-git --save
```

### 五、更新博客
``` bash
hexo clean          # 清楚本地静态网页public文件夹
hexo generate       # 重新生成静态网页
hexo deploy         # 部署本地静态网页到github上，以便在shadow000902.github.io域名下访问
```

### 六、绑定域名
1. 在E:/hexo/source下新建一个CNAME文件，把自己申请的域名（比如我申请的：shadow000902.space）填写在该文件里保存
2. 在[DNSPOD](https://www.dnspod.cn/)网站里，设置域名解析：
{% asset_img 设置域名解析.png 设置域名解析 %}
3. 修改域名提供商下的域名DNS服务器为github提供的DNS：
{% asset_img 修改域名提供商下的域名DNS服务器.png 修改域名提供商下的域名DNS服务器 %}

### 七、插件
1. 插件基本命令
1.1 安装插件：                                   npm install 插件名 --save
1.2 卸载插件：                                   npm uninstall 插件名 --save
1.3 更新插件和博客框架（需要在 E:\hexo 目录下）：     npm update
它实质上是通过项目根目录下 package.json 文件更新各大组件
2. 必备插件
2.1 支持RSS：             npm install hexo-generator-feed --save
2.2 生成站点地图：         npm install hexo-generator-sitemap --save
2.3 生成百度站点地图：      npm install hexo-generator-baidu-sitemap --save
2.4 HTML 压缩：           npm install hexo-html-minifier --save
2.5 JavaScript 压缩：     npm install hexo-uglify --save
2.6 CSS 压缩插件：        npm install hexo-clean-css --save
2.7 SEO优化：             npm install hexo-generator-seo-friendly-sitemap --save

### 八、统计功能
[为hexo博客添加访问次数统计功能](http://ibruce.info/2015/04/04/busuanzi/)

### 九、附加
[Hexo你的博客](http://ibruce.info/2013/11/22/hexo-your-blog/)

### 十、问题解决

1. 执行任何一条含``hexo``的命令都会报以下错误：
```
{ Error: Cannot find module './build/Release/DTraceProviderBindings'
    at Function.Module._resolveFilename (module.js:440:15)
    at Function.Module._load (module.js:388:25)
    at Module.require (module.js:468:17)
    at require (internal/module.js:20:19)
    at Object.<anonymous> (/usr/local/lib/node_modules/hexo/node_modules/dtrace-provider/dtrace-provider.js:17:23)
    at Module._compile (module.js:541:32)
    at Object.Module._extensions..js (module.js:550:10)
    at Module.load (module.js:458:32)
    at tryModuleLoad (module.js:417:12)
    at Function.Module._load (module.js:409:3)
    at Module.require (module.js:468:17)
    at require (internal/module.js:20:19)
    at Object.<anonymous> (/usr/local/lib/node_modules/hexo/node_modules/bunyan/lib/bunyan.js:79:18)
    at Module._compile (module.js:541:32)
    at Object.Module._extensions..js (module.js:550:10)
    at Module.load (module.js:458:32) code: 'MODULE_NOT_FOUND' }
```
解决办法：
```
➜  blog_source git:(master) ✗ ll
total 56
-rw-r--r--    1 taoyi  staff   1.0K  6 28 12:53 LICENSE
-rw-r--r--    1 taoyi  staff    12B  6 28 12:53 README.md
-rw-r--r--    1 taoyi  staff   2.8K  7 19 00:34 _config.yml
-rw-r--r--    1 taoyi  staff   554B  7 19 00:34 blog_source.iml
-rw-r--r--    1 taoyi  staff   174B  8  8 18:10 db.json
drwxrwxr-x  290 taoyi  staff   9.6K  8  8 17:57 node_modules
-rw-r--r--    1 taoyi  staff   560B  8  8 18:10 package.json
drwxr-xr-x   16 taoyi  staff   544B  8  8 01:46 public
drwxr-xr-x    5 taoyi  staff   170B  6 28 12:53 scaffolds
drwxr-xr-x   11 taoyi  staff   374B  7 19 00:55 source
drwxr-xr-x    4 taoyi  staff   136B  6 28 12:55 themes
-rwxr-xr-x    1 taoyi  staff    57B  7 19 00:34 update.sh

➜  blog_source git:(master) ✗ npm install dtrace-provider

> dtrace-provider@0.6.0 install /usr/local/git_projects/blog_source/node_modules/dtrace-provider
> node scripts/install.js

hexo-site@0.0.0 /usr/local/git_projects/blog_source
└── dtrace-provider@0.6.0

➜  blog_source git:(master) ✗ hexo -v
zsh: command not found: hexo
➜  blog_source git:(master) ✗ sudo ln -s /usr/local/git_projects/blog_source/node_modules/hexo/bin/hexo /usr/local/bin/hexo
Password:
ln: /usr/local/bin/hexo: File exists
➜  blog_source git:(master) ✗ rm /usr/local/bin/hexo
rm: /usr/local/bin/hexo: Permission denied
➜  blog_source git:(master) ✗ sudo rm /usr/local/bin/hexo
➜  blog_source git:(master) ✗ sudo ln -s /usr/local/git_projects/blog_source/node_modules/hexo/bin/hexo /usr/local/bin/hexo
➜  blog_source git:(master) ✗ which hexo
/usr/local/bin/hexo
➜  blog_source git:(master) ✗ hexo -v
hexo: 3.2.2
hexo-cli: 1.0.2
os: Darwin 15.6.0 darwin x64
http_parser: 2.7.0
node: 6.2.1
v8: 5.0.71.52
uv: 1.9.1
zlib: 1.2.8
ares: 1.10.1-DEV
icu: 57.1
modules: 48
openssl: 1.0.2h
```
即：
安装``dtrace-provider``后，就解决了报错的问题。

2. 执行每条命令都会报以下错误：
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
