//二维数组中的查找

//题目：
//在一个二维数组中，每一行都按照从左到右递增的顺序，每一列都按照
//从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组
//和一个整数，判断数组中是否含有该整数。

//测试用例：
//1.二维数组中包含查找的元素(查找的元素是数组的最大值、最小值和介
//于元素的最大值与最小值之间)
//2.二维数组不包含查找的元素（查找的元素大于数组的最大值、小于数
//组的最小值和介于最大值和最小值中间但不再数组中）
//注：matrix 矩阵
#include<stdio.h>

//查找函数
//约定：查找成功返回1；查找失败返回0
int Find(int* matrix,int rows,int cols,int num){
    if(matrix!=NULL&&rows>0&&cols>0){
        int row = 0;
        int col = cols -1;
        while(col>=0 && row<rows){
            if(matrix[row*cols+col] <num){
                --col;
            }else if(matrix[row*cols+col] > num){
                ++row;
            }else{
                return 1;
            }
        }
    }
    return 0;
}

//主函数
int main(){
    int matrix[4][4] = {
        {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15}
    };
    printf("\n***********查询成功*************************\n");
    int ret = Find(&matrix[0][0],4,4,15);//最大值
    printf("ret except:1  actual:%d\n",ret);
    ret = Find(&matrix[0][0],4,4,1);//最小值
    printf("ret except:1  actual:%d\n",ret);
    ret = Find(&matrix[0][0],4,4,7);//介于最大值与最小值之间，存在
    printf("ret except:1  actual:%d\n",ret);
    printf("\n***********查询失败*************************\n");
    ret = Find(&matrix[0][0],4,4,16);//大于最大值
    printf("ret except:0  actual:%d\n",ret);
    ret = Find(&matrix[0][0],4,4,0);//小于最小值
    printf("ret except:0  actual:%d\n",ret);
    ret = Find(&matrix[0][0],4,4,5);//介于最大值与最小值之间，不存在
    printf("ret except:0  actual:%d\n",ret);
    return 0;
}
