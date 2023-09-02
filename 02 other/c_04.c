#include <stdio.h>
#include <unistd.h>
#include "threadpool.c"

// 示例任务函数
void taskFunction(void* arg) {
    int taskNumber = *(int*)arg;
    printf("执行任务 %d\n", taskNumber);
    sleep(1); // 模拟一些工作
}

int main() {
    // 创建一个包含4个线程的线程池
    threadpool* pool = threadpoolinit(10);
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
    waitThreadsEnd(pool);

    // 销毁线程池
    threadpooldestroy(pool);
    system("pause");

    return 0;
}