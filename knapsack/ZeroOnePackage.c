/**
 * 0-1背包问题
 * 输入，商品的数目N,背包的容量或者你的总钱币M
 * 每一行输入代表每一件商品的体积或者单价p,需要求的每一件商品的标准I,每一件商品有几个C(0-1背包里面默认都只有1个)
 * 输入N行截止
 * 输出需要求的商品的最大标准
 * 5 10
 * 4 6
 * 5 4
 * 6 5
 * 2 3
 * 2 6
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printf_arr(int *arr,int len){
  for(int i=0;i<len;i++){
    printf("%4d",*(arr+i));
  }
  printf("\n");
}
void printf_2arr(int **arr,int N,int M){
   for(int i=0;i<N+1;i++){
    for(int j=0;j<M+1;j++){
      printf("%4d",*(arr[i]+j));
    }
    printf("\n");
  }
}
int **createWantArr(int N,int M,int *price,int *want){
  int **arr=(int **)malloc((N+1)*sizeof(int *));
  for(int i=0;i<N+1;i++){
    arr[i]=(int *)malloc((M+1)*sizeof(int));
    memset(arr[i],0,(M+1)*sizeof(int));
  }
  for(int row=1;row<=N;row++){
    for(int col=1;col<=M;col++){
      if(col<*(price+row)){
        *(arr[row]+col)=*(arr[row-1]+col);
      }else{
        int a=*(arr[row-1]+col);
        int b=*(price+row)+*(arr[row-1]+col-*(price+row));
        *(arr[row]+col)=(a>b ? a :b);
      }
    }
  }
  return arr;
}
void myArrFree(int **arr,int N,int M){
  for(int i=0;i<=N;i++){
    free(arr[i]);
    arr[i]=NULL;
  }
  free(arr);
  arr=NULL;
}
int main(){
  int N,M;
  while(1){
    scanf("%d%d",&N,&M);
    int *price=(int *)malloc((N+1)*sizeof(int));
    int *want=(int *)malloc((N+1)*sizeof(int));
    memset(price,0,(N+1)*sizeof(int));
    memset(want,0,(N+1)*sizeof(int));
    for(int i=1;i<=N;i++){
      int Price,Want;
      scanf("%d%d",&Price,&Want);
      *(price+i)=Price;
      *(want+i)=Want;
    }
    /**
     * price={0,4,5,6,2,2};
     * want={0,6,4,5,3,6};
     */
    printf_arr(price,N+1);
    printf_arr(want,N+1);
    //初始化价值矩阵
    int **arr=createWantArr(N,M,price,want);
    printf_2arr(arr,N,M);
    printf("%d\n",*(arr[N]+M));
    myArrFree(arr,N,M);
  }
  return 0;
}
