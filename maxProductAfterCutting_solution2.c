
//题目：剪绳子(贪婪算法)
//给你一根长度为n的绳子，请把绳子剪成m段（m，n都是整数，n>1并且m>1）,每段绳子
//的长度记为K[0],k[1],...k[m].请问k[0]*k[1]*...*k[m]可能的最大乘积是 多少？例
//如：当绳子的长度为8时，我们把它剪成长度分别为2、3、3的三段，此时得到的乘积
//是18.
#include "maxProductAfterCutting_solution2.h"
int maxProductAfterCutting_solution2(int length){
    if(length < 2){
        return 0;
    }
    if(length == 2){
        return 1;
    }
    if(length == 3){
        return 2;
    }
    //经可能的剪去长度为3的绳子段
    int timesOf3 = length/3;
    //当绳子最后剩下的长度为4的时候，不能剪去长度为3的绳子段。
    //此时更好的方法是把绳子剪成长度为2的俩段，因为2*2>3*1
    if(length - timesOf3*3 == 1){
        timesOf3-=1;
    }
    int  timesOf2 =( length- timesOf3 )*3/2;
    return (int)(pow(3,timesOf3))*(int)(pow(2,timesOf2));
}
//主函数
int main(){
    int ret = maxProductAfterCutting_solution2(8);
    printf("ret = %d\n",ret);
    return 0;
}
