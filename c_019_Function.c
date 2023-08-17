#include <stdio.h>
#include <string.h>

// 声明函数(先声明在定义)
void f1();
// 函数定义
void f1()
{
    printf("hello world\n");
}

// sayHi
void sayHi(char name[]);
void sayHi(char name[])
{
    printf("%s 你好!\n",name);
}

// collect info and print it
struct info {
        char name[20];
        int gender;
        int age;
    };

struct info collectInfo();
struct info collectInfo()
{
    
    char name[20];
    int gender; 
    int age;
    printf("\n开始收集信息:\n");
    printf("姓名: ");
    scanf("%s",name); 
    // name[19] = '\0';
    // strcat(name,"\0");
    printf("性别: ");
    scanf("%d",&gender);
    printf("年龄: ");
    scanf("%d",&age);
    struct info a ={
        "",
        gender,
        age
    };
    // 字符串操作谨慎处理
    strncpy(a.name, name, sizeof(a.name) - 1);   
    // 使用strncpy将name数组的内容复制到a.name中
    a.name[sizeof(a.name) - 1] = '\0';           
    // 确保a.name以'\0'结尾
    printf("%s %d %d\n",a.name,a.gender,a.age);

    return a;
    

}

int main()
{
    // f1();
    // char name[20];
    // printf("请输入名字:\t");
    // scanf("%s",name);
    // sayHi(name);

    struct info b;

    b = collectInfo();
    // printf("%s %s %d",b.name,b.gender==0?"女":"男",b.age);
    printf("%s %d %d",b.name,b.gender,b.age);


    return 0;
}