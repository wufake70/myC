#include <stdio.h>
#include <math.h>
#include <stdlib.h> // malloc
/*
malloc函数申请动态内存空间，
    malloc(size_t size),参数size即要申请空间的大小(字节),返回该空间的地址，
    初始化的值并不是0，是随机的，
    可能申请失败，返回值为 NULL,
    申请的内存是在堆上，
    申请的内存不是自动释放，需要使用free函数，
    free不能对局部变量进行释放，未定义行为。

*/

int main()
{
    char *pchar;
    unsigned int size=pow(2,32)-1;
    // 动态申请10g内存，空间未被使用，任务管理器看不到
    pchar=(char *)malloc(size);
    if(pchar==NULL){
        printf("内存分配失败！");
        exit(0);
    }

    for(unsigned int i=0;i<size;i++) pchar[i]='A';
    system("pause");
    // 需要释放内存
    free(pchar);

    return 0;
}