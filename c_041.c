#include <stdio.h>
#include <stdlib.h>

struct test{
    int x;
    struct test *p;
};

// 尾插法
void add(struct test **a,int d){
    struct test *b,*tmp;
    // 开辟堆内存空间
    b = (struct test*)malloc(sizeof(struct test));
    b->x=d;
    b->p=NULL;
    tmp=*a;
    while(*a!=NULL){
        a=&(*a)->p;

    }
    tmp=*a;
    *a=b;
    b->p=tmp;

}

// 打印并释放
void printList(struct test *a){
    struct test* tmp=NULL;
    while(a!=NULL){
        
        printf("%d ",a->x);
        tmp=a;
        a=a->p;
        free(tmp);

    }
    printf("\n");
}


int main()
{
    // 头指针
    struct test *hp=NULL;
    add(&hp,1);
    add(&hp,2);
    add(&hp,3);
    add(&hp,4);
    printList(hp);

    printf("%d \n",hp->x);


}