#include <stdio.h>
#include <stdlib.h>


/*
文件打开,关闭
    fopen(dir,mode) 返回 file pointer

    fclose(fp)

*/
int main()
{
    // 文件指针
    FILE *fp;
    int ch;
    if((fp=fopen("../base.c","r"))==NULL)
    {
        printf("文件打开失败\n");
        exit(EXIT_FAILURE);
    }

    printf("文件打开成功!!\n");

    //读取内容并打印
    // getc获取单字符
    while((ch=getc(fp))!=EOF){      // 宏定义EOF是-1
        putchar(ch);
    }

    // 关闭文件
    fclose(fp);
    printf("\n");
    system("pause");

    return 0;
}