### 实现C++ lower_bound() upper_bound()
```c
#include <stdio.h>

/* 在有序的升序数组中找到第一个大于等于key的索引 */
/* 如果找不到返回将key插入的索引 */
int lower_bound(int arr[], int start, int end, int key){
    while(start<end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            end=mid-1;
        }else if(arr[mid]>key){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    if(arr[start]>=key){
        return start;
    }
    return start+1;
}

/* 在有序的升序数组中找到第一个大于key的索引 */
/* 如果找不到返回将key插入的索引 */
int upper_bound(int arr[], int start, int end, int key){
    while(start<end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            start=mid+1;
        }else if(arr[mid]>key){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    if(arr[start]>key){
        return start;
    }
    return start+1;
}

int main(int argc, char *argv[]){
    printf("Hello World!\n");
    int arr[]={1,3,5,5,5,7,7,8,9};
    int size=9;
    printf("****test lower_bound****\n");
    printf("key=0 index=%d\n", lower_bound(arr, 0, size-1, 0));
    printf("key=1 index=%d\n", lower_bound(arr, 0, size-1, 1));
    printf("key=4 index=%d\n", lower_bound(arr, 0, size-1, 4));
    printf("key=5 index=%d\n", lower_bound(arr, 0, size-1, 5));
    printf("key=7 index=%d\n", lower_bound(arr, 0, size-1, 7));
    printf("key=8 index=%d\n", lower_bound(arr, 0, size-1, 8));
    printf("key=10 index=%d\n", lower_bound(arr, 0, size-1, 10));

    printf("****test upper_bound****\n");
    printf("key=0 index=%d\n", upper_bound(arr, 0, size-1, 0));
    printf("key=1 index=%d\n", upper_bound(arr, 0, size-1, 1));
    printf("key=4 index=%d\n", upper_bound(arr, 0, size-1, 4));
    printf("key=5 index=%d\n", upper_bound(arr, 0, size-1, 5));
    printf("key=7 index=%d\n", upper_bound(arr, 0, size-1, 7));
    printf("key=8 index=%d\n", upper_bound(arr, 0, size-1, 8));
    printf("key=10 index=%d\n", upper_bound(arr, 0, size-1, 10));
    return 0;
}
```