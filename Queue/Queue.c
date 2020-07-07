#include "Queue.h"
/** Initialize your data structure here. Set the size of the queue to be k. */
Queue *initQueue(int k){
    Queue *obj=(Queue *)malloc(sizeof(Queue));
    obj->data=(ElemType *)malloc(k*sizeof(ElemType));
    obj->head=-1;
    obj->tail=-1;
    obj->size=k;
    obj->len=0;
    return obj;
}
/** Insert an element into the circular queue. Return true if the operation is successful. */
my_bool enQueue(Queue *obj,ElemType e){
    if(isFull(obj)){
        return my_false;
    }
    if(isEmpty(obj)){
        obj->head=0;
    }
    obj->tail=(obj->tail+1)%obj->size;
    obj->data[obj->tail]=e;
    obj->len++;
    return my_true;
}
/** Delete an element from the circular queue. Return true if the operation is successful. */
my_bool deQueue(Queue *obj,ElemType *e){
    if(isEmpty(obj)){
        return my_false;
    }
    obj->len--;
    *e=obj->data[obj->head];
    if(obj->head==obj->tail){
        obj->tail=-1;
        obj->head=-1;
        return my_true;
    }
    obj->head=(obj->head+1)%obj->size;
    return my_true;
}
/** Get the front item from the queue. */
ElemType Front(Queue *obj){
    if(isEmpty(obj)){
        return -1;
    }
    return obj->data[obj->head];
}
/** Get the last item from the queue. */
ElemType Rear(Queue *obj){
    if(isEmpty(obj)){
        return -1;
    }
    return obj->data[obj->tail];
}
/** Checks whether the circular queue is empty or not. */
my_bool isEmpty(Queue *obj){
    return obj->len==0;
}
/** Checks whether the circular queue is full or not. */
my_bool isFull(Queue *obj){
    return obj->len==obj->size;
}
/**printf queue*/
void printfQueue(Queue q){
    int head=q.head;
    int tail=q.tail;
    int size=q.size;
    while(head!=tail){
        printf("%2d",q.data[head]);
        head=(head+1)%size;
    }
    printf("%2d\n",q.data[head]);
}
/**clear queue*/
void clearQueue(Queue *obj){
    obj->head=-1;
    obj->tail=-1;
    obj->len=0;
}
