#include <stdio.h>
#include "DoubleLinkTable.h"
int main(int argc,char *argv[]){
  DL *myHead=doublelinktable_CNode(0);
  for(int i=10;i>=1;i--){
    doublelinktable_unshift(myHead,doublelinktable_CNode(i));
  }
  doublelinktable_forward_print(myHead);
  printf("************************************************\n");
  for(int i=11;i<=20;i++){
    doublelinktable_push(myHead,doublelinktable_CNode(i));
  }
  doublelinktable_forward_print(myHead);
  printf("************************************************\n");
  doublelinktable_opposite_print(myHead);
  printf("************************************************\n");
  doublelinktable_delete(myHead,-1);
  doublelinktable_delete(myHead,10);
  doublelinktable_opposite_print(myHead);
}