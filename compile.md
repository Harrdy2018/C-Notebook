## compile 知识
### gcc 编译流程
* ```c语言源文件```经过```预处理```得到```预处理后的文件```
* ```预处理后的文件```经过```编译```得到```汇编文件```
* ```汇编文件```经过```汇编器```得到```目标文件```
* ```目标文件```经过```链接```得到```可执行程序```
### GCC常用编译选项
* -E 仅仅预处理，不编译、汇编、链接
* -S 仅仅编译指定的源文件，不汇编、链接
* -c 编译、汇编指定的源文件，但是不链接
* -o file 指定输出文件
* -I directory 指定```include```包含问价的搜索目录
* -g 生成能被```gdb```调试器所使用的调试信息
### compile
* -E 预处理(preprocess)
```
gcc -E test.c -o test.i 等价于 gcc -E test.c > test.i 
保留注释 gcc -E -C test.c -o test.i
```
* -S 编译(compile) 生成汇编代码文件
```
gcc -S test.i -o test.s
```
* -c 由汇编器将汇编代码转变成机器可以执行的指令得到目标文件
```
gcc -c test.s -o test.o
```
* 链接 链接到库中，变成可执行文件
```
gcc test.o -o test
```
### 一步到位编译
* gcc test.c -o test
### 动态链接库
* math.h中使用 cos需要链接数学库 gcc main.c -lm -o app
* -L参数 为 GCC 增加另一个搜索链接库的目录 gcc main.c -lm -L/usr/lib64/ -o app
```sh
[root@localhost Desktop]# find / -name libm.so
/usr/lib64/libm.so
[root@localhost Desktop]# ll /usr/lib64/ | grep libm.so
lrwxrwxrwx   1 root root       21 Jul 15  2018 libm.so -> ../../lib64/libm.so.6
lrwxrwxrwx.  1 root root       12 Jul  5  2018 libm.so.6 -> libm-2.17.so
```
### 生成动态链接库
```
.so--->shared object file，共享对象文件，它是一种特殊的目标文件（object file），可以在程序运行时被加载（链接）进来。
使用动态链接库的优点是：程序的可执行文件更小，便于程序的模块化以及更新，同时，有效内存的使用效率更高。
创建一个动态链接库，可以使用 GCC 的-shared选项。输入文件可以是源文件、汇编文件或者目标文件。
-fPIC 选项作用于编译阶段，告诉编译器产生与位置无关代码（Position-Independent Code）；
这样一来，产生的代码中就没有绝对地址了，全部使用相对地址，所以代码可以被加载器加载到内存的任意位置，都可以正确的执行。
这正是共享库所要求的，共享库被加载时，在内存的位置不是固定的。
```
* 从源文件生成动态链接库：gcc -fPIC -shared hello.c -o libhello.so
* 从目标文件生成动态链接库：
```sh
gcc -fPIC -c hello.c -o hello.o
gcc -shared hello.o -o libhello.so
# -fPIC 选项作用于编译阶段，在生成目标文件时就得使用该选项，以生成位置无关的代码
```
* 将动态链接库链接到可执行文件 gcc main.c libhello.so -o app
* 将动态链接库链接到可执行文件 gcc main.c -lhello -L. -o app
### 动态库路径问题
* 动态库搜索路径顺序
```
编译时自定义
LD_LIBRARY_PATH
/etc/ld.so.conf
```
* 环境变量 LD_LIBRARY_PATH
```sh
echo $LD_LIBRARY_PATH
export LD_LIBRARY_PATH=newPath:$LD_LIBRARY_PATH
```
* /etc/ld.so.conf 编译时使用的动态库的路径，加载so库的路径
```
一般的话，/lib   /usr/lib  /usr/lib64  /usr/local/lib 会存于配置文件之中
配置完之后运行  ldconfig  是将/etc/ld.so.conf列出下的路径下的库文件缓存到/etc/ld.so.cache以供使用
whereis ldconfig
/usr/sbin/ldconfig
```
### why? extern "C" {} ?
* util.h
```c
// util.h

#ifndef UTIL_H
#define UTIL_H
int add(int, int);
#endif
```
* util.c
```c
// util.c

int add(int a, int b)
{
	return a + b;
}
```
* main.c
```c
// main.c

#include <stdio.h>
#include "util.h"

int main(int argc, char *argv[])
{
	int sum = add(1, 2);
	printf("%d\n", sum);
	return 0;
}
```
* gcc 编译 add还是add
```sh
[root@localhost Desktop]# gcc -c main.c -o main.o && objdump -t main.o

main.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 main.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .rodata	0000000000000000 .rodata
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	000000000000003c main
0000000000000000         *UND*	0000000000000000 add
0000000000000000         *UND*	0000000000000000 printf
```
* g++ 编译 add变成了_Z3addii(g++编译器原因,因为C++支持函数重载（函数名称相同，参数列表不同）)
```sh
[root@localhost Desktop]# g++ -c main.c -o main.o && objdump -t main.o

main.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 main.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .rodata	0000000000000000 .rodata
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	000000000000003c main
0000000000000000         *UND*	0000000000000000 _Z3addii
0000000000000000         *UND*	0000000000000000 printf
```
* _Z3adddd，表示参数列表为两个double类型的add函数，（3代表函数名称是3个字符）
* _Z3addii，表示参数列表为两个int类型的add函数
```sh
[root@localhost Desktop]# cat main.c
// main.c

#include <stdio.h>
#include "util.h"

int add(double a, double b)
{
	return a+b;
}

int main(int argc, char *argv[])
{
	int sum = add(1, 2);
	printf("%d\n", sum);
	return 0;
}
[root@localhost Desktop]# g++ -c main.c -o main.o && objdump -t main.o

main.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 main.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .rodata	0000000000000000 .rodata
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	000000000000001e _Z3adddd
000000000000001e g     F .text	000000000000003c main
0000000000000000         *UND*	0000000000000000 _Z3addii
0000000000000000         *UND*	0000000000000000 printf
```
* 起源
```
由于gcc和g++生成符号表的方式不同，导致在C++项目中如果使用gcc编译的C模块，会出现链接错误。
因为链接器会去C模块的（.o）文件中查找，_Z3addii这样的符号。
显然在C模块的目标文件(.o)中，不存在_Z3addii这样的符号，它有的只是_add。

什么叫：C++项目中如果使用gcc编译的C模块？
一个项目整体是C++项目，最终编译用g++编译，此时来了一个经过gcc编译的util.o目标文件，也就是一个C模块
```
* 解决办法
```sh
[root@localhost Desktop]# cat util.c
// util.c

int add(int a, int b)
{
	return a + b;
}
[root@localhost Desktop]# cat util.h
// util.h

#ifndef UTIL_H
#define UTIL_H
extern "C" int add(int, int);
#endif
[root@localhost Desktop]# cat main.c
// main.c
#include <stdio.h>
#include "util.h"
int main(int argc, char *argv[])
{
	int sum = add(1, 2);
	printf("%d\n", sum);
}
```
* c模块
```sh
[root@localhost Desktop]# gcc -c util.c -o util.o && objdump -t util.o

util.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 util.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	0000000000000014 add
```
* c++项目
```sh
[root@localhost Desktop]# g++ -c main.c -o main.o && objdump -t main.o

main.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 main.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .rodata	0000000000000000 .rodata
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	000000000000003c main
0000000000000000         *UND*	0000000000000000 add
0000000000000000         *UND*	0000000000000000 printf
```
#### c模块头文件中的extern "C" {}标准写法
```sh
 [root@localhost Desktop]# cat util.h
// util.h
#ifndef UTIL_H
#define UTIL_H

#ifdef __cplusplus
extern "C" {
#endif
int add(int, int);
#ifdef __cplusplus
}
#endif

#endif
[root@localhost Desktop]# cat main.c
// main.c
#include <stdio.h>
#include "util.h"
int main(int argc, char *argv[])
{
	int sum = add(1, 2);
	printf("%d\n", sum);
	return 0;
}
```
* g++编译有 __cplusplus宏
```sh
[root@localhost Desktop]# g++ -c main.c -o main.o && objdump -t main.o

main.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 main.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .rodata	0000000000000000 .rodata
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	000000000000003c main
0000000000000000         *UND*	0000000000000000 add
0000000000000000         *UND*	0000000000000000 printf
```
* gcc编译没有 __cplusplus宏
```sh
[root@localhost Desktop]# gcc -c main.c -o main.o && objdump -t main.o

main.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 main.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .rodata	0000000000000000 .rodata
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	000000000000003c main
0000000000000000         *UND*	0000000000000000 add
0000000000000000         *UND*	0000000000000000 printf
```
