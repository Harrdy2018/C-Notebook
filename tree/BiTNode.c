#include <stdio.h>
#include <stdlib.h>
enum myBool{
  left=0,
  right=1
};
typedef char TElemType;
/**
 * 二叉树的二叉链表结点结构定义
 */
typedef struct BiTNode{
  TElemType data;
  struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void TreeInit(BiTNode *root);
BiTNode *createNode(TElemType data){
  BiTNode *node=(BiTNode *)malloc(sizeof(BiTNode));
  node->data=data;
  node->lchild=NULL;
  node->rchild=NULL;
  return node;
}
void push(BiTNode *parent,BiTNode *child,enum myBool isRight){
  if(isRight){
    parent->rchild=child;
  }else{
    parent->lchild=child;
  }
}
/**
 * 初始化空二叉树
 */
void TreeInit(BiTNode *root){
  root=NULL;
}
/**
 * 释放二叉树中的所有结点
 */
void ClearBTree(BiTNode *root){
  if(root != NULL){
    ClearBTree(root->lchild);
    ClearBTree(root->rchild);
    free(root);
    root=NULL;
  }
}
/**
 * 计算二叉树的深度
 */
int BTreeDepth(BiTNode *root){
  if(root == NULL){
    return 0;
  }else{
    int depl=BTreeDepth(root->lchild);
    int depr=BTreeDepth(root->rchild);
    if(depl>depr){
      return depl+1;
    }
    return depr+1;
  }
}
/**
 * 刚开始学习树，简单粗暴的构建树的方法
 */
BiTNode *createTree(){
  int length=9;
  char aa[9]={'A','B','C','D','E','F','G','H','I'};
  BiTNode *root=createNode(aa[0]);
  BiTNode *BNode=createNode(aa[1]);
  BiTNode *CNode=createNode(aa[2]);
  push(root,BNode,left);
  push(root,CNode,right);
  BiTNode *DNode=createNode(aa[3]);
  BiTNode *ENode=createNode(aa[4]);
  BiTNode *FNode=createNode(aa[5]);
  push(root->lchild,DNode,left);
  push(root->rchild,ENode,left);
  push(root->rchild,FNode,right);
  BiTNode *GNode=createNode(aa[6]);
  BiTNode *HNode=createNode(aa[7]);
  BiTNode *INode=createNode(aa[8]);
  push(root->lchild->lchild,GNode,left);
  push(root->lchild->lchild,HNode,right);
  push(root->rchild->lchild,INode,right);
  return root;
}
/**
 * 二叉树的前序遍历递归算法
 * root结点作为参照，root left right
 */
void PreOrderTraverse(BiTree T){
  if(T==NULL){
    return ;
  }
  printf("%4c",T->data);
  PreOrderTraverse(T->lchild);
  PreOrderTraverse(T->rchild);
}
/**
 * 二叉树的中序遍历递归算法
 * root结点作为参照，left root right
 */
void MidOrderTraverse(BiTree T){
  if(T==NULL){
    return ;
  }
  MidOrderTraverse(T->lchild);
  printf("%4c",T->data);
  MidOrderTraverse(T->rchild);
}
/**
 * 二叉树的后序遍历递归算法
 * root结点作为参照，left right root
 */
void PostOrderTraverse(BiTree T){
  if(T==NULL){
    return ;
  }
  PostOrderTraverse(T->lchild);
  PostOrderTraverse(T->rchild);
  printf("%4c",T->data);
}
/**
 * 前序输入创建二叉树
 * AB#D##C##
 * 为什么要使用二级指针?
 * 首先我创建一个为NULL的root结点的指针newRoot BiTree newRoot=NULL
 * 为了改变newRoot的值，我必须传它的引用，也就是地址
 */
void CreateBiTree(BiTree *T){
  TElemType ch;
  scanf("%c",&ch);
  if(ch=='#'){
    *T=NULL;
  }else{
    *T=(BiTree)malloc(sizeof(BiTNode));
    if(*T== NULL){
      printf("merroy malloc failed");
    }
    (*T)->data=ch;
    CreateBiTree(&(*T)->lchild);
    CreateBiTree(&(*T)->rchild);
  }
}
/**
 * 后序遍历创建二叉树
 * ###DB##CA
 * 考虑到找到根节点会很快的完成任务，于是乎root right left遍历，发现是AC##BD###
 * 恰好是逆序的
 */
static int length=9;
void CreateBiTree_Post(BiTree *T,char array[]){
  char ch=array[length-1];
  length--;
   if(ch=='#'){
    *T=NULL;
  }else{
    *T=(BiTree)malloc(sizeof(BiTNode));
    if(*T== NULL){
      printf("merroy malloc failed");
    }
    (*T)->data=ch;
    CreateBiTree_Post(&(*T)->rchild,array);
    CreateBiTree_Post(&(*T)->lchild,array);
  }
}
int main(){
  BiTNode *root=createTree();
  PreOrderTraverse(root);
  printf("\n");
  MidOrderTraverse(root);
  printf("\n");
  PostOrderTraverse(root);
  printf("\n");
  //BiTree newRoot=NULL;
  //CreateBiTree(&newRoot);
  //PreOrderTraverse(newRoot);
  BiTree nnRoot;
  TreeInit(nnRoot);
  char aa[]={'#','#','#','D','B','#','#','C','A'};
  CreateBiTree_Post(&nnRoot,aa);
  PreOrderTraverse(nnRoot);
  return 0;
}