//堆排序
//时间复杂度：O(nlogn)
//空间复杂度：O（1）
//稳定性：不稳定
#include<stdio.h>
//方法一：艰难个新元素放到数组的末尾，上浮式调整
//方法二：下沉式调整，起始位置放置与堆从后往前第一个非叶子结点

//下沉式调整函数AdjustDown的实现
void swap(int* a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
void AdjustDown(int array[],size_t size,size_t index){
    size_t parent = index;
    size_t child = 2 *parent +1;
    while(child<size){
        if(child+1<size&&array[child+1]>array[child]){
            child = child +1;
        }
        if(array[parent] <array[child]){
            swap(&array[parent],&array[child]);
        }
        parent = child;
        child = 2* parent +1;
    }
    return;
}


void HeapCreate(int array[],size_t size){
    if(array == NULL){
        //非法输入
        return;
    }
    size_t i = (size - 1 - 1)/2;
    for(;i>0;--i){
        AdjustDown(array,size,i);
    }
    AdjustDown(array,size,0);
    return;;
}
void HeapPop(int array[],size_t size){
    if(size <= 1){
        return;
    }
    swap(&array[0],&array[size-1]);
    --size;
    AdjustDown(array,size,0);
    return;
}

//主排序函数实现
void HeapSort(int array[],size_t size){
    if(size<=1){
        return;
    }
    HeapCreate(array,size);
    size_t i = 0;
    for(;i<size;++i){
        HeapPop(array,size-i);
    }
    return;
}



//主函数
int main(){
    int arr[] = {1,3,6,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("排序前：");
    int i = 0;
    for(;i<size;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    HeapSort(arr,size);
    printf("排序后：");
    i = 0;
    for(;i<size;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}


