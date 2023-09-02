#include <stdio.h>
#include <stdatomic.h>
#include "threadpool.c"
#include <time.h>
#include <unistd.h>

/*
多线程资源争夺问题

加锁和原子操作
    原子操作是更底层的操作，他更快但是只能进行简单操作，如数值加减
    加锁更高级，稍慢，可以进行跟复杂操作。
*/

int counts_0=0;
// 原子变量
atomic_int counts_1=0;


threadpool* pool=NULL;

// 任务函数
void taskFun(void* arg)
{
    printf("task %d\n",*(int*)arg);
    // 加锁(非原子变量)
    pthread_mutex_lock(&pool->mutexpool);
    counts_0++;
    pthread_mutex_unlock(&pool->mutexpool);
    
    // 原子操作
    atomic_fetch_add(&counts_1,1);
    sleep(1);

    // 告诉threadpool 当前task结束
    currentTaskEnd(pool);
    
}

int main()
{
    pool=threadpoolinit(10);
    if(pool==NULL){
        printf("无法创建线程池\n");
        return 1;
    }

    // 获取当前时间戳
    time_t t1=time(NULL);
    
    // 添加任务到线程池
    int numTasks = 20;
    for (int i = 0; i < numTasks; i++) {
        int* taskNumber = (int*)malloc(sizeof(int));
        *taskNumber = i;
        threadpoolAdd(pool, taskFun, taskNumber);
    }

    waitThreadsEnd(pool,numTasks);
    // sleep(1);
    threadpooldestroy(pool);
    time_t t2=time(NULL);

    printf("counts_0: %d\tcounts_1: %d\t timer: %d\n",counts_0,counts_1,(int)(t2-t1));

    system("pause");
    return 0;

    
    


    return 0;
}