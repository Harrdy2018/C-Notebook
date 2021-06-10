#include <stdio.h>
int parent[6];
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

int unionNode(int x, int y, int parent[]){
    int x_root = findParent(x, parent);
    int y_root = findParent(y, parent);
    if (x_root != y_root) {
        parent[x_root] = y_root;
    } else {
        return 1;
    }
    return 0;
}


int main()
{
    int graph[6][2] = {
        {0,1},
        {1,2},
        {1,3},
        {3,4},
        {2,4},
        {2,5}
    };
    initParent(parent);
    printf("Union & Find \n");
    for(int i=0;i<6;i++){
        if(unionNode(graph[i][0], graph[i][1], parent) == 1){
            printf("have a circle !\n");
            break;
        }
    }
    return 0;
}