#include<stdio.h>
int my_atoi(char* pstr){
    int ret_interger = 0;//返回值
    int interger_sign = 1; //标志符号
    //判断指针是否为空
    if(pstr == NULL){
        printf("空指针\n");
        return 0;
    }
    //跳过前面的空格字符
    while(*pstr == ' '){
        pstr++;
    }
    //判断正负号
    if(*pstr == '-'){
        interger_sign = -1;
    }
    if(*pstr == '-'|| *pstr == '+'){
        pstr++;
    }
    //把数字字符转换成整数，并把最后的整数赋值给ret_interger
    while(*pstr>='0'&&*pstr<='9'){
        ret_interger = ret_interger*10+*pstr - '0';
        pstr++;
    }
    ret_interger = ret_interger*interger_sign;
    return ret_interger;
}

int main(){
    char a[] = " -100";;
    char b[] = " 360";
    int c;
    c = my_atoi(a)+ my_atoi(b);
    printf("a:%d\n",my_atoi(a));
    printf("b:%d\n",my_atoi(b));
    printf("except :260   actual: %d \n",c);
}
