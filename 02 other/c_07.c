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
char* path_arr[1000000];

atomic_int path_arr_index=0,
    txt_counts=0,
    pdf_counts=0,
    docx_counts=0,
    pptx_counts=0,
    csv_counts=0,
    ppt_counts=0,
    jpg_counts=0,
    jpeg_counts=0,
    png_counts=0,
    gif_counts=0;

void scan(void*arg)
{
    char* path=(char*)arg;
    DIR *dir=opendir(path);
    if(dir==NULL){
        printf("%s\t文件夹打开失败T_T\n",path);
        system("pause");
        exit(1);
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
            // atomic_fetch_add(&dir_counts,1);

        }else{
            // atomic_fetch_add(&file_counts,1);
            // pdf
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".pdf")==0){
                pthread_mutex_lock(&pool->mutexpool);
                path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                }
                strcpy(path_arr[path_arr_index], path_1);
                pthread_mutex_unlock(&pool->mutexpool);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&pdf_counts,1);
                continue;

            }
            // txt
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".txt")==0){
                pthread_mutex_lock(&pool->mutexpool);
                path_arr[path_arr_index] = malloc(strlen(path_1) + 1);

                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                pthread_mutex_unlock(&pool->mutexpool);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&txt_counts,1);
                continue;

            }
            // docx
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".docx")==0){
                pthread_mutex_lock(&pool->mutexpool);
                path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                pthread_mutex_unlock(&pool->mutexpool);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&docx_counts,1);
                continue;

            }
            // pptx 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".pptx")==0){
                pthread_mutex_lock(&pool->mutexpool);
                path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                pthread_mutex_unlock(&pool->mutexpool);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&pptx_counts,1);
                continue;

            }
            // csv 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".csv")==0){
                pthread_mutex_lock(&pool->mutexpool);
                path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                pthread_mutex_unlock(&pool->mutexpool);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&csv_counts,1);
                continue;

            }
            // ppt 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".ppt")==0){
                pthread_mutex_lock(&pool->mutexpool);
                path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                pthread_mutex_unlock(&pool->mutexpool);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&ppt_counts,1);
                continue;

            }
            // jpg  
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".jpg")==0){
                pthread_mutex_lock(&pool->mutexpool);
                path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                pthread_mutex_unlock(&pool->mutexpool);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&jpg_counts,1);
                continue;

            }
            // png  
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".png")==0){
                pthread_mutex_lock(&pool->mutexpool);
                path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                pthread_mutex_unlock(&pool->mutexpool);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&png_counts,1);
                continue;

            }
            // gif 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".gif")==0){
                pthread_mutex_lock(&pool->mutexpool);
                path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                pthread_mutex_unlock(&pool->mutexpool);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&gif_counts,1);
                continue;

            }
            // jpeg 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".jpeg")==0){
                pthread_mutex_lock(&pool->mutexpool);
                path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                pthread_mutex_unlock(&pool->mutexpool);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&jpeg_counts,1);
                continue;

            }
            
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
    // system("chcp 65001 > nul"); 对线程池有影响，不要使用

    pool=threadpoolinit(16);
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
    printf("该路径下共扫描到\n\t\t %d个pdf,\t%d个txt\
                           \n\t\t %d个docx，\t%d个pptx\
                           \n\t\t %d个csv，\t%d个ppt\
                           \n\t\t %d个jpg，\t%d个jpeg\
                           \n\t\t %d个png，\t%d个gif\
                           。\n共耗时 %d秒。\n",\
                           pdf_counts,txt_counts,\
                           docx_counts,pptx_counts,\
                           csv_counts,ppt_counts,\
                           jpg_counts,jpeg_counts,\
                           png_counts,gif_counts,\
                           (int)(t2-t1));

    // 写入操作
    FILE* fp=NULL;
    if((fp=fopen("path.txt","a+"))==NULL){
        printf("打开失败!!\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<path_arr_index;i++){
        fputs(path_arr[i],fp);
        fputs("\n",fp);
    }
    fclose(fp);

    // 释放动态内存
    for(int i=0;i<path_arr_index;i++){
        free(path_arr[i]);
    }

    system("pause");



    return 0;
}