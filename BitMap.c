//位图，，减少空间的消耗，便于处理大量数据
#include "BitMap.h"

//函数实现
void BitMapInit(BitMap* bm, uint64_t capacity){
    //1.判断非法输入
    if(bm == NULL){
        //非法输入
        return;
    }
    //2.初始化结构体变量
    bm->capacity = capacity;
    uint64_t size = capacity/(8*sizeof(uint64_t))+ 1;
    //为结构体中的指针变量开辟空间
    bm->data = (uint64_t*)malloc(size*sizeof(uint64_t));
    //初始化
    memset(bm->data,0,size);
    return;
}

void BitMapDestroy(BitMap* bm){
    //1.判断非法输入
    if(bm == NULL){
        //非法输入
        return;
    }
    //2.释放动态开辟空间
    bm->capacity = 0;
    free(bm->data);
    bm->data = NULL;
    return;
}
void GetBitHashOff(BitMap* bm,uint64_t* n,uint64_t* offset){
    //判断非法输入
    if(bm == NULL){
        return;
    }
    //判断下标
    *n = bm->capacity/(8*sizeof(uint64_t));
    //判断偏移量
    *offset = bm->capacity%(8*sizeof(uint64_t));
    return;
}
// 把第 index 位置为1 
void BitMapSet1(BitMap* bm, uint64_t index){
    if(bm == NULL || index>= BitMapMax){
        //非法输入
        return;
    }
    //获取index的下标与偏移量
    uint64_t n;//下标
    uint64_t offset;//偏移量
    GetBitHashOff(bm,&n,&offset);
    //要想将每一位置为1，应进行按位或运算
    bm->data[n] = bm->data[n] | (0x1ul<<offset);
    return;
}
// 把第 index 位置为0 
void BitMapSet0(BitMap* bm, uint64_t index){
    if(bm == NULL || index>= BitMapMax){
        //非法输入
        return;
    }
    //获取index的下标与偏移量
    uint64_t n;//下标
    uint64_t offset;//偏移量
    GetBitHashOff(bm,&n,&offset);
    //要想将每一位置为0，应进行按位与运算
    bm->data[n] = bm->data[n] & ~(0x1ul<<offset);
    return;
}
//BitMap 元素查找
void BitMapPrint(BitMap* bm,int value,char* msg){
    printf("\n******%s*******\n",msg);
    int i = 0;
    int size = bm->capacity/(8*sizeof(uint64_t))+1;
    for(;i<size;++i){
        int j = 0;
        for(;j<sizeof(uint64_t)*8;++j){
            if(bm->data[i]&(0x1ul<<j) ==value){
                printf("[%d:%d:value] ",i,j);
            }
        }
    }
    printf("\n");
    return;
}
 // 测试 index 为是 1 , 还是 0. 如果是1, 就返回1. 否则返回0. 
int BitMapTest(BitMap* bm, uint64_t index){
    if(bm == NULL || index >=BitMapMax){
        //非法输入
        return 0;
    }
    uint64_t n;
    uint64_t offset;
    GetBitHashOff(bm,&n,&offset);
    int ret = bm->data[n]&(0x1ul<<offset);
    if(ret == 0){
        return 0;
    }else{
        return 1;
    }
}
 // 把整个位图所有的位都设为1. 
void BitMapFill(BitMap* bm){
    if(bm == NULL){
        //非法输入
        return;
    }
    uint64_t size = bm->capacity/(8*sizeof(uint64_t))+1;
    memset(bm->data,0xff,size*sizeof(uint64_t));
    return;
} 
 // 把整个位图所有的位都设为0. 
void BitMapClear(BitMap* bm){
    if(bm == NULL){
        //非法输入
        return;
    }
    uint64_t size = bm->capacity/(8*sizeof(uint64_t))+1;
    memset(bm->data,0x0,size*sizeof(uint64_t));
    return;
} 
//检测函数
void TestBitMapClear(){
    BitMap bm;
    BitMapInit(&bm,BitMapMax);
    BitMapClear(&bm);
    BitMapPrint(&bm,1,"Clear");
    BitMapDestroy(&bm);
    return;
}
void TestBitMapFill(){
    BitMap bm;
    BitMapInit(&bm,BitMapMax);
    BitMapFill(&bm);
    BitMapPrint(&bm,0,"Fill");
    BitMapDestroy(&bm);
    return;
}
void TextBitMapTest(){
    BitMap bm;
    BitMapInit(&bm,BitMapMax);
    BitMapSet1(&bm,8);
    int ret = BitMapTest(&bm,8);
    printf("ret except:1 actual:%d\n",ret);
    BitMapSet0(&bm,8);
    ret = BitMapTest(&bm,8);
    printf("ret except:0 actual:%d\n",ret);
    BitMapDestroy(&bm);
    return;
}
void testBitMapSet0(){
    BitMap bm;
    BitMapInit(&bm,BitMapMax);
    BitMapSet0(&bm,8);
    int ret = BitMapTest(&bm,8);
    printf("ret except:0 actual:%d\n",ret);
    BitMapDestroy(&bm);
    return;
}
void testBitMapSet1(){
    BitMap bm;
    BitMapInit(&bm,BitMapMax);
    BitMapSet1(&bm,8);
    int ret = BitMapTest(&bm,8);
    printf("ret except:1 actual:%d\n",ret);
    BitMapDestroy(&bm);
    return;
}
void TestBitMapInit(){
    BitMap bm;
    BitMapInit(&bm,BitMapMax);
    printf("bm.capacity except:1000 actual:%d\n",bm.capacity);
    BitMapDestroy(&bm);
    return;
}
void TestBitMapDestroy(){
    BitMap bm;
    BitMapInit(&bm,BitMapMax);
    BitMapDestroy(&bm);
    printf("bm.capacity except:0 actual:%d\n",bm.capacity);
    return;
}

//主函数
int main(){
    TestBitMapInit();
    TestBitMapDestroy();
    testBitMapSet1();
    testBitMapSet0();
    TextBitMapTest();
    TestBitMapFill();
    TestBitMapClear();
    return 0;
}
