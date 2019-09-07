#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N,M;
int *arr,head=-1,tail=-1,numofque=0;
void printfQueue();
void enQueue(int value){
    if(head==-1){
        head=0;
    }
    tail=(tail+1)%N;
    arr[tail]=value;
    numofque++;
}
/**Joesphus 问题的出列情况*/
int deQueue(){
    int e;
    e=arr[head];
    /*
    //极端情况 [1,2] head=0 tail=1 报数2
    //出列两次 [1,2] head=0 tail=1
    //入列一次 [1,2] head=tail=0 刚刚好呀
    if(head==tail){
        head=-1;
        tail=-1;
        numofque--;
        return e;
    }*/
    head=(head+1)%N;
    numofque--;
    return e;
}
/**从当前位置开始报数，报M个人,可以优化*/
void test(int real){
    //出列real次
    int info[real];
    for(int j=0;j<real;j++){
        info[j]=deQueue();
    }
    for(int j=0;j<real-1;j++){
        enQueue(info[j]);
    }
    //printfQueue(); 
}
void printfQueue(){
    printf("queue head %d\n",head);
    printf("queue tail %d\n",tail);
    printf("queue numofque %d\n",numofque);
    printf("queue\n");
    int j=head;
    while(j!=tail){
        printf("%d\n",arr[j]);
        j=(j+1)%N;
    }
    printf("%d\n",arr[j]);
}
int main(void){
    scanf("%d%d",&N,&M);
    arr=(int *)malloc(N*sizeof(int));
    memset(arr,0,N*sizeof(int));
    for(int i=1;i<=N;i++){
        enQueue(i);
    }
    //printfQueue();
    for(int i=1;i<=N-1;i++){
        if(M%numofque==0){
            test(numofque);
        }else if(M%numofque==1){
            deQueue();
        }else{
            test(M%numofque);
        }
    }
    printf("%d\n",arr[head]);
    return 0;
}