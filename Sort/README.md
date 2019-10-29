## 排序
* [交换排序类](#交换排序类)
* [选择排序类](#选择排序类)
* [插入排序类](#插入排序类)
* [归并排序类](#归并排序类)
### 交换排序类
* [冒泡排序](./BubbleSort.c)
```
标准：排序时间与交换时间的总和
最好情况：排序表本身有序，compare=n-1，swap=0，时间复杂度o[n]
最坏情况：逆序，compare=(n-1)+(n-2)+...+1=n(n-1)/2，swap=(n-1)+(n-2)+...+1=n(n-1)/2,时间复杂度o[n^2]
时间复杂度：o[n^2]
稳定排序：比如说进行从小到大排序，当前仅当前面的大于后面的才发生交换
总结：最差
```
* [快速排序](./QuickSort.c)
```c
/**
 * 将*left交换到数组的枢轴，使得左边都比他小，右边都比他大
 */
int *FindPivot(int *left,int *right){
  while(left<right){
    while(*left<*right){
      right--;
    }
    swap(&(*left),&(*right));
    while(*left<*right){
      left++;
    }
    swap(&(*left),&(*right));
  }
  return left;
}
```
```
我们将数组int arr[9]={50,10,90,30,70,40,80,60,20};带入；
进入外面的while循环：
    此时*left=50 *right=20;不满足；
    交换 int arr[9]={20,10,90,30,70,40,80,60,50}
    此时*left=20 *right=50;满足；
        left++,此时*left=10,依然满足
        left++,此时*left=90,不满足
    交换int arr[9]={20,10,50,30,70,40,80,60,90}

    由于现在*left=50 *right=90,没走完一趟，继续

    此时*left=50 *right=90;满足；
      right--;,此时*right=60；满足；
      right--;此时*right=80;满足；
      right--;此时*right=40；不满足；
    交换int arr[9]={20,10,40,30,70,50,80,60,90}
    此时*left=40,*right=50;;满足；
      left++;此时*left=30;满足；
      left++;此时*left=70;不满足；
    交换int arr[9]={20,10,40,30,50,70,80,60,90}

    由于现在*left=50 *right=70,没走完一趟，继续

    此时*left=50,*right=70满足;
      right--;注意此时*left=*right=50;不满足
    交换int arr[9]={20,10,40,30,50,70,80,60,90}
    此时*left=*right=50;依然不满足
    交换int arr[9]={20,10,40,30,50,70,80,60,90}

    结束循环

函数FindPivot的作用：
    使*left成为pivot,并返回他的地址;
    在最外面的循环里面，每循环一次，最终left指针依然指向起始值；
    循环结束的时候，left指针和right指针相遇，同时指向起始值；
```
### 选择排序类
* [简单选择排序](./SelectSort.c)
```
int arr[9]={9,1,5,8,3,7,4,6,2};
需要选择9-1=8次
第一次 min=0;
       从min=0开始找出最小值，min=1,交换
       int arr[9]={1,9,5,8,3,7,4,6,2};
第二次 min=1;
       从min=1开始找出最小值，min=8,交换
       int arr[9]={1,2,5,8,3,7,4,6,9}
...
标准：排序时间与交换时间的总和
最好情况：排序表本身有序，compare=(n-1)+(n-2)+...+1=n(n-1)/2，swap=0,时间复杂度o[n^2]
最坏情况：逆序，compare=(n-1)+(n-2)+...+1=n(n-1)/2，swap=n-1，时间复杂度o[n^2]
时间复杂度：o[n^2]
稳定排序：比如说进行从小到大排序，当前仅当前面的大于后面的才发生交换
总结：排序性能上略优于冒泡排序(swap少)
```
* [堆排序](./HeapSort.c)
```
先构造一个大顶堆，或者小顶堆；
loop
  交换两端元素；
  继续构建堆
```
### 插入排序类 
***插入排序算法中的哨兵是为了模拟我们打扑克的插入操作而引入的***
* [直接插入排序](./StraightInsertionSort.c)
```直接插入排序算法复杂度分析
空间复杂度：需要一个记录的辅助空间(哨兵)；
标准：排序时间与交换时间的总和
概率相同原则：若待排序对象序列中出现各种可能排列的概率相同，则可取最好情况和最坏情况的平均情况
最好情况：排序表本身有序，compare=n-1，move=0,时间复杂度o[n]
最坏情况：逆序，compare=2+3+...+n=(n+2)(n-1)/2，
          [6,5,4,3,2] 5先和6比较,然后5作为哨兵,哨兵再和6比较
          move=3+4+5+...+(n+1)=(n+4)(n-1)/2,
          5先移动到哨兵的位置，6再移动到5的位置，哨兵再移动一次
          则平均比较和平均移动次数约为n^2/4,时间复杂度为o[n^2]
时间复杂度：o[n^2]
稳定排序：比如说进行从小到大排序，当前仅当前面的大于后面的才执行
总结：直接排序>选择排序>冒泡排序
```  
* [希尔排序](./ShellSort.c)
```c
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
```
* 希尔排序思路
```
将数组int arr[10]={0,9,1,5,8,3,7,4,6,2};带入，其中位置0作为哨兵
增量increment=9;
loop
  increment=4
  for loop(i=5~9)
    arr[5]=3 arr[5-increment]=arr[1]=9
    保存小值arr[0]=3 int arr[10]={3,9,1,5,8,3,7,4,6,2}
    j=1时，有arr[0]<arr[1] int arr[10]={3,9,1,5,8,9,7,4,6,2}
    j=1-4没有了
    将哨兵附上int arr[10]={3,3,1,5,8,9,7,4,6,2}

    i=6;
    arr[6]=7 arr[2]=1什么也不做
    int arr[10]={3,3,1,5,8,9,7,4,6,2}

    i=7;
    arr[7]=4 arr[3]=5
    保存小值arr[0]=4 int arr[10]={4,3,1,5,8,3,7,4,6,2}
    j=3时，有arr[0]<arr[3] int arr[10]={4,3,1,5,8,9,7,5,6,2}
    j=3-4没有了
    将哨兵附上int arr[10]={4,3,1,4,8,9,7,5,6,2}

    i=8;
    arr[8]=6 arr[4]=8
    保存小值arr[0]=6 int arr[10]={4,3,1,4,8,9,7,5,6,2}
    j=4时，有arr[0]<arr[4] int arr[10]={6,3,1,4,8,9,7,5,8,2}
    j=4-4但是不小于
    int arr[10]={6,3,1,4,6,9,7,5,8,2}

    i=9;
    arr[9]=2 arr[5]=9
    保存小值arr[0]=2 int arr[10]={2,3,1,4,6,9,7,5,8,2}
    j=5时，有arr[0]<arr[5] int arr[10]={2,3,1,4,6,9,7,5,8,9}
    j=5-4时,也有 int arr[10]={2,3,1,4,6,3,7,5,8,9}
    int arr[10]={2,2,1,4,6,3,7,5,8,9}
  
  increment=2
    i=5时需要交换 int arr[10]={3,2,1,3,6,4,7,5,8,9}
  increment=1
    i=2 交换 int arr[10]={1,1,2,3,6,4,7,5,8,9}
    i=5 交换 int arr[10]={4,1,2,3,4,6,7,5,8,9}
    i=7 交换 int arr[10]={5,1,2,3,4,6,7,7,8,9}
             int arr[10]={5,1,2,3,4,6,6,7,8,9}
             int arr[10]={5,1,2,3,4,5,6,7,8,9}
```
*** 
### 归并排序类
* [归并排序](./MergingSort.c)
```c
int *MSort(int arr[],int start,int end){
  int size=end-start+1;
  int *res=(int *)malloc(size*sizeof(int));
  memset(res,0,size*sizeof(int));
  if(start==end){
    res[0]=arr[start];
  }else{
    int mid=(end+start)/2;
    int *a=MSort(arr,start,mid);
    int *b=MSort(arr,mid+1,end);
    Merge(a,mid-start+1,b,end-mid,res);
    PrintfArr(res,size);
  }
  return res;
}
```
* 归并排序思路(递归实现)
```
sort(50,10,90,30)===>sort(50,10)===>sort(50)---由于start=end故返回res1={50}
                                    sort(10)---由于start=end故返回res2={10}
                                    merge------合并返回res3={10,50};
                    sort(90,30)===>sort(90)----由于start=end故返回res4={90}
                                   sort(30)----由于start=end故返回res5={30}
                                   merge-------合并返回res6={30,90};
                    merge----------------------合并返回res7={10,30,50,90};
```