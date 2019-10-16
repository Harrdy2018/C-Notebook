## union 共用体
### 大小
* struct 所占内存长度是其中最大字段大小的整数倍
* union 所占的内存长度等于最长的成员变量的长度
```c
/*共用体所占内存并非是13个字节，而是double的两倍，即16个字节，而且每次输出都是它前面离它最近的值*/
#include <stdio.h>
union Data{
    int i;
    float f;
    char str[13];
    double d;
};
void main(void){
    union Data data;
    printf("%d\n",sizeof(data));
    printf("%d\n",sizeof(double));//8
}
```
### 作用
* 节省内存
### 应用场景
```
通信中的数据包会用到共用体:因为不知道对方会发一个什么包过来，用共用体的话就很简单了，定义几种格式的包，
收到包之后就可以直接根据包的格式取出数据。
```
* 判断主机字节序
```c
#include <stdio.h>
union Data{
    int data;
    char str;
};
void main(void){
    union Data data;
    data.data=0x01020304;
    if(data.str==0x01){
        printf("big end");
    }
    if(data.str==0x04){
        printf("small end");
    }
}
```