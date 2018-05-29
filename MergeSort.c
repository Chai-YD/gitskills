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
//递归版本
void _MergeSort(int array[],int64_t beg,int64_t end,int *tmp){
    if(end - beg <=1){
        return;
    }
     int64_t mid =beg+(end-beg)/2;
    //此时有俩个区间
    //[beg,mid),[mid,end)
    _MergeSort(array,beg,mid,tmp);
    _MergeSort(array,mid,end,tmp);
    _MergeArray(array,beg,mid,end,tmp);
}
//归并排序函数实现
void MergeSort(int array[],int64_t size){
    int *tmp = (int *)malloc(sizeof(int)*size);
    _MergeSort(array,0,size,tmp);
    free(tmp);
}

//测试函数
void TestMergeSort(){
    int array[] = {1,3,2,6,5,9};
    int64_t size = sizeof(array)/sizeof(array[0]);
    int i = 0;
    for(;i<size;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
    MergeSort(array,size);
    i = 0;
    for(;i<size;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
    return;
}
//主函数
int main(){
    TestMergeSort();
    return 0;
}


