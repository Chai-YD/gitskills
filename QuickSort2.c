//交换法
#include<stdio.h>
#include<stdint.h>
#include "stack.h"
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int64_t Partion(int array[],int64_t beg,int64_t end){
    if(end - beg<=1){
        return beg;
    }
    int64_t left = beg;
    int64_t right = end -1;
    int key = array[right];
    while(left <right){
        while(left<right&&array[left] <key){
            ++left;
        }
        while(left<right&&array[right]>key){
            --right;
        }
        if(left<right){
            swap(&array[left],&array[right]);
        }
    }
    swap(&array[left],&key);
    return left;
}
//非递归版本快速排序
void QuickSortByLoop(int array[],int64_t size){
    if(size<= 1){
        return;
    }
    SeqStack seq;
    SeqStackInit(&seq);
    int64_t beg = 0;
    int64_t end = size;
    SeqStackPush(&seq,beg);
    SeqStackPush(&seq,end);
    while(1){
        int ret = GetStackTop(&seq,&end);
        if(ret == 0){
            //栈为空
        return;
        }
        SeqStackPop(&seq,&end);
        GetStackTop(&seq,&beg);
        SeqStackPop(&seq,&beg);
        if(end - beg <= 1){
            continue;
        }
        int64_t mid = Partion(array,beg,end);
        SeqStackPush(&seq,beg);
        SeqStackPush(&seq,mid);
        SeqStackPush(&seq,mid+1);
        SeqStackPush(&seq,end);
    }
    return;
}

//检测函数
void TestQuickSort(){
    int array[] = {1,3,9,2,6,4};
    int64_t size = sizeof(array)/sizeof(array[0]);
    int i = 0;
    for(;i<size;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
    QuickSortByLoop(array,size);
    i = 0;
    for(;i<size;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
    return;
}

//主函数
int main(){
    TestQuickSort();
    return 0;
}
