#include <stdio.h>
#include <unistd.h>
#include "threadpool.c"

/*
当要执行的任务函数，并不耗时，如: 只有数字类型自增等操作，
单线程和多线程区别不大,甚至多线程更慢，多线程的自身操作也有一定的开销。

*/

threadpool* pool=NULL;

// 示例任务函数
void taskFunction(void* arg) {
    int taskNumber = *(int*)arg;
    printf("执行任务 %d\n", taskNumber);
    sleep(1); // 模拟一些工作

    // 告诉threadpool 当前task结束
    currentTaskEnd(pool);
}

int main() {
    // 创建一个包含4个线程的线程池
    pool = threadpoolinit(10);
    if (pool == NULL) {
        printf("无法创建线程池\n");
        return 1;
    }

    // 添加任务到线程池
    int numTasks = 100;
    for (int i = 0; i < numTasks; i++) {
        int* taskNumber = (int*)malloc(sizeof(int));
        *taskNumber = i;
        threadpoolAdd(pool, taskFunction, taskNumber);
    }

    // 等待任务池所有任务执行完成
    waitThreadsEnd(pool,numTasks);

    // 销毁线程池
    threadpooldestroy(pool);
    system("pause");

    return 0;
}