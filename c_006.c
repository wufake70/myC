#include <stdio.h>

int main(){
    printf("%d\n",5+5);

    printf("\n取余操作\n");
    // 取余 %,操作数必须是整数。
    printf("9%%5取余 %d\n",9%5);


    //类型转换
    /*
    两个不同类型的数据，先将占用空间小的转换成为大的，进行运算。
    */
   printf("%d\n",sizeof (1+1.4));   // 8 浮点数

    // 强制类型转换 
    printf("%d\n",1+2.4);   // ❌
    printf("%f\n",1+2.4);   // ✔
    printf("%d\n",1+(int)2.4);  // ✔




    return 0;
}



