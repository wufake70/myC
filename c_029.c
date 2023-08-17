#include <stdio.h>

void quickSort(int a[],int,int);
void quickSort(int a[],int left,int right)
{
    // i,j为可以移动的标记点，i++,j--;
    int i=left,j=right;
    int element=a[(left+right)/2];
    int temp;

    // i,j跑到相反方向位置，结束排序。
    while(i<=j){
        while(a[i]<element) i++;
        while(a[j]>element) j--;
        if(i<=j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++,
            j--;
        }
    }
    // j标记点没到达left，继续递归
    // i标记点没到达right，继续递归
    if(left<j){
        quickSort(a,left,j);
    }
    if (i<right)    {
        quickSort(a,i,right);
    }
      
}

int main()
{
    int array[10] = {18,34,2,1,0,42,99,344,53,23};
    quickSort(array,0,9);
    for(int i=0;i<10;i++) printf("%d ",array[i]);

    return 0;

}