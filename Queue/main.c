#include "Queue.h"
int main(void){
    printf("*******Queue***********\n");
    Queue *obj=initQueue(3);
    printf("%d\n",enQueue(obj,1));
    printf("%d\n",enQueue(obj,2));
    printf("%d\n",enQueue(obj,3));
    printf("%d\n",enQueue(obj,4));
    printfQueue(*obj);
    printf("%d\n",Rear(obj));
    printf("%d\n",isFull(obj));
    int a;
    printf("%d\n",deQueue(obj,&a));
    printf("%d\n",enQueue(obj,4));
    printf("%d\n",Rear(obj));
    printfQueue(*obj);    
    return 0;
}