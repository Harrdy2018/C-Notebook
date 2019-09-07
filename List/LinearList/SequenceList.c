#include <stdio.h>
#include <stdlib.h>
#include "SequenceList.h"
/**
 * 初始化线性表
 */
enum my_bool InitList(SqList *L){
  L->data=(ElemType *)malloc(sizeof(ElemType)*LIST_SIZE);
  if(L->data == NULL){
    return my_false;
  }
  L->length=0;
  L->listsize=LIST_SIZE;
  printf("sequence list init finish!\n");
  return my_true;
}
/**
 * 在线性表L中的第i个位置插入新元素e,肯定从1开始啦
 */
enum my_bool ListInsert(SqList *L,int i,ElemType e){
  //位置错误，你总不能看见内存不用吧
  if(i<1 || i>=(L->length)+2){
    printf("position error\n");
    return my_false;
  } 
  if(L->length >= L->listsize){
    L->data=(ElemType *)realloc(L->data,(LIST_SIZE+LIST_INCREMENT)*sizeof(ElemType));
    if(L->data == NULL){
      printf("realloc error\n");
      return my_false;
    }
    L->listsize+=LIST_INCREMENT;
  }
  ElemType *q=&(L->data[i-1]);
  ElemType *p=&(L->data[L->length-1]);
  for(;p>=q;p--){
    *(p+1)=*p;
  }
  *q=e;
  L->length++;
  return my_true;
}
/**
 * 在线性表L中删除第i个位置元素,将删除的元素由e带回
 */
enum my_bool ListDelete(SqList *L,int i,ElemType *e){
  //位置错误，你总不能看见内存不用吧
  if(i<1 || i>=(L->length)+2){
    printf("position error\n");
    return my_false;
  }
  ElemType *q=&(L->data[i-1]);
  *e=*q;
  ElemType *p=&(L->data[L->length-1]);
  for(;q<p;q++){
    *q=*(q+1);
  }
  L->length--;
  return my_true;
}
void ListPrint(SqList *L){
  ElemType *start=&(L->data[0]);
  ElemType *end=&(L->data[L->length-1]);
  for(;start<=end;start++){
    printf("the data of current position is %d\n",*start);
  }
}
enum my_bool ListIsEmpty(SqList *L){
  if(L->length == 0){
    printf("list is empty\n");
    return my_true;
  }else{
    return my_false;
  }
}
/**
 * 将线性表L中的第i个位置元素返回给e
 */
enum my_bool GetElem(SqList *L,int i,ElemType *e){
  if(i<1 || i>=(L->length)+1){
    printf("position error\n");
    return my_false;
  }
  ElemType *position=&(L->data[i-1]);
  *e=*position;
  return my_true;
}
void ClearList(SqList *L){
  while(L->data != NULL){
    free(L->data);
  }
  L->length=0;
}
/**
 * 返回线性表L的元素个数
 */
int ListLength(SqList *L){
  return L->length;
}
/**
 * 在线性表中查找与给定值e相等的元素
 * 如果查找成功，返回该元素在表中的序号，否则返回-1
 */
int LocateElem(SqList *L,ElemType e){
  for(int i=0;i<L->length;i++){
    if(L->data[i] == e){
      return i+1;
    }
  }
  return -1;
}
/**
 * 在线性表中查找当前元素的前驱
 * 如果current是L中的元素且不是第一个，则用previous返回这个前驱
 */
enum my_bool PriorElem(SqList *L,ElemType current,ElemType *previous){
  int position=LocateElem(L,current);
  if(position != -1 && L->data[0] != current){
    *previous=L->data[position-2];
    return my_true;
  }
  return my_false;
}
/**
 * 在线性表中查找当前元素的后继
 * 如果current是L中的元素且不是最后一个，则用next返回这个后继
 */
enum my_bool NextElem(SqList *L,ElemType current,ElemType *next){
  int position=LocateElem(L,current);
  if(position != -1 && L->data[L->length-1] != current){
    *next=L->data[position];
    return my_true;
  }
  return my_false;
}
/**
 * 将所有的在线性表Lb中但不在La中的数据元素插入到La中
 */
void ListUnion(SqList *La,SqList *Lb){
  ElemType e;
  for(int i=1;i<=(Lb->length);i++){
    GetElem(Lb,i,&e);
    if(LocateElem(La,e)==-1){
      ListInsert(La,La->length+1,e);
    }
  }
}