#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[]){
     int i = 0;
     int ret = atoi(argv[1]);
     while(i<+argc){
         if(ret <atoi(argv[i]));{
             ret = atoi(argv[i]);
         }
         i++;
     }
     printf("ret =%d\n",ret);
     return ret;
}
