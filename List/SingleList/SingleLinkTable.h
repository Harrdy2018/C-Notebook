#ifndef __SingleLinkTable_H_
#define __SingleLinkTable_H_
typedef struct LinkTable{
  int id;
  struct LinkTable *next;
}L;
enum my_bool{
  my_false=0,my_true
};
L *linktable_CNode(int data);
void linktable_unshift(L *head,L *newNode);
void linktable_push(L *head,L *newNode);
enum my_bool linktable_delete(L *head,int data);   
L *linktable_reverse_useloop(L *head);
L *linktable_reverse_userecursion(L *head);
void linktable_print(L *head);
#endif