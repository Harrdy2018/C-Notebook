#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NULLVALUE -3026
#define VISITED 1
#define NOTVISITED 0
#define SIZE 16
typedef struct{
  int *hash;
  int *visited;
}MyHashSet;
typedef enum my_bool{
  my_false=0,my_true
}my_bool;
my_bool myHashSetSearch(MyHashSet *obj,int key,int *addr);
MyHashSet* myHashSetCreate() {
    MyHashSet *H=(MyHashSet *)malloc(sizeof(MyHashSet));
    H->hash=(int *)malloc(sizeof(int)*SIZE);
    H->visited=(int *)malloc(sizeof(int)*SIZE);
    memset(H->hash,NULLVALUE,sizeof(int)*SIZE);
    memset(H->visited,NOTVISITED,sizeof(int)*SIZE);
    return H;
}
/**
 * Hash函数
 * 除留余数法
 */
int hash(int key){
  int addr=key%SIZE;
   //有可能为负数的情况
    while(addr<0){
        addr++;
    }
    return addr;
}
/**
 * 插入关键字进散列表
 */
void myHashSetAdd(MyHashSet* obj, int key) {
    int addr=hash(key);
    if(!myHashSetSearch(obj,key,&addr)){
      //如果这个坑被别人占了，找下一个坑
      while(obj->visited[addr]==VISITED){
        addr=hash(addr+1);
     }
      obj->hash[addr]=key;
      obj->visited[addr]=VISITED; 
    } 
}
/**
 * search
 * int *addr的意思是，我调用这个函数之前，先在外部定义 int index
 * 然后int *addr=&index,you know???
 */
my_bool myHashSetSearch(MyHashSet *obj,int key,int *addr){
  //对一个key进行hash得到的就是索引，也就是地址
  *addr=hash(key);
  if(obj->visited[*addr]==VISITED){
    while(obj->hash[*addr] != key){
      *addr=hash(*addr+1)/SIZE;
      //如果得到的为空地址或者又回到了原点，肯定没找到
      if(obj->hash[*addr]== NULLVALUE|| *addr==hash(key)){
       return my_false;
      }
    }
    return my_true;
  }
  return my_false;
}
my_bool myHashSetContains(MyHashSet* obj, int key) {
   int addr=hash(key);
   if(myHashSetSearch(obj,key,&addr)){
     return my_true;
   }
   return my_false;
}
void myHashSetFree(MyHashSet* obj) {
    free(obj->hash);
    obj->hash=NULL;
    free(obj->visited);
    obj->visited=NULL;
    free(obj);
    obj=NULL;
}
void printf_hash(MyHashSet *obj){
  for(int i=0;i<SIZE;i++){
    printf("%4d",obj->hash[i]);
  }
  printf("\n");
}
int main(){
  int length=16;
  int keys[]={-20,-2,-11,0,12,67,56,16,25,37,22,29,15,47,48,34};
  MyHashSet *H=myHashSetCreate();
  for(int i=0;i<length;i++){
    myHashSetAdd(H,keys[i]);
  }
  printf_hash(H);
  return 0;
}
