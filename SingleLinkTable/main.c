#include <stdio.h>
#include "SingleLinkTable.h"
int main(){
  int a=1;
  L *head=linktable_CNode(a);
  printf("%p %u\n",head,sizeof(head));
  //头插
  for(int i=7;i>=2;i--){
    linktable_unshift(head,linktable_CNode(i));
  }
  //尾插
  for(int i=8;i<=12;i++){
    linktable_push(head,linktable_CNode(i));
  }
  linktable_print(head);
  printf("%p\n",head);
  printf("*****************\n");
  //linktable_delete(head,13);
  //linktable_delete(head,5);
  //linktable_print(head);
  //逆序测试
  L *newLinkTable=linktable_reverse_useloop(head);
  linktable_print(newLinkTable);
  linktable_print(head);
  linktable_print(linktable_reverse_userecursion(newLinkTable));
  linktable_print(newLinkTable);
  return 0;
}