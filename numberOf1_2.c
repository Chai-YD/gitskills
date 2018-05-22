


#include<stdio.h>

//***************************************************
//位移1，将位移后的1与输入数字进行比较，计算1的个数
//***************************************************


int numberOf1(int n){
    int count = 0;
    unsigned int flag = 1;
    while(flag){
        if(n&flag){
            ++count;
        }
        flag<<=1;
    }
    return count;
}
//主函数
int main(){
    int count = numberOf1(5);
    printf("5:%d\n",count);
    count = numberOf1(8);
    printf("8:%d\n",count);
    count = numberOf1(10);
    printf("10:%d\n",count);
    return 0;
}
