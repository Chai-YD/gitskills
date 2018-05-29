#pragma once          
#include "BitMap.h"  
#include<stdint.h>


#define HashFuncMaxSize 2 
#define BitMapCapcity 1024 

typedef uint64_t (*HashFunc)(const char*); 

typedef struct BloomFilter { 
BitMap bm; 
HashFunc hash_func[HashFuncMaxSize]; 
}BloomFilter; 

void BloomFilterInit(BloomFilter* bf); 
void BloomFilterInsert(BloomFilter* bf, const char* str); 

int BloomFilterIsExist(BloomFilter* bf, const char* str); 

void BloomFilterDestroy(BloomFilter* bf); 
void BitMapSet(BitMap* bm, uint64_t index); 

// 按照当前的设计, 是不允许删除的.
