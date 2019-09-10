```c
/* Close the file descriptor FD.*/
extern int close (int __fd);
/* Read NBYTES into BUF from FD.  Return the
   number read, -1 for errors or 0 for EOF. */
extern ssize_t read (int __fd, void *__buf, size_t __nbytes) __wur;
/* Write N bytes of BUF to FD.  Return the number written, or -1.*/
extern ssize_t write (int __fd, const void *__buf, size_t __n) __wur;
/* unistd.h  */
```
* example
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void main(void){
    char *p=(char *)malloc(1024*sizeof(char));
    memset(p,0,1024*sizeof(char));
    /*比如输入qw  实际上p="qw\r\n"*/
    int ret=read(0,p,1024);
    for(int i=0;p[i] != '\0';i++){
        printf("%d**%c**%d",i,p[i],p[i]);
    }
    printf("\n");
    printf("num read %d  len %d\n",ret,strlen(p));

    for(int i=0;p[i] != '\0';i++){
       	int num=write(1,&p[i],1);
	printf("have write %d\n",num);
    }
    free(p);
    p=NULL;
}
```
* 输入a的时候  读到的实际实际上是['a','回车换行','\0']
* linux上将\r\n看成是一个字符
* strlen计算字符串的实际长度
* fd=0表示标注输入 fd=1表示标准输出
```
[harrdy@localhost Desktop]$ gcc -g -std=c99  main.c -o main.o && ./main.o
a
0**a**971**
**10
num read 2  len 2
ahave write 1

have write 1
```