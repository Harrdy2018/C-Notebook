#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#define STACK_SIZE_INCREMENT 5

/**
 * 初始化操作，创建一个容量为size的空栈
 * obj->top==obj->base 为空栈
*/
Stack *InitStack(int size){
    Stack *obj=(Stack *)malloc(sizeof(Stack));
    if(obj==NULL){
        return NULL;
    }
    obj->base=(SElemType *)malloc(size*sizeof(SElemType));
    if(obj->base==NULL){
        free(obj);
        obj=NULL;
        return NULL;
    }
    obj->top=obj->base;
    obj->capacity=size;
    return obj;
}

/**
 * 判满
*/
MyBool IsFullStack(Stack *obj){
    return obj->top==obj->base+obj->capacity;
}

/**
 * 判空
*/
MyBool IsEmptyStack(Stack *obj){
    return obj->base==obj->top;
}

/**
 * push操作，入栈
 * 前提，栈非满；写入数据,栈顶指针上移
*/
MyBool PushStack(Stack *obj,SElemType ele){
    if(IsFullStack(obj)){
        obj->base=(SElemType *)realloc(obj->base,(obj->capacity+STACK_SIZE_INCREMENT)*sizeof(SElemType));
        if(obj->base==NULL){
            return my_false;
        }
        obj->top=obj->base+obj->capacity;
        obj->capacity+=STACK_SIZE_INCREMENT;
    }
    *obj->top=ele;
    obj->top++;
    return my_true;
}

/**
 * Pop操作，出栈
 * 前提，栈非空；栈顶指针下移,用 ele 保存值
*/
MyBool PopStack(Stack *obj,SElemType *ele){
    if(IsEmptyStack(obj)){
        return my_false;
    }
    obj->top--;
    *ele=*obj->top;
    return my_true;
}

/**
 * 若栈存在，则销毁它
 * 销毁栈是把整个栈都释放掉
*/
void DestroyStack(Stack *obj){
    free(obj->base);
    obj->base=NULL;
    obj->top=NULL;
    free(obj);
    obj=NULL;
}

/**
 * 将栈清空
 * 清空栈指的是把把栈里的元素都清除掉，但栈本身还在(此时栈为空栈)
*/
void ClearStack(Stack *obj){
    obj->top=obj->base;
}

/**
 * 若栈存在且非空，用ele返回栈顶元素
*/
void TopEleOfStack(Stack *obj,SElemType *ele){
    if(!IsEmptyStack(obj)){
        *ele=*(obj->top-1);
    }
}

/**
 * 返回栈中元素个数
*/
int LengthOfStack(Stack *obj){
    return obj->top - obj->base;
}

/**
 * 遍历栈中元素
*/
void TraverseStack(Stack *obj){
    int len=LengthOfStack(obj);
    for(int i=0;i<len;i++){
        printf("%4d",obj->base[i]);
    }
    printf("\n");
}