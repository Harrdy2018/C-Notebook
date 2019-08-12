## 加密解密
```
两个整数N和K
加密字符串,长度是N+K-1;
输出解密字符串

N=6 K=4 明文1001010
全部异或运算
 1001010
  1001010
   1001010
    1001010
--------------
 1110100110
 
输入
 7 4
 1110100110
输出
 1001010
 
输入
 6 2
 1110001
输出
 101111
```
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int test(char pp,int mingwen[],int lenB,int index,int opt){
  int sum=pp-'0';
  for(int i=index+1;i<=index+opt-1;i++){
    if(i==lenB){
      break;
    }
    sum=sum^mingwen[i];
  }
  return sum;
}
int main(){
  int N,K;
  scanf("%d%d\n",&N,&K);
  char *jiami=(char *)malloc((N+K-1)*sizeof(char));
  scanf("%s",jiami);
  int *mingwen=(int *)malloc(N*sizeof(int));
  memset(mingwen,0,N*sizeof(int));
  for(int j=N-1;j>=0;j--){
    mingwen[j]=test(jiami[(N+K-1)-(N-j)],mingwen,N,j,K);
  }
  for(int i=0;i<N;i++){
    printf("%d",mingwen[i]);
  }
  return 0;
}
```
***注意异或运算是逆运算 1^?=0   1^0=1 即1^1=0***
