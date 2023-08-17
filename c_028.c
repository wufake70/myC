#include <stdio.h>
 
 void f1(void);
 void f1(void)
 {
    static int a=0;
    printf("这是第 %d 次\n",++a  );
    if(a==1000) return;
    f1();
 }

int main()
{
    f1();
    return 0;
}