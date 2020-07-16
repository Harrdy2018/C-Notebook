* volatile 关键字
* 现在基础不够，还不能完全的理解
```
也就是说, 加上volatile关键字, 相当于程序员告诉编译器:
you! 你不能认为这段代码在当前程序块中它不会有什么用, 
但是有可能在其它地方, 变量可能被程序修改, 程序的运行状态跟外界有关, 你不能优化它, 原原本本地执行它!
```
* static 关键字
* 当我们同时编译多个文件时，所有未加static前缀的全局变量和函数都具有全局可见性
```
C语言中函数定义时前加static 作用
1.作用
函数中加“static”的含义不是指存储方式，而是指对函数的作用域仅局限于本文件。
2.好处
使用内部函数的好处是：不同的人编写不同的函数时，不用担心自己定义的函数，是否会与其它文件中的函数同名，因为同名也没有关系。
3.根本原因
根本原因是C语言中同一个工程中不能有同名函数。
```
```c
//main.c
#include <stdio.h>
//对于函数来讲，static的作用仅限于隐藏
int main()
{
    extern char a;
    extern void msg();
    printf("%c\n", a);
    (void)msg();
    return 0;
}
//test.c
#include<stdio.h>
char a = 'A';
void msg()
{
    printf("%s\n", "Hello");
}
//more.sh
gcc -c main.c test.c
gcc -g main.o test.o  -o main.exe && ./main.exe
rm -rf main.exe main.o test.o
```
