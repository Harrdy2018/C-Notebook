#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (a>b?a:b)
typedef struct TreeNode{
    int val;
    struct TreeNode *parent,*left,*right;
}TreeNode;
typedef enum my_bool{
    my_false=0,my_true
}my_bool;
TreeNode *createTreeNode(int k);
my_bool insert(TreeNode **obj,TreeNode *root,TreeNode *x);
void inOrder(TreeNode *root);
void preOrder(TreeNode *root);
int treeHeight(TreeNode *root);
int getTreeBalanceFactor(TreeNode *root);
TreeNode *search(TreeNode *root,int x);
void transplant(TreeNode **root,TreeNode *x,TreeNode *y);
void treeRrotate(TreeNode **root,TreeNode *x);
void treeLrotate(TreeNode **root,TreeNode *x);
void treeLRrotate(TreeNode **root,TreeNode *x);
void treeRLrotate(TreeNode **root,TreeNode *x);
void treeRebalance(TreeNode **root,TreeNode *x);