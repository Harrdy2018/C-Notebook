#### 安装MySQL数据库
* 本地重启服务报错---本地计算机上的MySQL服务启动后停止。某些服务在未由其他服务或程序使用时将自动
```sh
移除服务 mysqld remove
安装服务 mysqld install 服务名字(mysql) --defaults-file="D:\MySQL\mysql-5.7.10-winx64\my.ini"
继续重启服务即可
```
* windows上如何正确用git bash终端连接MySQL数据库
```sh
Harrdy@DESKTOP-T94UKG2 MINGW64 ~/Desktop
$ winpty mysql -u root -p
Enter password: root

$ winpty mysql --host=127.0.0.1 --user=root --password
$ winpty mysql --host="127.0.0.1" --user=root --password
$ winpty mysql --host=localhost --user=root --password
```
#### 基本命令
* ```alter user user() identified by "root";``` 修改密码命令
* ```show databases;``` 列出 MySQL 数据库管理系统的数据库列表
```sh
mysql> use mysql; # 切到mysql数据库
Database changed
mysql> show tables; # 显示指定数据库的所有表
+---------------------------+
| Tables_in_mysql           |
+---------------------------+
| columns_priv              |
| user                      |
+---------------------------+
2 rows in set (0.00 sec)

mysql> show columns from user;
+------------------------+-----------------------------------+------+-----+-----------------------+-------+
| Field                  | Type                              | Null | Key | Default               | Extra |
+------------------------+-----------------------------------+------+-----+-----------------------+-------+
| Host                   | char(60)                          | NO   | PRI |                       |       |
| User                   | char(32)                          | NO   | PRI |                       |       |
| account_locked         | enum('N','Y')                     | NO   |     | N                     |       |
+------------------------+-----------------------------------+------+-----+-----------------------+-------+
3 rows in set (0.00 sec)
```
* 创建数据库
```sh
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
4 rows in set (0.00 sec)

mysql> create database harrdy1028;
Query OK, 1 row affected (0.00 sec)

mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| harrdy1028         |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
5 rows in set (0.00 sec)
```
* ```drop database harrdy2018;``` 删除数据库