#include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void printf_arr(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%4d",arr[i]);
    }
    printf("\n");
}
void SelectSort(int arr[],int len){
    //选择len-1次,每一次都要找出最小值
    for(int i=0;i<=len-2;i++){
        int min=i;
        for(int j=i+1;j<=len-1;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        if(i!=min){
            swap(arr+i,arr+min);
        }
    }
}
void main(void){
    int len=9;
    int arr[9]={9,1,5,8,3,7,4,6,2};
    printf_arr(arr,len);
    SelectSort(arr,len);
    printf_arr(arr,len);
}