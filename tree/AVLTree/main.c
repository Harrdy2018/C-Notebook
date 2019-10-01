#include "tree.h"
void main(void){
    printf("AVL tree\n");
    int arr[5]={1,2,3,4,5};
    int len=5;
    TreeNode *root=createTreeNode(arr[0]);
    for(int i=1;i<len;i++){
        insert(&root,root,createTreeNode(arr[i]));
    }
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    //print balance factor
    for(int i=0;i<len;i++){
        printf("%4d",getTreeBalanceFactor(search(root,arr[i])));
    }
}