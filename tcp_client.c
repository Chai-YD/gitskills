#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>


//主函数
int main(int argc,char* argv[]){
	if(argc != 3){
		printf("usage:%s [ip] [port]\n",argv[0]);
	}
	//创建套接字
	int sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0){
		printf("socket error!\n");
		return 1;
	}
	//创建struct sockaddr_in 结构体
	struct sockaddr_in client_socket;
	client_socket.sin_family = AF_INET;
	client_socket.sin_port = htons(atoi(argv[2]));
	client_socket.sin_addr.s_addr = inet_addr(argv[1]);
	//链接
	int ret = connect(sock,(struct sockaddr*)&client_socket,sizeof(client_socket));
	if(ret <0){
		printf("connet error!\n");
		return 2;
	}
	printf("connect success!\n");
	char buf[1024];
	buf[0] = 0;
	while(1){
		printf("client:#");
		fflush(stdout);
		ssize_t s = read(0,buf,sizeof(buf)-1);
		if(s>0){
			buf[s-1] = 0;
		}
		write(sock,buf,sizeof(buf));
		if(strncmp(buf,"quit",4)==0){
			printf("quit!\n");
			break;
		}
		printf("please wait!\n");
		read(sock,buf,sizeof(buf));
		printf("server:$%s\n",buf);
	}
	close(sock);
	return 0;
}
