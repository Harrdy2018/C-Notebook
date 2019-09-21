## 深信服 linux
* Linux 系统启动过程
```
内核的引导
运行init
系统初始化
建立终端
用户登录系统
```
* 进程间通信的方式
```
管道(pipe)(包括匿名管道和命名管道)
信号(signal)
消息队列(queue)
共享内存(最快)
信号量
套接字
```
* sizeof
```c
#include <stdio.h>
#include <string.h>
void main(void){
    //p 与 [] 结合
    int p[10];
    printf("%d\n",sizeof(p));//40
    //k 先与 [] 结合
    int *k[10];
    printf("%d\n",sizeof(p));//40
    //m 直接与 * 结合，表示普通指针
    int (*m)[10];
    printf("%d\n",sizeof(m));//4
    //str 是个指向字符串首地址的指针
    char *str="oppolp";
    printf("%d %d\n",strlen(str),sizeof(str));//6 4
    //pp 是个字符串
    char pp[]={'o','p','p','o','l','p','\0'};
    printf("%d %d\n",strlen(pp),sizeof(pp));//6 7
    //test 是个字符串
    char test[]="oppolp";
    printf("%d %d\n",strlen(test),sizeof(test));//6 7
    //aa 是个字符数组，因为限制了长度
    char aa[6]="oppolp";
    printf("%d\n",sizeof(aa));//6
}
```
* 宏定义求最大值
```c
#include <stdio.h>
#define max(a,b) (a>b ? a:b)
#define Max(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))
void main(void){
    printf("%d\n",max(2,1));//2
    printf("%d\n",max(1,2));//2
    printf("%d\n",Max(1,2,3));//3
    printf("%d\n",Max(1,3,2));//3
    printf("%d\n",Max(2,3,1));//3
}
```
* 进程有几种状态
* 中断和轮询
* leetcode 151 反转字符串里的单词
* 数组和链表的比较
```
数组和链表有以下不同：
（1）存储形式：数组是一块连续的空间，声明时就要确定长度。链表是一块可不连续的动态空间，长度可变，每个节点要保存相邻结点指针；
（2）数据查找：数组的线性查找速度快，查找操作直接使用偏移地址。链表需要按顺序检索结点，效率低；
（3）数据插入或删除：链表可以快速插入和删除结点，而数组则可能需要大量数据移动；
（4）越界问题：链表不存在越界问题，数组有越界问题。
数组便于查询，链表便于插入删除。数组节省空间但是长度固定，链表虽然变长但是占了更多的存储空间。
```