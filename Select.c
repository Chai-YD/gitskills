#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/select.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>


//初始化文件数组函数实现
void Init(int* fd_list,int fd_list_size){
    int i = 0;
    for(;i<fd_list_size;++i){
        fd_list[i] = -1;
    }
    return;
}

//nfds的计算函数实现
void Reload(int listen_fd,int* connect_list,int connect_list_size,
        fd_set* read_fds,int* max_fd){
    //清除描述词组set的全部位
    FD_ZERO(read_fds);
    //设置描述词组set的相关fd位
    FD_SET(listen_fd,read_fds);
    int max = listen_fd;

    int i = 0;
    for(;i<connect_list_size;++i){
        if(connect_list[i] != -1){
            FD_SET(connect_list[i],read_fds);
            if(connect_list[i]>max){
                max = connect_list[i];
            }
        }
    }
    *max_fd = max;
    return;
}

void Add(int fd,int *connect_list,int connect_list_size){
    int i = 0;
    for(;i<connect_list_size;++i){
        if(connect_list[i] == -1){
            connect_list[i] = fd;
            break;
        }
    }
    return;
}

int main(int argc,char* argv[]){
    if(argc != 3){
        return 1;
    }
    //创建结构体
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr =inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));
    //创建套接字
    int listen_fd = socket(AF_INET,SOCK_STREAM,0);
    if(listen_fd <0){
        //创建失败
        perror("socket");
        return 1;
    }
    //绑定
    int ret = bind(listen_fd,(struct sockaddr*)&addr,sizeof(addr));
    if(ret < 0){
        //绑定失败
        perror("bind");
        return 1;
    }
    //监听
    ret = listen(listen_fd,5);
    if(ret < 0){
        //监听失败
        perror("listen");
        return 1;
    }
    fd_set read_fds;
    int fd_list[1024];
    //初始化文件数组
    Init(fd_list,sizeof(fd_list)/sizeof(int));
    //进入循环
    for(;;){
        //在一个运行的服务器中，套接字文件描述符一定存在
        int max_fd = listen_fd;
        //select函数中参数nfds的计算
        Reload(listen_fd,fd_list,sizeof(fd_list)/sizeof(int),&read_fds,&max_fd);
        printf("before select:%d\n",FD_ISSET(listen_fd,&read_fds));
        //最后一个参数，表示参数timeout取值
        //NULL：表示没有timeout，一直被阻塞
        //0：表示仅检测描述符的状态，然后立即返回
        //特定的时间值：表示如果在指定的时间段里没有事件发生，将超时返回
        int ret = select(max_fd+1,&read_fds,NULL,NULL,NULL);
        printf("after select:%d\n",FD_ISSET(listen_fd,&read_fds));
        if(ret < 0){
            perror("select");
            return 1;
        }
        if(ret == 0){
            printf("select timeout\n");
            continue;
        }
        //处理listen_fd
        if(FD_ISSET(listen_fd,&read_fds)){
            struct sockaddr_in client_addr;
            //计算client_addr的大小
            socklen_t len = sizeof(client_addr);
            //连接客户端
            int connect_fd = accept(listen_fd,(struct sockaddr*)&client_addr,&len);
            if(connect_fd<0){
                //连接失败
                perror("accept");
                continue;
            }
            //连接成功
            printf("client:%s:%d connected\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
            //将连接描述符添加至描述词组中
            Add(connect_fd,fd_list,sizeof(fd_list)/sizeof(int));
        }
        //处理connect_fd
        size_t i = 0;
        for(;i<sizeof(fd_list)/sizeof(int);++i){
            if(fd_list[i] == -1){
                continue;
            }
            if(!FD_ISSET(fd_list[i],&read_fds)){
                continue;
            }
            char buf[1024] = {0};
            ssize_t read_size = read(fd_list[i],buf,sizeof(buf)-1);
            if(read_size < 0){
                perror("read");
                continue;
            }
            if(read_size == 0){
                printf("client say: goodbye\n");
                close(fd_list[i]);
                fd_list[i] = -1;
            }
            printf("client say:%s\n",buf);
            write(fd_list[i],buf,strlen(buf));
        }
    }
    return 0;
}
