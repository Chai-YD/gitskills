#include<stdio.h>


//*******************************************
//移动输入值，将其与1进行与运算，计算1的个数
//*******************************************


int NumberOf1(int n){
    int count =0;
    while(n){
        if(n&1){
            ++count;
        }
        n>>=1;
    }
    return count;
}


//主函数
int main(){
    int count = NumberOf1(5);
    printf("5:%d\n",count);
    count = NumberOf1(8);
    printf("8:%d\n",count);
    count = NumberOf1(10);
    printf("10:%d\n",count);
    return 0;
}
