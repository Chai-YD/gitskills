#include<stdio.h>



//插入函数
void InsertSort(int array[],size_t size){
    if(array == NULL){
        //非法输入
        return;
    }
    if(size <= 1){
        //无需排序
        return;
    }
    size_t bount = 1;
    for(;bount<size;++bount){
        int bount_value = array[bount];
        size_t cur = bount;
        for(;cur >0;--cur){
            if(array[cur-1] > bount_value){
                array[cur] = array[cur - 1];
            }else{
                //找到量合适的位置
                break;
            }
        }
        array[cur] = bount_value;
    }
    return;
}
void TestInsertSort(){
    int array[] = {1,3,2,6,8};
    size_t size = sizeof(array)/sizeof(array[0]);
    int i = 0;
    for(;i<size;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
    InsertSort(array,size);
    i = 0;
    for(;i<size;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
}
//主函数
int main(){
    TestInsertSort();
    return 0;
}
