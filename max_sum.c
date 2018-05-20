#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    int *arr = (int*)malloc(sizeof(int)*(argc-1));
    int i =0;
    for(;i<argc-1;++i){
        arr[i] = atoi(argv[i+1]);
    }
    i = 0 ;
    int key = arr[0];
    int sum = 0;
    for(;i<argc-1;++i){
        int j = i+1;
        sum =arr[i];
        for(;j<argc-1;++j){
            sum = sum+arr[j];
            if(key<sum){
                key = sum;
            }
        }
    }
    printf("%d\n",key);
    return 0;
}
