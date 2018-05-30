//重定向
//#include<unistd.h>
//int dup(int oldfd)


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
    int new_fd = dup(fd);
    if(new_fd != 1){
        perror("dup");
        return 1;
    }
    printf("new_fd:%d\n",new_fd);
    close(fd);
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
    close(new_fd);
    return 0;
}
