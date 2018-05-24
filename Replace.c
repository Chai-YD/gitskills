#include<stdio.h>
#include<stdlib.h>

//函数的实现
void ReplaceBlank(char** src1){
    int count = 0;//记录空格数
    int s_count = 0;//记录原字符串的长度
    char* cur = *src1;
    while(*cur != '\0'){
        //进行计算源字符串的长度,不包括结束符
        if(*cur == ' '){
            ++count;
        }
        ++s_count;
        ++cur;
    }
    char* dest = (char*)malloc(sizeof(char)*(s_count + count*2 +1));
    dest[s_count+count*2] = '\0';
    int num = s_count + count*2;
    char* src = *src1;
    while(s_count-- != 0){
        if(src[s_count] == ' '){
            dest[--num] = '0';
            dest[--num] = '2';
            dest[--num] = '%';
        }else{
            dest[--num] = src[s_count];
        }
    }
   *src1 = dest;
    return;
}
//测试用例
void textreplaceBlank(){
    char* src = "Mr John Smith";
    //char* src = "I am";
    ReplaceBlank(&src);
    while(*src != '\0'){
        printf("%c",*src);
        ++src;
    }
    printf("\n");
    return;
}
int main(){
    textreplaceBlank();
    return 0;
}


