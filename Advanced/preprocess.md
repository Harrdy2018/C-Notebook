## preprocess
```c
#define NAME
#include <stdio.h>
int main()
{
    #ifdef NAME
        printf("you have defined NAME !");
    #else
        printf("you have not defined NAME !");
    #endif
    return 0;
}
```