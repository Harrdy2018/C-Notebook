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
