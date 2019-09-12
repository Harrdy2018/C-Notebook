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
### 结构体指针
* 结构体指针实例
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu{
  char *name;
}stu1={"lukang"};
int main ()
{
  struct stu *p=&stu1;
  printf("%s\n",p->name);
  return 0;
}
```
* 定义结构体的同时，定义结构体指针
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu{
  char *name;
}stu1={"lukang"},*p=&stu1;
int main ()
{
  printf("%s\n",p->name);
  return 0;
}
```
* 只是简单的将结构体的首地址赋值给一个指针
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu{
  char *name;
}class[2]={
  {"lukang"},
  {"hewen"}
},*p=class;
int main ()
{
  int len=sizeof(struct stu);
  int lenw=sizeof(class);
  printf("%d %d\n",len,lenw);
  printf("%s %s\n",p->name,(p+1)->name);
  return 0;
}
```
* 结构体指针数组
```
struct stu *p[2]={&stu1,&stu2};
本质上是一个数组，数组里面装的是结构体的地址，为什么呢因为，*p[2],这个*是与后面结合，即*p[2]===*(p[2])
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu{
  char *name;
}stu1={"lukang"},stu2={"hewen"};
int main ()
{
  struct stu *p[2]={&stu1,&stu2};
  printf("%s %s\n",p[0]->name,p[1]->name);
  return 0;
}
```
* hikvison 选择题
```c
#include <stdio.h>
struct c{
    int x;
    int y;
}s[2]={2,3,4,7},k[2]={{2,3},{4,7}};
int main(void)
{
    printf("hello world\n");
    printf("%d %d %d %d\n",s[0].x,s[0].y,s[1].x,s[1].y);//2 3 4 7
    printf("%d %d %d %d\n",k[0].x,k[0].y,k[1].x,k[1].y);//2 3 4 7
	return 0;
}
```
