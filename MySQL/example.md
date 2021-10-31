#### 创建资料库
##### 创建员工表格
```sql
-- branch_id int 部门ID
-- sup_id int 主管ID
create table employee(emp_id int primary key, name varchar(20), birth_date date, sex varchar(1), salary int, branch_id int, sup_id int); 

mysql> describe employee;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| emp_id     | int(11)     | NO   | PRI | NULL    |       |
| name       | varchar(20) | YES  |     | NULL    |       |
| birth_date | date        | YES  |     | NULL    |       |
| sex        | varchar(1)  | YES  |     | NULL    |       |
| salary     | int(11)     | YES  |     | NULL    |       |
| branch_id  | int(11)     | YES  |     | NULL    |       |
| sup_id     | int(11)     | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+
```
##### 创建部门表格
```sql
create table branch(branch_id int primary key, branch_name varchar(20), manager_id int, foreign key(manager_id) references employee(emp_id) on delete set null);

mysql> describe branch;
+-------------+-------------+------+-----+---------+-------+
| Field       | Type        | Null | Key | Default | Extra |
+-------------+-------------+------+-----+---------+-------+
| branch_id   | int(11)     | NO   | PRI | NULL    |       |
| branch_name | varchar(20) | YES  |     | NULL    |       |
| manager_id  | int(11)     | YES  | MUL | NULL    |       |
+-------------+-------------+------+-----+---------+-------+
```
##### 员工表添加外键
```sql
-- 员工表的branch_id是要到部门表的branch_id去找
alter table employee add foreign key(branch_id) references branch(branch_id) on delete set null;

mysql> describe employee;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| emp_id     | int(11)     | NO   | PRI | NULL    |       |
| name       | varchar(20) | YES  |     | NULL    |       |
| birth_date | date        | YES  |     | NULL    |       |
| sex        | varchar(1)  | YES  |     | NULL    |       |
| salary     | int(11)     | YES  |     | NULL    |       |
| branch_id  | int(11)     | YES  | MUL | NULL    |       |
| sup_id     | int(11)     | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+


-- 员工表的sup_id是要到自身的emp_id去找
alter table employee add foreign key(sup_id) references employee(emp_id) on delete set null;

mysql> describe employee;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| emp_id     | int(11)     | NO   | PRI | NULL    |       |
| name       | varchar(20) | YES  |     | NULL    |       |
| birth_date | date        | YES  |     | NULL    |       |
| sex        | varchar(1)  | YES  |     | NULL    |       |
| salary     | int(11)     | YES  |     | NULL    |       |
| branch_id  | int(11)     | YES  | MUL | NULL    |       |
| sup_id     | int(11)     | YES  | MUL | NULL    |       |
+------------+-------------+------+-----+---------+-------+
```
##### 创建顾客表
```sql
create table client(client_id int primary key, client_name varchar(20), phone varchar(20));

mysql> describe client;
+-------------+-------------+------+-----+---------+-------+
| Field       | Type        | Null | Key | Default | Extra |
+-------------+-------------+------+-----+---------+-------+
| client_id   | int(11)     | NO   | PRI | NULL    |       |
| client_name | varchar(20) | YES  |     | NULL    |       |
| phone       | varchar(20) | YES  |     | NULL    |       |
+-------------+-------------+------+-----+---------+-------+
```
##### 创建工作关系表
```sql
mysql> create table works_with(
    -> emp_id int,
    -> client_id int,
    -> total_sales int,
    -> primary key(emp_id, client_id),
    -> foreign key(emp_id) references employee(emp_id) on delete cascade,
    -> foreign key(client_id) references client(client_id) on delete cascade
    -> );

mysql> describe works_with;
+-------------+---------+------+-----+---------+-------+
| Field       | Type    | Null | Key | Default | Extra |
+-------------+---------+------+-----+---------+-------+
| emp_id      | int(11) | NO   | PRI | NULL    |       |
| client_id   | int(11) | NO   | PRI | NULL    |       |
| total_sales | int(11) | YES  |     | NULL    |       |
+-------------+---------+------+-----+---------+-------+
```
#### 插入数据，完善资料
```sql
insert into branch values(1,'研发',null);
insert into branch values(2,'行政',null);
insert into branch values(3,'资讯',null);

mysql> select * from branch;
+-----------+-------------+------------+
| branch_id | branch_name | manager_id |
+-----------+-------------+------------+
|         1 | 研发        |       NULL |
|         2 | 行政        |       NULL |
|         3 | 资讯        |       NULL |
+-----------+-------------+------------+
```
```sql
insert into `employee` values(206, '小黄', '1998-10-08', 'F', 50000, 1, null);
insert into `employee` values(207, '小绿', '1985-09-16', 'M', 50000, 2, 206);
insert into `employee` values(208, '小黑', '2000-12-19', 'M', 50000, 3, 206);
insert into `employee` values(209, '小白', '1997-01-22', 'F', 50000, 3, 207);
insert into `employee` values(210, '小蓝', '1925-11-10', 'F', 50000, 1, 207);

mysql> select * from employee;
+--------+--------+------------+------+--------+-----------+--------+
| emp_id | name   | birth_date | sex  | salary | branch_id | sup_id |
+--------+--------+------------+------+--------+-----------+--------+
|    206 | 小黄   | 1998-10-08 | F    |  50000 |         1 |   NULL |
|    207 | 小绿   | 1985-09-16 | M    |  50000 |         2 |    206 |
|    208 | 小黑   | 2000-12-19 | M    |  50000 |         3 |    206 |
|    209 | 小白   | 1997-01-22 | F    |  50000 |         3 |    207 |
|    210 | 小蓝   | 1925-11-10 | F    |  50000 |         1 |    207 |
+--------+--------+------------+------+--------+-----------+--------+
```
```sql
update `branch` set `manager_id`=206 where `branch_id`=1;
update `branch` set `manager_id`=207 where `branch_id`=2;
update `branch` set `manager_id`=208 where `branch_id`=3;

mysql> select * from branch;
+-----------+-------------+------------+
| branch_id | branch_name | manager_id |
+-----------+-------------+------------+
|         1 | 研发        |        206 |
|         2 | 行政        |        207 |
|         3 | 资讯        |        208 |
+-----------+-------------+------------+
```
```sql
insert into `client` values(400, '阿狗', '254354335');
insert into `client` values(401, '阿猫', '25633899');
insert into `client` values(402, '旺来', '45354345');
insert into `client` values(403, '露西', '54334365');
insert into `client` values(404, '艾瑞克', '2542563643');

mysql> select * from client;
+-----------+-------------+------------+
| client_id | client_name | phone      |
+-----------+-------------+------------+
|       400 | 阿狗        | 254354335  |
|       401 | 阿猫        | 25633899   |
|       402 | 旺来        | 45354345   |
|       403 | 露西        | 54334365   |
|       404 | 艾瑞克      | 2542563643 |
+-----------+-------------+------------+
```
```sql
insert into `works_with` values(206, 400, '70000');
insert into `works_with` values(207, 401, '24000');
insert into `works_with` values(208, 402, '9800');
insert into `works_with` values(208, 403, '24000');
insert into `works_with` values(210, 404, '87940');

mysql> select * from works_with;
+--------+-----------+-------------+
| emp_id | client_id | total_sales |
+--------+-----------+-------------+
|    206 |       400 |       70000 |
|    207 |       401 |       24000 |
|    208 |       402 |        9800 |
|    208 |       403 |       24000 |
|    210 |       404 |       87940 |
+--------+-----------+-------------+
```
#### 题目
* 取得薪水前三高的员工
```sql
mysql> select * from employee order by `salary` desc limit 3;
+--------+--------+------------+------+--------+-----------+--------+
| emp_id | name   | birth_date | sex  | salary | branch_id | sup_id |
+--------+--------+------------+------+--------+-----------+--------+
|    206 | 小黄   | 1998-10-08 | F    |  50000 |         1 |   NULL |
|    207 | 小绿   | 1985-09-16 | M    |  50000 |         2 |    206 |
|    208 | 小黑   | 2000-12-19 | M    |  50000 |         3 |    206 |
+--------+--------+------------+------+--------+-----------+--------+
```
* 取得所有员工的名字
```sql
mysql> select `name` from `employee`;
+--------+
| name   |
+--------+
| 小黄   |
| 小绿   |
| 小黑   |
| 小白   |
| 小蓝   |
+--------+

-- 查找去重
mysql> select distinct `sex` from `employee`;
+------+
| sex  |
+------+
| F    |
| M    |
+------+
```
#### 聚合函数 ```aggregate functions```
* 取得员工人数 ```select count(*) from `employee`;```
* 有几个sup_id ```select count(`sup_id`) from `employee`;```
* 取得所有出生于1970-01-01之后的女性员工人数 ```select count(*) from employee where birth_date>'1970-01-01' and sex='F';```
* 员工平均薪水 ```select avg(`salary`) from `employee`;```
* 员工薪水总和 ```select sum(`salary`) from `employee`;```
* 薪水最高 ```select max(`salary`) from `employee`;```
* 薪水最低 ```select min(`salary`) from `employee`;```
#### 万用字元  ```wildcards```
* ```%```代表多个字元，```_```代表一个字元
* 电话号码尾数335 ```select * from client where phone like '%335';```
* 电话号码开头254 ```select * from client where phone like '254%';```
* 生日在12月的员工 ```select * from employee where `birth_date` like '____-12%';```
#### ```union```
* 员工名字 union 客户名字 ```select `name` from employee union select `client_name` from client;```
* 员工id+员工名字 union 客户id+客户名字```select `emp_id`,`name` from employee union select `client_id`,`client_name` from client;```
* ```select `emp_id` as `total_id`,`name` from employee union select `client_id`,`client_name` from client;```
* 员工薪水 union 销售金额 ```select salary from employee union select `total_sales` from works_with;```
#### ```join```
* 取得所有部门经理的名字 ```select * from `employee` join `branch` on `emp_id` = `manager_id`;```
* ```select * from `employee` join `branch` on employee.emp_id = branch.manager_id;```
* ```select employee.emp_id, employee.name, branch.branch_name from `employee` join `branch` on employee.emp_id = branch.manager_id;```
* ```select employee.emp_id, employee.name, branch.branch_name from `employee` left join `branch` on employee.emp_id = branch.manager_id;```
* ```select employee.emp_id, employee.name, branch.branch_name from `employee` right join `branch` on employee.emp_id = branch.manager_id;```
#### 子查询 ```subquery```
* 找出研发部门经理名字
```sql
select `name`
from `employee`
where `emp_id` = (
    select `manager_id`
    from `branch`
    where `branch_name` = '研发'
);
```
* 找出对单一客户销售金额超过50000的员工名字
```sql
select `name`
from `employee`
where `emp_id` in (
    select `emp_id`
    from `works_with`
    where `total_sales` > 50000
);
```
#### ```on delete```
```sql
create table branch(branch_id int primary key, branch_name varchar(20), manager_id int, foreign key(manager_id) references employee(emp_id) on delete set null);
-- 如果对应的 employeee(emp_id) 某个员工离职了，这样branch表就没什么可对应的
-- 在branch没什么可对应的，就将其值设置为null

-- foreign key(emp_id) references employee(emp_id) on delete cascade
-- 对应不到，资料直接删掉
```