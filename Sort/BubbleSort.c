#include <stdio.h>
/*交换空间复杂度 o[1]*/
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
/*交换空间复杂度 o[0]*/
void swap2(int *a,int *b){
    *a=(*a)^(*b);
    *b=(*a)^(*b);
    *a=(*a)^(*b);
}
/**
 * 数组长度len 记住两点：
 * 第一、需要走 len-1 躺则，1<=i<=len-1
 * 第二、每一趟都是从 0~len-i-1,则，0<=j<=len-i-1
 * 为什么交换可以改进？
 * 例如： 1 5 2 3 4
 * 第一次循环，将5放在最后面 1 2 3 4 5
 * 后面就没有交换了，可以改进
 */
void BubbleSort(int arr[],int len){
    for(int i=1;i<=len-1;i++){
        //预设不会发生交换
        int isSwap=0;
        for(int j=0;j<=len-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap2(arr+j,arr+j+1);
                isSwap=1;
            }
        }
        if(isSwap==0){
            break;
        }
    }
}
void printf_arr(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%d\n",arr[i]);
    }
}
void main(void){
    int arr[5]={1,5,2,3,4};
    int len=5;
    BubbleSort(arr,len);
    printf_arr(arr,len);
}
