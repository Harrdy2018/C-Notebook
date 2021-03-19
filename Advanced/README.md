## C语言基础进阶
* [遍历二维数组](./a.md)
* [float和double类型](./b.md)
* [结构体](./struct.md)
* [goto](./goto.md)
* [处理错误信息](./solve_error.md)
* [函数指针](./func_ptr.md)
* [指针数组、数组指针](./ptr_and_arr.md)
* [Volatile](./keyword.md)
### basic
* 0长度数组  结构体实现变长数组的写法
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024
#define CUR 512
struct buffer{
    int len;
    char data[0];
};

void main(void){
    //size
    //0长度数组不占用存储空间
    printf("%d\n",sizeof(struct buffer));//4
    // apply
    struct buffer *p=(struct buffer *)malloc(sizeof(struct buffer)+sizeof(char)*CUR);
    p->len=CUR;
    memcpy(p->data,"Hello World",CUR);
    printf("%d  %s\n",p->len,p->data);
    //destory
    free(p);
    p=NULL;
}
```
### typeof 获取类型
```c
#include <stdio.h>
#include <stdlib.h>
struct apple
{
    int weight;
    int color;
};
struct apple *get_apple_info()
{
    struct apple *a1=malloc(sizeof(struct apple));
    a1->weight=2;
    a1->color=1;
    return a1;
}
int main()
{
    typeof(get_apple_info()) test=get_apple_info();
    printf("weight=%d clolr=%d \n", test->weight, test->color);
    return 0;
}
```
```c
// max宏内(void)(&_x == &_y)语句用于检查参数类型一致性
// 当参数x和y类型不同时，会产生” comparison of distinct pointer types lacks a cast”的编译警告
// 类型不一样，指针所指示的内存空间不一样
#define max(x,y) ({            \
    typeof(x) _max1=(x);       \
    typeof(y) _max2=(y);       \
    (void)(&_max1==&_max2);    \
    _max1>_max2?_max1:_max2;}) \
```
### 结构体成员的偏移地址
```c
#include <stdio.h>
#define offsetof(TYPE, MEMBER) ((unsigned int) &((TYPE *)0)->MEMBER)
struct people {
    int age;
    char name[10];
    int sex;
};
int main()
{
    struct people xiaoming = {
        .age=18,
        .name="xiaoming",
        .sex=0
    };
    printf("address age=%d\n", offsetof(struct people, age));
    printf("address name=%d\n", offsetof(struct people, name));
    printf("address sex=%d\n", offsetof(struct people, sex));
    return 0;
}
```
### container_of
* 已知结构体type的成员member的地址ptr，求解结构体type的起始地址
```c
#include <stdio.h>
#define offsetof(TYPE, MEMBER) ((unsigned int) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({               \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) );})\

struct people {
    int age;
    char name[10];
    int sex;
};
int main()
{
    struct people xiaoming = {
        .age=18,
        .name="xiaoming",
        .sex=0
    };
    printf("start address xiaoming=0x%x\n", &xiaoming);
    printf("start address xiaoming=0x%x\n", container_of(&xiaoming.age, struct people, age));
    printf("start address xiaoming=0x%0x\n", container_of(&xiaoming.name, struct people, name));
    printf("start address xiaoming=0x%0x\n", container_of(&xiaoming.sex, struct people, sex));
    return 0;
}
```
### 网络字节序转换
```c
#define BYTE_REVERT_4(x) \
    ((((x)&0xff000000) >> 24) | (((x)&0x00ff0000) >> 8) | (((x)&0x0000ff00) << 8) | (((x)&0x000000ff) << 24))
#define BYTE_REVERT_3(x) ((((x)&0xff0000) >> 16) | ((x)&0x00ff00) | (((x)&0x0000ff) << 16))
#define BYTE_REVERT_2(x) ((((x)&0xff00) >> 8) | (((x)&0x00ff) << 8))

#ifndef NTOHL
#define NTOHL(x) BYTE_REVERT_4(x)
#endif

#define NTOH3(x) BYTE_REVERT_3(x)

#ifndef NTOHS
#define NTOHS(x) BYTE_REVERT_2(x)
#endif

#ifndef HTONL
#define HTONL(x) BYTE_REVERT_4(x)
#endif

#define HTON3(x) BYTE_REVERT_3(x)

#ifndef HTONS
#define HTONS(x) BYTE_REVERT_2(x)
#endif
```
