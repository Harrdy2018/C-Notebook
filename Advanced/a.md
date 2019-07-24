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