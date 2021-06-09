#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadFunc(void *args){
    char *str = (char *)args;
    for(int i=1;i<200;i++){
        printf("thread:%s %d\n", str,i);
    }
    return NULL;
}

int main()
{
    pthread_t th1;
    pthread_t th2;

    pthread_create(&th1, NULL, threadFunc, "th1");
    pthread_create(&th2, NULL, threadFunc, "th2");

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}