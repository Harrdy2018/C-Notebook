## static 关键字
* 多文件编译的时候 隐藏
* a.c file
```c
#include <stdio.h>
int a=123;
static int b=234;
void test(){
    printf("Hello World!!!\n");
}
static void TEST(){
    printf("Hello World\n");
}
```
* main.c file
```c
#include <stdio.h>
void main(void){
    extern int a;
    extern int b;
    printf("%d\n",a);
    //printf("%d\n",b);
    test();
    //TEST();
}
```
* 保持变量内容的持久
```c
#include <stdio.h>
/*
存储在静态数据区的变量会在程序刚开始运行时就完成初始化，也是唯一的一次初始化。
共有两种变量存储在静态存储区：全局变量和static变量，只不过和全局变量比起来，static可以控制变量的可见范围，说到底static还是用来隐藏的。
即使变量名相同，全局变量和static变量的地址也不一样
*/
int test(){
    static int count=10;// 事实上此赋值语句从来没有执行过
    return count--;
}
int count=1;
void main(void){
    for(;count<=10;++count){
        printf("%d   %d\n",count,test());
    }
}
/*
1   10
2   9
3   8
4   7
5   6
6   5
7   4
8   3
9   2
10   1
*/
```
* static的第三个作用是默认初始化为0。
```
其实全局变量也具备这一属性，因为全局变量也存储在静态数据区。
在静态数据区，内存中所有的字节默认值都是0x00，某些时候这一特点可以减少程序员的工作量。
比如初始化一个稀疏矩阵，我们可以一个一个地把所有元素都置0，然后把不是0的几个元素赋值。如果定义成静态的，就省去了一开始置0的操作。
再比如要把一个字符数组当字符串来用，但又觉得每次在字符数组末尾加’\0’太麻烦。如果把字符串定义成静态的，就省去了这个麻烦，因为那里本来就是’\0’
```
```c
#include <stdio.h>
int a;
int arr[10];
void main(void){
    int i;
    static char str[10];
    printf("%d\n",a);
    printf("%d\n",i);
    printf("start%send\n",str);
    for(int j=0;j<10;j++){
        printf("%d\n",arr[j]);
    }
}
```