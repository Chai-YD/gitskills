#include<stdio.h>

#include"Hash_func.h"

uint64_t BKDRHash(const char *str){
    uint64_t hash = 0;
    uint64_t ch = 0;
    while(ch = (size_t)*str++){
        hash = hash *131 +ch;
    }
    return hash;
}

uint64_t SDBMHash(const char *str){
    uint64_t hash = 0;
    uint64_t ch = 0;
    while(ch = (size_t)*str++){
        hash = 65599 * hash + ch;
    }
    return hash;
}
