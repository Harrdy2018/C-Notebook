## 函数指针
```
如果在程序中定义了一个函数，那么在编译时系统就会为这个函数代码分配一段存储空间，这段存储空间的首地址称为这个函数的地址。
而且函数名表示的就是这个地址。既然是地址我们就可以定义一个指针变量来存放，这个指针变量就叫作函数指针变量，简称函数指针。
int(*p)(int, int);
定义了一个指针变量 p，该指针变量可以指向返回值类型为 int 型，且有两个整型参数的函数。
```
* 函数返回值类型 (* 指针变量名) (函数参数列表);
```c
#include <stdio.h>
int Func(int x);/*声明一个函数*/
int Func(int x){
    return x;
}
int main(void){
    printf("%p %p\n",Func,&Func);//00401410  00401410
    int (*p1) (int x);  /*定义一个函数指针*/
    int (*p2) (int x);
    p1 = Func;          /*将Func函数的首地址赋给指针变量p1*/
    printf("%d %d\n",p1(2),(*p1)(2));//2  2
    p2 = &Func;          /*将Func函数的首地址赋给指针变量p2*/
    printf("%d %d\n",p2(2),(*p2)(2));//2  2
    return 0;
}
```
* example
```c
#include <stdio.h>
int Max(int a,int b){
    if(a==b){
        return a;
    }
    return a>b ? a : b; 
}
int main(void){
    int (*p)(int a,int b);
    p=Max;
    printf("%d\n",(*p)(3,4));//4
    printf("%d\n",(*p)(3,3));//3
    return 0;
}
```
### 应用场景
* 函数指针通常用作回调函数 只提供一个函数的原型，具体的实现由调用者设定
* 函数指针的一个典型应用场合是实现回调。为什么要回调？
* 就是因为此时还不知道具体函数定义，事件发生时才调用、才确定；类比于面向对象中的“多态”+设计模式中的“观察者模式”，回调的实质仍然是抽象
```c
#include <stdio.h>
void dog_printf(){
    printf("I am a dog!\n");
}
void cat_printf(){
    printf("I am a cat!\n");
}
void test(void (*p)(void)){
    p();
}
void main(void){
    test(dog_printf);//I am a dog!
    test(cat_printf);//I am a cat!
}
```
* 用typedef来定义一个指针函数这样使在大型代码中更加简洁
```
这里面的pfun代表的是函数的类型，通过pfun来代表void (*)(int)函数类型即pfun是指针函数的别名，
pfun p相当于定义了一个void (*p)(int)函数指针
```
```c
#include<stdio.h>
typedef void (*pfun)(int data);
void myfun(int data)
{
    printf("%d\n",data);
}
int main()
{
    pfun p=myfun;
    (*p)(100);
    return 0;
}
```
* 第三种用结构体函数指针的方法
```c
#include<stdio.h>
typedef struct gg
{
    void (*pfun)(int data);
}gg;

void myfun(int data)
{
    printf("%d\n",data);
}
int main()
{
    gg gcode;
    gcode.pfun=myfun;
    (gcode.pfun)(100);
    return 0;
}
```
