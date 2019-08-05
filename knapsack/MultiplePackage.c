/**
 * 完全背包问题
 * N=3 M=8
 * price={0,1,2,2};
 * want={0,6,10,20};
 * nums={0,10,5,2};
 * 
 * 3 8  //3种物品，背包承重为8
 * 1 6 10   //第一种物品，价格为1，标准为6，数目10
 * 2 10 5
 * 2 20 2
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
int **createWantArr(int N,int M,int *price,int *want,int *nums){
  int **arr=(int **)malloc((N+1)*sizeof(int *));
  for(int i=0;i<N+1;i++){
    arr[i]=(int *)malloc((M+1)*sizeof(int));
    memset(arr[i],0,(M+1)*sizeof(int));
  }
  for(int row=1;row<=N;row++){
    for(int col=1;col<=M;col++){
      //如果当前钱币不足以买当前物品
      if(col<*(price+row)){
        *(arr[row]+col)=*(arr[row-1]+col);
      }else{
        int n=col/(*(price+row));
        int m=*(nums+row);
        n=(n<=m ? n : m);
        int a=*(arr[row-1]+col);
        int b=n*(*(want+row))+*(arr[row-1]+col-n*(*(price+row)));
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
    int *nums=(int *)malloc((N+1)*sizeof(int));
    memset(price,0,(N+1)*sizeof(int));
    memset(want,0,(N+1)*sizeof(int));
    memset(nums,0,(N+1)*sizeof(int));
    for(int i=1;i<=N;i++){
      int Price,Want,Nums;
      scanf("%d%d%d",&Price,&Want,&Nums);
      *(price+i)=Price;
      *(want+i)=Want;
      *(nums+i)=Nums;
    }
    printf_arr(price,N+1);
    printf_arr(want,N+1);
    printf_arr(nums,N+1);
    //初始化价值矩阵
    int **arr=createWantArr(N,M,price,want,nums);
    printf_2arr(arr,N,M);
    printf("%d\n",*(arr[N]+M));
    myArrFree(arr,N,M);
  }
  return 0;
}
