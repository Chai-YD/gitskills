//希尔排序
#include<stdio.h>

//函数的实现
void ShellSort(int arr[],int n){
    int i,j,gap;//gap为增量
    int tmp;
    gap = n/2;
    while(gap> 0){
        //对所有相隔gap位置的所有元素组进行排序
        for(i = gap;i<n;i++){
            tmp = arr[i];
            j = i - gap;
            while(j>= 0 && tmp<arr[j]){
                //对相隔gap位置的元素进行排序
                arr[j+gap] = arr[j];
                j = j-gap;
            }
            arr[j+gap] = tmp;
            //j = j - gap;
        }
        //减小增量
        gap = gap/2;
    }
}

int main(){
    int arr[] = {2,6,5,3,4,8,1,11,7,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i =0 ;
    printf("arr: ");
    for(;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    ShellSort(arr,n);
    printf("ShellSort: ");
    for(i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
