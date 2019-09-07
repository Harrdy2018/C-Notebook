typedef struct DoubleLinkTable{
  int num;
  struct DoubleLinkTable *prev;
  struct DoubleLinkTable *next;
}DL;
enum my_bool {
  my_false=0,my_true
};
DL *doublelinktable_CNode(int data);
/**
 * 双向列表的正向遍历
 */
void doublelinktable_forward_print(DL *head);
void doublelinktable_unshift(DL *head,DL *newData);
void doublelinktable_push(DL *head,DL *newData);
/**
 * 双向列表的反向遍历
 */
void doublelinktable_opposite_print(DL *head);
enum my_bool doublelinktable_delete(DL *head,int data);