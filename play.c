#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int first = 1;

typedef struct node_ node_t;
struct node_{
    char *name;
    node_t *prev;
    node_t *next;
};
node_t *head = NULL;
node_t *cur = NULL;//当前歌曲
enum{STOP,PAUSE,PLAY};
int status = STOP;
void list_init(){
    head = malloc(sizeof(node_t));
    memset(head,0x00,sizeof(node_t));
    head->next = head->prev =head;
}
void list_inseart(const char *name){
    node_t *p = malloc(sizeof(node_t));
    memset(p,0x00,sizeof(node_t));

    p->name = malloc(strlen(name)+1);
    strcpy(p->name,name);

    p->next = head->next;
    p->prev = head;
    head->next->prev = p;
    head->next = p;
}
void load_music(const char *path){
    DIR *pdir = opendir(path);
    if(pdir == NULL){
        perror("opendir");
        exit(1);
    }
    struct dirent *p = NULL;
    while((p = readdir(pdir)) != NULL){
        if(p->d_name[0] == '.')
            continue;
        list_inseart(p->d_name);
        //printf("%s\n",p->d_name);
    }
    closedir(pdir);
}
void list_show(){
    node_t *p = head->next;

    while(p != head){
        printf("%s ",p->name);
        if(p == cur){
            printf(" <==cur");
        }
        printf("\n");
        p = p->next;
    }
}



int menu(){
    printf("*****************************\n");
    printf("1.play/pause\n");
    printf("2.next\n");
    printf("3.prev\n");
    printf("4.stop\n");
    printf("0.exit\n");
    printf("\n*****************************\n");
    list_show();

    int choose = 4;
    do{
        printf(">");
        scanf("%d",&choose);
        if(choose>=0&&choose<=4)   //雷1
            break;
        printf("choose invalid\n");
        while(getchar() != '\n');
    }while(1);
    return choose;
}

void playPause(){
    if(first == 1){
        char buf[1024] ={};
        sprintf(buf, "madplay -o wav:- /home/chaiyandong/Desktop/mp3lib/my_music/%s 2> /dev/null | aplay &",cur->name);
        system(buf);
        first = 0;
        status = PLAY;
    }else{
        if(status == PLAY){
            system("killall -SIGSTOP aplay");
            status = PAUSE;
        }else if(status == PAUSE){
            system("killall -SIGCONT aplay");
            status = PLAY;
        }
    }
}
void stop(){
    system("killall -SIGSTOP aplay");
    first = 1;
}
void next(){
    stop();
    cur = cur->next;
    if(cur == head){
        cur = cur->next;
    }
    playPause();
}
void prev(){
    stop();
    cur = cur->prev;
    if(cur == head){
        cur = cur->prev;
    }
    playPause();
}
int main( int argc,char *argv[] ){
    list_init();
    load_music("/home/chaiyandong/Desktop/mp3lib/my_music");
    if(head->next != head){
        cur = head->next;
    }
    do{
        int choose = menu();
        switch(choose){
            case 1:
                playPause();  //雷2
                break;
            case 2:
                next();
                break;
            case 3:
                prev();
                break;
            case 4:
                stop();
                break;
            case 0:
                printf("谢谢欣赏！\n");
                system("killall -SIGKILL aplay");
                exit(0);
            default:
                //do nothing
                break;
        }
    }while(1);
   //list_show();
    return 0;
}
