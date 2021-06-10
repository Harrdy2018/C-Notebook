#include <stdio.h>
int parent[6];
int rank[6]={0};
void initParent(int arr[])
{
    for (int i=0;i<6;i++){
        arr[i]=-1;
    }
    return;
}

int findParent(int x, int parent[]){
    while(parent[x] != -1){
        x = parent[x];
    }
    return x;
}

int unionNode(int x, int y, int parent[], int rank[]){
    int x_root = findParent(x, parent);
    int y_root = findParent(y, parent);
    if (x_root == y_root) {
        return 0;
    } else {
        if(rank[x_root] > rank[y_root]){
            parent[y_root] = x_root;
        } else if(rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        } else {
            parent[x_root] = y_root;
            rank[y_root]++;
        }
        return 1;
    }
}


int main()
{
    int graph[5][2] = {
        {0,1},
        {1,2},
        {2,3},
        {3,4},
        {4,5}
    };
    initParent(parent);
    printf("Union & Find \n");
    for(int i=0;i<5;i++){
        if(unionNode(graph[i][0], graph[i][1], parent, rank) == 0){
            printf("have a circle !\n");
            return 0;
        }
    }
    printf("no have a circle !\n");
    return 0;
}