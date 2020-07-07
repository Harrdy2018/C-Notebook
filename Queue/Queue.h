#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct queue{
    ElemType *data;
    int head;
    int tail;
    int size;
    int len;
}Queue;
typedef enum my_bool{
    my_false=0,my_true
}my_bool;
Queue *initQueue(int k);
my_bool enQueue(Queue *obj,ElemType e);
my_bool deQueue(Queue *obj,ElemType *e);
ElemType Front(Queue *obj);
ElemType Rear(Queue *obj);
my_bool isEmpty(Queue *obj);
my_bool isFull(Queue *obj);
void printfQueue(Queue q);
void clearQueue(Queue *obj);
#endif