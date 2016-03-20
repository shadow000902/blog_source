---
title: 利用Hexo在Github Page上部署个人博客
date: 2016-03-18 00:06:40
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
1. 创建名为**shadow000902**.github.io的新的仓库（repository），**shadow000902**必须为自己的用户名
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
2.7 SEO优化：             npm install hexo-generator-seo-friendly-sitemap

### 八、统计功能
[为hexo博客添加访问次数统计功能](http://ibruce.info/2015/04/04/busuanzi/)

### 九、附加
[Hexo你的博客](http://ibruce.info/2013/11/22/hexo-your-blog/)

