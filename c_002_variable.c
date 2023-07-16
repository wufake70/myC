#include <stdio.h>

int main(){
    /*
    命名规则
        字母、下划线、数字
        第一个字符是字母
        区分大小写
    */
   printf("\
    命名规则\n\
        字母、下划线、数字\n\
        第一个字符是字母\n\
        区分大小写\n\
        不能用关键字\n\
   ");
   
//   声明变量
    int a,b = 1; // a没有被初始化。
    float c = 2;
    // 字符串格式化函数
    printf("a:%d\tb:%10d\tc:%.2f\n",a,b,c);  // 这里的10表示所占的宽度。
    c = a = 10;
    printf("%d\t",a);
    printf("%.1f\t",c);
    printf("%d\n",(int)c);


    char aa = 'a';
    printf("%100c",aa);
    
    return 0;
}