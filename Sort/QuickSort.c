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


/*
#include <stdio.h>
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}
void quickSort(int arr[], int start, int end)
{
    if (start >= end) {
        // 当base被换到的位置刚好处于边界的时候
        printf("start %d end %d\n", start, end);
        return;
    }
    int base = arr[start];
    int left = start;
    int right = end;
    while (left < right) {
        // right 先走
        while (arr[right] >= base && left < right) {
            right--;
        }
        // left 先走
        while (arr[left] <= base && left < right) {
            left++;
        }
        // 满足条件交换(最好情况下，第一次就碰头了)
        swap(arr, left, right);
    }
    // left 和 right 碰头
    swap(arr, start, left);

    quickSort(arr, start, left - 1);
    quickSort(arr, left + 1, end);
}
int main(int argc, char *argv[])
{
    int arr[10] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    quickSort(arr, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
*/
