#include <stdio.h>
void printf_arr(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%4d",arr[i]);
    }
    printf("\n");
}
//直接插入排序
/*
int arr[]={5,3,4,6,2};
需要进行插入操作4次
第一次  3<5 guard=3
        发现哨兵比5小 int arr[]={5,5,4,6,2};
        停止while循环，放置哨兵int arr[]={3,5,4,6,2};
第二次  4<5 guard=4
        发现哨兵比5小 int arr[]={3,5,5,6,2};
        停止while循环，放置哨兵int arr[]={3,4,5,6,2};
第三次  6>5 不选择
第四次  2<6 guard=2
        发现哨兵比6小 int arr[]={3,4,5,6,6};
        发现哨兵比5小 int arr[]={3,4,5,5,6};
        发现哨兵比4小 int arr[]={3,4,4,5,6};
        发现哨兵比3小 int arr[]={3,3,4,5,6};
        停止while循环，放置哨兵int arr[]={2,3,4,5,6};
*/
void StraightInsertionSort(int arr[],int len){
    if(len<=1){
        return;
    }
    for(int i=1;i<=len-1;i++){
        if(arr[i]<arr[i-1]){
            int guard=arr[i];
            int j=i-1;
            while(guard<arr[j] && j>=0){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=guard;
        }
    }
}
void main(void){
    int len=5;
    int arr[]={5,3,4,6,2};
    printf_arr(arr,len);
    StraightInsertionSort(arr,len);
    printf_arr(arr,len);
}