#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void PrintfArr(int arr[],int len);
/**
 * 将两个有序数组进行归并
 */
void Merge(int *arrA,int lenA,int *arrB,int lenB,int *res){
  int i=0,j=0;
  while(i<lenA && j<lenB){
    if(arrA[i]<arrB[j]){
      res[i+j]=arrA[i];
      i++;
    }else{
      res[i+j]=arrB[j];
      j++;
    }
  }
  //谁先达到最大长度，谁先结束
  if(i==lenA){
    for(;j<lenB;j++){
      res[i+j]=arrB[j];
    }
  }else{
    for(;i<lenA;i++){
      res[i+j]=arrA[i];
    }
  }
}
/**
 * arr排序数组
 * start起始索引，结束索引
 */
int *MSort(int arr[],int start,int end){
  int size=end-start+1;
  int *res=(int *)malloc(size*sizeof(int));
  memset(res,0,size*sizeof(int));
  if(start==end){
    res[0]=arr[start];
  }else{
    int mid=(end+start)/2;
    int *a=MSort(arr,start,mid);
    int *b=MSort(arr,mid+1,end);
    Merge(a,mid-start+1,b,end-mid,res);
    PrintfArr(res,size);
  }
  return res;
}
void PrintfArr(int arr[],int len){
  for(int i=0;i<len;i++){
    printf("%4d",arr[i]);
  }
  printf("\n");
}
int main(){
  int arr[9]={50,10,90,30,70,40,80,60,20};
  //int arr[4]={50,10,90,30};
  int start=0;
  int end=8;
  int *result=MSort(arr,start,end);
  PrintfArr(result,9);
  return 0;
}