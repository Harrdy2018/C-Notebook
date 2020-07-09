## 在一个句子里面反转每一个单词
```c
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int flag = 0;
    while (scanf("%s", str) != -1) {
        if(flag==1){
            printf("%s", " ");
        }
        int len = strlen(str);
        for (int i=len-1;i>=0;i--) {
            printf("%c", str[i]);
        }
        flag = 1;
    }
    return 0;
}
```
```
abc def
cba fed

haha oppo HuaWei
ahah oppo ieWauH
```
