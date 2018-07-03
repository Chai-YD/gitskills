#include<stdio.h>
#include<unistd.h>
#include"./keyboard/keyboard.h"
#include<signal.h>
#include<stdlib.h>
#include<sys/time.h>


#define FC 5     //前景颜色
//0黑
#define BC 7   //背景颜色
#define W 10   //地图的宽度
#define H 20   //地图的高度

struct data{
    int x; //列
    int y; //行
};
struct data t = {5,0};//图形的位置

/*数组表示（0；1）
 0 0 0 0 0
 0 0 0 0 0
 0 0 0 0 0
 0 0 0 0 0
 0 0 0 0 0
*/


#if 0
   []       //旋转此处不进行编辑
 [][][]     


   []
   []
   [][]


   []
   []
 [][]


 [][]
   [][]


   [][]
 [][]


 [][]
 [][]

   []
   []
   []
   []

#endif

//int background[H][W];

struct shape{
    int s[5][5];
};
struct shape shape_arr[7] = {
    //方块图案
    {
        0,0,0,0,0,
        0,0,1,0,0,
        0,1,1,1,0,
        0,0,0,0,0,
        0,0,0,0,0
    },
    {
        0,0,0,0,0,
        0,1,0,0,0,
        0,1,1,1,0,
        0,0,0,0,0,
        0,0,0,0,0
    },
    {
        0,0,0,0,0,
        0,0,1,0,0,
        0,0,1,1,0,
        0,0,0,1,0,
        0,0,0,0,0
    },
    {
        0,0,0,0,0,
        0,0,1,0,0,
        0,1,1,0,0,
        0,1,0,0,0,
        0,0,0,0,0
    },
    {
        0,0,0,0,0,
        0,1,1,0,0,
        0,1,1,0,0,
        0,0,0,0,0,
        0,0,0,0,0
    },
    {
        0,0,0,0,0,
        0,0,1,0,0,
        0,0,1,0,0,
        0,0,1,0,0,
        0,0,0,0,0
    },
    {
        0,0,0,0,0,
        0,0,0,0,0,
        0,1,1,1,0,
        0,1,0,0,0,
        0,0,0,0,0
    }
};

void drow_element(int x,int y,int c){
    //控制位置
    //系统从（0.0）开始，用户从（1.1）开始
    x *=2;           //x坐标占用两个字符
    x++;
    y++;
    printf("\033[?25l");                     //隐蔽光标
    printf("\033[%d;%dH",y,x);               //设置光标位置
    //设置图形颜色
    printf("\033[3%dm\033[4%dm",c,c);        //设置颜色
    //设置图形
    printf("[]");
    fflush(stdout);                         //刷新
    printf("\033[0m");                      //关闭
}

void drow_shape(int x,int y,struct shape p,int c){
    int i;
    for(i=0;i<5;i++){
        int j;
        for(j=0;j<5;j++){
            if(p.s[i][j] != 0){
                //绘制图形
                drow_element(x+j,y+i,c);
            }
        }
    }
}

void drow_back(){
    int i;
    for(i = 0;i<H;i++){
        int j;
        for(j = 0;j<W;j++){
            drow_element(j,i,BC);
        }
    }
}

int can_move(int x,int y,struct shape p){
    int i;
    for(i = 0 ;i<5;i++){
        int j;
        for(j= 0;j<5;j++){
            if(p.s[i][j]==0){
                continue;
            }
            if(x+j>=W){
                return 0;
            }
            if(y+i>H){
                return 0;
            }
            if(x+j<=0){
                return 0;
            }
        }
    }
    return 1;
}

//下落
void tetris_timer(struct data* t){
    drow_shape(t->x,t->y,shape_arr[0],BC);
    if(can_move(t->x,t->y,shape_arr[0])){
        t->y++;
    }else{
        t->y = 0;
    }
    drow_shape(t->x,t->y,shape_arr[0],FC);
}

struct shape turn_90(struct shape p){
    struct shape t;
    int i;
    for(i = 0 ;i<5;i++){
        int j;
        for(j=0;j<5;j++){
            t.s[i][j] = p.s[4-j][i];
        }
    }
    return t;
}

int tetris(struct data* t){
    int ret = 0;
    int c = get_key();
    if(is_left(c)){
        drow_shape(t->x,t->y,shape_arr[0],BC);
        t->x--;
        drow_shape(t->x,t->y,shape_arr[0],FC);
    }else if(is_right(c)){
        drow_shape(t->x,t->y,shape_arr[0],BC);
        t->x++;
        drow_shape(t->x,t->y,shape_arr[0],FC);
    }else if(is_esc(c)){
        ret = 1;
    }else if(is_down(c)){
        drow_shape(t->x,t->y,shape_arr[0],BC);
        t->y++;
        drow_shape(t->x,t->y,shape_arr[0],FC);
    }else if(is_up(c)){
        drow_shape(t->x,t->y,shape_arr[0],BC);
        shape_arr[0] = turn_90(shape_arr[0]);
        drow_shape(t->x,t->y,shape_arr[0],FC);
    }
    return ret;
}

void handler(int s){
    tetris_timer(&t);
}

int main(){
    init_keyboard();
    int i;
    drow_back();
    struct sigaction act;
    act.sa_handler = handler;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGALRM,&act,NULL);
    //设置闹钟时间
    struct itimerval it;
    //初始化结构体
    it.it_value.tv_sec = 0;
    it.it_value.tv_usec = 1;
    it.it_interval.tv_sec = 1;
    it.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL,&it,NULL);//设置闹钟
    while(1){
        //tetris_timer(&t);
        if(tetris(&t) == 1){
            break;
        }
        //sleep(1);
    }
    //测试函数
    //for(i = 0;i<10;i++){
    //    /*drow_element(10,i,FC);//垂直
    //    drow_element(i,10,FC);//平移
    //    sleep(1);
    //    drow_element(10,i,BC);*/
    //    drow_shape(5,i,shape_arr[0],FC);
    //    sleep(1);
    //    drow_shape(5,i,shape_arr[0],BC);
    //}
    printf("\033[?25h");
    recover_keyboard();
    return 0;
}
