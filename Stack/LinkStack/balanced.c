#include "Stack.h"
char str[100];
LinkStack *obj;
my_bool isLeftParenthese(char ch){
    switch(ch){
        case '(':
        case '[': 
        case '{': return my_true;
        default : return my_false;
    }
}
char LefttoRight(char ch){
    switch(ch){
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
    }
}
my_bool test(){
    int i=0;
    while(str[i] != '\0'){
        if(isLeftParenthese(str[i])){
            Push(obj,str[i]);
        }else{
            if(isEmpty(obj)){
                return my_false;
            }else{
                int ele;
                GetTop(obj,&ele);
                if(LefttoRight((char)ele)==str[i]){
                    Pop(obj,&ele);
                }else{
                    return my_false;
                }
            }
        }
        i++;
    }
    if(isEmpty(obj)){
        return my_true;
    }else{
        return my_false;
    }
}
int main(void){
    //([{}])
    printf("****balanced****\n");
    scanf("%s",str);
    printf("%s\n",str);
    obj=InitLinkStack();
    printf("%d\n",test());
    return 0;
}