#include "BinarySearchTree.h"
void main(void){
    int arr[]={10,5,15,1,7,13,20,3,11,14,2,12};
    int len=12;
    TreeNode *root=createTreeNode(arr[0]);
    for(int i=1;i<len;i++){
        insert(root,createTreeNode(arr[i]));
    }
    //traversal
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    printf("\n");
    Delete(&root,search(root,10));
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    printf("\n");
}