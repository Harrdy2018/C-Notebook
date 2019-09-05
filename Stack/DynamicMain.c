#include <stdio.h>
#include "DynamicStack.h"
int main(void){
    Stack *pStack=InitStack();
    printf("the capcity of stack is %d\n",pStack->capacity);
    printf("****************************************************\n");
    int arr[]={1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        Push(pStack,arr[i]);
        printf("the capcity of stack is %d\n",pStack->capacity);
    }
    TraverseStack(pStack);
    printf("****************************************************\n");
    while(!isEmpty(pStack)){
        int e;
        Pop(pStack,&e);
        printf("pop %d\n",e);
        printf("the capcity of stack is %d\n",pStack->capacity);
        TraverseStack(pStack);
    }
    return 0;
}