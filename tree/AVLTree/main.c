#include "tree.h"
void main(void){
    printf("AVL tree\n");
    int arr[12]={10,5,15,1,7,13,20,3,11,14,2,12};
    int len=12;
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
    printf("\n");
    treeDelete(&root,search(root,10));
    treeDelete(&root,search(root,13));
    treeDelete(&root,search(root,1));
    treeDelete(&root,search(root,2));
    treeDelete(&root,search(root,3));
    treeDelete(&root,search(root,11));
    treeDelete(&root,search(root,5));
    treeDelete(&root,search(root,7));
    preOrder(root);
    printf("\n");
}