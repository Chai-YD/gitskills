//数组的大小为n+1，元素值为0～n
//查询这个数组是否有相同元素
//如果有，输出任意一个相同元素
//测试代码关键点：无相同元素，有相同元素，空指针
#include<stdio.h>
//约定：函数返回1，表示有相同元素；返回0，表示没有相同元素
//判断函数
int duplication(int data[],int size,int *value){
    if(data == NULL||size<=0){
        return 0;
    }
    int i = 0;
    for(;i<size;++i){
        if(data[i]<0||data[i]>=size){
            return 0;
        }
    }
    for(i = 0;i<size;++i){
        while(data[i] != i){
            int tmp = data[i];
            if(data[i] == data[tmp]){
                *value = data[i];
                return 1;
            }
            //swap data[i] and data[tmp]
            data[i] = data[tmp];
            data[tmp] = tmp;
        }
    }
    return 0;
}

int main(){
    //不存在
    int data[] = {1,3,2,0};
    int size = sizeof(data)/sizeof(data[0]);
    int value;
    int ret = duplication(data,size,&value);
    //存在
    int data1[] = {1,3,5,1,2,4};
    int size1 = sizeof(data1)/sizeof(data1[0]);
    int value1;
    int ret1 = duplication(data1,size1,&value1);
    //出现不规范值
    int data2[] = {1,3,6,1,2,4};
    int size2 = sizeof(data2)/sizeof(data2[0]);
    int value2;
    int ret2 = duplication(data2,size2,&value2);
    printf("ret except:0 actual:%d\n",ret);
    printf("ret1 except :1 actual:%d\n",ret1);
    printf("value except: 1  actual: %d\n",value1);
    printf("ret2 except :0 actual:%d\n",ret2);
    return 0;
}
