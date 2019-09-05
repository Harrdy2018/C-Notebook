#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
/**
 * 初始化操作，建立一个空栈
*/
Stack *InitStack(){
    Stack *S=(Stack *)malloc(sizeof(Stack));
    S->data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType));
    S->top=-1;
    S->capacity=MAXSIZE;
    return S;
}
/**
 * 判满
*/
my_bool isFull(Stack *S){
    return S->top==S->capacity-1 ? my_true:my_false;
}
/**
 * 判空
*/
my_bool isEmpty(Stack *S){
    return S->top==-1 ? my_true:my_false;
}
/**
 * push操作，入栈
 * 前提，栈非满；栈顶指针先上移，然后写入数据
*/
my_bool Push(Stack *S,SElemType ele){
    if(isFull(S)){
        return my_false;
    }
    S->top++;
    S->data[S->top]=ele;
    return my_true;
}
/**
 * Pop操作，出栈
 * 前提，栈非空；首先用 ele 保存值，然后栈顶指针下移
*/
my_bool Pop(Stack *S,SElemType *ele){
    if(isEmpty(S)){
        return my_false;
    }
    *ele=S->data[S->top];
    S->top--;
    return my_true;
}
/**
 * 若栈存在，则销毁它
 * 销毁栈是把整个栈都释放掉
*/
void DestroyStack(Stack *S){
    free(S->data);
    S->data=NULL;
    free(S);
    S=NULL;
}
/**
 * 将栈清空
 * 清空栈指的是把把栈里的元素都清除掉，但栈本身还在(此时栈为空栈)
*/
void ClearStack(Stack *S){
    S->top=-1;
}
/**
 * 若栈存在且非空，用ele返回栈顶元素
*/
void GetTop(Stack *S,SElemType *ele){
    if(!isEmpty(S)){
        *ele=S->data[S->top];
    }
}
/**
 * 返回栈中元素个数
*/
int StackLength(Stack *S){
    return S->top;
}
/**
 * 遍历栈中元素
*/
void TraverseStack(Stack *S){
    int len=StackLength(S);
    for(int i=0;i<=len;i++){
        printf("%4d",S->data[i]);
    }
    printf("\n");
}