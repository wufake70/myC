#include <stdio.h>
#include <stdlib.h>
/*
单链表
    结构体一个成员是指向该类型指针,

    方便数据增减

*/

struct Test1{
    int x;  // 信息域
    struct Test1 *next;
};
// 头插法,传入头指针
void addTest1(struct Test1 **a){
    struct Test1 *b,*tmp;
    b = (struct Test1 *)malloc(sizeof(struct Test1));
    printf("需要插入的数据: ");
    scanf("%d",&(*b).x);
    if(*a!=NULL){
        tmp=*a;
        *a=b;
        b->next=tmp;

    }else{
        *a=b;
        b->next=NULL;
    }
}

// 打印并释放
void printList(struct Test1 *a){
    struct Test1* tmp=NULL;
    while(a!=NULL){
        
        printf("%d ",a->x);
        tmp=a;
        a=a->next;
        free(tmp);

    }
    printf("\n");
}

int main() {
    // 头指针
    struct Test1 *hp=NULL;
    // 头插法
    addTest1(&hp);
    addTest1(&hp);
    addTest1(&hp);
    addTest1(&hp);
    printf("%d \n",(*hp).x);
    printf("%d \n",hp->next->x);

    printf("打印链表: \n");
    printList(hp);
    printf("%d \n",(*hp).x);
    printf("%d \n",hp->next->x);


    return 0;
}