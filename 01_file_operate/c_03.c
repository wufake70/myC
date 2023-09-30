#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

// 读写操作 字符串
// fgets 读取一行字符串，以'\n'结尾,
// fputs

int main()
{
    FILE *fp;
    char buffer[MAX];
    
    if((fp=fopen("测试.txt","a+"))==NULL){
        printf("打开失败!!\n");
        exit(EXIT_FAILURE);
    }

    // 读取
    /*
    需要设置eof指示器，出错为非零值，正常为0

    fgets 读取一行字符串，以'\n'结束,
    保存在字符串buffer，且指定每次读取的大小
    当读到eof结束，但并没有字符内容时，buffer保持不变
    */
    while(!feof(fp)){

        fgets(buffer,MAX,fp);
        printf("%s",buffer);
    }

    // 写入操作
    fputs("hello c\n",fp);
    fputs("hello c\n",fp);


    // 关闭
    fclose(fp);
    


    return 0;
}