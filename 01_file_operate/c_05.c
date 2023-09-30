#include <stdio.h>
#include <stdlib.h>
/*
二进制读写操作
    将程序运行时内存的数据写入文件，
    方便后面直接将文件数据载入内存
    
    fwrite
    size_t write_counts=fwrite(arr,sizeof(int),5,fp); 

    fread
    size_t read_counts=fread(arr2,sizeof(int),5,fp);
    fread，fwrite返回数据是读或写的字节数(数据项为1时),
    fread，返回0时表示已到达文件末尾。

*/

int main()
{
    FILE *fp;
    if((fp=fopen("binray.txt","wb+"))==NULL){
        printf("文件打开失败T_T\n");
        exit(EXIT_FAILURE);
    }

    int arr[5]={1,2,3,4,5};

    // 写入二进制数据
    // 成功写入的计数器
    size_t write_counts=fwrite(arr,sizeof(int),5,fp); 
    // printf("%d\n",(int)write_counts);
    if(write_counts!=5){
        printf("写入不完整\n");
    }else{
        printf("成功写入。\n");

    }

    // 读取二进制数据-->数组
    int arr2[5];
    fseek(fp,0,SEEK_SET);
    // 成功读取的计数器
    size_t read_counts=fread(arr2,sizeof(int),5,fp);
    if(read_counts!=5){
        printf("读取不完整T_T\n");
        exit(EXIT_FAILURE);
    }else{
        printf("读取成功\n");
        for(int i=0;i<5;i++) printf("%d\t",arr2[i]);
    }
    printf("\n");
    system("pause");
    
    


    return 0;
}