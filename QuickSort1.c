//交换法
#include<stdio.h>
#include<stdint.h>

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

void _QuickSort1(int array[],int64_t beg,int64_t end){
    if(end-beg <=1){
        return;
    }
    int64_t mid = Partion(array,beg,end);
    _QuickSort1(array,beg,mid);
    _QuickSort1(array,mid,end);
    return;
}

//交换法快速排序函数实现
void QuickSort1(int array[],int64_t size){
    _QuickSort1(array,0,size);
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
    QuickSort1(array,size);
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
