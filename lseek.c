//*****************************************
//使用lseek函数移动文件的读写位置
//*****************************************

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

//主函数
int main(){
    int fd;
    char path[] = "/home/chaiyandong/BAT/LINUX/基础IO/txt1.txt";//定义文件路径
    int size;
    char s[100] = "";//定义一个字符串
    extern int errno;
    fd = open(path,O_RDONLY);//打开文件
    if(fd != -1){
        printf("opened file %s\n",path);
    }else{
        printf("cann't open file %s\n",path);
    }
    size = read(fd,s,3);//读取三个字符
    printf("%d:",size);
    printf("%s\n",s);

    size = read(fd,s,3);//读取三个字符
    printf("%d:",size);
    printf("%s\n",s);

    lseek(fd,8,SEEK_SET);
    size = read(fd,s,3);//读取三个字符
    printf("%d:",size);
    printf("%s\n",s);

    lseek(fd,0,SEEK_SET);
    size = read(fd,s,3);//读取三个字符
    printf("%d:",size);
    printf("%s\n",s);
}


