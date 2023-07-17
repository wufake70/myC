#include <stdio.h>

int main()
{
    int a[6]={[2]=999};
    for(int i;i<sizeof a/sizeof (int);i++)
    {
        printf("%d\n",a[i]);

    }

    printf("支持动态数组\n");
    int b;
    printf("请输入长度\n");
    scanf("%d",&b);
    int c[b];
    printf("数组c的长度为%d",sizeof c/sizeof(int));


    return 0;
}