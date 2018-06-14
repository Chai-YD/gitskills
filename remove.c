//******************************
//使用remove函数删除指定文件
//******************************

#include<stdio.h>
#include<string.h>
#include<errno.h>

//主函数
int main(){
    //extern可以置于变量或者函数前，以表示变量或者
    //函数的定义在别的文件中，提示编译器遇到此变量
    //和函数时在其他模块中寻找其定义。另外，extern
    //也可用来进行链接指定。
    extern int errno;
    char* path = "/home/chaiyandong/BAT/LINUX/基础IO/tmp.txt";
    if(remove(path)==0){
        printf("deleted file %s\n",path);//删除成
    }else{
        printf("cann't delete the file %s\n",path);//删除失败
        printf("errno:%d\n",errno);//显示错误码
        printf("ERR:%s\n",strerror(errno));//显示错误信息
    }
    return 0;
}



