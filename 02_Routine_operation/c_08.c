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
FILE* fp=NULL;
char* path_arr[300000];

atomic_int path_arr_index= ATOMIC_VAR_INIT(0),
    txt_counts= ATOMIC_VAR_INIT(0),
    pdf_counts= ATOMIC_VAR_INIT(0),
    docx_counts= ATOMIC_VAR_INIT(0),
    pptx_counts= ATOMIC_VAR_INIT(0),
    csv_counts= ATOMIC_VAR_INIT(0),
    ppt_counts= ATOMIC_VAR_INIT(0),
    jpg_counts= ATOMIC_VAR_INIT(0),
    jpeg_counts= ATOMIC_VAR_INIT(0),
    png_counts= ATOMIC_VAR_INIT(0),
    gif_counts= ATOMIC_VAR_INIT(0);

/*
写入操作&清空数组
过渡(10w)使用malloc函数导致闪退
每过10000 立即释放，
*/
void writeData(void* arg)
{
    FILE* fp=(FILE*)arg;
        
    for(int i=0;i<atomic_load(&path_arr_index)+1;i++){
        fputs(path_arr[i],fp);
        fputs("\n",fp);
        // 释放动态内存
        free(path_arr[i]);
        path_arr[i]=NULL; // 避免空闲指针
    }
    path_arr_index = ATOMIC_VAR_INIT(0);
}

