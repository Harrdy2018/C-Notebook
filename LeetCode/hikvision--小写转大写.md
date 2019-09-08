* for循环控制用的很妙
```c
#include <stdio.h>
void test(char *s){
    for(int i=0;s[i];i++){
        if(s[i]>='a' && s[i]<='z'){
            s[i]+='A'-'a';
        }
    }
}
int main(){
    char str[]="Hello";
    test(str);
    printf("%s\n",str);
}
```
* my
```c
#include <stdio.h>
void test(char *s){
    int i=0;
    while(s[i] != '\0'){
        if(s[i]>='a' && s[i]<='z'){
            s[i]=s[i]-('a'-'A');
        }
        i++;
    }
}
int main(){
    char str[]="Hello";
    test(str);
    printf("%s\n",str);
}
```