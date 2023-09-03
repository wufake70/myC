#include <stdio.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>       

#include "threadpool.c"
#include <stdatomic.h>

/*
    多线程中最好不要使用 system函数。

*/

threadpool* pool=NULL;
atomic_int file_counts=0,dir_counts=0;

void scan(void*arg)
{
    char* path=(char*)arg;
    DIR *dir=opendir(path);
    if(dir==NULL){
        printf("%s\t文件夹打开失败T_T\n",path);
        exit(1);// system("pause");
    }

    struct dirent *entry;
    struct stat file_stat;
    char path_1[1024];

    while((entry=readdir(dir))!=NULL){
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        strcpy(path_1,path);
        strcat(path_1,entry->d_name);

        // path_2作为 threadpoolAdd(pool,scan,path_2)的参数需要存放在堆上，确保其不被修改
        char* path_2=malloc(sizeof(char)*(strlen(path_1)+2));
        strcpy(path_2,path_1);
        // 获取文件(夹)路径信息
        if(stat(path_2,&file_stat)!=0){
            // printf("路径信息错误或没有权限T_T\n");
            continue;
        }
        
        // 判断文件(夹)打印名字
        if(S_ISDIR(file_stat.st_mode)){
            
            strcat(path_2,"/");

            threadpoolAdd(pool,scan,path_2);
            atomic_fetch_add(&dir_counts,1);

        }else{
            atomic_fetch_add(&file_counts,1);
            
        }
    }

    // 释放动态内存
    free(path);
    // 关闭文件夹
    closedir(dir);
    currentTaskEnd(pool);
}


int main()
{
    // system("chcp 65001 > nul");  对线程池有影响，不要使用

    pool=threadpoolinit(10);
    if(pool==NULL){
        printf("无法创建线程池T_T!");
        exit(1);
    }

    char* path=malloc(sizeof(char)*1024);
    printf("请输入路径: ");
    scanf("%[^\n]",path);
    if(path[strlen(path)-1]!='/'){
        sprintf(path,"%s/",path);
    }

    time_t t1=time(NULL),t2;
    printf("请稍等...\n");
    scan(path);
    waitThreadsEnd(pool);
    t2=time(NULL);

    sleep(2);

    threadpooldestroy(pool);
    printf("该路径下共扫描到 %d个文件夹,%d个文件。\n共耗时 %d秒。\n",dir_counts,file_counts,(int)(t2-t1));

    system("pause");
    return 0;
}