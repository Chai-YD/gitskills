//重定向
//#include<unistd.h>
//int dup2(int oldfd,int newfd)


#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
    int fd = open("./log",O_CREAT|O_RDWR);
    if(fd <0){
        perror("open");
        return 1;
    }
    close(1);
    dup2(fd,1);
    //dup2与dup的区别，，dup2不需要重新定义文件描述符与检测，，
    for(;;){
        char buf[1024] = {0};
        ssize_t read_size = read(0,buf,sizeof(buf)-1);
        if(read_size<0){
            perror("read");
            continue;
        }
        printf("%s",buf);
        fflush(stdout);
    }
    close(fd);
    return 0;
}
