//头文件
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MAX 1024
//函数实现
void usage(const char* proc){
    printf("[%s][port]\n",proc);
    return;
}

int startup(int port){
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock<0){
        perror("socket");
        exit(2);
    }
    //日志库，，此处不进行编写
    //防止服务器挂掉，重新启动是的时间等待
    int opt=1;
    setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = htonl(INADDR_ANY);
    local.sin_port = htons(port);
    if(bind(sock,(struct sockaddr *)&local,sizeof(local))<0){
        perror("bind");
        exit(3);
    }
    if(listen(sock,5)<0){
        perror("listen");
        exit(4);
    }
    return sock;
}

//get_line函数的实现（按行读取函数的实现）
void get_line(int sock,char line[],int size){
    //行分割符（\n,\r,\r\n）都应该考虑在内,均视为\n处理
    int c = 'a';
    ssize_t s = 0;
    int i = 0;
    while(i<size-1&&c!='\n'){
        s = recv(sock,&c,1,0);
        if(s > 0){
            if(c=='\r'){
                if(recv(sock,&c,1,MSG_PEEK)>0){
                    if(c != '\n'){
                        //下一个字符不为\n
                        c = '\n';
                    }else{
                        //下一个字符为\n
                        recv(sock,&c,1,0);
                    }
                }
            }
            line[i++] = c;
        }else{
            return;
            break;
        }
    }
    line[i] = '\0';
    return;
}
//hander_request函数的实现
void* hander_request(void* arg){
    int sock = (int)arg;
    char line[MAX];
    do{
        get_line(sock,line,sizeof(line));//按行读取
        printf("%s",line);//将读取行打印出来
    }while(strcmp(line,"\n")!=0);
    close(sock);
}

//主函数
int main(int argc,char* argv[]){
    if(argc !=2){
        usage(argv[0]);
        return 1;
    }
    int listen_sock = startup(atoi(argv[1]));//函数待实现
    //进入循环体
    for(;;){
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        int new_sock = accept(listen_sock,(struct sockaddr*)&client,&len);
        printf("循环\n");
        if(new_sock<0){
            perror("accept");
            continue;
        }
        printf("success accept!\n");
        pthread_t id;
        pthread_create(&id,NULL,hander_request,(void*)new_sock);//hander_request函数带解决
        //将线程分离，，防止进程进行等待，导致服务器出错
        pthread_detach(id);
    }
}