void scan(void*arg)
{
    char* path=(char*)arg;
    DIR *dir=opendir(path);
    if(dir==NULL){
        printf("%s\tFail open DIR T_T\n",path);
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

        if(stat(path_1,&file_stat)!=0){
            // printf("The path information wrong OR No permission T_T\n");
            continue;
        }
        
        // 判断文件(夹)打印名字
        if(S_ISDIR(file_stat.st_mode)){
            // path_2作为 threadpoolAdd(pool,scan,path_2)的参数需要存放在堆上，确保其不被修改
            char* path_2=malloc(sizeof(char)*(strlen(path_1)+10));
            strcpy(path_2,path_1);
            // 获取文件(夹)路径信息
            
            strcat(path_2,"/");
            threadpoolAdd(pool,scan,path_2);

        }else{
            // atomic_fetch_add(&file_counts,1);
            // pdf
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".pdf")==0){
                pthread_mutex_lock(&pool->mutexpool);
                if(atomic_load(&path_arr_index)>5000) writeData(fp);
                path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                }
                strcpy(path_arr[path_arr_index], path_1);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&pdf_counts,1);
                pthread_mutex_unlock(&pool->mutexpool);
                continue;

            }
            // txt
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".txt")==0){
                pthread_mutex_lock(&pool->mutexpool);
                if(atomic_load(&path_arr_index)>5000) writeData(fp);
                path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);

                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&txt_counts,1);
                pthread_mutex_unlock(&pool->mutexpool);
                continue;

            }
            // docx
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".docx")==0){
                pthread_mutex_lock(&pool->mutexpool);
                if(atomic_load(&path_arr_index)>5000) writeData(fp);
                path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&docx_counts,1);
                pthread_mutex_unlock(&pool->mutexpool);
                continue;

            }
            // pptx 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".pptx")==0){
                pthread_mutex_lock(&pool->mutexpool);
                if(atomic_load(&path_arr_index)>5000) writeData(fp);
                path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&pptx_counts,1);
                pthread_mutex_unlock(&pool->mutexpool);
                continue;

            }
            // csv 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".csv")==0){
                pthread_mutex_lock(&pool->mutexpool);
                if(atomic_load(&path_arr_index)>5000) writeData(fp);
                path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&csv_counts,1);
                pthread_mutex_unlock(&pool->mutexpool);
                continue;

            }
            // ppt 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".ppt")==0){
                pthread_mutex_lock(&pool->mutexpool);
                if(atomic_load(&path_arr_index)>5000) writeData(fp);
                path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&ppt_counts,1);
                pthread_mutex_unlock(&pool->mutexpool);
                continue;

            }
            // jpg  
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".jpg")==0){
                pthread_mutex_lock(&pool->mutexpool);
                if(atomic_load(&path_arr_index)>5000) writeData(fp);
                path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&jpg_counts,1);
                pthread_mutex_unlock(&pool->mutexpool);
                continue;

            }
            // png  
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".png")==0){
                // path_arr 不能存储太多数据，这里png 高达12万，存不下会闪退
                // if(atomic_load(&png_counts)>2000) continue;
                pthread_mutex_lock(&pool->mutexpool);
                if(atomic_load(&path_arr_index)>5000) writeData(fp);
                path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&png_counts,1);
                pthread_mutex_unlock(&pool->mutexpool);
                continue;

            }
            // gif 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".gif")==0){
                pthread_mutex_lock(&pool->mutexpool);
                if(atomic_load(&path_arr_index)>5000) writeData(fp);
                path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&gif_counts,1);
                pthread_mutex_unlock(&pool->mutexpool);
                continue;

            }
            // jpeg 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".jpeg")==0){
                pthread_mutex_lock(&pool->mutexpool);
                if(atomic_load(&path_arr_index)>5000) writeData(fp);
                path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                while(path_arr[path_arr_index] == NULL){
                    path_arr[path_arr_index] = (char*)malloc(strlen(path_1) + 1);
                }                
                strcpy(path_arr[path_arr_index], path_1);
                atomic_fetch_add(&path_arr_index,1);
                atomic_fetch_add(&jpeg_counts,1);
                pthread_mutex_unlock(&pool->mutexpool);
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

    pool=threadpoolinit(50);
    if(pool==NULL){
        printf("Unable make threadpool T_T!");
        exit(1);
    }

    if((fp=fopen("path.txt","w"))==NULL){
            printf("Fail open!!\n");
            exit(EXIT_FAILURE);
    }

    char* path=malloc(sizeof(char)*1024);
    printf("Input path: ");
    scanf("%[^\n]",path);
    if(path[strlen(path)-1]!='/'){
        sprintf(path,"%s/",path);
    }

    time_t t1=time(NULL),t2;
    printf("Wait...\n");
    threadpoolAdd(pool,scan,path);
    waitThreadsEnd(pool);
    if(atomic_load(&path_arr_index)>0) writeData(fp);
    t2=time(NULL);

    sleep(2);

    threadpooldestroy(pool);

    char msg[500];
    int file_sum=pdf_counts+txt_counts+\
                 docx_counts+ppt_counts+\
                 pptx_counts+csv_counts+\
                 jpeg_counts+jpg_counts+\
                 png_counts+gif_counts;

    sprintf(msg,"The path scan: \n\t\t %d pdf,\t%d txt\
                                \n\t\t %d docx,\t%d pptx\
                                \n\t\t %d csv,\t%d ppt\
                                \n\t\t %d jpg,\t%d jpeg\
                                \n\t\t %d png,\t%d gif\
                                \n\t\t %d Files,\tConsumed time %d sec.\n\n",\
                                pdf_counts,txt_counts,\
                                docx_counts,pptx_counts,\
                                csv_counts,ppt_counts,\
                                jpg_counts,jpeg_counts,\
                                png_counts,gif_counts,\
                                file_sum,(int)(t2-t1));

    fseek(fp,0,SEEK_SET);
    fputs(msg,fp);
    fclose(fp);

    printf("The path scan \n\t\t %d pdf,\t%d txt\
                           \n\t\t %d docx,\t%d pptx\
                           \n\t\t %d csv,\t%d ppt\
                           \n\t\t %d jpg,\t%d jpeg\
                           \n\t\t %d png,\t%d gif\
                           \n\t\t %d Files,\tConsumed time %d sec.\n",\
                           pdf_counts,txt_counts,\
                           docx_counts,pptx_counts,\
                           csv_counts,ppt_counts,\
                           jpg_counts,jpeg_counts,\
                           png_counts,gif_counts,\
                           file_sum,(int)(t2-t1));

    

    system("pause");

    return 0;
}