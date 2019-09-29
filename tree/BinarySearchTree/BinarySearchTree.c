#include "BinarySearchTree.h"
TreeNode *createTreeNode(int k){
    TreeNode *root=(TreeNode *)malloc(sizeof(TreeNode));
    root->val=k;
    root->left=NULL;
    root->parent=NULL;
    root->right=NULL;
    return root;
}
TreeNode *search(TreeNode *root,int k){
    if(root==NULL){
        return NULL;
    }
    if(k==root->val){
        return root;
    }else if(k>root->val){
        return search(root->right,k);
    }else{
        return search(root->left,k);
    }
}
TreeNode *predecessor(TreeNode *x){
    if(x->left!=NULL){
        return findMax(x->left);
    }else{
        TreeNode *current=x->parent;
        while(current != NULL && current->val>x->val){
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
        while(current != NULL && current->val<x->val){
            current=current->parent;
        }
        return current;
    }
}
TreeNode *findMin(TreeNode *root){
    if(root != NULL){
        while(root->left != NULL){
            root=root->left;
        }
        return root;
    }
    return NULL;
}
void transplant(TreeNode *x,TreeNode *y){
    //虽然交换root节点是个特例，但是不能在这里写，因为交换需要改变root
    if(x->parent->right==x){
        x->parent->right=y;
        y->parent=x->parent;
    }else{
        x->parent->left=y;
        y->parent=x->parent;
    }
}
void Delete(TreeNode **root,TreeNode *z){
    if(*root==z){
        //z is root
        //case 1 z is leaf
        if(z->left==NULL && z->right==NULL){
            z==NULL;
            return ;
        }
        //case 2 z has one child
        if(z->left!=NULL && z->right==NULL){
            *root=z->left;
            z->left->parent=NULL;
            return ;
        }
        if(z->left==NULL && z->right!=NULL){
            *root=z->right;
            z->right->parent=NULL;
            return ;
        }
        //case 3 z has both child
        if(z->left!=NULL && z->right != NULL){
            TreeNode *y=successor(z);
            if(y==z->right){
                transplant(z,y);
                *root=y;
                y->parent=NULL;
                y->left=z->left;
                z->left->parent=y;
            }else{
                if(y->right != NULL){
                    transplant(y,y->right);
                }
                //与root节点移植需要慎重
                y->left=z->left;
                z->left->parent=y;
                y->right=z->right;
                z->right->parent=y;
                *root=y;
                y->parent=NULL; 
            }
            return ;
        }
    }else{
        //leaf
        if(z->left==NULL && z->right==NULL){
            if(z->parent->left==z){
                z->parent->left=NULL;
            }else{
                z->parent->right=NULL;
            }
            return;
        }
        //has one child
        if(z->left!=NULL && z->right==NULL){
            transplant(z,z->left);
            return ;
        }
        if(z->right!=NULL && z->left==NULL){
            transplant(z,z->right);
            return ;
        }
        //has both child
        if(z->left!=NULL && z->right!=NULL){
            TreeNode *y=successor(z);
            if(y==z->right){
                //如果待删除节点的后继就是节点的右儿子
                transplant(z,y);
                y->left=z->left;
                z->left->parent=y;
            }else{
                if(y->right!=NULL){
                    transplant(y,y->right);
                }
                transplant(z,y);
                y->left=z->left;
                z->left->parent=y;
                y->right=z->right;
                z->right->parent=y;
            }
            return ;
        }
    }
}
TreeNode *findMax(TreeNode *root){
    if(root != NULL){
        while(root->right != NULL){
            root=root->right;
        }
        return root;
    }
    return NULL;
}
my_bool insert(TreeNode *root,TreeNode *z){
    if(z->val<root->val){
        if(root->left==NULL){
            root->left=z;
            z->parent=root;
            return my_true;
        }else{
            return insert(root->left,z);
        }
    }else if(z->val>root->val){
        if(root->right==NULL){
            root->right=z;
            z->parent=root;
            return my_true;
        }else{
            return insert(root->right,z);
        }
    }else{
        return my_false;
    } 
}
void inOrder(TreeNode *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%4d",root->val);
        inOrder(root->right);
    }
}
void preOrder(TreeNode *root){
    if(root != NULL){
        printf("%4d",root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}