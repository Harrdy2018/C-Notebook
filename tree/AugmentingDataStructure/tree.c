#include "tree.h"

TreeNode *createTreeNode(int e){
    TreeNode *obj=(TreeNode *)malloc(sizeof(TreeNode));
    obj->val=e;
    obj->subtreeSize=1;
    obj->left=obj->parent=obj->right=NULL;
    return obj;
}
my_bool insert(TreeNode *root,TreeNode *x){
    if(x->val==root->val){
        return my_false;
    }else if(x->val>root->val){
        if(root->right==NULL){
            root->right=x;
            x->parent=root;
            //root使命已经完成
            while(root != NULL){
                root->subtreeSize++;
                root=root->parent;
            }
            return my_true;
        }else{
            return insert(root->right,x);
        }
    }else{
        if(root->left==NULL){
            root->left=x;
            x->parent=root;
            //root使命已经完成
            while(root != NULL){
                root->subtreeSize++;
                root=root->parent;
            }
            return my_true;
        }else{
            return insert(root->left,x);
        }       
    }
}
int rank(TreeNode *root,int x){
    if(x==root->val){
        return root->left==NULL?1:root->left->subtreeSize+1;
    }else if(x>root->val){
        if(root->right == NULL){
            return root->left==NULL?1:root->left->subtreeSize+1;
        }else{
            return root->left==NULL?1+rank(root->right,x):root->left->subtreeSize+1+rank(root->right,x);
        }
    }else{
        if(root->left == NULL){
            return 0;
        }else{
            return rank(root->left,x);
        }
    }
}
TreeNode *select(TreeNode *root,int n){
    //n为1时，就是在子树里面找最小值的结点
    if(n==1){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
   if(n<root->subtreeSize){
        if(root->left==NULL){
            return select(root->right,n-1);
        }else{
            if(n>root->left->subtreeSize){
                if(n==root->left->subtreeSize+1){
                    return root;
                }else{
                    int m=root->left->subtreeSize;
                    return select(root->right,n-m-1);
                }
            }else{
                return select(root->left,n);
            }
        }
    }
    //此情况就是在子树里面找最大值的结点
    if(n==root->subtreeSize){
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    if(n>root->subtreeSize){
        return NULL;
    }
}
void inOrder(TreeNode *root){
    if(root != NULL){
        inOrder(root->left);
        printf("val of TreeNode is %2d,subtreeSize of TreeNode is %2d\n",root->val,root->subtreeSize);
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