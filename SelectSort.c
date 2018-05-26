#include<stdio.h>
//选择排序
//时间复杂度：O(n^2)
//空间复杂度：O（1）
//稳定性：不稳定


//交换函数
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

//函数的实现
void SelectSort(int array[],int size){
    if(size<=1){
        //无需排序
        return;
    }
    //数组元素个数大于1
    size_t bount = 0;//边界
    for(;bount<size;++bount){
        size_t cur = bount+1;
        for(;cur<size;++cur){
            if(array[bount] > array[cur]){
                swap(&array[bount],&array[cur]);
            }
        }//二层循环结束
    }//一层循环结束
    return;
}


//主函数
int main(){
    int arr[] = {1,6,3,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("排序后：");
    int i = 0;
    for(;i<size;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    SelectSort(arr,size);
    printf("排序后：");
    i = 0;
    for(;i<size;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
