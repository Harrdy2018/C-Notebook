## 结构体
### 定义结构体类型和变量
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义结构体数据类型
struct stu{
  char *name;
  int num;
  int age;
  char group;
  float score;
};
//定义结构体变量
struct stu stu1,stu2;
//定义结构体的同时定义结构体变量
struct person{
  char *name;
}p1,p2;
//如果只需要 child1、schild2 两个变量，后面不需要再使用结构体名定义其他变量，那么在定义时也可以不给出结构体名
struct{
  char *name;
}child1,child2;
int main ()
{
  printf("define");
  return(0);
}
```
### 结构体赋值
* 定义和赋值分开
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义结构体数据类型
struct{
  char *name;
  int num;
  int age;
  char group;
  float score;
}stu1;
int main ()
{
  stu1.name="lukang";
  stu1.num=1214;
  stu1.age=18;
  stu1.group='A';
  stu1.score=98;
  printf("yi dui yi fu zhi");
  return(0);
}
```
* 定义的时候并且赋值
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义结构体数据类型
struct{
  char *name;
  int num;
  int age;
  char group;
  float score;
}stu1,stu2={"lukang",1214,18,'A',98};
int main ()
{
  printf("define and fu zhi");
  return(0);
}
```
### 结构体数组
```c
```