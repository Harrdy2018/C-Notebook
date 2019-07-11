#include <stdio.h>
#define MAXSIZE 10
typedef struct {
  int r[MAXSIZE+1];//用于储存排序数组，r[0]用作哨兵或临时变量
  int length;
}SqList;
/**
 * 函数申明
 */
void swap(SqList *L,int i,int j);
void printf_list(SqList *L);
void swap(SqList *L,int i,int j){
  int temp=L->r[i];
  L->r[i]=L->r[j];
  L->r[j]=temp;
}
void printf_list(SqList *L){
  for(int i=1;i<=L->length;i++){
    printf("%d ",L->r[i]);
  }
  printf("\n");
}
/**
 * 选择，选择，每次筛选出后面最小的
 */
void SelectSort(SqList *L){
  //有10个数，最外面我只需要循环9次即可
  for(int i=1;i<L->length;i++){
    int min=i+1;
    for(int j=i+1;j<=L->length;j++){
      if(L->r[j]<L->r[min]){
        min=j;
      }
    }
    if(L->r[i]>L->r[min]){
      swap(L,i,min);
    }
    printf_list(L);
  }
}
int main(){
  SqList myList={
    {0,10,9,1,5,8,3,7,4,6,2},10
  };
  SelectSort(&myList);
}
