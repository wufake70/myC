#include <stdio.h>
#include <stdlib.h>
/*

读写操作（单字符）
*/
int main()
{
    FILE *fp;
    int ch;

    if((fp=fopen("测试.txt","a+"))==NULL){
        printf("文件打开失败 T_T\n");
        exit(EXIT_FAILURE);
    }

    printf("文件打开成功!!\n读取内容\n\n");
    while ((ch=getc(fp))!=EOF)
    {
        putchar(ch);
    }
    printf("\n输出完成\n");

    // 写入操作
    printf("写入操作\n");
    char str[13] = "hello world\n\0";
    int i=0;
    while (str[i]!='\0')
    {
        putc(str[i],fp);
        i++;
    }

    // 关闭文件
    fclose(fp);
    
    

    

    return 0;
}