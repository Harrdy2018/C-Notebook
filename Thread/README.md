## thread
### 100个线程将数字累加
```c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int g_result = 0;

void *ProcessTask(void *args){
    g_result++;
    printf("process id=%u thread id=%u g_result=%d\n", getpid(), pthread_self(), g_result);
    return NULL;
}

int main()
{
    printf("start main process id=%u thread id=%u g_result=%d\n", getpid(), pthread_self());
    pthread_t th;
    for(int i=0;i<100;i++){
        int ret=pthread_create(&th, NULL, ProcessTask, &i);
        if(ret != 0){
            printf("Create ProcessTask %d failed!\n", i);
            return -1;
        }
    }
    sleep(5);
    printf("end main g_result=%d\n", g_result);
    return 0;
}
```