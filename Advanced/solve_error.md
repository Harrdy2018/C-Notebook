```c
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
/*
errno.h头文件里面 
extern int errno;
errno变量表示error的标记*/
/*
string.h头文件里面
extern char *strerror (int __errnum) __THROW;
函数返回一个描述'errno'值的string*/
/*
stdlib.h头文件里面
extern void perror (const char *__s);
打印描述errno值的意思
*/
void main(void){
    for(int i=0;i<10;i++){
        errno=i;
        printf("test: %s\n",strerror(errno));
    }
    errno=0;
    perror("test");
    errno++;
    perror("test");
}
/*
test: No error
test: Operation not permitted
test: No such file or directory
test: No such process
test: Interrupted function call
test: Input/output error
test: No such device or address
test: Arg list too long
test: Exec format error
test: Bad file descriptor
test: No error
test: Operation not permitted
*/
/*
printf("test: %s\n",strerror(errno));
等效于
perror("test");
*/
```