#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdio.h>
#include <stdlib.h>
typedef int SElemType;
typedef struct my_StackNode{
    SElemType data;
    struct my_StackNode *next;
}StackNode;
typedef struct my_LinkStack{
    StackNode *top;
    int count;
}LinkStack;
typedef enum my_bool{
  my_false=0,my_true
}my_bool;
StackNode *CreateStackNode(SElemType ele);
LinkStack *InitLinkStack();
my_bool Push(LinkStack *obj,SElemType ele);
my_bool isEmpty(LinkStack *obj);
my_bool Pop(LinkStack *obj,SElemType *ele);
void GetTop(LinkStack *obj,SElemType *ele);
void TraverseLinkStack(LinkStack LS);
int LinkStackLength(LinkStack *obj);
void DestroyStack(LinkStack *obj);
void ClearStack(LinkStack *obj);
#endif