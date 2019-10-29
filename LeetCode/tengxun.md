## 腾讯 测试开发面试
* 宏定义求数组长度(答对)
```c
#include<stdio.h>
#define ARRAY_SIZE(ARRAY) (sizeof(ARRAY)/sizeof(ARRAY[0]))
int main(void) {
    int arr[]={1,2,3,4,5};
    printf("%d\n",ARRAY_SIZE(arr));//5
    char str[]="12345";
    printf("%d\n",ARRAY_SIZE(str));//6
    return 0;
}
```
