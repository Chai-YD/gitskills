
//**************************************
//函数sync的使用
//**************************************

//#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//#include<unistd.h>
//
//
//
////主函数
//int main(){
//    int fd;
//    char path[] = "/home/chaiyandong/BAT/LINUX/基础IO/txt1.txt";
//    char s[100] = "hello world!";
//    extern int errno;
//    fd = open(path,O_RDONLY);
//    if(fd != -1){
//        printf("opened file %s\n",path);
//    }else{
//        printf("cann't open file %s\n",path);
//    }
//    write(fd,s,sizeof(s));
//    sync(); //同步数据到磁盘
//    printf("sync function done\n");
//    close(fd);
//    return 0;
//}


//**************************************
//函数fsync的使用
//**************************************

//注：该函数可以将指定文件的缓冲区数据同步到磁盘
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>




//主函数
int main(){
    int fd;
    char path[] = "/home/chaiyandong/BAT/LINUX/基础IO/txt2.txt";
    char s[100] = "hello errno!";
    fd = open(path,O_WRONLY|O_CREAT);
    if(fd != -1){
        printf("opened file %s\n",path);
    }else{
        printf("cann't open file %s\n");
    }
    write(fd ,s,sizeof(s));
    if(fsync(fd)==0){
        printf("fsync function done!\n");
    }else{
        printf("fsync funtion failed\n");
    }
    close(fd);
    return 0;
}






