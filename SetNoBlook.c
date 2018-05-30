//基于fcntl，实现一个SETNOBLOCK函数，将文件描述符设置为非阻塞
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void SetNoBlock(int fd){
    //获取文件状态标记
    int fl = fcntl(fd,F_GETFL);
    if(fl<0){
        perror("fcntl");
        return;
    }
    //设置文件状态标记
    fcntl(fd,F_SETFL,fl|O_NONBLOCK);
}

//主函数
int main(){
    //无阻塞状态
   // SetNoBlock(0);
    while(1){
        char buf[1024] = {0};
        ssize_t read_size = read(0,buf,sizeof(buf)-1);
        if(read_size<0){
            perror("read");
            sleep(1);
            continue;
        }
        printf("input:%s\n",buf);
    }
    return 0;
}
