## 宏定义
### ## 作用 连接操作符
* 整形的宏参数连接成一个数
```c
#include <stdio.h>
#define link(x,y) (x##y)
#define test(a,b) a##b
int main(){
    int num=link(12,34);
    int nj=test(12,32);
    printf("%d\n",num);//1234
    printf("%d\n",nj);//1232
}
```
* 网络编程运用
```c
#include <stdio.h>
#include <string.h>
typedef unsigned short int sa_family_t;
#define __SOCKADDR_COMMON(sa_prefix) sa_family_t sa_prefix##family
struct sockaddr_un{
        __SOCKADDR_COMMON (sun_);
        char sun_path[108];
    };
int main(){
   struct sockaddr_un test;
   test.sun_family=2;
   //why?? test.sun_path="lukang";
   strcpy(test.sun_path,"lukang");
   printf("%d  %s\n",(&test)->sun_family,(&test)->sun_path);
}
```
### 空格 作用 连接操作符
* 字符串形的宏参数连接成一个新的字符串
```c
#include <stdio.h>
#define link(x,y) (x y)
#define test(a,b) a b
int main(){
    char *str=link("abc","def");
    char *obj=test("sd","ooo");
    printf("%s\n",str);//abcdef
    printf("%s\n",obj);//sdooo
}
```
### # 作用 字符串化操作符
* #的作用就是讲#后面的宏参数进行字符串的操作，也就是将#后面的参数两边加上一对双引号使其成为字符串
```c
#include <stdio.h>
#define change(x) #x
int main(){
    char *str=change(12.34);
    printf("%s\n",str);//"12.34"
}
```
### #@ 字符化操作符
* 目前好像不支持呀
```c
```
### \ 行继续操作
* 写较长的宏
```c
#include <stdio.h>
#define test(a,b) { \
printf("%d\n",a); \
printf("%d\n",b);}
int main(){
    test(12,23);
}
```