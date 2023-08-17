#include <stdio.h>
#include <stdlib.h>
/*

在C语言中，函数参数传递是按值传递的，
这意味着在函数中对参数的修改不会影响到函数外部的变量。

如果我们想要在函数内部修改指针变量的值,
需要传递指针的指针（双重指针）作为参数。

*/

// 可理解为 传入int 指针或指针变量
// void modifyPointer(int* ptr) {
void modifyPointer(int** ptr) {
    // int newValue = 20;
    int* newValue = (int*)malloc(sizeof(int));
    *newValue = 20;

    // 通过int 指针修改值
    // *ptr=newValue;   // ok的 

    // 修改指针变量的值为newValue的地址
    // 单层解引用
    // ptr = &newValue; // 无法修改

    // 双层解引用
    *ptr=newValue;      // ok的

}

void test(int a){
    a = 999;
    printf("%d\n",a);
}

int main() {
    int value = 10;
    int* ptr = &value;

    printf("原始值: %d\n", *ptr);
    modifyPointer(&ptr);
    printf("修改后的值: %d\n", *ptr);

    // ====
    test(value);
    printf("%d\n",value);
    free(ptr);

    return 0;
}