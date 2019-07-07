#include <stdio.h>
/**
 * 堆排序
 * 这里我用数组模拟线性表
 */
void arr_print(int arr[],int len){
  for(int i=0;i<len;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}
void swap(int arr[],int a,int b){
  int temp=arr[a];
  arr[a]=arr[b];
  arr[b]=temp;
}
void HeapAdjust(int arr[],int index,int end){
  int temp=arr[index];
  for(int j=2*index+1;j<=end;j=2*j+1){
    //比较左右子树，记下最大的序号
    if(j+1<=end && arr[j+1]>arr[j]){
      j++;
    }
    if(temp>=arr[j]){
      break;
    } 
    arr[index]=arr[j];
    index=j;
  }
  arr[index]=temp;
}
void HeapSort(int arr[],int len){
  for(int i=len/2-1;i>=0;i--){
    HeapAdjust(arr,i,len-1);
  }
  for(int i=len-1;i>=0;i--){
    swap(arr,0,i);
    HeapAdjust(arr,0,i-1);
  }
}
int main(int argc,char *argv[]){
  int length=11;
  int arr[]={50,10,90,30,70,40,80,60,20,100,45};
  arr_print(arr,length);
  HeapSort(arr,length);
  arr_print(arr,length);
  return 0;
}
