//题目：不修改数组找到重复的数字
//在一个长度为n+1的数组里的所有数字都有1～n的范围内，所有数组中至少有一个
//是重复的，请找出数组中任意一个重复的数字，但不能修改输入的数组。如果输入
//长度为8的数组{2,3,5,4,3,2,6,7}，那么对应的输出是重复数字2或者3.

//测试用例：
//1.长度为n的数组内包含一个或多个重复的数字
//2.数组内不包含重复的数字
//3.无效输入（存在数字不再范围内）


#include<stdio.h>

//调用函数
int duplicationEX(int data[],int size,int *value){
    //1.对数组和输出形参数进行检测
    if(data == NULL ||size  <= 0){
        return 0; 
    }
    //2.对数组元素进行检测
    int i = 0;
    for(;i<size;++i){
        if(data[i] <0 ||data[i] >=size){
            return 0;
        }
    }
    //3.进行重复元素的查找
    //约定：返回值为1表示找到了，返回值为0表示没找到
    int left = 1;
    int right = size-1;
    int mid;
    int count;
    while(right >= left){
        mid = left + ((right-left)>>1);
        count = 0;
        for(i = 0; i < size;++i){
            if(data[i]>=left && data[i]<=mid){
                ++count;
            }
        }
        if(count > mid-left+1){
            if(mid == left){
                *value = left;
                return 1;
            }
            right = mid;
        }else{
            if(mid == right){
                *value = right;
                return 1;
            }
            left = mid + 1;
        }
    }
    return 0;
}


//主函数
int main(){
    //1.构造数组、求数组长度、输出形参数（将数组中任意的重复数组带出）
    int data[] = {2,3,5,4,3,2,6,7};
    int size = sizeof(data)/sizeof(data[0]);
    int value;
    //2.调用函数
    int ret = duplicationEX(data,size,&value);
    //3.进行函数输出值的检测
    if(ret == 1){
        printf("找到了，value :%d\n",value);
    }else{
        printf("未找到，ret except:0 ,actual:%d\n",ret);
    }
    //1.构造数组、求数组长度、输出形参数（将数组中任意的重复数组带出）
    int data1[] = {2,3,7};
    int size1 = sizeof(data1)/sizeof(data1[0]);
    int value1;
    //2.调用函数
    int ret1 = duplicationEX(data1,size1,&value1);
    //3.进行函数输出值的检测
    if(ret1 == 1){
        printf("找到了，value1 :%d\n",value1);
    }else{
        printf("未找到，ret1 except:0 ,actual:%d\n",ret1);
    }
    //4.return
    return 0;
}
