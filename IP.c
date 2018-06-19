//**************************************
//gethostbyname函数的使用
//**************************************
//#include<stdio.h>
//#include<string.h>
//#include<netdb.h>
//#include<sys/socket.h>
//#include<netinet/in.h>
//#include<arpa/inet.h>
//#include<errno.h>

//主函数
//int main(){
//    struct hostent* host;
//    char hostname[] = "www.baidu.com";
//    struct sockaddr_in local;
//    struct in_addr in;
//    extern int errno;
//    if((host = gethostbyname(hostname) )!= NULL){
//        memcpy(&local.sin_addr.s_addr,host->h_addr,4);
//        in.s_addr = local.sin_addr.s_addr;
//        printf("Domain name:%s\n",hostname);
//        printf("IP length:%d\n",host->h_length);
//        printf("Type:%d\n",host->h_addrtype);
//        printf("IP: %s\n",inet_ntoa(in));
//    }else{
//        printf("errno:%d\n",errno);
//        printf("ERR:%s\n",strerror(errno));
//    }
//    return 0;
//}

//**************************************
//gethostbyaddr函数的使用
//**************************************

#include<stdio.h>
#include<sys/socket.h>
#include<errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<netdb.h>

//主函数
int main(){
    struct hostent *host;
    char addr[] = "228.28.152.201";
    struct sockaddr_in local;
    struct in_addr in;
    extern int errno;
    if((host = gethostbyaddr(addr,sizeof(addr),AF_INET)) != (struct hostent*)NULL){
        memcpy(&local.sin_addr.s_addr,host->h_addr,4);
        in.s_addr = local.sin_addr.s_addr;
        printf("Domain name:%s\n",host->h_name);
        printf("IP length:%d\n",host->h_length);
        printf("type :%d\n",host->h_addrtype);
        printf("IP:%s\n",inet_ntoa(in));
        printf("IP:%s\n",addr);
    }else{
        printf("errno:%d\n",errno);
        printf("ERR:%s\n",strerror(errno));
    }
    return 0;
}












