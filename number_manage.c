#include"number_manage.h"

int menu(){
    int j=0;
    while(1){
        printf("\n*************************************************\n");
        printf("\n********  1:add a number                *********\n");
        printf("\n********  2:all the number              *********\n");
        printf("\n********  3:select a number by name     *********\n");
        printf("\n********  4:delete a number by name     *********\n");
        printf("\n********  5:save to file                *********\n");
        printf("\n********  6:load number from file       *********\n");
        printf("\n********  0:exit                        *********\n");
        printf("\n*************************************************\n");
        printf("please select a menu:\n");
        scanf("%d",&j);
        if(j==0){
            printf("byebye\n");
            exit(1);
        }
        if(j<0||j>6){
            printf("error ,continue\n");
            continue;
        }else{
            return j;
        }
    }
}

void shownum(struct telnum t){
    printf("Name : %s\n",t.name);
    printf("tel : %s\n",t.tel);
}
 
struct telnum addnum(){
    struct telnum numtmp;
    char na[11],tel[13];
    printf("add a telephone number:\n");
    printf("please input the name:\n");
    scanf("%s",na);
    printf("please input the num:\n");
    scanf("%s",tel);
    strcpy(numtmp.name,na);
    strcpy(numtmp.tel,tel);
    return numtmp;
}

void selectbyname(){
    char na[20];
    int n,j;
    n=0;
    printf("select number by name:\n");
    printf("please input a name:\n");
    scanf("%s",na);
    for(j=0;j<i;++j){
        if(strcmp(num[j].name,na) == 0){
            shownum(num[j]);
            n++;
        }
    }
    if(n == 0){
        printf("no such a name\n");
    }
}


void delenum(){
    char na[20];
    int j,n;
    n=0;
    printf("delete a num by name:\n");
    printf("please input a name:\n");
    scanf("%s",na);
    for(j=0;j<i;++j){
        if(strcmp(num[j].name,na) == 0){
            n++;
            for(;j<i;j++){
                num[j] = num[j+1];
            }
            --i;
            break;
        }
    }
    if(n == 0){
        printf("no such a name\n");
    }
}

void loadfromfile(){
    int j = 0,fd ,t;
    char na[11];
    char tel[13];
    i = 0;
    char file[] = "/home/chaiyandong/BAT/LINUX/基础IO/N_M/tel.txt";
    extern int errno;
    fd = open(file,O_RDONLY);
    if(fd != -1){
        printf("opened file %s\n",file);
    }else{
        printf("cann't open file %s\n",file);
        printf("errno:%d\n",errno);
        printf("ERR:%s\n",strerror(errno));
    }
    while(read(fd,&num[i],sizeof(struct telnum))>0){
        ++i;
    }
    close(fd);
}

void savetofile(){
    int j ,fd;
    char path[] = "/home/chaiyandong/BAT/LINUX/基础IO/N_M/tel.txt";
    extern int errno;
    //O_TRUNC:如果文件已经存在，则将文件的长度截为0
    fd = open(path,O_WRONLY|O_TRUNC|O_CREAT);
    if(fd != -1){
        printf("opened file %s\n",path);
    }else{
        printf("cann't open file %s\n",path);
        printf("errno:%d\n",errno);
        printf("ERR:%s\n",strerror(errno));
    }
    for(j = 0; j<i;++j){
        printf("%d %s\n",j,num[j].name);
        write(fd,&num[j],sizeof(struct telnum));
    }
    printf("saved\n");
    close(fd);
}



//主函数
int main(){
    //printf("hha");
    //menu();
    int s,j;
    printf("*******TelePhone Notebook***********\n");
    while(1){
        s = menu();
        if(s == 1){
            num[i] = addnum();
            ++i;
        }
        if(s == 2){
            for(j=0;j<i;++j){
                shownum(num[j]);
            }
        }
        if(s == 3){
            selectbyname();
        }
        if(s == 4){
            delenum();
        }
        if(s == 5){
            savetofile();
        }
        if(s == 6){
            loadfromfile();
        }
    }
    return 0;
}
