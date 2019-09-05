#include <stdio.h>
#include "Stack.h"
int main(void){
    Stack stack;
    printf("%p %d %d %d\n",&stack,sizeof(stack),stack.data[0],stack.top);
    InitStack(&stack);
    printf("%d\n",stack.top);
    int arr[]={1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        Push(&stack,arr[i]);
    }
    TraverseStack(&stack);
    while(!isEmpty(&stack)){
        int e;
        Pop(&stack,&e);
        printf("%d\n",e);
        TraverseStack(&stack);
    }
    return 0;
}