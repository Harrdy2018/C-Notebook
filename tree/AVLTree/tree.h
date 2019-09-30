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
my_bool insert(TreeNode *root,TreeNode *x);
void inOrder(TreeNode *root);
void preOrder(TreeNode *root);
int treeHeight(TreeNode *root);
int getTreeBalanceFactor(TreeNode *root);
TreeNode *search(TreeNode *root,int x);
void transplant(TreeNode **root,TreeNode *x,TreeNode *y);
void treeRRotate(TreeNode **root,TreeNode *x);
void treeLRotate(TreeNode **root,TreeNode *x);
void treeLRRotate(TreeNode **root,TreeNode *x);
void treeRLRotate(TreeNode **root,TreeNode *x);