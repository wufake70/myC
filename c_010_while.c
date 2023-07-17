#include <stdio.h>

int main()
{
    
    // int count = 0;
    // while(getchar()!='\n') count++;
    // printf("一共输入了%d个字符",count);

    int pwd;

    do 
    {
        printf("请输入密码:\t");
        scanf("%d",&pwd);

    } while (pwd!=666);
    printf("Good!");
    
}