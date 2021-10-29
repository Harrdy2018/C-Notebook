#### 安装MySQL数据库
* 查询服务
```sh
$ winpty sc query
$ winpty sc query mysql

SERVICE_NAME: mysql
        TYPE               : 10  WIN32_OWN_PROCESS
        STATE              : 4  RUNNING
                                (STOPPABLE, PAUSABLE, ACCEPTS_SHUTDOWN)
        WIN32_EXIT_CODE    : 0  (0x0)
        SERVICE_EXIT_CODE  : 0  (0x0)
        CHECKPOINT         : 0x0
        WAIT_HINT          : 0x0
```
* 启动服务
```
$ winpty net start mysql
$ winpty sc start mysql
```
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
* 建表格
```sh
mysql> create table `student_AA`(
    -> `student_id` int,
    -> `name` varchar(20),
    -> `major` varchar(20),
    -> primary key(`student_id`)
    -> );

# 增加约束
mysql> create table `student`(
    `student_id` int,
    `name` varchar(20) not null,
    `major` varchar(20) unique,
    `hobby` varchar(10) default '吃',
    primary key (`student_id`));

# 自动加
mysql> create table `student`(
    `student_id` int auto_increment,
    `name` varchar(20),
    `major` varchar(20),
    primary key(`student_id`));

mysql> create table student(
    -> student_id int primary key,
    -> name varchar(20),
    -> major varchar(20));
Query OK, 0 rows affected (0.05 sec)

mysql> describe student;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| student_id | int(11)     | NO   | PRI | NULL    |       |
| name       | varchar(20) | YES  |     | NULL    |       |
| major      | varchar(20) | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+
3 rows in set (0.01 sec)

mysql> drop table student; # 删表
```
* 添加表属性(字段) ```mysql> alter table `student` add gpa decimal(3,2);```
* 删除表属性(字段) ```mysql> alter table "student" drop column gpa;```
* 插入资料 ```mysql> insert into `student` values(1,'小白','历史');```
* 插入null资料 ```mysql> insert into `student` values(3,'小绿',null);```
* 按属性顺序插入 ```mysql> insert into `student`(`name`,`major`,`student_id`) values('小黑','化学',4);```
* 查询该表所有 ```mysql> select * from student;```
#### 修改、删除资料
* 关闭安全更新模式 ```mysql> set sql_safe_updates=0;```
* ```mysql> update `student` set `major`='英语文学' where `major`='英语';```
* ```mysql> update `student` set `major`='生化系' where `major`='生物' or `major`='化学';```
* ```mysql> update `student` set `name`='小慧',`major`='生化系' where `major`='生物' or `major`='化学';```
* 删除 ```mysql> delete from `student` where `student_id`=4;```
* ```mysql> delete from `student` where `student_id`=4 and `major`='物理';```
* ```mysql> delete from `student` where `score` < 10;```
#### 如何搜寻资料
* ```mysql> select * from student;```
* ```mysql> select `name` from student;```
* ```mysql> select `name`, `major` from student;```
* ```mysql> select * from student where `major` in('历史','英语');```
* 递增 ```mysql> select * from student order by `score`;```
* 递增 ```mysql> select * from student order by `score` asc;```
* 多字段排序 ```mysql> select * from student order by `score`,`student_id`;```
* 递减 ```mysql> select * from student order by `score` desc;```
* 只传一笔资料 ```mysql> select * from student limit 1;```
* 取前三低 ```mysql> select * from student order by `score` limit 3;```
* 取前三高 ```mysql> select * from student order by `score` desc limit 3;```
