#include<stdio.h>

//*****************************************************
//提高效率,使循环的次数等于整数二进制的位数
//*****************************************************

int numberOf1(int n){
    int count = 0;
    while(n){
        n = (n-1)&n;
        ++count;
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


