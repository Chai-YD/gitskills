//题目：剪绳子(动态算法)
//给你一根长度为n的绳子，请把绳子剪成m段（m，n都是整数，n>1并且m>1）,每段绳子
//的长度记为K[0],k[1],...k[m].请问k[0]*k[1]*...*k[m]可能的最大乘积是 多少？例
//如：当绳子的长度为8时，我们把它剪成长度分别为2、3、3的三段，此时得到的乘积
//是18.

#include "maxProductAfterCutting_solution1.h"
//剪绳子函数
int maxProductAfterCutting_solution1(int length){
    if(length < 2){
        return 0;
    }
    if(length == 2){
        return 1;
    }
    if(length == 3){
        return 2;
    }
    int *products =(int*)malloc(sizeof(int)*(length+1));
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    int max = 0;
    for(int i =4;i<=length;++i){
        max = 0;
        for(int j = 0;j<=i/2;++j){
            int product = products[j]*products[i-j];
            if( max<product ){
                max = product;
                products[i] = max;
            }
        }
    }
    max = products[length];
    free(products);
    return max;
}

//主函数
int main(){
    int ret = maxProductAfterCutting_solution1(8);
    printf("ret = %d\n",ret);
    return 0;
}




