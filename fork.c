#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    int ret = fork();
    if(ret>0){
        printf("I am father!");
        printf("hello porc:%d!,ret :%d\n",getpid(),ret);
    }else if(ret == 0){
        printf("I am child!");
        printf("hello porc:%d!,ret :%d\n",getpid(),ret);
    }else{
        perror("fork");
        return 1;
    }
    sleep(1);
    return 0;
}
