#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
内存泄漏
    隐式内存泄漏，没有free释放内存空间。
    丢失内存块地址

*/
int main()
{
    int count=0;
    while (count<pow(2,31)-1)
    {
        char *a=malloc(1);
        // free(a);  // 隐式内存泄漏
        a=(char *)&count;  // 丢失内存块地址。
        count++;
        if(count==pow(2,30)-1) printf("%d",count);
        
    }
    

    return 0;
}