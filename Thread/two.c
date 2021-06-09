#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[5000];
typedef struct {
    int start;
    int end;
    int res;
} MY_ARGS;

void *threadFunc(void *args){
    MY_ARGS *my_args = (MY_ARGS *)args;
    int start = my_args->start;
    int end = my_args->end;
    for (int i = start; i < end; i++) {
        my_args->res += arr[i];
    }
    return NULL;
}

int main()
{
    for(int i=0; i<5000;i++){
        arr[i] = rand()%50;
    }
    MY_ARGS args1={0,2500,0};
    MY_ARGS args2={2500,5000,0};

    pthread_t th1;
    pthread_t th2;

    pthread_create(&th1, NULL, threadFunc, &args1);
    pthread_create(&th2, NULL, threadFunc, &args2);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    int sum1 = args1.res;
    int sum2 = args2.res;
    printf("sum1=%d sum2=%d sum1+sum2=%d\n", sum1, sum2, sum1 + sum2);
    return 0;
}