#include <stdio.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>       // 判断是文件夹还是文件

/*
sprintf 格式化拼接路径
    sprintf(path,"%s/",path);

*/

int file_counts=0,dir_counts=0;

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
            dir_counts++;
            printf("dir: %s\n",path_1);
            scan(strcat(path_1,"/"));
            // printf("\n");
        }else{
            printf("file: %s\n",path_1);
            file_counts++;
            
        }
    }

    // 关闭文件夹
    closedir(dir);
}


int main()
{
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
    printf("该路径下共扫描到 %d个文件夹,%d个文件。\n共耗时 %d秒。\n",dir_counts,file_counts,(int)(t2-t1));

    system("pause");



    return 0;
}