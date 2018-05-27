#include<stdio.h>
#include<stdlib.h>
//希尔函数
void myshell(int array[],int64_t size){
    if(size<=1){
        //无需进行排序
        return;
    }
    //数组元素个数大于1
    //此时使用希尔排序
    int64_t gap = size/2;
    for(;gap > 0;gap/=2){
        //此处相当与插入排序中的bound = 1
        int64_t bound = gap;
        for(;bound<size;++bound){
            int bound_value = array[bound];
            int64_t cur =bound;
            for(;cur>0;cur-=gap){
                if(array[cur-gap]>bound_value){
                    array[cur] = array[cur-gap];
                }else{
                    break;
                }
            }//第三层循环结束
            array[cur] = bound_value;
        }//第二层循环结束
    }//第一层循环结束
}

//主函数
int main(){
    int arr[] = {1,6,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("排序前：");
    int i = 0;
    for(;i<size;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    myshell(arr,size);
    printf("排序后：");
    i = 0;
    for(;i<size;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
