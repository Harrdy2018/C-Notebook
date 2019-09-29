#include <stdio.h>
#include <stdlib.h>
/**
 * subtreeSize 当前结点，包含其本身以及所有子结点的个数
*/
struct TreeNode{
    int val;
    int subtreeSize;
    struct TreeNode *left,*right,*parent;
};
typedef struct TreeNode TreeNode;
typedef enum my_bool{
    my_false=0,my_true
}my_bool;

TreeNode *createTreeNode(int e);
my_bool insert(TreeNode *root,TreeNode *x);
void inOrder(TreeNode *root);
void preOrder(TreeNode *root);
//树中有多少个结点比x小
int rank(TreeNode *root,int x);
//寻找排第n位的结点，默认从小到大
TreeNode *select(TreeNode *root,int n);