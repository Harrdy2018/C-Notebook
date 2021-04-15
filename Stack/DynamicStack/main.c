#include <stdio.h>
#include "Stack.h"
int main(void){
    Stack *pStack=InitStack(2);
    printf("the capcity of stack is %d\n",pStack->capacity);
    printf("****************************************************\n");
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++){
        PushStack(pStack,arr[i]);
        printf("the capcity of stack is %d\n",pStack->capacity);
    }
    TraverseStack(pStack);
    printf("****************************************************\n");
    while(!IsEmptyStack(pStack)){
        int e;
        PopStack(pStack,&e);
        printf("pop %d\n",e);
        printf("the capcity of stack is %d\n",pStack->capacity);
        TraverseStack(pStack);
    }

    /* 进制转换 */
    int num=100;
    Stack *obj=InitStack(1);
    while(num!=0){
        PushStack(obj,num%8);
        num=num/8;
    }
    printf("the capcity of stack is %d\n",obj->capacity);
    while(!IsEmptyStack(obj)){
        int e;
        PopStack(obj,&e);
        printf("%d",e);
    }
    return 0;
}
