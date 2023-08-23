#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>       // 判断是文件夹还是文件
/*
opendir(const char *path)：
    打开一个文件夹，并返回一个指向DIR类型的指针。
    参数path指定了要打开的文件夹的路径。
    如果打开成功，返回一个指向DIR类型的指针；如果失败，返回NULL。

readdir(DIR *dir)：
    读取已经打开的文件夹中的下一个目录项，并返回一个指向dirent结构体的指针。
    参数dir是一个指向DIR类型的指针。当读取完所有的目录项后，返回NULL。

closedir(DIR *dir)：
    关闭先前使用opendir()函数打开的文件夹。
    参数dir是一个指向DIR类型的指针。返回值为0表示关闭成功，-1表示失败。

*/

/*
    使用stat()函数：
    stat()函数可以获取文件或文件夹的详细信息，包括文件类型。
    通过检查文件类型信息即可判断是文件还是文件夹。

    如果是普通文件，即常规文件类型（regular file），
    则使用S_ISREG()宏返回非零值；
    
    如果是目录文件类型（directory），
    则使用S_ISDIR()宏返回非零值。

*/

int main()
{
    // 要打开的路径
    char *path="../";

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
        strcpy(path_1,path);
        strcat(path_1,entry->d_name);
        // 获取文件(夹)路径信息
        if(stat(path_1,&file_stat)!=0){
            printf("路径信息错误或者没有系统权限T_T\n");
            // exit(EXIT_FAILURE);
            continue;
        }
        
        // 判断文件(夹)打印名字
        printf("%s: %s\n",S_ISDIR(file_stat.st_mode)?"文件夹":"文件",entry->d_name);
    }

    // 关闭文件夹
    closedir(dir);



    return 0;
}