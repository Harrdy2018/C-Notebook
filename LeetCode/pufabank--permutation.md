## 全排列
* n个数全排列问题
```
        per({1,2,3},k=0,m=2)
        第一次循环 i=0
        swap(arr+i,arr+k)  {1,2,3}                 
        per({1,2,3},k=1,m=2)
            j=1
                swap(arr+j,arr+k)
                per({1,2,3},k=2,m=2) printf {1,2,3}
            j=2
                swap(arr+j,arr+k)
                per({1,2,3},k=2,m=2) printf {1,3,2}
```
```c
//全排列问题
#include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void permutation(int arr[],int k,int m){
    if(k==m){
        //只剩下最后一个元素
        for(int i=0;i<=m;i++){
            printf("%d",arr[i]);
        }
        printf("\n");
    }else{
        for(int i=k;i<=m;i++){
            swap(arr+k,arr+i);
            permutation(arr,k+1,m);
            swap(arr+k,arr+i);
        }
    }
}
int main(void){
    int arr[]={1,2,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    permutation(arr,0,len-1);
    return 0;
}
```