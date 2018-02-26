---
title: Python通过SSH隧道连接MySQL数据库
date: 2018-01-10 09:56:03
categories: [python]
tags: [ssh]
---

#### 方式一：通过``MySQLdb``模块
```python
	def con_sshDb(self, sql):
		# ssh的地址，端口，用户名，密码
		from sshtunnel import SSHTunnelForwarder
		with SSHTunnelForwarder(
				('XXX.XXX.XXX.XXX', 22),
				ssh_password="XXXXXX",
				ssh_username="XXXXXX",
				remote_bind_address=('XXX.XXX', 3306)
				) as server:
			# 此处必须是是127.0.0.1
			import MySQLdb
			conn = MySQLdb.connect(host='127.0.0.1',
								   port=server.local_bind_port,
								   # Navicat常规处的链接用户名和密码，以及连接数据库名称
								   user='XXXXXX',
								   passwd='XXXXXX',
								   db='XXXXXX')
			# .cursor()用来获得python执行Mysql命令的方法
			cursor = conn.cursor()
			select = sql
			# .execute()执行mysql语句
			cursor.execute(select)
			# fetchall()则是接收全部的返回结果行
			data = cursor.fetchall()
		return data
```

  <!--more-->

#### 方式二：通过``paramiko``模块
```python
	def con_sshDb(self, sql):
		import paramiko
		ssh = paramiko.SSHClient()
		ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
		ssh.connect("XXX.XXX.XXX.XXX", 22, "ssh_username", "ssh_password")
        select = sql
		stdin, stdout, stderr = ssh.exec_command("mysql -u user -p passwd -D mysql -e 'select'")
		print stdout.readlines()
		ssh.close()
```

#### 方式二：通过``sqlalchemy``模块
```python
	def con_sshDb(self, sql):
		from sshtunnel import SSHTunnelForwarder
		with SSHTunnelForwarder(
				('XXX.XXX.XXX.XXX', 22),
				ssh_password="XXXXXX",
				ssh_username="XXXXXX",
				remote_bind_address=('XXX.XXX', 3306)
				) as server:
			server.start()  # start ssh sever
			print 'Server connected via SSH'

			# connect to PostgreSQL
			local_port = str(server.local_bind_port)
			from sqlalchemy import create_engine
			engine = create_engine('postgresql://<db_user>:<db_pwd>@127.0.0.1:' + local_port +'/<db_name>')

			from sqlalchemy.orm import sessionmaker
			Session = sessionmaker(bind=engine)
			session = Session()
			print 'Database session created'

			select = sql
			data = session.execute(select)
		return data
```
