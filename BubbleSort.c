#include<stdio.h>

//交换函数
void swap(int *a,int *b){
    int tmp =*a;
    *a = *b;
    *b = tmp;
    return;
}
//函数的实现
void BubbleSort(int array[],size_t size){
    if(size <=1){
        return;
    }
    //数组元素数大于1
    size_t bount = 0;//边界
    for(;bount<size;++bount){
        //从后往前遍历，将关键字小的放置在关键字大的前面
        //关键字相等时，相对位置不发生改变
        size_t cur = size - 1;
        for(;cur>bount;--cur){
            if(array[cur] < array[cur-1]){
                swap(&array[cur],&array[cur-1]);
            }
        }//二次遍历结束
    }//一次遍历结束
    return;
}

//主函数
int main(){
    int arr[] = {1,2,6,3};
    int i =0;
    printf("排序前：");
    for(;i<sizeof(arr)/sizeof(arr[0]);++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    BubbleSort(arr,sizeof(arr)/sizeof(arr[0]));
    i =0;
    printf("排序前：");
    for(;i<sizeof(arr)/sizeof(arr[0]);++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
