#include <stdio.h>
void PrintfArr(int arr[],int len);
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
/**
 * 将*left交换到数组的枢轴，使得左边都比他小，右边都比他大
 */
int *FindPivot(int *left,int *right){
  while(left<right){
    while(*left<*right){
      right--;
    }
    swap(&(*left),&(*right));
    while(*left<*right){
      left++;
    }
    swap(&(*left),&(*right));
  }
  return left;
}
void QuickSort(int *left,int *right){
  if(left != right){
    int *pivot=FindPivot(left,right);
    QuickSort(left,pivot);
    QuickSort(pivot+1,right);
  }   
}
void PrintfArr(int arr[],int len){
  for(int i=0;i<len;i++){
    printf("%4d",arr[i]);
  }
  printf("\n");
}
int main(){
  int arr[9]={50,10,90,30,70,40,80,60,20};
  int len=9;
  int *left=arr;
  int *right=arr+len-1;
  QuickSort(left,right);
  PrintfArr(arr,9);
  return 0;
}