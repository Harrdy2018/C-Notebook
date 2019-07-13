#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 5  //商品个数
#define C 10 //背包容量
void printf_arr(int arr[][C+1],int row,int col){
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      printf("%4d",arr[i][j]);
    }
    printf("\n");
  }
}
void createArr(int arr[][C+1],int weight[],int value[]){
  for(int col=1;col<=C;col++){
    for(int row=1;row<=N;row++){
      if(weight[row]>col){
        arr[row][col]=arr[row-1][col];
      }else{
        int a=arr[row-1][col];
        int b=value[row]+arr[row-1][col-weight[row]];
        arr[row][col]=(a>b ? a :b);
      }
    }
  }
}
int main(){
  int weight[]={0,4,5,6,2,2};
  int value[]={0,6,4,5,3,6};
  int maxValue[N+1][C+1];
  memset(maxValue,0,sizeof(maxValue));
  //初始化价值矩阵
  printf_arr(maxValue,N+1,C+1);
  createArr(maxValue,weight,value);
  //创建价值矩阵
  printf("****************************************************\n");
  printf_arr(maxValue,N+1,C+1);
  return 0;
}