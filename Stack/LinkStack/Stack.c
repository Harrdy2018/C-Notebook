#include "Stack.h"
StackNode *CreateStackNode(SElemType ele){
    StackNode *node=(StackNode *)malloc(sizeof(StackNode));
    node->data=ele;
    node->next=NULL;
    return node;
}
LinkStack *InitLinkStack(){
    LinkStack *obj=(LinkStack *)malloc(sizeof(LinkStack));
    obj->top=NULL;
    obj->count=0;
    return obj;
}
my_bool Push(LinkStack *obj,SElemType ele){
    StackNode *node=CreateStackNode(ele);
    node->next=obj->top;
    obj->top=node;
    obj->count++;
    return my_true;
}
my_bool isEmpty(LinkStack *obj){
    return obj->top==NULL ? my_true:my_false;
}
my_bool Pop(LinkStack *obj,SElemType *ele){
    if(isEmpty(obj)){
        return my_false;
    }
    *ele=obj->top->data;
    StackNode *current=obj->top;
    obj->top=obj->top->next;
    obj->count--;
    free(current);
    if(current != NULL){
        current=NULL;
    }
    return my_true;
}
void GetTop(LinkStack *obj,SElemType *ele){
    if(isEmpty(obj)){
        return ;
    }
    *ele=obj->top->data;
}
void TraverseLinkStack(LinkStack LS){
    LinkStack *current=&LS;
    while(current->top != NULL){
        printf("%4d",current->top->data);
        current->top=current->top->next;
    }
    printf("\n");
}
int LinkStackLength(LinkStack *obj){
    return obj->count;
}
void DestroyStack(LinkStack *obj){
    ClearStack(obj);
    free(obj);
    if(obj != NULL){
        obj=NULL;
    }
}
void ClearStack(LinkStack *obj){
    if(obj->top != NULL){
        StackNode *current=obj->top;
        obj->top=obj->top->next;
        free(current);
        if(current != NULL){
            current=NULL;
        }
    }
    obj->count=0;
}