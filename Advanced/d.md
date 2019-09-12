## goto 控制
* 无条件转移语句
* 可以看出在执行goto flag语句之后直接跳转到flag:printf("nihao\n");
* flag:为标记行，冒号切记不可省略
```c
#include <stdio.h>
void main(void){
    if(1){
        goto flag;
    }
    printf("hello");
    flag: 
        printf("nihao");
        printf("Harrdy\n");
}
```
* 如果程序没经过goto falg; 那么flag:将没有意义
```c
#include <stdio.h>
void main(void){
    if(0){
        goto flag;
    }
    printf("hello");
    flag: 
        printf("nihao");
        printf("Harrdy\n");
}
```
```shell
$ ./test.sh
hellonihaoHarrdy
```