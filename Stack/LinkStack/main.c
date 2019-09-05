#include <stdio.h>
#include "Stack.h"
int main(void){
    LinkStack *obj=InitLinkStack();
    printf("the length of linkstack is %d\n",LinkStackLength(obj));
    printf("****************************************************\n");
    int arr[]={1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        Push(obj,arr[i]);
        printf("the length of linkstack is %d\n",LinkStackLength(obj));
    }
    TraverseLinkStack(*obj);
    printf("****************************************************\n");
    while(!isEmpty(obj)){
        int e;
        Pop(obj,&e);
        printf("pop %d\n",e);
        printf("the length of linkstack is %d\n",LinkStackLength(obj));
        TraverseLinkStack(*obj);
    }
    return 0;
}