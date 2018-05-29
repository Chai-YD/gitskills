#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
void _MergeArray(int array[],int64_t beg,int64_t mid,int64_t end,int* tmp){
    int64_t cur1 = beg;
    int64_t cur2 = mid;
    int64_t tmp_index = beg;
    while(cur1<mid&&cur2<end){
        if(array[cur1]<array[cur2]){
            tmp[tmp_index++] = array[cur1++];
        }else{
            tmp[tmp_index++] = array[cur2++];
        }
    }
    while(cur1<mid){
        tmp[tmp_index++] = array[cur1++];
    }
    while(cur2 <end){
        tmp[tmp_index++] = array[cur2++];
    }
    //将tmp中的内容拷贝到array中
    memcpy(array+beg,tmp+beg,sizeof(int)*(end-beg));
}
//非递归版本
void MergeSortByLoop(int array[],int64_t size){
    if(size<=1){
        return;
    }
    int *tmp = (int*)malloc(sizeof(int)*size);
    //定义一个步长gap，初始为1，每次合并俩个长度为gap的有序区间
    int64_t gap = 1;
    for(;gap<size;++gap){
        int64_t i=0;
        for(;i<size;i+=2*gap){
            int64_t beg = i;
            int64_t mid = i+gap;
            if(mid >size){
                mid = size;
            }
            int64_t end = i+2*gap;
            if(end >size){
                end = size;
            }
            _MergeArray(array,beg,mid,end,tmp);
        }
    }
    free(tmp);
}

//测试函数
void TestMergeSortByLoop(){
    int array[] = {1,3,2,6,5,9};
    int64_t size = sizeof(array)/sizeof(array[0]);
    int i = 0;
    for(;i<size;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
    MergeSortByLoop(array,size);
    i = 0;
    for(;i<size;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
    return;
}
//主函数
int main(){
    TestMergeSortByLoop();
    return 0;
}


