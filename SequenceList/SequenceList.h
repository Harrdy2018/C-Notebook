#define LIST_SIZE 20
#define LIST_INCREMENT 10
typedef int ElemType;
/**
 * 线性表
 * 三个属性：
 * 存储空间的起始位置；
 * 线性表的最大存储容量；
 * 线性表的当前长度
 */
typedef struct SequenceList{
  ElemType *data;
  int length;  //线性表当前长度
  int listsize; //当前分配的存储容量
}SqList;
enum my_bool{
  my_false=0,my_true
};
enum my_bool InitList(SqList *L);
enum my_bool ListIsEmpty(SqList *L);
enum my_bool ListInsert(SqList *L,int i,ElemType e);
enum my_bool ListDelete(SqList *L,int i,ElemType *e);
enum my_bool GetElem(SqList *L,int i,ElemType *e);
enum my_bool PriorElem(SqList *L,ElemType current,ElemType *previous);
enum my_bool NextElem(SqList *L,ElemType current,ElemType *next);
void ListPrint(SqList *L);
void ClearList(SqList *L);
void ListUnion(SqList *La,SqList *Lb);
int ListLength(SqList *L);
int LocateElem(SqList *L,ElemType e);