## 关键字__attribute__ 
* 可以对结构体（struct ）或共用体（union ）进行属性设置。
* 大致有六个参数值可以被设定，即：aligned, packed, transparent_union, unused, deprecated 和 may_alias 
* __attribute__((aligned(8))) 设置8字节对齐
* __attribute__((packed)) 的作用就是告诉编译器取消结构在编译过程中的优化对齐,按照实际占用字节数进行对齐。
```c
void test()
{
    printf("%s\n", "Hello World!");
    struct student1{
        char name[7];
        int id;
        char subject[5];
    };
    printf("size of student1=%d\n", sizeof(struct student1));//20
    struct student2{
        char name[7];
        int id;
        char subject[5];
    }__attribute__((aligned(4)));
    printf("size of student2=%d\n", sizeof(struct student2));//20
    struct student3{
        char name[7];
        int id;
        char subject[5];
    }__attribute__((aligned(8)));
    printf("size of student3=%d\n", sizeof(struct student3));//24
    struct student4{
        char name[7];
        int id;
        char subject[5];
    }__attribute__((packed));
    printf("size of student4=%d\n", sizeof(struct student4));//16
}
```
* __attribute__((aligned)) 默认对齐方式
```c
struct student1{
    char name[7];
    int id;
    char subject[5];
}__attribute__((aligned));
printf("size of student1=%d\n", sizeof(struct student1));//32
```
### __attribute__((constructor)) && __attribute__((destructor))
* 可以修饰函数，constructor参数让系统执行main()函数之前调用函数.同理, destructor让系统在main()函数退出或者调用了exit()之后,调用函数
```c
#include <stdio.h>
#include "test.h"
__attribute__((destructor))
static void afterFunction()
{
    printf("%s\n", "afterFunction");

}
int main(int argc, char *argv[])
{
    //test();
    printf("%s\n", "main function");
    return 0;
}
__attribute__((constructor)) static void beforeFunction()
{
    printf("%s\n", "beforeFunction");

}
/*
$ ./more.sh
beforeFunction
main function
afterFunction
*/
```
* 带有优先级的 这个1-100的范围是保留的,所以,最好从100之后开始用
```c
#include <stdio.h>
#include "test.h"
// 声明和实现分离的写法如下
// 申明
__attribute__((constructor(201))) static void beforeFunctionA();
//实现
static void beforeFunctionA()
{
    printf("%s\n", "beforeFunctionA");
}
__attribute__((constructor(101))) static void beforeFunctionB()
{
    printf("%s\n", "beforeFunctionB");
}
static __attribute__((constructor(108))) void beforeFunctionC()
{
    printf("%s\n", "beforeFunctionC");
}
int main(int argc, char *argv[])
{
    //test();
    printf("%s\n", "main function");
    return 0;
}
```
