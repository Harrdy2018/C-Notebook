## 数组基本知识
* 数组可变长度
```c
//数组长度初始化问题
#include <stdio.h>
int main(void){
    int len=3;
    int arr[len];
    //可变长度数组申明没问题，赋值有问题
    //int arr[len]={1,2,3};
    printf("%d\n",sizeof(arr));
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    for(int i=0;i<len;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
```