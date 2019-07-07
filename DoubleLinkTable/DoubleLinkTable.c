#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkTable.h"

DL *doublelinktable_CNode(int data){
  DL *p=(DL *)malloc(sizeof(DL));
  if(p==NULL){
    printf("create dl node fair!\n");
    return NULL;
  }
  p->num=data;
  p->next=NULL;
  p->prev=NULL;
  return p;
}
void doublelinktable_forward_print(DL *head){
  DL *current=head;
  while(current->next != NULL){
    printf("the num of node is: %d\n",current->num);
    current=current->next;
  }
  printf("the num of node is: %d\n",current->num);
}
void doublelinktable_opposite_print(DL *head){
  DL *current=head;
  while(current->next != NULL){
    current=current->next;
  }
  while(current->prev != NULL){
    printf("the num of node is: %d\n",current->num);
    current=current->prev;
  }
  printf("the num of node is: %d\n",current->num);
}
void doublelinktable_unshift(DL *head,DL *new){
  //如果只有一个头结点
  if(head->next == NULL){
    head->next=new;
    new->prev=head;
  }else{
    //如果至少有两个节点
    new->next=head->next;
    head->next->prev=new;
    new->prev=head;
    head->next=new;
  }
}
void doublelinktable_push(DL *head,DL *new){
  //寻找末节点
  DL *current=head;
  while(current->next != NULL){
    current=current->next;
  }
  current->next=new;
  new->prev=current;
}
enum my_bool doublelinktable_delete(DL *head,int data){
  DL *current=head;
  while(current->next != NULL){
    current=current->next;
    if(current->num == data){
      if(current->next == NULL){
        current->prev->next=NULL;
        free(current);
      }else{
        current->prev->next=current->next;
        current->next->prev=current->prev;
        free(current);
      }
      return my_true;
    }
  }
  printf("delete data : %d failed ! no have link node !\n",data);
  return my_false;
}
