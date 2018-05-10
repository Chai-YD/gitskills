#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>


void ProcessRequest(int client_sock,struct sockaddr_in* client_socket){
		char buf_ip[24];
		//初始化
		buf_ip[0] = 0;
		while(1){
			char buf[1024];
			buf[0] =0;
			ssize_t s = read(client_sock,buf,sizeof(buf)-1);          
			if(s>0){
				buf[s] = 0;
				printf("[%s:%d]say#%s\n",buf_ip,client_socket->sin_port,buf);
				buf[0] = 0;
				printf("server:#%s\n",buf);
				fflush(stdout);
				s = read(0,buf,sizeof(buf)-1);
				if(s>0){
					buf[s] = 0;
				}
				if(strncmp(buf,"quit",4)==0){
					printf("quit!\n");
					break;
				}
				write(client_sock,buf,sizeof(buf));
				printf("please wait!\n");
			}
			else if(s==0){
				printf("client[%s:%d]quit\n",buf_ip,client_socket->sin_port);
				break;
			}else{
				continue;
			}
		}
	}
void CreateWorker(int client_sock,struct sockaddr_in* client_socket){
	pid_t pid;
	pid = fork();
	if(fork()<0){
		perror("fork");
		return;
	}else if(pid== 0){
		if(fork()==0){
			ProcessRequest(client_sock,client_socket);
		}
	}else{
		close(client_sock);
		waitpid(pid,NULL,0);
	}
}
//主函数
int main(int argc,char* argv[]){
	if(argc != 3){
		printf("usage:%s [ip] [port]\n",argv[0]);
	}
	//创建套接字
	int sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0){
		printf("socket error!errno is %d,errstring is %s\n",errno,strerror(errno));
		exit(1);
	}
	//创建struct sockaddr结构体
	struct sockaddr_in server_socket;
	struct sockaddr_in client_socket;
	//清空结构体server_socket,并进行赋值
	//bzero(&server_socket,sizeof(server_socket));
	server_socket.sin_family = AF_INET;
	server_socket.sin_port = htons(atoi(argv[2]));
	server_socket.sin_addr.s_addr = inet_addr(argv[1]);//注意此处的inet_addr的使用
	if(bind(sock,(struct sockaddr*)&server_socket,sizeof(server_socket))<0){
		printf("bind error!errno is %d,errstring is %s\n",errno,strerror(errno));
		close(sock);
		return 2;
	}
	//监视
	if(listen(sock,5)<0){
		printf("listen error! errno is %d,errstring is %s\n",errno,strerror(errno));
		return 3;
	}
	printf("bind and listen success,wait accept!\n");
	for(;;){
		//链接
		int len = sizeof(client_socket);
		int client_sock = accept(sock,(struct sockaddr*)&client_socket,&len);//此处的len位输入输出参数
		if(client_sock<0){
			printf("accept error!");
			continue;
		}
		char buf_ip[24];
		inet_ntop(AF_INET,&client_socket.sin_addr,buf_ip,sizeof(buf_ip));
		printf("get connect!ip is %s,port is %d!\n",buf_ip,ntohs(client_socket.sin_port));
		CreateWorker(client_sock,&client_socket);
	}
	return 0;
}

