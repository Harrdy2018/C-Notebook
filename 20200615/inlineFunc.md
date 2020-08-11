### inline function
* 函数内联能消除函数调用的开销
* 被多个源文件调用的内联函数要放在头文件中定义
```c
// inline.h
inline void doSomething();
inline void doSomething()
{
    printf("this is inline function");
}
```
```c
// main.c
#include "inline.h"
int main(int argc, char *argv[])
{
    doSomething();
    return 0;
}
// gcc -c -fgnu89-inline -Wall -g main.c -o main.o
// 编译的时候加上 -fgnu89-inline
```
