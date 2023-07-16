#include <stdio.h>
#include <stdlib.h>
/*
常量是指在程序运行期间不可更改的值。
宏定义则是在编译期间就被替换的符号常量。
 
*/
// 定义符号常量(宏定义)格式（预处理命令）
#define NAME "wufake"
#define OLD 18
#define YEAR 2023
#define MONTH 7
#define DAY 14
// 预处理不需要分号

void main(){
    printf("名字:%s\n\
年龄:%d\n\
时间:%d.%d.%d\n\
    ",NAME,OLD,YEAR,MONTH,DAY);
system("pause");
    

}