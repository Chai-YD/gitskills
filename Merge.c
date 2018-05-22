//归并排序
#include "Merge.h"
//归并函数
void Merge(RecType arr[],int low,int mid,int high){
    int i = low;
    int j = mid+1;
    int k = 0;
    RecType* arr1 = (RecType*)malloc((high-low+1)*sizeof(RecType));
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            arr1[k] == arr[i];
            ++i;
            ++k;
        }else{
            arr1[k] = arr[j];
            ++j;
            ++k;
        }
    }
    while(i<=mid){
        arr1[k] = arr[i];
        ++i;
        ++k;
    }
    while(j<=high){
        arr1[k] = arr[j];
        ++j;
        ++k;
    }
    //将arr1数组中的元素拷贝至数组arr
    for(k =0,i =0;i<=high;++i,++k){
        arr[i] = arr1[k];
    }
    //释放申请空间
    free(arr1);
}

//主函数
int main(){
    RecType arr[] = {5,6,7,8,1,2,3,4};
    Merge(arr,0,3,7);
    int i = 0;
    printf("Merge before:");
    for(;i<8;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    i = 0;
    printf("Merge after:");
    for(;i<8;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}


