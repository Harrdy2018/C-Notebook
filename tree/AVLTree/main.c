#include "tree.h"
void main(void){
    printf("AVL tree\n");
    int arr[9]={11,9,15,7,10,20,6,8,18};
    int len=9;
    TreeNode *root=createTreeNode(arr[0]);
    for(int i=1;i<len;i++){
        insert(root,createTreeNode(arr[i]));
    }
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    //height
    for(int i=0;i<len;i++){
        printf("%2d",treeHeight(search(root,arr[i])));
    }
    printf("\n");
    //right rotation
    treeRRotate(&root,search(root,11));
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    //left rotation
    treeLRotate(&root,search(root,9));
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    //RL(9)
    printf("right and left rotation\n");
    treeRLRotate(&root,search(root,15));
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
}