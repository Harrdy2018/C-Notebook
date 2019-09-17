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
    swap(left,right);
    while(*left<*right){
      left++;
    }
    swap(left,right);
  }
  return left;
}
void QuickSort(int arr[],int low,int high){
  if(low<high){
    int *left=arr+low;
    int *right=arr+high;
    int *pivot=FindPivot(left,right);
    int index=pivot-arr;
    printf("%d\n",index);
    QuickSort(arr,low,index-1);
    QuickSort(arr,index+1,high);
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
  QuickSort(arr,0,8);
  PrintfArr(arr,9);
  return 0;
}