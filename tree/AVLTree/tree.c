#include "tree.h"

TreeNode *createTreeNode(int k){
    TreeNode *obj=(TreeNode *)malloc(sizeof(TreeNode));
    obj->val=k;
    obj->parent=obj->left=obj->right=NULL;
    return obj;
}
my_bool insert(TreeNode **obj,TreeNode *root,TreeNode *x){
    if(x->val==root->val){
        return my_false;
    }else if(x->val>root->val){
        if(root->right==NULL){
            root->right=x;
            x->parent=root;
            //tree rebalance
            TreeNode *current=root;
            //insert操作 待插入节点的父亲如果BF=0 树的高度一定没变化
            //insert操作 待插入节点的父亲BF=1,-1,0,2,-2
            if(getTreeBalanceFactor(current)!=0){
                while(current!=NULL){
                    //当前结点依次去找他的父节点，如果出现一次BF=2 or -2 就作调整
                    if(getTreeBalanceFactor(current)==2 || getTreeBalanceFactor(current)==-2){
                        treeRebalance(obj,current);
                        break;
                    }
                    current=current->parent;
                }
            }
            return my_true;
        }else{
            return insert(obj,root->right,x);
        }
    }else{
        if(root->left==NULL){
            root->left=x;
            x->parent=root;
            //tree rebalance
            TreeNode *current=root;
            //insert操作 待插入节点的父亲如果BF=0 树的高度一定没变化
            //insert操作 待插入节点的父亲BF=1,-1,0
            if(getTreeBalanceFactor(current)!=0){
                while(current!=NULL){
                    //当前结点依次去找他的父节点，如果出现一次BF=2 or -2 就作调整
                    if(getTreeBalanceFactor(current)==2 || getTreeBalanceFactor(current)==-2){
                        treeRebalance(obj,current);
                        break;
                    }
                    current=current->parent;
                }
            }
            return my_true;
        }else{
            return insert(obj,root->left,x);
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
void treeRrotate(TreeNode **root,TreeNode *x){
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
void treeLrotate(TreeNode **root,TreeNode *x){
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
void treeLRrotate(TreeNode **root,TreeNode *x){
    if(x->left != NULL){
        treeLrotate(root,x->left);
        treeRrotate(root,x);
    }
}
/*
4                                       4
     6          as 6 done right rotation  5    as 4 done left rotation     4
  5                                         6                           5     6
*/
void treeRLrotate(TreeNode **root,TreeNode *x){
    if(x->right != NULL){
        treeRrotate(root,x->right);
        treeLrotate(root,x);
    }
}
void treeRebalance(TreeNode **root,TreeNode *x){
    int factor=getTreeBalanceFactor(x);
    if(factor==2 && (getTreeBalanceFactor(x->left)==1 || getTreeBalanceFactor(x->left)==0)){
        treeRrotate(root,x);
    }else if(factor==-2 && (getTreeBalanceFactor(x->right)==-1 || getTreeBalanceFactor(x->right)==0)){
        treeLrotate(root,x);
    }else if(factor==-2 && getTreeBalanceFactor(x->right)==1){
        treeRLrotate(root,x);
    }else if(factor==2 && getTreeBalanceFactor(x->left)==-1){
        treeLRrotate(root,x);
    }else{
        //只要BF满足AVL条件，这些异常都不考虑
        printf("the observe node is %d  there is exceptions\n",x->val);
    }
}

TreeNode *findMin(TreeNode *root){
    if(root != NULL){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    return NULL;
}
TreeNode *findMax(TreeNode *root){
  if(root != NULL){
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    return NULL;
}
TreeNode *predecessor(TreeNode *x){
    if(x->left!=NULL){
        return findMax(x->left);
    }else{
        TreeNode *current=x->parent;
        while(current!=NULL && current->val>x->val){
            current=current->parent;
        }
        return current;
    }
}
TreeNode *successor(TreeNode *x){
    if(x->right!=NULL){
        return findMin(x->right);
    }else{
        TreeNode *current=x->parent;
        while(current!=NULL && current->val<x->val){
            current=current->parent;
        }
        return current;
    }
}
void treeDelete(TreeNode **root,TreeNode *x){
    if(x==*root){
        //case 1 the node is leaf
        if(x->left==NULL && x->right==NULL){
            x=NULL;
            return ;
        }
        //case 2 the node have only child
        if(x->left!=NULL && x->right==NULL){
            transplant(root,x,x->left);
            if(getTreeBalanceFactor(x->left)==2 || getTreeBalanceFactor(x->left)==-2){
                treeRebalance(root,x->left);
            }
            return ;
        }
        if(x->left==NULL && x->right!=NULL){
            transplant(root,x,x->right);
            if(getTreeBalanceFactor(x->right)==2 || getTreeBalanceFactor(x->right)==-2){
                treeRebalance(root,x->right);
            }
            return ;
        }
        //case 3 the node have both child
        if(x->left!=NULL && x->right!=NULL){
            TreeNode *current=successor(x);
            if(current==x->right){
                transplant(root,x,x->right);
                if(getTreeBalanceFactor(current)==2 || getTreeBalanceFactor(current)==-2){
                    treeRebalance(root,current);
                }
            }else{
                TreeNode *curParent=current->parent;
                if(current->right!=NULL){
                    transplant(root,current,current->right);
                }
                transplant(root,x,current);
                current->left=x->left;
                x->left->parent=current;
                current->right=x->right;
                x->right->parent=current;
                //rebalance
                while(curParent != NULL){
                    if(getTreeBalanceFactor(curParent)==2 || getTreeBalanceFactor(curParent)==-2){
                        treeRebalance(root,curParent);
                        break;
                    }
                    curParent=curParent->parent;
                }
            }
            return ;
        }
    }else{
        //case 1 the node is leaf
        if(x->left==NULL && x->right==NULL){
            if(x->parent->left==x){
                x->parent->left=NULL;
            }else{
                x->parent->right=NULL;
            }
            TreeNode *current=x->parent;
            x->parent=NULL;
            //delete操作 待删除节点的父亲如果BF=1,-1 那么树的高度一定没变化
            //delete操作 待删除节点的父亲BF=1,-1,0,2,-2
            if(getTreeBalanceFactor(current)!=1 && getTreeBalanceFactor(current)!=-1){
                while(current != NULL){
                    if(getTreeBalanceFactor(current)==2 || getTreeBalanceFactor(current)==-2){
                        treeRebalance(root,current);
                        break;
                    }
                    current=current->parent;
                }
            }
            return ;
        }
        //case 2 the node have only child
        if(x->left!=NULL && x->right==NULL){
            TreeNode *current=x->parent;
            transplant(root,x,x->left);
            while(current != NULL){
                if(getTreeBalanceFactor(current)==2 || getTreeBalanceFactor(current)==-2){
                    treeRebalance(root,current);
                    break;
                }
                current=current->parent;
            }
            return ;
        }
        if(x->left==NULL && x->right!=NULL){
            TreeNode *current=x->parent;
            transplant(root,x,x->right);
            while(current != NULL){
                if(getTreeBalanceFactor(current)==2 || getTreeBalanceFactor(current)==-2){
                    treeRebalance(root,current);
                    break;
                }
                current=current->parent;
            }
            return ;
        }
        //case 3 the node have both child
        if(x->left!=NULL && x->right!=NULL){
            TreeNode *current=successor(x);
            if(current==x->right){
                transplant(root,x,x->right);
                while(current != NULL){
                    if(getTreeBalanceFactor(current)==2 || getTreeBalanceFactor(current)==-2){
                        treeRebalance(root,current);
                        break;
                    }
                    current=current->parent;
                }
            }else{
                TreeNode *curParent=current->parent;
                if(current->right!=NULL){
                    transplant(root,current,current->right);
                }
                transplant(root,x,current);
                current->left=x->left;
                x->left->parent=current;
                current->right=x->right;
                x->right->parent=current;
                //rebalance
                while(curParent != NULL){
                    if(getTreeBalanceFactor(curParent)==2 || getTreeBalanceFactor(curParent)==-2){
                        treeRebalance(root,curParent);
                        break;
                    }
                    curParent=curParent->parent;
                }
            }
            return ;
        }
    }
}
