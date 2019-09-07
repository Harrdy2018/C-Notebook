#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SingleLinkTable.h"

/**
 * 创建一个新的节点，返回指向这个节点的指针
 */
L *linktable_CNode(int data){
  L *p=(L *)malloc(sizeof(L));
  if(p==NULL){
    printf("malloc error ! \n");
    return NULL;
  }
  memset(p,0,sizeof(L));
  p->id=data;
  p->next=NULL;
  return p;
}
/**
 * 链表的头插，是在头部之后插入，头部不变
 */
void linktable_unshift(L *head,L *new){
  new->next=head->next;
  head->next=new;
}
/**
 * 链表的尾插
 */
void linktable_push(L *head,L *new){
  L *current=head;
  while(current->next != NULL){
    current=current->next;
  }
  current->next=new;
}
/**
 * 删除链表中的某个节点,头节点不能删除
 */
enum my_bool linktable_delete(L *head,int data){
  L *current=head;
  L *prev=NULL;
  while(current->next != NULL){
    prev=current;
    current=current->next;
    if (current->id==data)
    {
      if(current->next != NULL){
        prev->next=current->next;
        free(current);
      }else{
        prev->next=NULL;
        free(current);
      }
      return my_true;
    }
  }
  printf("delete data : %d failed ! no have link node !\n",data);
  return my_false;
}
/**
 * 链表的逆序
 * 循环
 * 如果是空链表或者只有一个元素，直接返回头节点
 */
L *linktable_reverse_useloop(L *head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  L *prev=NULL;
  L *current=NULL;

  while(head != NULL){
    current=head->next;
    head->next=prev;
    prev=head;
    head=current;
  }
  return prev;
}
/**
 * 链表的逆序
 * 递归
 */
L *linktable_reverse_userecursion(L *head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  L *newHead;
  newHead=linktable_reverse_userecursion(head->next);
  head->next->next=head;
  head->next=NULL;
  return newHead;
}
/**
 * 链表的遍历
 */
void linktable_print(L *head){
  //为了不改变头结点
  L *current=head;
  if(current==NULL){
    printf("this is a NULL link table !");
  }else{
    while(current->next != NULL){
      printf("the node id is : %d\n",current->id);
      current=current->next;
    }
    printf("the node id is : %d\n",current->id);
  }
}