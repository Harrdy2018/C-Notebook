#include "tree.h"
void main(void){
    printf("Augmenting data structure\n");
    int len=12;
    int arr[12]={10,5,15,1,7,13,20,3,11,14,2,12};
    TreeNode *root=createTreeNode(arr[0]);
    printf("%d  %d\n",root->val,root->subtreeSize);
    for(int i=1;i<len;i++){
        insert(root,createTreeNode(arr[i]));
    }
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    for(int i=10;i<=15;i++){
        printf("%d\n",rank(root,i));
    }
    for(int i=1;i<=12;i++){
        printf("%4d",select(root,i)->val);
    }
    printf("\n");
}