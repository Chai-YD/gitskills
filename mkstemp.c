//*****************************
//使用mkstemp函数创建临时文件
//*****************************

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

//mkstemp函数介绍
//所谓临时文件，指的是程序运行时为了存储中间数据建立的文件。
//计算机重新启动时，这些文件会被系统自动删除。如果在程序运
//行时，需要把文件短时间写到磁盘上，可以使用mkstemp函数创建
//一个临时文件。

//文件名字必须定义成数组


//主函数
int main(){
    extern int errno;
    char path[] = "mytemp-XXXXXX";//定义文件名
    if(mkstemp(path)!=-1){
        printf("created temp file %s\n",path);//显示文件已经创建成功
    }else{
        printf("cann't create temp %s \n",path);
        printf("errno:%d\n",errno);
        printf("ERR:%s\n",strerror(errno));//显示错误信息
    }
    return 0;
}
