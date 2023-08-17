#include <stdio.h>
#include <stdlib.h>

/*
malloc函数,申请的内存空间地址是连续的,
    不会初始化操作，需要使用mem开头的函数(string.h)


*/
int main()
{
    // 动态创建整型数组
    int *pint=NULL;
    int num,i;
    printf("请输入录入整数的个数: ");
    scanf("%d",&num);
    pint=malloc(num*sizeof(int));
    // 录入整数(for循环初始化)
    for(i=0;i<num;i++){
        printf("录入整数: ");
        // scanf("%d",(pint+i)); // &pint[i]效果相同
        scanf("%d",&pint[i]);

    }
    printf("录入完毕。");
    for(i=0;i<num;i++) {
        // printf("%d,",*(pint+i));
        printf("%d,",pint[i]);
    }


    free(pint);  
    return 0;
}