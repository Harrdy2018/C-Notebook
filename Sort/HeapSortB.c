#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
完全二叉树：从上到下，从左到右依次排列
从完全二叉树最后一个父节点构造堆 int parent=(last_node-1)/2;
    调整堆
将堆的根元素与最后一个节点互换，输出，继续构造堆
*/

void swap(int tree[], int i, int j){
    int temp=tree[i];
    tree[i]=tree[j];
    tree[j]=temp;
    return;
}

void heapify(int tree[], int n, int i){
    int parent = i;
    int left=2*parent+1;
    int right=2*parent+2;
    int max = parent;
    if(left<n && tree[max]<tree[left]){
        max = left;
    }

    if(right<n && tree[max]<tree[right]){
        max = right;
    }

    if(max != parent) {
        swap(tree, parent, max);
        heapify(tree, n, max);
    }
    return;
}

void build_heap(int tree[], int n){
    int last_node=n-1;
    int parent=(last_node-1)/2;
    for(int i=parent;i>=0;i--){
        heapify(tree, n, i);
    }
    return;
}

int main()
{
    printf("Hello world!\n");
    int tree[] = {2,5,3,1,10,4};
    int n=6;

    /*
    for(int i=0;i<n;i++){
        printf("%d ", tree[i]);
    }
    printf("\n");
    build_heap(tree, n);
    for(int i=0;i<n;i++){
        printf("%d ", tree[i]);
    }
    printf("\n");
    */

    for(int i=n;i>=1;i--){
        build_heap(tree, i);
        swap(tree, 0, i-1);
        printf("%d ", tree[i-1]);
    }
    printf("\n");
    return 0;
}