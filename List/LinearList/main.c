#include <stdio.h>
#include "SequenceList.h"
int main(int argc,char *argv[]){
  SqList L;
  SqList *pL=&L;
  InitList(pL);
  printf("****************test error ListInsert()********************\n");
  ListInsert(pL,0,12);
  printf("****************test ListInsert()********************\n");
  for(int i=1;i<=pL->listsize;i++){
    ElemType j=i;
    ListInsert(pL,i,j);
  }
  ListPrint(pL);
  printf("****************test more ListInsert()********************\n");
  ListInsert(pL,10,100);
  ListPrint(pL);
  printf("length %d    listsize %d\n",pL->length,pL->listsize);
  printf("****************test ListDelete()********************\n");
  ElemType ee;
  ElemType eee;
  ListDelete(pL,3,&ee);
  ListPrint(pL);
  printf("the delete ele is %d  length %d\n",ee,pL->length);
  ListDelete(pL,3,&eee);
  ListPrint(pL);
  printf("the delete ele is %d  length %d\n",eee,pL->length);
  printf("****************test ListIsEmpty()********************\n");
  printf("%d\n",ListIsEmpty(pL));
  printf("****************test GetElem()********************\n");
  ElemType eeee;
  if(GetElem(pL,4,&eeee)){
    printf("the get elem is %d\n",eeee);
  }
  printf("****************test ListLength()********************\n");
  printf("the length of the list is %d\n",ListLength(pL));
  printf("****************test LocateElem()********************\n");
  printf("the 10 of list number is %d\n",LocateElem(pL,10));
  printf("****************test PriorElem()********************\n");
  ElemType eeeee;
  enum my_bool aa=PriorElem(pL,10,&eeeee);
  if(aa){
    printf("the prior of 10 is %d\n",eeeee);
  }
  printf("****************test NextElem()********************\n");
  ElemType eeeeee;
  enum my_bool bb=NextElem(pL,10,&eeeeee);
  if(bb){
    printf("the next of 10 is %d\n",eeeeee);
  }
  printf("****************test ListUnion()********************\n");
  SqList L2;
  SqList *pLB=&L2;
  InitList(pLB);
    for(int i=1;i<=pLB->listsize;i++){
    ElemType j=i+1000;
    ListInsert(pLB,i,j);
  }
  ListPrint(pLB);
  ListUnion(pL,pLB);
  ListPrint(pL);
  return 0;
}