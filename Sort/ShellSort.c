#include <stdio.h>
void PrintfArr(int arr[],int len){
  for(int i=0;i<len;i++){
    printf("%4d",arr[i]);
  }
  printf("\n");
}
void ShellSort(int arr[],int len){
  int size=len-1;
  int increment=size;
  do{
    increment=increment/3+1;
    for(int i=increment+1;i<len;i++){
      if(arr[i]<arr[i-increment]){
        arr[0]=arr[i];
        int j;
        for(j=i-increment;j>0&&arr[0]<arr[j];j=j-increment){
          arr[j+increment]=arr[j];
        }
        arr[j+increment]=arr[0];
      }
    }
  }while(increment>1);
}

int main(){
  int arr[10]={0,9,1,5,8,3,7,4,6,2};
  int len=10;
  ShellSort(arr,len);
  PrintfArr(arr,len);
  return 0;
}