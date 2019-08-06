/**
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1
 * nums=[-1,0,3,5,9,12],target=9
 * 4
 */
#include <stdio.h>
int search(int* nums, int numsSize, int target){
  if(numsSize==0){
    return -1;
  }
  int *left=nums;
  int *right=nums+numsSize-1;
  while(left<right){
    int *mid=left+(right-left)/2;
    if(*mid==target){
      return mid-nums;
    }else if(*mid<target){
      left=mid+1;
    }else{
      right=mid-1;
    }
  }
  if(*left==target){
    return left-nums;
  }else{
    return -1;
  }
}
int main(){
  printf("binary search template 1\n");
  int nums[6]={-1,0,3,5,9,12};
  int numsSize=6;
  int target=9;
  printf("%d\n",search(nums,numsSize,target));
  return 0;
}