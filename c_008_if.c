#include<stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("输入一个值: ");

    // 输入函数，
    // & 取地址符号，它可以用来获取变量的内存地址。
    
    scanf("%d",&num);
    if (num>100)
    {
        printf("%d大于100",num);
    }else if (num==100)
    {
        printf("%d等于100",num);
    }else if (num<100)
    {
        printf("%d小于100",num);
    }
    printf("\n");
    
    system("pause");
    
    


}