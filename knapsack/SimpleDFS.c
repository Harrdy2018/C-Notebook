#include <stdio.h>
#include <string.h>
#define N 5  //商品个数
#define C 10 //背包容量
/**
 * c代表剩余背包的容量；n代表剩余物品数目；
 * c=0即代表背包分配成功
 */
int DFS(int c,int n,int weight[]){
  if(c==0){
    return 1;
  }
  if(DFS(c-weight[n],n-1,weight)){
    printf("%2d%4d\n",n,weight[n]);
    return 1;
  }
  return DFS(c,n-1,weight);
}
int main(){
  int weight[]={0,4,5,6,2,2};
  int value[]={0,6,4,5,3,6};
  DFS(C,N,weight);
  printf("****************************************************\n");
  
  return 0;
}