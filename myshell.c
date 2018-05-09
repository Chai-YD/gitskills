#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

int argc  = 0;
char* argv[8] = {}; 

void do_parse(char* buf){ // 字符串解析
    argc = 0;
    int i = 0;
    int status = 0;
    for(; buf[i]!=0; i++){
        if(!isspace(buf[i])&&status == 0){ //如果是字符并且是从空格到字符
            argv[argc++] = buf + i;
            status = 1;
        }else if(isspace(buf[i])){ // 如果是字符到空格
            buf[i] = 0;
            status = 0;
        }   
    }   
}
void do_shell(){
    pid_t pid = fork(); // 创建子进程
    if(pid == -1){
        perror("fork");
        return;
    }
    else if(pid > 0)
       wait(NULL);  // 父进程等待子进程结束
    else{ // 子进程进行进程替换
        if(execvp(argv[0],argv) == -1)
            perror("execvp"),exit(1);
    }
}

int main(){
    char buf[1024] = {};
    while(1){
        memset(buf, 0x00, sizeof(buf));
        printf("shell >");
        scanf("%[^\n]", buf);  // 命令行读取
        scanf("%*c");
        if(strcmp(buf, "exit") == 0)
            break;
        do_parse(buf);
        do_shell();
    }
}
