---
title: Appium安装
date: 2016-03-31 18:19:45
categories: [Appium]
tags: [appium]
---

### 一、命令行正常安装Appium
1. 安装node.js
```
XXX@XXX:~$ node -v                                              # 安装[0.10.46](https://nodejs.org/dist/v0.10.46/node-v0.10.46.tar.gz)版本的node
v0.10.46
XXX@XXX:~$ npm -v                                               # 安装node的时候同时安装了[2.15.1]版本的npm
2.15.1
XXX@XXX:~$ appium -v
1.4.16
```

2. 使用node.js安装Appium

<!--more-->

```
npm install -g appium                                           # -g 全局参数
或者
npm --registry http://registry.cnpmjs.org install -g appium     # 推荐这种,npm的国内镜像
```
3. 修改Appium安装源方法
```
npm config get registry                                         # 查看当前npm的镜像源地址
npm config set registry=https://registry.npm.taobao.org/        # 替换npm源为淘宝的npm镜像源
npm config get registry                                         # 查看镜像源是否替换成功
```

### 二、异常安装Appium方法
1. 下载[Appium客户端](http://appium.io/)
2. 安装Appium客户端到电脑，查看目录如图：
{% asset_img Appium安装目录结构.png Appium安装目录结构 %}
3. 完整解压其中的node_modules.7z文件，如图所示：
{% asset_img node_modules目录结构.png node_modules目录结构 %}
4. 在node_modules/.bin文件夹中就有可以在CMD中运行的appium批处理文件：
{% asset_img Appium运行批处理文件.png Appium运行批处理文件 %}
5. 在sdk、jdk、python、环境变量设置好的情况下，CMD进入node_modules/.bin下，就可以直接命令行运行appium：
{% asset_img Appium正常运行.png Appium正常运行 %}

### 三、源码安装
1. 下载源代码
2. 编译运行

### 四、安装指定版本的appium
```
npm install -g appium@1.4.16
```
该方法应对ubuntu系统无法安装上appium@1.5.3的问题，问题原因未知

### 五、Appium应用所附加需要的
1. JDK
2. SDK
3. python
4. selenium
```
pip install selenium -i http://pypi.douban.com/simple       # 使用国内地址
```
5. Appium-Python-Client
```
pip install Appium-Python-Client
```
6. 安装和使用``appium``遇到的问题解决
6.1 安装后无法使用
```
Appium will not work if used or installed with sudo
error: Appium will not work if used or installed with sudo. Please rerun/install as a non-root user. If you had to install Appium using `sudo npm install -g appium`, the solution is to reinstall Node using a method (Homebrew, for example) that doesn't require sudo to install global npm packages.

[1]+  Exit 1                  appium
```
该问题显示appium不能使用root用户来安装，不然无法运行，所以需要卸载用root用户安装的appium，该用一般用户来安装
**解决方案**
1、改变``node``的所有者
```
cd /usr/local/lib
sudo chown -R taoyi node_modules
```
2、卸载``appium``
```
npm -g uninstall appium
```
3、重新安装``appium``
```
npm -g install appium
```
4、启动``appium``
```
appium &
```
6.2 安装中遇到权限问题无法安装
```
npm ERR!  { [Error: EACCES, symlink '/lib/node_modules/appium/bin/appium.js']
npm ERR!   errno: 3,
npm ERR!   code: 'EACCES',
npm ERR!   path: '/lib/node_modules/appium/bin/appium.js' }
npm ERR!
npm ERR! Please try running this command again as root/Administrator.
```
**解决方案**
1、修改目录权限
```
sudo chmod 777 /usr/local/lib/node_modules -R
```
2、安装依旧有相同的问题
查看/lib/node_modules目录，我们发现并没有/lib/node_modules/appium/bin/appium.js文件。显然，该文件是安装时生成的，因此问题应该出在安装起npm上，查看npm相关文档我们发现日志中提到的符号链接的路径是可以修改的，因此，解决权限问题可以将该符号链接修改到用户有权限的目录中。
3、**解决方案**
执行以下命令修改符号链接路径
```
npm config set prefix '~/.npm-packages'
```
将新路径添加到环境变量
```
vim ~/.bashrc  
# 在文件中添加以下内容
export PATH="$PATH:$HOME/.npm-packages/bin"
```
使环境变量生效
```
source .bashrc
```
6.3 ``appium``启动问题
``appium``启动时可能会遇到下列问题
```
XXX@XXX:~$ appium
error: uncaughtException: fn must be a function
See http://goo.gl/916lJJ
date=Sat Nov 21 2015 10:37:25 GMT+0800 (HKT), pid=2504, uid=501, gid=20, cwd=/usr/local/lib/node_modules/appium, execPath=/usr/local/bin/node, version=v0.10.34, argv=[node, /usr/local/bin/appium], rss=103559168, heapTotal=86062080, heapUsed=56309664, loadavg=[1.6328125, 1.86767578125, 1.81103515625], uptime=39552, trace=[column=15, file=/usr/local/lib/node_modules/appium/node_modules/appium-chromedriver/node_modules/appium-jsonwp-proxy/node_modules/appium-support/node_modules/bluebird/js/main/promisify.js, function=Function.Promise.promisify, line=268, method=Promise.promisify, native=false, column=13, file=lib/fs.js, function=, line=46, method=null, native=false, column=26, file=module.js, function=Module._compile, line=456, method=_compile, native=false, column=10, file=module.js, function=Object.Module._extensions..js, line=474, method=Module._extensions..js, native=false, column=32, file=module.js, function=Module.load, line=356, method=load, native=false, column=12, file=module.js, function=Function.Module._load, line=312, method=Module._load, native=false, column=17, file=module.js, function=Module.require, line=364, method=require, native=false, column=17, file=module.js, function=require, line=380, method=null, native=false, column=11, file=/usr/local/lib/node_modules/appium/node_modules/appium-chromedriver/node_modules/appium-jsonwp-proxy/node_modules/appium-support/build/lib/tempdir.js, function=, line=12, method=null, native=false, column=26, file=module.js, function=Module._compile, line=456, method=_compile, native=false, column=10, file=module.js, function=Object.Module._extensions..js, line=474, method=Module._extensions..js, native=false, column=32, file=module.js, function=Module.load, line=356, method=load, native=false, column=12, file=module.js, function=Function.Module._load, line=312, method=Module._load, native=false, column=17, file=module.js, function=Module.require, line=364, method=require, native=false, column=17, file=module.js, function=require, line=380, method=null, native=false, column=19, file=/usr/local/lib/node_modules/appium/node_modules/appium-chromedriver/node_modules/appium-jsonwp-proxy/node_modules/appium-support/build/index.js, function=, line=11, method=null, native=false, column=26, file=module.js, function=Module._compile, line=456, method=_compile, native=false, column=10, file=module.js, function=Object.Module._extensions..js, line=474, method=Module._extensions..js, native=false, column=32, file=module.js, function=Module.load, line=356, method=load, native=false, column=12, file=module.js, function=Function.Module._load, line=312, method=Module._load, native=false, column=17, file=module.js, function=Module.require, line=364, method=require, native=false, column=17, file=module.js, function=require, line=380, method=null, native=false, column=42, file=lib/proxy.js, function=, line=2, method=null, native=false, column=26, file=module.js, function=Module._compile, line=456, method=_compile, native=false, column=10, file=module.js, function=Object.Module._extensions..js, line=474, method=Module._extensions..js, native=false, column=32, file=module.js, function=Module.load, line=356, method=load, native=false, column=12, file=module.js, function=Function.Module._load, line=312, method=Module._load, native=false, column=17, file=module.js, function=Module.require, line=364, method=require, native=false, column=17, file=module.js, function=require, line=380, method=null, native=false, column=17, file=/usr/local/lib/node_modules/appium/node_modules/appium-chromedriver/node_modules/appium-jsonwp-proxy/build/index.js, function=, line=9, method=null, native=false, column=26, file=module.js, function=Module._compile, line=456, method=_compile, native=false, column=10, file=module.js, function=Object.Module._extensions..js, line=474, method=Module._extensions..js, native=false, column=32, file=module.js, function=Module.load, line=356, method=load, native=false, column=12, file=module.js, function=Function.Module._load, line=312, method=Module._load, native=false, column=17, file=module.js, function=Module.require, line=364, method=require, native=false, column=17, file=module.js, function=require, line=380, method=null, native=false, column=28, file=lib/chromedriver.js, function=, line=3, method=null, native=false, column=26, file=module.js, function=Module._compile, line=456, method=_compile, native=false, column=10, file=module.js, function=Object.Module._extensions..js, line=474, method=Module._extensions..js, native=false, column=32, file=module.js, function=Module.load, line=356, method=load, native=false], stack=[TypeError: fn must be a function, , See http://goo.gl/916lJJ, , at Function.Promise.promisify (/usr/local/lib/node_modules/appium/node_modules/appium-chromedriver/node_modules/appium-jsonwp-proxy/node_modules/appium-support/node_modules/bluebird/js/main/promisify.js:268:15), at Object.<anonymous> (lib/fs.js:46:13), at Module._compile (module.js:456:26), at Object.Module._extensions..js (module.js:474:10), at Module.load (module.js:356:32), at Function.Module._load (module.js:312:12), at Module.require (module.js:364:17), at require (module.js:380:17), at Object.<anonymous> (/usr/local/lib/node_modules/appium/node_modules/appium-chromedriver/node_modules/appium-jsonwp-proxy/node_modules/appium-support/build/lib/tempdir.js:12:11), at Module._compile (module.js:456:26), at Object.Module._extensions..js (module.js:474:10), at Module.load (module.js:356:32), at Function.Module._load (module.js:312:12), at Module.require (module.js:364:17), at require (module.js:380:17), at Object.<anonymous> (/usr/local/lib/node_modules/appium/node_modules/appium-chromedriver/node_modules/appium-jsonwp-proxy/node_modules/appium-support/build/index.js:11:19), at Module._compile (module.js:456:26), at Object.Module._extensions..js (module.js:474:10), at Module.load (module.js:356:32), at Function.Module._load (module.js:312:12), at Module.require (module.js:364:17), at require (module.js:380:17), at Object.<anonymous> (lib/proxy.js:2:42), at Module._compile (module.js:456:26), at Object.Module._extensions..js (module.js:474:10), at Module.load (module.js:356:32), at Function.Module._load (module.js:312:12), at Module.require (module.js:364:17), at require (module.js:380:17), at Object.<anonymous> (/usr/local/lib/node_modules/appium/node_modules/appium-chromedriver/node_modules/appium-jsonwp-proxy/build/index.js:9:17), at Module._compile (module.js:456:26), at Object.Module._extensions..js (module.js:474:10), at Module.load (module.js:356:32), at Function.Module._load (module.js:312:12), at Module.require (module.js:364:17), at require (module.js:380:17), at Object.<anonymous> (lib/chromedriver.js:3:28), at Module._compile (module.js:456:26), at Object.Module._extensions..js (module.js:474:10), at Module.load (module.js:356:32)]
```
google我们发现问题是``node.js``版本太低导致。
使用``apt-get``安装的node版本还是``0.10.46``
所以需要以源码方式安装，下载``0.12.15``的源码包
```
wget XXX/node-v0.12.15.tar.gz
tar xvf node-v0.12.15.tar.gz
cd node-v0.12.15
make
make install
```
之后再运行``appium``就可以正常启动了


7. 注意点
**安装appium需要首先安装相匹配的``node``和``npm``，如第一点中所述**
这一点至关重要，否则总是会遇到各种各样乱七八糟的问题。

8. ``appium1.4.16``版本安装成功日志
```
XXX@XXX:~$ npm -g install appium@1.4.16
npm WARN optional dep failed, continuing udidetect@1.0.7

> utf-8-validate@1.1.0 install /usr/local/lib/node_modules/appium/node_modules/ws/node_modules/utf-8-validate
> node-gyp rebuild

make: Entering directory `/usr/local/lib/node_modules/appium/node_modules/ws/node_modules/utf-8-validate/build'
  CXX(target) Release/obj.target/validation/src/validation.o
  SOLINK_MODULE(target) Release/obj.target/validation.node
  COPY Release/validation.node
make: Leaving directory `/usr/local/lib/node_modules/appium/node_modules/ws/node_modules/utf-8-validate/build'

> bufferutil@1.1.0 install /usr/local/lib/node_modules/appium/node_modules/ws/node_modules/bufferutil
> node-gyp rebuild

make: Entering directory `/usr/local/lib/node_modules/appium/node_modules/ws/node_modules/bufferutil/build'
  CXX(target) Release/obj.target/bufferutil/src/bufferutil.o
  SOLINK_MODULE(target) Release/obj.target/bufferutil.node
  COPY Release/bufferutil.node
make: Leaving directory `/usr/local/lib/node_modules/appium/node_modules/ws/node_modules/bufferutil/build'
npm WARN peerDependencies The peer dependency continuation-local-storage@~3 included from cls-bluebird will no
npm WARN peerDependencies longer be automatically installed to fulfill the peerDependency
npm WARN peerDependencies in npm 3+. Your application will need to depend on it explicitly.
npm WARN peerDependencies The peer dependency bluebird@>=1.0.3 included from cls-bluebird will no
npm WARN peerDependencies longer be automatically installed to fulfill the peerDependency
npm WARN peerDependencies in npm 3+. Your application will need to depend on it explicitly.

> utf-8-validate@1.2.1 install /usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/engine.io/node_modules/ws/node_modules/utf-8-validate
> node-gyp rebuild

make: Entering directory `/usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/engine.io/node_modules/ws/node_modules/utf-8-validate/build'
  CXX(target) Release/obj.target/validation/src/validation.o
  SOLINK_MODULE(target) Release/obj.target/validation.node
  COPY Release/validation.node
make: Leaving directory `/usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/engine.io/node_modules/ws/node_modules/utf-8-validate/build'

> bufferutil@1.2.1 install /usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/engine.io/node_modules/ws/node_modules/bufferutil
> node-gyp rebuild

make: Entering directory `/usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/engine.io/node_modules/ws/node_modules/bufferutil/build'
  CXX(target) Release/obj.target/bufferutil/src/bufferutil.o
  SOLINK_MODULE(target) Release/obj.target/bufferutil.node
  COPY Release/bufferutil.node
make: Leaving directory `/usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/engine.io/node_modules/ws/node_modules/bufferutil/build'

> utf-8-validate@1.2.1 install /usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/socket.io-client/node_modules/engine.io-client/node_modules/ws/node_modules/utf-8-validate
> node-gyp rebuild

make: Entering directory `/usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/socket.io-client/node_modules/engine.io-client/node_modules/ws/node_modules/utf-8-validate/build'
  CXX(target) Release/obj.target/validation/src/validation.o
  SOLINK_MODULE(target) Release/obj.target/validation.node
  COPY Release/validation.node
make: Leaving directory `/usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/socket.io-client/node_modules/engine.io-client/node_modules/ws/node_modules/utf-8-validate/build'

> bufferutil@1.2.1 install /usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/socket.io-client/node_modules/engine.io-client/node_modules/ws/node_modules/bufferutil
> node-gyp rebuild

make: Entering directory `/usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/socket.io-client/node_modules/engine.io-client/node_modules/ws/node_modules/bufferutil/build'
  CXX(target) Release/obj.target/bufferutil/src/bufferutil.o
  SOLINK_MODULE(target) Release/obj.target/bufferutil.node
  COPY Release/bufferutil.node
make: Leaving directory `/usr/local/lib/node_modules/appium/node_modules/socket.io/node_modules/socket.io-client/node_modules/engine.io-client/node_modules/ws/node_modules/bufferutil/build'

> appium-chromedriver@2.3.2 install /usr/local/lib/node_modules/appium/node_modules/appium-chromedriver
> node install-npm.js

info Chromedriver Install Opening temp file to write chromedriver_linux64 to...
info Chromedriver Install Downloading http://chromedriver.storage.googleapis.com/2.18/chromedriver_linux64.zip...
info Chromedriver Install Writing binary content to /tmp/11678-532-16jz6cz/chromedriver_linux64.zip...
info Chromedriver Install Extracting /tmp/11678-532-16jz6cz/chromedriver_linux64.zip to /tmp/11678-532-16jz6cz/chromedriver_linux64
info Chromedriver Install Creating /usr/local/lib/node_modules/appium/node_modules/appium-chromedriver/chromedriver/linux...
info Chromedriver Install Copying unzipped binary, reading from /tmp/11678-532-16jz6cz/chromedriver_linux64/chromedriver...
info Chromedriver Install Writing to /usr/local/lib/node_modules/appium/node_modules/appium-chromedriver/chromedriver/linux/chromedriver_64...
info Chromedriver Install /usr/local/lib/node_modules/appium/node_modules/appium-chromedriver/chromedriver/linux/chromedriver_64 successfully put in place
npm WARN engine hawk@0.10.2: wanted: {"node":"0.8.x"} (current: {"node":"0.10.46","npm":"2.15.1"})
npm WARN engine cryptiles@0.1.3: wanted: {"node":"0.8.x"} (current: {"node":"0.10.46","npm":"2.15.1"})
npm WARN engine sntp@0.1.4: wanted: {"node":"0.8.x"} (current: {"node":"0.10.46","npm":"2.15.1"})
npm WARN engine boom@0.3.8: wanted: {"node":"0.8.x"} (current: {"node":"0.10.46","npm":"2.15.1"})
npm WARN engine hoek@0.7.6: wanted: {"node":"0.8.x"} (current: {"node":"0.10.46","npm":"2.15.1"})
/usr/local/bin/appium -> /usr/local/lib/node_modules/appium/bin/appium.js
/usr/local/bin/appium-doctor -> /usr/local/lib/node_modules/appium/bin/appium-doctor.js
/usr/local/bin/authorize_ios -> /usr/local/lib/node_modules/appium/bin/authorize-ios.js
appium@1.4.16 /usr/local/lib/node_modules/appium
├── camel-back-promise@1.0.0
├── vargs@0.1.0
├── win-spawn@2.0.0
├── bytes@1.0.0
├── path@0.11.14
├── stack-trace@0.0.9
├── bufferpack@0.0.6
├── utf7@1.0.0
├── uuid-js@0.7.5
├── rimraf@2.2.8
├── through@2.3.8
├── node-idevice@0.1.5
├── bplist-parser@0.1.0
├── xmldom@0.1.19
├── node-uuid@1.4.3
├── q@1.1.2
├── js2xmlparser2@0.2.0
├── ncp@2.0.0
├── async@0.9.2
├── underscore@1.8.3
├── xpath@0.0.9
├── colors@1.0.3
├── adm-zip@0.4.7
├── safari-launcher@2.0.5
├── temp@0.8.3 (os-tmpdir@1.0.1)
├── sandboxed-module@2.0.3 (require-like@0.1.2)
├── which@1.2.0 (is-absolute@0.1.7)
├── mv@2.0.3 (ncp@0.6.0)
├── underscore.string@3.0.3
├── mkdirp@0.5.1 (minimist@0.0.8)
├── touch@0.0.3 (nopt@1.0.10)
├── difflib@0.2.4 (heap@0.2.6)
├── morgan@1.5.3 (basic-auth@1.0.3, depd@1.0.1, on-finished@2.2.1, debug@2.2.0)
├── method-override@2.3.5 (methods@1.1.1, vary@1.0.1, parseurl@1.3.0, debug@2.2.0)
├── serve-favicon@2.2.1 (fresh@0.2.4, ms@0.7.1, parseurl@1.3.0, etag@1.6.0)
├── bplist-creator@0.0.6 (stream-buffers@2.2.0)
├── es6-promise@2.3.0
├── glob@4.4.2 (inherits@2.0.1, once@1.3.2, inflight@1.0.4, minimatch@2.0.10)
├── winston@0.9.0 (cycle@1.0.3, eyes@0.1.8, isstream@0.1.2, pkginfo@0.3.1)
├── npmlog@1.1.0 (ansi@0.3.0, are-we-there-yet@1.0.4, gauge@1.1.0)
├── appium-atoms@0.0.5
├── body-parser@1.12.4 (content-type@1.0.1, depd@1.0.1, qs@2.4.2, on-finished@2.2.1, raw-body@2.0.2, debug@2.2.0, iconv-lite@0.4.8, type-is@1.6.9)
├── express@4.11.2 (utils-merge@1.0.0, merge-descriptors@0.0.2, methods@1.1.1, fresh@0.2.4, cookie@0.1.2, escape-html@1.0.1, range-parser@1.0.3, vary@1.0.1, cookie-signature@1.0.5, finalhandler@0.3.3, media-typer@0.3.0, parseurl@1.3.0, serve-static@1.8.1, content-disposition@0.5.0, path-to-regexp@0.1.3, depd@1.0.1, qs@2.3.3, etag@1.5.1, debug@2.1.3, on-finished@2.2.1, send@0.11.1, proxy-addr@1.0.8, type-is@1.5.7, accepts@1.2.13)
├── unzip@0.1.11 (setimmediate@1.0.4, match-stream@0.0.2, readable-stream@1.0.33, pullstream@0.4.1, fstream@0.1.31, binary@0.3.0)
├── prompt@0.2.14 (revalidator@0.1.8, pkginfo@0.3.1, read@1.0.7, utile@0.2.1, winston@0.8.3)
├── longjohn@0.2.9 (source-map-support@0.3.2)
├── request@2.53.0 (caseless@0.9.0, aws-sign2@0.5.0, forever-agent@0.5.2, form-data@0.2.0, stringstream@0.0.5, oauth-sign@0.6.0, tunnel-agent@0.4.1, isstream@0.1.2, json-stringify-safe@5.0.1, qs@2.3.3, tough-cookie@2.2.0, combined-stream@0.0.7, mime-types@2.0.14, http-signature@0.10.1, bl@0.9.4, hawk@2.3.1)
├── md5calculator@0.0.3 (crypto@0.0.3, unzip@0.1.8, elementtree@0.1.3)
├── ws@0.7.2 (options@0.0.6, ultron@1.0.2, utf-8-validate@1.1.0, bufferutil@1.1.0)
├── date-utils@1.2.17
├── grunt-cli@0.1.13 (resolve@0.3.1, nopt@1.0.10, findup-sync@0.1.3)
├── binary-cookies@0.1.1 (path@0.4.10, colors@0.6.2, async@0.2.10, underscore@1.4.4, argparse@0.1.16, winston@0.6.2)
├── swig@1.4.2 (optimist@0.6.1, uglify-js@2.4.24)
├── grunt@0.4.5 (dateformat@1.0.2-1.2.3, which@1.0.9, eventemitter2@0.4.14, getobject@0.1.0, colors@0.6.2, async@0.1.22, grunt-legacy-util@0.2.0, hooker@0.2.3, exit@0.1.2, nopt@1.0.10, lodash@0.9.2, minimatch@0.2.14, glob@3.1.21, coffee-script@1.3.3, underscore.string@2.2.1, iconv-lite@0.2.11, grunt-legacy-log@0.1.2, findup-sync@0.1.3, js-yaml@2.0.5)
├── namp@0.2.25 (highlight.js@8.9.1)
├── appium-support@1.1.2 (bluebird@2.10.2, lodash@3.10.1)
├── argparse@1.0.3 (sprintf-js@1.0.3, lodash@3.10.1)
├── xml2js@0.4.15 (sax@1.1.4, xmlbuilder@4.0.0)
├── plist@1.1.0 (util-deprecate@1.0.0, base64-js@0.0.6, xmlbuilder@2.2.1)
├── appium-xcode@2.0.5 (denodeify@1.2.1, q@1.4.1, npmlog@1.2.1, source-map-support@0.2.10, lodash@3.10.1, babel-runtime@5.5.5, asyncbox@2.3.1)
├── appium-uiauto@1.10.10 (argparse@0.1.16, winston@0.8.3)
├── node-simctl@2.1.0 (source-map-support@0.2.10, npmlog@1.2.1, appium-logger@1.1.7, asyncbox@2.3.1, es6-mapify@1.0.0, babel-runtime@5.5.5, teen_process@1.5.1)
├── socket.io@1.3.7 (debug@2.1.0, has-binary-data@0.1.3, socket.io-parser@2.2.4, socket.io-adapter@0.3.1, engine.io@1.5.4, socket.io-client@1.3.7)
├── appium-instruments@2.0.6 (underscore@1.7.0, winston@0.8.3, appium-support@1.0.3)
├── appium-adb@1.7.5 (underscore@1.6.0, ncp@0.5.1, q@1.0.1, appium-support@0.0.3, winston@0.7.3)
└── appium-chromedriver@2.3.2 (is-os@1.0.0, q@1.4.1, ps-node@0.0.4, source-map-support@0.3.3, rimraf@2.4.3, request-promise@0.4.3, appium-logger@1.1.7, lodash@3.10.1, request@2.65.0, babel-runtime@5.5.5, asyncbox@2.3.1, teen_process@1.5.1, appium-jsonwp-proxy@1.4.1)
XXX@XXX:~$ appium -v
1.4.16
```
