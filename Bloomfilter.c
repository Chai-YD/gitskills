#include "Bloomfilter.h"
#include<stdlib.h> 
#include"Hash_func.h"
#define HashFuncMax 10000
void BloomFilterInit(BloomFilter* bf){
    if(bf == NULL){
        return;
    }
    BitMapInit(&bf->bm,HashFuncMax);
    bf->hash_func[0] = SDBMHash;
    bf->hash_func[1] = BKDRHash;
    return;
} 

void BloomFilterDestroy(BloomFilter* bf){
    if(bf == NULL){
        return;
    }
    bf->hash_func[0] = NULL;
    bf->hash_func[1] = NULL;
    BitMapDestroy(&bf->bm);
    return;
} 
void BloomFilterInsert(BloomFilter* bf, const char* str){
    if(bf == NULL||str == NULL){
        //非法输入
        return;
    }
    size_t i =0;
    for(;i<HashFuncMaxSize;++i){
        uint64_t hash = bf->hash_func[i](str)%HashFuncMax;

    BitMapSet1(&bf->bm,hash);
    }
    return;
} 
int BloomFilterIsExist(BloomFilter* bf, const char* str){
    if(bf == NULL){
        return 0;
    }
    size_t i = 0;
    for(;i<HashFuncMaxSize;++i){
        uint64_t hash = bf->hash_func[i](str)%HashFuncMax;
        int ret = BitMapTest(&bf->bm,hash);
        if(ret == 0){
            return 0;
        }
    }
    return 1;
} 


void TestBloom(){
    BloomFilter bf;
    BloomFilterInit(&bf);
    BloomFilterInsert(&bf,"hehe");
    BloomFilterInsert(&bf,"haha");
    int ret = BloomFilterIsExist(&bf,"hehe");
    printf("ret excepted:1 actual:%d\n",ret);
    return;
}
int main(){
    TestBloom();
    return 0;
}








