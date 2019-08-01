//leetcode 705 设计哈希集合
//牺牲内存空间，换取搜索时间
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1000000
#define NULLVALUE -1
#define VISITED 1
#define NOTVISITED 0
typedef struct {
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
int hash(int k){
    return k%SIZE;
}
/*
牺牲内存空间，换取搜索时间？
内存空间足够的大，一个萝卜一个坑，搜索只要确定占坑了没有
 */
my_bool myHashSetSearch(MyHashSet *obj,int key,int *addr){
  *addr=hash(key);
  if(obj->visited[*addr]==NOTVISITED){
    return my_false;
  }
  return my_true;
}
//坑很大
void myHashSetAdd(MyHashSet* obj, int key) {
    int addr=hash(key);
    if(!myHashSetSearch(obj,key,&addr)){
      obj->hash[addr]=key;
      obj->visited[addr]=VISITED; 
    } 
}
void myHashSetRemove(MyHashSet* obj, int key) {
    int addr=hash(key);
    if(myHashSetSearch(obj,key,&addr)){
      obj->hash[addr]=NULLVALUE;
      obj->visited[addr]=NOTVISITED;
    }
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
  int arr[2]={1,2};
  MyHashSet *H=myHashSetCreate();
  myHashSetAdd(H,1);
  myHashSetAdd(H,2);
  printf("%d\n",myHashSetContains(H,1));
  printf("%d\n",myHashSetContains(H,3));
  myHashSetAdd(H,2);
  printf("%d\n",myHashSetContains(H,2));
  myHashSetRemove(H,2);
  printf("%d\n",myHashSetContains(H,2));
  return 0;
}
