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
    printf("%p\n",Func);//00401410
    int (*p) (int x);  /*定义一个函数指针*/
    p = Func;          /*将Func函数的首地址赋给指针变量p*/
    printf("%d\n",(*p)(2));//2
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