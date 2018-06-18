
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
//#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//#include<unistd.h>
//
////主函数
//int main(){
//    int fd;
//    char path[] = "/home/chaiyandong/BAT/LINUX/基础IO/txt2.txt";
//    char s[100] = "hello errno!";
//    fd = open(path,O_WRONLY|O_CREAT);
//    if(fd != -1){
//        printf("opened file %s\n",path);
//    }else{
//        printf("cann't open file %s\n");
//    }
//    write(fd ,s,sizeof(s));
//    if(fsync(fd)==0){
//        printf("fsync function done!\n");
//    }else{
//        printf("fsync funtion failed\n");
//    }
//    close(fd);
//    return 0;
//}


//**************************************
//函数fsync的使用
//**************************************

//#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//#include<unistd.h>
//#include<sys/file.h>
//
////主函数
//int main(){
//    int fd, i;
//    char path[] = "/home/chaiyandong/BAT/LINUX/基础IO/txt1.txt";
//    fd = open(path,O_WRONLY|O_CREAT);
//    if(fd != -1){
//        printf("opened file %s\n",path);
//        printf("please input a number to lock the file!\n");//提示输入一个数字
//        scanf("%d",&i);
//        if(flock(fd,LOCK_EX) == 0){//锁定文件
//            printf("the file was locked\n");
//        }else{
//            printf("the file was not locked\n");
//        }
//        printf("please input a number to unlock the file\n");//提示输入一个数字
//        scanf("%d",&i);
//        if(flock(fd,LOCK_UN) == 0){
//            printf("the file was unlocked\n");
//        }else{
//            printf("the file was not unclocked\n");
//        }
//        close(fd);
//    }else{
//        printf("cann't open file %s\n",path);
//    }
//    return 0;
//}


//**************************************
//函数fcntl的使用
//**************************************

//注：文件锁定函数
//与flock函数不同的是，fcntl可以设定对文件的某一部分进行锁定
//#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//#include<unistd.h>
//
////主函数
//int main(){
//    int fd;
//    char path[] = "/home/chaiyandong/BAT/LINUX/基础IO/txt3.txt";
//    struct flock fl;//定义一个flock结构体
//    char s[] = "hello world";
//    extern int errno;
//    fd = open(path,O_WRONLY|O_CREAT);
//    if(fd != -1){
//        printf("opened file %s\n",path);
//    }else{
//        printf("cann't open file %s\n",path);
//    }
//    //构造结构体内容
//    fl.l_type = F_RDLCK;
//    fl.l_whence = SEEK_SET;
//    fl.l_start = 2;
//    fl.l_len = 10;
//    fl.l_len = 15;
//    if(fcntl(fd,F_SETLKW,&fl) == 0){
//        printf("some string of the file was locked\n");
//    }else{
//        printf("not locked\n");
//    }
//    close(fd);
//    return 0;
//}


//**************************************
//函数rename的使用
//**************************************

#include<stdio.h>
#include<string.h>
#include<errno.h>

//主函数i
int main(){
    char path[] = "/home/chaiyandong/BAT/LINUX/基础IO/txt1.txt";
    char newpath[] = "/home/chaiyandong/BAT/LINUX/基础IO/chai.txt";
    extern int errno;
    if(rename(path,newpath) == 0){
        printf("the file %s was moved to %s.\n",path,newpath);
    }else{
        printf("cann't move the file %s\n",path);
        printf("errno:%d\n",errno);
        printf("ERR:%s\n",strerror(errno));
    }
    return 0;
}













