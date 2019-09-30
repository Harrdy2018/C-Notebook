#include "tree.h"

TreeNode *createTreeNode(int k){
    TreeNode *obj=(TreeNode *)malloc(sizeof(TreeNode));
    obj->val=k;
    obj->parent=obj->left=obj->right=NULL;
    return obj;
}
my_bool insert(TreeNode *root,TreeNode *x){
    if(x->val==root->val){
        return my_false;
    }else if(x->val>root->val){
        if(root->right==NULL){
            root->right=x;
            x->parent=root;
            return my_true;
        }else{
            return insert(root->right,x);
        }
    }else{
        if(root->left==NULL){
            root->left=x;
            x->parent=root;
            return my_true;
        }else{
            return insert(root->left,x);
        }      
    }
}
void inOrder(TreeNode *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%4d",root->val); 
        inOrder(root->right);
    }
}
void preOrder(TreeNode *root){
    if(root!=NULL){
        printf("%4d",root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}
/**
 * 深度和高度 leetcode 104 define
 *        3
 *    9         20
 *           15     7
 * 深度从上往下看，二叉树的深度为根节点到最远叶子节点的最长路径上的节点数,包含本身，为3
 * 高度从下往上看，二叉树的高度为最远叶子节点到根节点的最长路径上的节点数,包含本身，为3
*/
int treeHeight(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    return MAX(treeHeight(root->left),treeHeight(root->right))+1;
}
int getTreeBalanceFactor(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int leftH=treeHeight(root->left);
    int rightH=treeHeight(root->right);
    return leftH-rightH;
}
TreeNode *search(TreeNode *root,int x){
    if(root==NULL){
        return NULL;
    }
    if(x==root->val){
        return root;
    }
    if(x>root->val){
        return search(root->right,x);
    }
    if(x<root->val){
        return search(root->left,x);
    }
}
/*
作用 将x节点部分剔除，将y节点部分移植到x节点处
断了找到x节点的指针，只能通过x节点找到x部分的相关信息
改变了y->parent 指针指向
*/
void transplant(TreeNode **root,TreeNode *x,TreeNode *y){
    //把无关的pinter能断则断,不断掉遍历的时候容易dead loop
    if(y->parent!=NULL){
        if(y->parent->left==y){
            y->parent->left=NULL;
        }else{
            y->parent->right=NULL;
        }
    }
    //正常移植
    if(x==*root){
        *root=y;
        y->parent=NULL;
    }else{
        if(x->parent->left==x){
            x->parent->left=y;
            y->parent=x->parent;
        }else{
            x->parent->right=y;
            y->parent=x->parent;
        }
        x->parent=NULL;
    }   
}
/*
right rotation
下面的数字都是平衡因子
       C=2                      C=2
    B=1                      B=1                         B=0
A=0                       A=0                        A=0     C=0
 left unbalanced tree      right rotation          balanced tree
       8
    5               right rotation       5
3                                     3     8
*/
void treeRRotate(TreeNode **root,TreeNode *x){
    if(x->left!=NULL){
        TreeNode *y=x->left;
        if(y->right != NULL){
            transplant(root,y,y->right);
        }
        transplant(root,x,y);
        y->right=x;
        x->parent=y;
    }  
}
void treeLRotate(TreeNode **root,TreeNode *x){
    if(x->right!=NULL){
        TreeNode *y=x->right;
        if(y->left!=NULL){
            transplant(root,y,y->left);
        }
        transplant(root,x,y);
        y->left=x;
        x->parent=y;
    }
}
/*
      8                                 8
5          as 5 done left rotation    6    as 8 done right rotation   6
   6                                5                              5     8
*/
void treeLRRotate(TreeNode **root,TreeNode *x){
    if(x->left != NULL){
        treeLRotate(root,x->left);
        treeRRotate(root,x);
    }
}
/*
4                                       4
     6          as 6 done right rotation  5    as 4 done left rotation     4
  5                                         6                           5     6
*/
void treeRLRotate(TreeNode **root,TreeNode *x){
    if(x->right != NULL){
        treeRRotate(root,x->right);
        treeLRotate(root,x);
    }
}