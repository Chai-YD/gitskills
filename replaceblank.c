//替换空格//
//题目：
//请实现一个函数，把字符串中的每一个空格替换成“%20”.例如，输
//入“We are happy.”,则输出“We%20are%20happy.”.
//
#include<stdio.h>

//替换函数 
//此处传入的参数length为字符串的总长度
void ReplaceBlank(char string[],int length){
    if(string == NULL || length <= 0){
        return;
    }
    int orignalLength = 0;
    int numberofBlank = 0;
    int i = 0;
    while(string[i] != '\0'){
        ++orignalLength;
        if(string[i] == ' '){
            ++numberofBlank;
        }
        ++i;
    }
    int newLength = orignalLength + numberofBlank*2;
    //对新长度进行判断，是否超过数组的最大长度
    if(newLength > length){
        return;
    }
    //标记新旧指针，进行移动元素
    int indexofOrignal = orignalLength;
    int indexofNew = newLength;
    while(indexofOrignal >= 0&&indexofOrignal<indexofNew){
        if(string[indexofOrignal] == ' '){
            string[indexofNew--] = '0';
            string[indexofNew--] = '2';
            string[indexofNew--] = '%';
        }else{
            string[indexofNew--] = string[indexofOrignal];
        }
        --indexofOrignal;
    }
}
//主函数
int main(){
   char string[20] = "We are happy.";
   int length = sizeof(string)/sizeof(string[0]);
   ReplaceBlank(string,length);
   printf("%s\n",string);
   return 0;
}
