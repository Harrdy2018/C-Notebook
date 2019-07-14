#include <stdio.h>
#define MAXSIZE 5
typedef struct {
  int r[MAXSIZE+1];//用于储存排序数组，r[0]用作哨兵或临时变量
  int length;//有多少个数需要排序
} SqList;
/**
 * 直接插入排序
 */
void StraightInsertionSort(SqList *L){
  for(int i=2;i<=L->length;i++){
    if(L->r[i]<L->r[i-1]){
      L->r[0]=L->r[i];
      int j;
      for(j=i-1;L->r[0]<L->r[j];j--){
        L->r[j+1]=L->r[j];
      }
      L->r[j+1]=L->r[0];
    }
  }
}
void printf_list(SqList *L){
  for(int i=1;i<=L->length;i++){
    printf("%d ",L->r[i]);
  }
  printf("\n");
}
int main(){
  SqList myList={
    {0,5,3,4,6,2},5
  };
  //直接插入排序
  printf_list(&myList);
  StraightInsertionSort(&myList);
  printf("*************************\n");
  printf_list(&myList);
  return 0;
}