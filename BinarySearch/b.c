/**
 * leetcode 33 搜索旋转排序数组
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )
 * 这样的数组比较特别，它是在有序之后进行旋转的，所以4,5,6,7一定是递增
 * 0,1,2一定是递减，如果*mid=7 直接与右边比较大小，如果7大，小数一定在右边
 * 如果*mid=0 直接与右边比较大小，小于，小数一定在左边
 */
/**
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 */
#include <stdio.h>
void findMin(int* nums, int numsSize,int *addr){
  int *left=nums;
  int *right=nums+numsSize-1;
  while(left<right){
    int *mid=left+(right-left)/2;
    if(*mid>*right){
      left=mid+1;
    }else{
      right=mid;
    }
  }
  *addr=right-nums;
}
int search(int* nums, int numsSize, int target){
  if(numsSize==0){
    return -1;
  }
  int addr;
  findMin(nums,numsSize,&addr);
  int *left=nums;
  int *right=nums+numsSize-1;
  if(*left>target){
    left=nums+addr;
  }else if(addr>0 && *left<=target){
    right=nums+addr-1;
  }else{
      
  }
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
  printf("binary search template 1 螺旋数组\n");
  int nums[6]={1,2,3,4,5,6};
  int numsSize=6;
  int target=3;
  printf("%d\n",search(nums,numsSize,target));
  return 0;
}
