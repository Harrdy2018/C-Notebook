//leetcode 705 设计哈希集合
/*
哈希表的两个关键:
一、哈希函数的设计
二、哈希搜索的设计
 */
//牺牲内存空间，换取搜索时间
/*
不使用任何内建的哈希表库设计一个哈希集合
具体地说，你的设计应该包含以下的功能
add(value)：向哈希集合中插入一个值。
contains(value) ：返回哈希集合中是否存在这个值。
remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
示例:
MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // 返回 true
hashSet.contains(3);    // 返回 false (未找到)
hashSet.add(2);          
hashSet.contains(2);    // 返回 true
hashSet.remove(2);          
hashSet.contains(2);    // 返回  false (已经被删除)
注意：
所有的值都在 [1, 1000000]的范围内。
操作的总数目在[1, 10000]范围内。
不要使用内建的哈希集合库。
 */
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
