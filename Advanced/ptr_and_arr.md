## 指针数组
* [] 的优先级高于 * 的优先级
* 存储指针的数组
* int *p[10];   //一个数组，内部含有10个指向int类型的指针
```c
#include <stdio.h>
int main(void){
    int *p[3];
    int a=1,b=2,c=3;
    p[0]=&a;
    p[1]=&b;
    p[2]=&c;
    for(int i=0;i<3;i++){
        printf("%d\n",*(p[i]));
    }
    return 0;
}
```
## 数组指针
* 指向数组的指针
* int (*p)[10];  // 一个指针，它指向一个有10个int元素的数组
* int arr[3][10]; //与多维对比
```c
#include <stdio.h>
int main(void){
    int (*p)[3];
    int arr[2][3]={
        {1,2,3},
        {4,5,6}
    };
    p=arr+1;
    printf("%d\n",(*p)[0]);//4
    printf("%d\n",(*p)[1]);//5
    printf("%d\n",(*p)[2]);//6
    return 0;
}
```
* 数组名表示指向首元素的首地址，是一个指向普通变量的指针常量,当对其+1时偏移量是一个普通数据类型的内存大小
* &数组名表示的就是一个指向数组的指针常量，对其+1时偏移量是一个数组的内存大小
```
#include <stdio.h>
void main(void){
    int arr[3]={1,2,3};
    printf("%p %p\n",arr,arr+1);//0061FF24 0061FF28
    printf("%p %p\n",&arr,&arr+1);//0061FF24 0061FF30
    int (*p)[3]=&arr;
    printf("%p %p\n",p,p+1);//0061FF24 0061FF30
}
```
