#include <stdio.h>
#include <stdlib.h>

/*
有序的链表中插入一个数

*/
struct list{
    int x;
    struct list *next;
} a;

void add(struct list **a,int d){
    struct list *b,*t2;
    // 开辟堆内存空间
    b = (struct list*)malloc(sizeof(struct list));
    b->x=d;
    b->next=NULL;
    t2=*a;
    while(*a!=NULL){
        a=&(*a)->next;

    }
    t2=*a;
    *a=b;
    b->next=t2;

}

// 打印并释放
void printList(struct list *a){
    struct list* t2=NULL;
    while(a!=NULL){
        
        printf("%d ",a->x);
        t2=a;
        a=a->next;
        // free(t2);

    }
    printf("\n");
}

// 排序插入
void sort(struct list **p,int x){
    int count=0;
    struct list *b,*t1,*t2;
    b=(struct list*)malloc(sizeof(struct list));
    b->x=x;
    if((*p)->x<x){
        t1=*p;
    }
    while(*p!=NULL){
        if((*p)->x>b->x){
            if(!count){
                // 情况1 插入最小值
                b->next=*p;
                *p=b;
                return;
            }else{
                // 情况2 插入中间值
                t2->next=b;
                b->next=*p;
                *p=t1;
                return;
            }

        }
        count++;
        t2=*p;
        *p=(*p)->next;

        
    }
    // 情况3 插入最大值
    t2->next=b;
    b->next=NULL;
    *p=t1;

}

int main()
{
    struct list *hp=NULL;
    add(&hp,14);
    add(&hp,31);
    add(&hp,51);
    add(&hp,124);
    add(&hp,144);
    add(&hp,212);

    sort(&hp,1);
    sort(&hp,123);
    sort(&hp,1333);
    printList(hp);
    
    return 0;
}