//题目：机器人的运动范围

#include "moving.h"
//运动函数
int GetDigitSum(int number){
    int sum = 0;
    while(number>0){
        sum += number%10;
        number /= 10;
    }
    return sum;
}
int check(int threshold,int rows,int cols,int row,int col,int * visited){
    if(row>=0 && row<rows && col>=0 && col<cols && GetDigitSum(row)+GetDigitSum(col)<= threshold && (visited[row*cols+col] == 0)){
        return 1;
    }
    return 0;
}
int movingCountCore(int threshold,int rows,int cols,int row,int col,int* visited){
    int count = 0;
    if(check(threshold,rows,cols,row,col,visited)){
        visited[row*cols+col] = 1;
        count = 1+ movingCountCore(threshold,rows,cols,row-1,col,visited)\
                +movingCountCore(threshold,rows,cols,row,col-1,visited)\
                +movingCountCore(threshold,rows,cols,row+1,col,visited)\
                +movingCountCore(threshold,rows,cols,row,col+1,visited);
    }
    return count;
}
int movingCount(int threshold,int rows,int cols){
    if(threshold<0||rows<=0||cols<=0){
        return 0;
    }
    int * visited = (int *)malloc(sizeof(int)*rows*cols);
    //for(int i = 0; i<cols*rows;++i){
    //    visited[i] = 0;//初始化
    //}
    memset(visited,0,rows*cols);
    int count = movingCountCore(threshold,rows,cols,0,0,visited);
    free(visited);
    return count;
}


//主函数
int main(){
    //全部都在范围内
    int count = movingCount(18,5,5);
    printf("count expect:25 actual:%d\n",count);
    //部分在范围内
    count = movingCount(9,9,9);
    printf("count expect:48 actual:%d\n",count);
    //全部不在范围内
    count = movingCount(18,0,0);
    printf("count expect:0 actual:%d\n",count);
    return 0;
}




