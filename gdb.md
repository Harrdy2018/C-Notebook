## gdb 知识
### 你gdb了么？？？
### 如何进入调试系统
* test.c
```c
#include <stdio.h>
void digui(int n)
{
    printf("level1-value of %d\n", n);
    if(n>2){
        digui(n-1);
    }
    printf("level2-value of %d\n", n);
}
int main()
{
    int n=4;
    digui(n);
    return 0;
}
```
* gcc -g test.c -o test && ./test.exe
* 进入调试系统 gdb test.exe
### 调试基础命令
* list 使用list命令的时候默认输出源代码10行，并且依次累加
```sh
(gdb) show listsize
Number of source lines gdb will list by default is 10.
```
```sh
(gdb) set listsize 12  #设置显示行数，默认为10
(gdb) list 1,1         #显示1,1行的源代码
1       #include <stdio.h>
(gdb) list
2       void digui(int n)
3       {
4           printf("level1-value of %d\n", n);
5           if(n>2){
6               digui(n-1);
7           }
8           printf("level2-value of %d\n", n);
9       }
10      int main()
11      {
12          int n=4;
13          digui(n);
```
* 断点
```sh
(gdb) break 6  #第6行设置断点
Breakpoint 1 at 0x40142f: file test.c, line 6.
(gdb) break 8  #第8行设置断点
Breakpoint 2 at 0x40143d: file test.c, line 8.
(gdb) info breakpoints  #显示断点信息
Num     Type           Disp Enb Address    What
1       breakpoint     keep y   0x0040142f in digui at test.c:6
2       breakpoint     keep y   0x0040143d in digui at test.c:8
(gdb) clear 6 #删除6行的断点
Deleted breakpoint 1
(gdb) clear 8  #删除8行的断点
Deleted breakpoint 2
# (gdb) delete breakpoints 2 #删除第二个断点
(gdb) info breakpoints
No breakpoints or watchpoints.
```
### 调试
* break 6
* break 8
* run
```sh
(gdb) run     #执行遇到第一个断点就停止了
Starting program: C:\Users\Harrdy\Desktop\C-Notebook\LocalTest/test.exe
[New Thread 10720.0x4704]
[New Thread 10720.0x2d44]
level1-value of 4

Breakpoint 1, digui (n=4) at test.c:6
6               digui(n-1);
```
* continue
```sh
(gdb) continue  #继续执行遇到断点就停止
Continuing.
level1-value of 3

Breakpoint 1, digui (n=3) at test.c:6
6               digui(n-1);
```
### 例子
```c
#include <stdio.h>
int main()
{
    int a=4;
    int b=5;
    int c=6;
    return 0;
}
```
* 断点打到哪里，只会执行到行首，不会执行这一行代码
```sh
(gdb) break 4
Breakpoint 1 at 0x40141e: file test.c, line 4.
(gdb) break 5
Breakpoint 2 at 0x401426: file test.c, line 5.
(gdb) break 6
Breakpoint 3 at 0x40142e: file test.c, line 6.
(gdb) run
Starting program: C:\Users\Harrdy\Desktop\C-Notebook\LocalTest/test.exe
[New Thread 12904.0x66c]
[New Thread 12904.0xaec]

Breakpoint 1, main () at test.c:4
4           int a=4;
(gdb) print a
$1 = 4194432
(gdb) print b
$2 = 2478080
(gdb) print c
$3 = 0
(gdb) continue
Continuing.

Breakpoint 2, main () at test.c:5
5           int b=5;
(gdb) print a
$4 = 4
(gdb) print b
$5 = 2478080
(gdb) print c
$6 = 0
(gdb) continue
Continuing.

Breakpoint 3, main () at test.c:6
6           int c=6;
(gdb) print a
$7 = 4
(gdb) print b
$8 = 5
(gdb) print c
$9 = 0
```
### 多文件调试技巧
* 断点
```sh
(gdb) break test.c:5
Breakpoint 2 at 0x401449: file test.c, line 5.
(gdb) info breakpoints
Num     Type           Disp Enb Address    What
1       breakpoint     keep y   0x0040141e in main at main.c:5
        breakpoint already hit 1 time
2       breakpoint     keep y   0x00401449 in yy at test.c:5
```
* next 继续执行下一条语句 不会跟踪进入函数，而是继续执行下面的语句
* step 继续执行下一条语句 会跟踪进入函数内部
### print/f 表达式
* x(hex) 按十六进制格式显示变量。
* d(decimal) 按十进制格式显示变量。
* u(unsigned decimal) 按十进制格式显示无符号整型。
* o(octal) 按八进制格式显示变量。
* t(binary) 按二进制格式显示变量。
* a(address) 按十六进制格式显示变量。
* c(char) 按字符格式显示变量。
* f(float) 按浮点数格式显示变量
* i(instruction)
* s(string)
```
(gdb) print a=65
$15 = 65
(gdb) print/x a
$18 = 0x41
(gdb) print/d a
$19 = 65
(gdb) print/u a
$20 = 65
(gdb) print/o a
$21 = 0101
(gdb) print/t a
$22 = 1000001
(gdb) print/a a
$23 = 0x41
(gdb) print/c a
$26 = 65 'A'
(gdb) print/f a
$27 = 9.10844002e-44
```
### x/nfu address 表达式
* n: 需要显示的内存单元个数，也就是从当前地址向后显示几个内存单元的内容，一个内存单元的大小由后面的u定义
* f：显示格式
```
x(hex) 按十六进制格式显示变量。
d(decimal) 按十进制格式显示变量。
u(unsigned decimal) 按十进制格式显示无符号整型。
o(octal) 按八进制格式显示变量。
t(binary) 按二进制格式显示变量。
a(address) 按十六进制格式显示变量。
c(char) 按字符格式显示变量。
f(float) 按浮点数格式显示变量
```
* u：每个单元的大小，按字节数来计算。默认是4 bytes。GDB会从指定内存地址开始读取指定字节，并把其当作一个值取出来，并使用格式f来显示
* b:1 byte     h:2 bytes     w:4 bytes g:8 bytes
* b(byte), h(halfword), w(word), g(giant, 8 bytes).
* 比如x/3uh 0x54320表示从内存地址0x54320读取内容，h表示以双字节为单位，3表示输出3个单位，u表示按照十六进制显示。
### 调用函数
* 一般入参
```sh
call (void)adda(1,2)
call (int)addb(1,2)

p adda(1,2)
p big=22 # p改变入参值
p adda(big,13)
```
* 结构体入参
```sh
(gdb) p (Student *)malloc(sizeof(Student))
$29 = (Student *) 0x9a17d8
(gdb) p ((Student *)0x9a17d8)->age=123
$30 = 123
(gdb) p ((Student *)0x9a17d8)->name="oppo"
$31 = "oppo\000\000\000\000\000"
(gdb) call (void)printStruct(((Student *)0x9a17d8))
123--oppo
(gdb) p sizeof(Student)
$32 = 16
(gdb) p sizeof(Student *)
$33 = 4
```
