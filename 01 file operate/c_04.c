#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
格式化读写操作
    fprintf 写入

    fscanf 读取
    
    fseek(fp,0,SEEK_SET) 将文件指针调至开头
    ftell 获取文件指针位置
*/

int main()
{
    FILE *fp;
    if((fp=fopen("date.txt","w+"))==NULL){
        printf("文件打开失败 T_T\n");
        exit(EXIT_FAILURE);
    }

    time_t t;
    time(&t);
    struct tm *p;
    p=localtime(&t);
    // 格式化写入
    fprintf(fp,"%d-%d-%d %d:%d:%d",1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);

    // 格式化读取
    // 将文件指针调至开头
    fseek(fp,0,SEEK_SET);
    int year,mon,day;
    fscanf(fp,"%d-%d-%d",&year,&mon,&day);
    printf("%d-%d-%d\n",year,mon,day);
    
    fclose(fp);




    return 0;
}