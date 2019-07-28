#include <stdio.h>
#include <stdlib.h>
#define NULLKEY -32768
typedef struct{
  int *elem;/*数据元素存储的基址 */
  int length;/*散列表数据元素长度 */
}HashTable;
HashTable *InitHashTable(int len);
int Hash(int key,int length);
void InsertHash(HashTable *H,int key);
int SearchHash(HashTable *H,int key,int *addr);
/**
 * 初始化一个长度为length的HashTable
 */
HashTable *InitHashTable(int len){
  HashTable *H=(HashTable *)malloc(sizeof(HashTable));
  H->length=len;
  H->elem=(int *)malloc(len*sizeof(int));
  for(int i=0;i<len;i++){
    H->elem[i]=NULLKEY;
  }
  return H;
}
/**
 * Hash函数
 * 除留余数法
 */
int Hash(int key,int length){
  int addr=key%length;
    while(addr<0){
        addr++;
    }
    return addr;
}
/**
 * 插入关键字进散列表
 */
void InsertHash(HashTable *H,int key){
  int length=H->length;
  int addr=Hash(key,length);
  //如果不为NULL，表明位置有人占了
  while(H->elem[addr] != NULLKEY){
    //开放地址法的线性探测
    addr=(addr+1)%length;
  }
  H->elem[addr]=key;
}
/**
 * search
 * int *addr的意思是，我调用这个函数之前，先在外部定义 int index
 * 然后int *addr=&index,you know???
 */
int SearchHash(HashTable *H,int key,int *addr){
  int length=H->length;
  //对一个key进行hash得到的就是索引，也就是地址
  *addr=Hash(key,length);
  while(H->elem[*addr] != key){
    *addr=(*addr+1)%length;
    //如果得到的为空地址或者又回到了原点，肯定没找到
    if(H->elem[*addr]== NULLKEY || *addr==Hash(key,length)){
      return 0;
    }
  }
  return 1;
}
int main(){
  printf("HashTable\n");
  int length=16;
  int keys[]={-20,-2,-11,0,12,67,56,16,25,37,22,29,15,47,48,34};
  HashTable *H=InitHashTable(length);
  for(int i=0;i<length;i++){
    InsertHash(H,keys[i]);
  }
  for(int i=0;i<length;i++){
    printf("%4d",H->elem[i]);
  }
  printf("\nsearching\n");
  //先在我要查找34
  int index;
  if(SearchHash(H,34,&index)){
    printf("you find it at %d\n",index);
  }
  if(H->elem){
    free(H->elem);
    H->elem=NULL;
  }
  free(H);
  H=NULL;
  return 0;
}
