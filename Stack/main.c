#include <stdio.h>
#include "Stack.h"
int main(void){
    Stack *pStack=InitStack();
    int arr[]={1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        Push(pStack,arr[i]);
    }
    TraverseStack(pStack);
    while(!isEmpty(pStack)){
        int e;
        Pop(pStack,&e);
        printf("pop %d\n",e);
        TraverseStack(pStack);
    }
    return 0;
}