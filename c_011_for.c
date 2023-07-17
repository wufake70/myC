#include <stdio.h>

int main()
{

    // long long int a = 2;
    // for (int i=0;i<=30;i++) a = a*2;
    
    // printf("2的32次方为%lld\n",a);
    // unsigned int b = a;
    // printf("%lld\n",b);

    // 判断素数
    // printf("请输入一个数:\t");
    // int num;
    // scanf("%d",&num);
    // // printf("%d",num/2);
    // for (int i =2;i<=num/2;i++) 
    // {
    //     if(num%i==0){
    //         printf("%d不是素数。",num);
    //         return 0;
    //     }
    // }
    // printf("%d是素数",num);
    // // for(;;) 等价于 while(1)

    // 打印九九乘法表
    int a=1,b;
    for(a;a<=9;a++)
    {
        for(b=1;b<=a;b++)  // 控制行输出
        { 
            printf("%dx%d=%d\t",a,b,a*b);

        }
        printf("\n");
    }
    
    return 0;
}