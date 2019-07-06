typedef struct DoubleLinkTable{
  int num;
  struct DoubleLinkTable *prev;
  struct DoubleLinkTable *next;
}DL;
enum bool {
  false=0,true
};
DL *doublelinktable_CNode(int data);
/**
 * 双向列表的正向遍历
 */
void doublelinktable_forward_print(DL *head);
void doublelinktable_unshift(DL *head,DL *new);
void doublelinktable_push(DL *head,DL *new);
/**
 * 双向列表的反向遍历
 */
void doublelinktable_opposite_print(DL *head);
enum bool doublelinktable_delete(DL *head,int data);