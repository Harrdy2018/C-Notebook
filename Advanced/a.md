## 遍历二维数组
```c
#include <stdio.h>
void printf_arr(int p[][3],int row,int col){
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      printf("%4d",p[i][j]);
    }
    printf("\n");
  }
}
int main(int argc,char *argv[]){
  int a[4][3]={
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,11,12}
  };
  printf_arr(a,4,3);
  return 0;
}
```
```c
#include <stdio.h>
void printf_arr(int (*p)[3],int row,int col){
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      printf("%4d",*(p[i]+j));
    }
    printf("\n");
  }
}
int main(int argc,char *argv[]){
  int a[4][3]={
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,11,12}
  };
  printf_arr(a,4,3);
  return 0;
}
```
```c
#include <stdio.h>
void printf_arr(int *p,int row,int col){
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      printf("%4d",*(p+3*i+j));
    }
    printf("\n");
  }
}
int main(int argc,char *argv[]){
  int a[4][3]={
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,11,12}
  };
  printf_arr(*a,4,3);
  return 0;
}
```
### 二维动态数组的初始化与遍历
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 2
#define COL 3
int main(){
  int **b=(int **)malloc(ROW*sizeof(int *));
  for(int i=0;i<ROW;i++){
    b[i]=(int *)malloc(COL*sizeof(int));
    memset(b[i],0,COL*sizeof(int));
  }
  for(int i=0;i<ROW;i++){
    for(int j=0;j<COL;j++){
      printf("%4d",*(b[i]+j));
    }
    printf("\n");
  }
  return 0;
}
```