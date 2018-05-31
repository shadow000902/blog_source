# -*- coding: utf-8 -*-

import sys
import re
import os

reload(sys)
sys.setdefaultencoding('utf8')

# 指定环境：DEV or PRE
ENV = str(sys.argv[1])

# 线上环境登录域名
online01 = "#define HTTP2 @\"http://saas.chehang168.com\""
online02 = "//#define HTTP2 @\"http://saas.chehang168.com\""
# 测试环境登录域名
test01 = "#define HTTP2 @\"http://test-www.cheoo.com/saas\""
test02 = "//#define HTTP2 @\"http://test-www.cheoo.com/saas\""
#//TODO 优化为正则，使匹配结果唯一

# 清除代码中的改动，保持与远程一致
os.system('git reset --hard')

# 线上环境切测试环境
if ENV == "DEV":
    file_data = ""
    with open("Util2.h", "r") as f:
        for line in f:
            if online01 in line:
                line = line.replace(online01, online02)
            file_data += line
    with open("Util2.h","w") as f:
        f.write(file_data)
if ENV == "DEV":
    file_data = ""
    with open("Util2.h", "r") as f:
        for line in f:
            if test02 in line:
                line = line.replace(test02, test01)
            file_data += line
    with open("Util2.h","w") as f:
        f.write(file_data)

# 测试环境切线上环境
if ENV == "PRE":
    file_data = ""
    with open("Util2.h", "r") as f:
        for line in f:
            if online02 in line:
                line = line.replace(online02, online01)
            file_data += line
    with open("Util2.h","w") as f:
        f.write(file_data)
if ENV == "PRE":
    file_data = ""
    with open("Util2.h", "r") as f:
        for line in f:
            if test01 in line:
                line = line.replace(test01, test02)
            file_data += line
    with open("Util2.h","w") as f:
        f.write(file_data)
