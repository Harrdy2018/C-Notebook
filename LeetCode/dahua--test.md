## 浙江大华笔试
* 求CPU 流水线执行指令时间
```
一条指令都可以分解为取指、分析和执行三步。已知取指时间4t，分析时间3t，执行时间5t。
如果按照流水线方式执行，执行完100条指令需要多少时间?
由于是流水线并行执行所以除第一条指令需要（4+3+5）外，其它指令每5执行一条，所以最后的时间是：（4+3+5）+（100-1）*5=507
```
* sizeof()
```c
#include <stdio.h>
void test(char str[]){
    //如果是通过函数传递过来的地址，那么sizeof会把数组首地址和指针无差别当成是地址
    printf("%d\n",sizeof(str));
}
void testB(char *str){
    //如果是通过函数传递过来的地址，那么sizeof会把数组首地址和指针无差别当成是地址
    printf("%d\n",sizeof(str));
}
void main(){
    //str没限制长度，是一个字符串
    char str[]="linux";
    char *p=str;
    printf("%d\n",sizeof(str));//6
    printf("%d\n",sizeof(p));//4
    test("testasc");//4
    testB("testasc");//4
}
```