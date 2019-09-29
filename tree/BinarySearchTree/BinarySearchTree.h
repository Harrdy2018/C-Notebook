#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTreeNode{
    int val;
    struct BinarySearchTreeNode *parent,*left,*right;
}TreeNode;
typedef enum my_bool{
    my_false=0,my_true
}my_bool;

TreeNode *createTreeNode(int k);
TreeNode *findMin(TreeNode *root);
TreeNode *findMax(TreeNode *root);
TreeNode *search(TreeNode *root,int k);
TreeNode *predecessor(TreeNode *x);
TreeNode *successor(TreeNode *x);
void Delete(TreeNode **root,TreeNode *z);
void transplant(TreeNode *x,TreeNode *y);
my_bool insert(TreeNode *root,TreeNode *x);
void inOrder(TreeNode *root);
void preOrder(TreeNode *root);
