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
 * 非标准版冒泡排序
 * 每次都是拿当前的元素和其他元素比较
 */
void BubbleSortA(SqList *L){
  for(int i=1;i<L->length;i++){
    for(int j=i+1;j<=L->length;j++){
      if(L->r[i]>L->r[j]){
        swap(L,i,j);
      }
    }
    printf_list(L);
  }
}
void BubbleSort0(SqList *L){
  //有10个数，最外面我只需要循环9次即可
  for(int i=1;i<L->length;i++){
    //第一次循环，10个数，两两比较，需要比较9次
    //第一次循环，9个数，两两比较，需要比较8次
    for(int j=1;j<L->length+1-i;j++){
      if(L->r[j]>L->r[j+1]){
        swap(L,j,j+1);
      }
    }
    printf_list(L);
  }
}
/**
 * 例如： 1 5 2 3 4
 * 第一次循环，将5放在最后面 1 2 3 4 5
 * 后面就没有交换了，可以改进
 */
void BubbleSort(SqList *L){
  for(int i=1;i<L->length;i++){
    //预设不会发生交换
    int isSwap=0;
    for(int j=1;j<L->length+1-i;j++){
      if(L->r[j]>L->r[j+1]){
        swap(L,j,j+1);
        isSwap=1;
      }
    }
    if(isSwap==0){
      break;
    }
    printf_list(L);
  }
}
int main(){
  SqList myList={
    {0,10,9,1,5,8,3,7,4,6,2},10
  };
  SqList myListB=myList;
  //冒泡排序
  BubbleSortA(&myList);
  printf("*************************\n");
  BubbleSort0(&myList);
  printf("*************************\n");
  BubbleSort(&myListB);
}