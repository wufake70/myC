#include <stdio.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>       // 判断是文件夹还是文件


// char path_arr[1000][1000000];  // 静态存储区空间有限
char* path_arr[1000000];
int path_arr_counts=0;
int txt_counts=0,
    pdf_counts=0,
    docx_counts=0,
    pptx_counts=0,
    csv_counts=0,
    ppt_counts=0,
    jpg_counts=0,
    jpeg_counts=0,
    png_counts=0,
    gif_counts=0;

void scan(char *path)
{
    // 创建文件夹指针
    DIR *dir=opendir(path);
    if(dir==NULL){
        printf("文件夹打开失败T_T\n");
        exit(EXIT_FAILURE);
    }

    // 文件夹子项
    struct dirent *entry;
    // 文件(夹)状态
    struct stat file_stat;
    char path_1[1024];

    // 读取下一个目录项
    while((entry=readdir(dir))!=NULL){
        
        // 去除特殊文件夹 ".",".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        strcpy(path_1,path);
        strcat(path_1,entry->d_name);
        // 获取文件(夹)路径信息
        if(stat(path_1,&file_stat)!=0){
            // printf("路径信息错误或没有权限T_T\n");
            continue;
        }
        
        // 判断文件(夹)打印名字
        if(S_ISDIR(file_stat.st_mode)){
            
            scan(strcat(path_1,"/"));
        }else{
            // pdf
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".pdf")==0){
                path_arr[path_arr_counts] = malloc(strlen(path_1) + 1);
                if (path_arr[path_arr_counts] == NULL) {
                    // 内存分配失败的处理逻辑
                    printf("内存分配失败\n");
                    // 可以选择退出程序或采取其他处理措施
                    // exit(1);
                    continue;
                }
                strcpy(path_arr[path_arr_counts], path_1);
                path_arr_counts++;
                pdf_counts++;
                continue;

            }
            // txt
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".txt")==0){
                path_arr[path_arr_counts] = malloc(strlen(path_1) + 1);
                if (path_arr[path_arr_counts] == NULL) {
                    // 内存分配失败的处理逻辑
                    printf("内存分配失败\n");
                    // 可以选择退出程序或采取其他处理措施
                    // exit(1);
                    continue;
                }                strcpy(path_arr[path_arr_counts], path_1);
                path_arr_counts++;
                txt_counts++;
                continue;

            }
            // docx
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".docx")==0){
                path_arr[path_arr_counts] = malloc(strlen(path_1) + 1);
                if (path_arr[path_arr_counts] == NULL) {
                    // 内存分配失败的处理逻辑
                    printf("内存分配失败\n");
                    // 可以选择退出程序或采取其他处理措施
                    // exit(1);
                    continue;
                }                strcpy(path_arr[path_arr_counts], path_1);
                path_arr_counts++;
                docx_counts++;
                continue;

            }
            // pptx 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".pptx")==0){
                path_arr[path_arr_counts] = malloc(strlen(path_1) + 1);
                if (path_arr[path_arr_counts] == NULL) {
                    // 内存分配失败的处理逻辑
                    printf("内存分配失败\n");
                    // 可以选择退出程序或采取其他处理措施
                    // exit(1);
                    continue;
                }                strcpy(path_arr[path_arr_counts], path_1);
                path_arr_counts++;
                pptx_counts++;
                continue;

            }
            // csv 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".csv")==0){
                path_arr[path_arr_counts] = malloc(strlen(path_1) + 1);
                if (path_arr[path_arr_counts] == NULL) {
                    // 内存分配失败的处理逻辑
                    printf("内存分配失败\n");
                    // 可以选择退出程序或采取其他处理措施
                    // exit(1);
                    continue;
                }                strcpy(path_arr[path_arr_counts], path_1);
                path_arr_counts++;
                csv_counts++;
                continue;

            }
            // ppt 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".ppt")==0){
                path_arr[path_arr_counts] = malloc(strlen(path_1) + 1);
                if (path_arr[path_arr_counts] == NULL) {
                    // 内存分配失败的处理逻辑
                    printf("内存分配失败\n");
                    // 可以选择退出程序或采取其他处理措施
                    // exit(1);
                    continue;
                }                strcpy(path_arr[path_arr_counts], path_1);
                path_arr_counts++;
                ppt_counts++;
                continue;

            }
            // jpg  
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".jpg")==0){
                path_arr[path_arr_counts] = malloc(strlen(path_1) + 1);
                if (path_arr[path_arr_counts] == NULL) {
                    // 内存分配失败的处理逻辑
                    printf("内存分配失败\n");
                    // 可以选择退出程序或采取其他处理措施
                    // exit(1);
                    continue;
                }                strcpy(path_arr[path_arr_counts], path_1);
                path_arr_counts++;
                jpg_counts++;
                continue;

            }
            // png  
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".png")==0){
                path_arr[path_arr_counts] = malloc(strlen(path_1) + 1);
                if (path_arr[path_arr_counts] == NULL) {
                    // 内存分配失败的处理逻辑
                    printf("内存分配失败\n");
                    // 可以选择退出程序或采取其他处理措施
                    // exit(1);
                    continue;
                }                strcpy(path_arr[path_arr_counts], path_1);
                path_arr_counts++;
                png_counts++;
                continue;

            }
            // gif 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".gif")==0){
                path_arr[path_arr_counts] = malloc(strlen(path_1) + 1);
                if (path_arr[path_arr_counts] == NULL) {
                    // 内存分配失败的处理逻辑
                    printf("内存分配失败\n");
                    // 可以选择退出程序或采取其他处理措施
                    // exit(1);
                    continue;
                }                strcpy(path_arr[path_arr_counts], path_1);
                path_arr_counts++;
                gif_counts++;
                continue;

            }
            // jpeg 
            if(strrchr(entry->d_name,'.')&&strcmp(strrchr(entry->d_name,'.'),".jpeg")==0){
                path_arr[path_arr_counts] = malloc(strlen(path_1) + 1);
                if (path_arr[path_arr_counts] == NULL) {
                    // 内存分配失败的处理逻辑
                    printf("内存分配失败\n");
                    // 可以选择退出程序或采取其他处理措施
                    // exit(1);
                    continue;
                }                strcpy(path_arr[path_arr_counts], path_1);
                path_arr_counts++;
                jpeg_counts++;
                continue;

            }
            
            
        }
    }

    // 关闭文件夹
    closedir(dir);
}


int main()
{
    system("chcp 65001 > nul");
    char path[1024];
    printf("请输入路径: ");
    scanf("%s",path);
    if(path[strlen(path)-1]!='/'){
        // 路径拼接
        sprintf(path,"%s/",path);
    }

    time_t t1=time(NULL),t2;
    printf("请稍等...\n");
    scan(path);
    t2=time(NULL);
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
    for(int i=0;i<path_arr_counts;i++){
        fputs(path_arr[i],fp);
        fputs("\n",fp);
    }
    fclose(fp);

    // 释放动态内存
    for(int i=0;i<path_arr_counts;i++){
        free(path_arr[i]);
    }
    system("pause");



    return 0;
}