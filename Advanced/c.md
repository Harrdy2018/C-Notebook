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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义结构体数组和变量
struct stu{
  char *name;
  int num;
  int age;
  char group;
  float score;
}class[5];//一个班级有5名学生
//定义+变量+初始化
struct stuA{
    char *name;  //姓名
    int num;  //学号
    int age;  //年龄
    char group;  //所在小组 
    float score;  //成绩
}classA[5] = {
    {"Li ping", 5, 18, 'C', 145.0},
    {"Zhang ping", 4, 19, 'A', 130.5},
    {"He fang", 1, 18, 'A', 148.5},
    {"Cheng ling", 2, 17, 'F', 139.0},
    {"Wang ming", 3, 17, 'B', 144.5}
};
//定义+变量+初始化+不指明数组长度
struct stuC{
    char *name;  //姓名
    int num;  //学号
    int age;  //年龄
    char group;  //所在小组 
    float score;  //成绩
}classC[] = {
    {"Li ping", 5, 18, 'C', 145.0},
    {"Zhang ping", 4, 19, 'A', 130.5},
    {"He fang", 1, 18, 'A', 148.5},
    {"Cheng ling", 2, 17, 'F', 139.0},
    {"Wang ming", 3, 17, 'B', 144.5}
};
int main ()
{
  printf("struct array");
  return(0);
}
```