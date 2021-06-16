#include <stdio.h>
#include <stdlib.h>

/*
arr[6]={1,3,5,7,9,11}   start=0 end=5

                                      arr[0~5]=36
                arr[0~2]=9                                        arr[3~5]=27
    arr[0~1]=4             arr[2]=5                    arr[3~4]=16          arr[5]=11
arr[0]=1      arr[1]=3                          arr[3]=7       arr[4]=9
构造线段树满二叉树不足补0 tree[15]={36,9,27,4,5,16,11,1,3,0,0,7,9,0,0}
*/

#define MAX_LEN 1000

void build_tree(int arr[], int start, int end, int tree[], int node){
    if (start == end){
        tree[node]=arr[start];
    } else {
        int mid = (start+end)/2;
        int left_node = 2*node + 1;
        int right_node = 2*node + 2;
        build_tree(arr, start, mid, tree, left_node);
        build_tree(arr, mid+1, end, tree, right_node);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

/*
update arr[idx]=val;
*/
void update_tree(int arr[], int start, int end, int tree[], int node, int idx, int val) {
    if (start == end){
        arr[idx]=val;
        tree[node] = val;
    } else {
        int mid=(start+end)/2;
        int left_node=2*node+1;
        int right_node=2*node+2;
        if(idx>=start && idx<=mid){
            update_tree(arr,start,mid,tree,left_node,idx,val);
        }

        if(idx>=mid+1 && idx<=end){
            update_tree(arr,mid+1,end,tree,right_node,idx,val);
        }
        tree[node] = tree[left_node] + tree[right_node];
    }
    return;
}

/*
query(L,R) 计算arr[L~R]=?
*/
int query_tree(int arr[], int start, int end, int tree[], int node, int L, int R) {
    printf("start=%d\n", start);
    printf("end=%d\n", end);
    printf("\n");

    if(R<start || L>end){
        return 0;
    }else if(L<=start && end>=R){
        return tree[node];
    }else if(start==end){
        return tree[node];
    } else {
        int mid=(start+end)/2;
        int left_node = 2*node+1;
        int right_node=2*node+2;
        int sum_left = query_tree(arr,start,mid,tree,left_node,L,R);
        int sum_right = query_tree(arr,mid+1,end,tree,right_node,L,R);
        return sum_left+sum_right;
    }
}

int main()
{
    int arr[] = {1,3,5,7,9,11};
    int size = 6;
    int tree[MAX_LEN]={0};

    build_tree(arr, 0, size-1, tree, 0);
    for(int i=0;i<15;i++){
        printf("tree[%d]=%d\n", i, tree[i]);
    }

    printf("\n");
    update_tree(arr,0,size-1,tree,0,4,6);
    for(int i=0;i<15;i++){
        printf("tree[%d]=%d\n", i, tree[i]);
    }

    printf("\n");
    int s = query_tree(arr,0,size-1,tree,0,2,5);
    printf("s=%d\n", s);
    return 0;
}