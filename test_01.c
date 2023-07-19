#include <stdio.h>

int main()
{
    char *a[] = {"wo","zai","huawei"};
    // 指针数组保存的地址值指向字符串
    // 但这个地址值并不是字符数组(字符串)的第一个元素的地址\
    换句话说，这个地址值就是指向字符数组的指针

    char ** p = a;
    printf("p=%p a=%p &a[0]=%p &a[1]=%p\n",p,a,&a[0],&a[1]);
    // *(*(p+2)+1) = "H";
    printf("%c %c %c \n",*(a[2]+1),a[2][1],*(*(p+2)+1));



    return 0;
}