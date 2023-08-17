#include <stdio.h>
#include <string.h>
struct book{
    char name[20];

} book1;

// 传递结构体参数,效率低
void addBook(struct book a){

}

// 传递结构体指针，效率高
void addBook2(struct book *a){

}
int main(){
    strcpy(book1.name,"C和指针");
    // 申明结构体指针
    struct book *p=NULL;
    p=&book1;

    // 通过结构体指针访问成员
    printf("%s \n",(*p).name); // 点号(.)优先级高于星号(*)
    printf("%s \n",p->name);


    return 0;
}