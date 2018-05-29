//挖坑法
#include "QuickSort.h"


//QuickSort函数
void QuickSort(RecType arr[],int start,int tail){
    int i = start;
    int j = tail;
    RecType tmp = arr[i];
    if(i<j){
        while(i!=j){
            while(j>i&&arr[j] > tmp){//从右向左找到第一个小于tmp的值
                --j;
            }
            arr[i] = arr[j];
            while(i<j && arr[i] < tmp){//从左向右找到第一个大于tmp的值
                ++i;
            }
            arr[j] = arr[i];
        }
        arr[i] = tmp;
        QuickSort(arr,start,i-1);//对左区间递归排序
        QuickSort(arr,i+1,tail);//对右区间递归排序
    }
}


//主函数
int main(){
    RecType arr[] = {0,1,2,3,4,5};
    QuickSort(arr,0,5);
    int i = 0;
    printf("排序前：");
    for(;i<6;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("排序后：");
    i = 0;
    for(;i<6;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    RecType arr1[] = {3,9,2,5,4,8};
    QuickSort(arr1,0,5);
    i = 0;
    printf("排序前：");
    for(;i<6;++i){
        printf("%d ",arr1[i]);
    }
    printf("\n");
    printf("排序后：");
    i = 0;
    for(;i<6;++i){
        printf("%d ",arr1[i]);
    }
    printf("\n");
    return 0;
}
