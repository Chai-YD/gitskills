//*********************************
//使用create函数创建文件
//*********************************

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

//主函数
int main(){
    //extern可以置于变量或者函数前，以表示变量或者
    //函数的定义在别的文件中，提示编译器遇到此变量
    //和函数时在其他模块中寻找其定义。另外，extern
    //也可用来进行链接指定。
    extern int error;
    char* path = "/home/chaiyandong/BAT/LINUX/基础IO/tmp.txt";
    if(creat(path,0766)==-1){
        printf("can't create the file %s.\n",path);//创建失败
        printf("errno:%d\n",error);//显示错误码
        printf("create file %s\n",strerror(errno));//显示错误信息
    }else{
        printf("created file %s\n",path);//显示创建成功
    }
    return 0;
}

