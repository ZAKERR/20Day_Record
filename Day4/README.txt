1----->
   Oracle数据库操作:
   修改管理员密码.
   1.通过先登录 /as sysdba
   2.ALTER USER system IDENTIFIED BY 密码.
   
   
   Mysql数据库忘记密码操作:
   1.找到配置文件my.ini(可能会跟安装程序不一样的目录)
   2.mysqld下面添加skip-grant-tables
   3.保存后重启mySQL (每次启动会重新读取配置文件)
   4.输入mysql -u root -p就可以不用密码登录了，出现password：的时候直接回车可以进入
   5.update user set authentication_string = password("123456") where user="root" ;
   (5.7 以后 password字段已经改成了authentication_string)
   6.flush privileges;
     总结:
	 1.初始化文件..需要重启服务才能生效.  
	 2.初始化文件..有可能不在主程序目录
   
   
   
   python连接Mysql:(MySqldb不再被python3支持)
   
   
   
   
   
   