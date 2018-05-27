//*********************************
//开放地址发解决哈希冲突
//*********************************
#include "Hash.h"                     

size_t HashFuncDefault(KeyType key){
    return key%HashMaxSize;
}

void HashInit(HashTable* ht, HashFunc hash_func){
    if(ht == NULL){
        //非法输入
        return;
    }  
    ht->size = 0;
    ht->func = hash_func;
    int i =0;
    for(;i<HashMaxSize;++i){
        ht->data[i].stat = Empty;        
    }
    return;
} 

void HashDestroy(HashTable* ht){
    if(ht == NULL){
        //非法输入
        return;
    }
    ht->size = 0;
    ht->func = NULL;
    return;
} 
void HashInsert(HashTable* ht, KeyType key, ValType value){
    if(ht ==NULL||key<0){
        //非法输入
        return;
    }
    if(ht->size> 0.8*HashMaxSize){
        //哈希表已经达到上限
        return;
    }
    size_t offset = ht->func(key);
    while(1) {
        if(ht->data[offset].stat != Valid){
            ht->data[offset].key = key;
            ht->data[offset].value = value;
            ht->data[offset].stat = Valid;
            ++ht->size;
            return;
        }else if(ht->data[offset].stat == Valid&&ht->data[offset].key == key){
            //约定不能出现相同的key值
            return;
        }else{
            offset = (offset+1)%HashMaxSize;
        }
    }//while循环结束
} 
void Hashprintf(HashTable* ht,char* msg){
    printf("\n*****%s*********\n",msg);
    int i = 0;
    for(;i<HashMaxSize;i++){
        if(ht->data[i].stat == Valid){
            printf("【%d  %d:%d】 ",i,ht->data[i].key,ht->data[i].value);
        }
    }
    printf("\n");
    return;
}

// 输入key, 查找对应key的value. 
int HashFind(HashTable* ht, KeyType key, ValType* value){
    if(ht == NULL){
        //非法输入
        return 0;
    }
    if(ht->size == 0){
        //哈希表为空
        return 0;
    }
    size_t offset = ht->func(key);
    while(1){
        if(ht->data[offset].stat == Valid && ht->data[offset].key == key){
            *value = ht->data[offset].value;
            return 1;
        }else if(ht->data[offset].stat == Empty){
            return 0;
        }else{
            offset = (offset+1)%HashMaxSize;
        }
    }//while结束 
}

void HashRemove(HashTable* ht, KeyType key){
    if(ht == NULL){
        //非法输入
        return;
    } 
    KeyType offset = ht->func(key);
    while(1){
        if(ht->data[offset].stat == Valid && ht->data[offset].key == key){
            ht->data[offset].stat = Deleted;
            --ht->size;
            return;
        }else if(ht->data[offset].stat == Empty){
            return;
        }else{
            offset = (offset+1)%HashMaxSize;
        }
    }
}
//返回1 表示非空；返回0表示空
int HashEmpty(HashTable* ht){
    if(ht ==NULL){
        //非法输入
        return 0;
    }
    int i =0 ;
    for(;i<HashMaxSize;++i){
        if(ht->data[i].stat == Valid){
            return 1;
        }
    }
    return 0;
}

size_t HashSize(HashTable* ht){
    if(ht == NULL){
        //非法输入
        return 0;
    }
    if(ht->size == 0){
        //空
        return 0;
    }
    return ht->size;
}
//测试函数
void TextHashSize(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    int ret = HashSize(&ht);
    printf("ret expected:0 actual :%d\n",ret);
    return;
}
void TestHashEmpty(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    int ret = HashEmpty(&ht);
    printf("ret expected:0 actual:%d\n",ret);
    return;
}
void TestInit(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    printf("size expected:0  actual:%d\n",ht.size);
    printf("sunc expected:%p actual:%p\n",HashFuncDefault,ht.func);
}

void TestDestroy(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    HashDestroy(&ht);
    printf("size expected:0  actual:%d\n",ht.size);
}
void TestHashInsert(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    HashInsert(&ht,1002,5);
    printf("size expected:1 actual:%d\n",ht.size);
    printf("value expected:5 actual:%d\n",ht.data[2].value);
    HashInsert(&ht,2002,5);
    printf("size expected:2 actual:%d\n",ht.size);
    printf("value expected:5 actual:%d\n",ht.data[3].value);
    HashInsert(&ht,2002,5);
    printf("size expected:2 actual:%d\n",ht.size);
    Hashprintf(&ht,"插入");
    return;
}
void testHashFind(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    HashInsert(&ht,1002,5);
    HashInsert(&ht,2002,5);
    ValType value;
    HashFind(&ht,2002,&value);
    printf("value expected:5 actual:%d\n",value);
    return;
}
void TestHashRemove(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    HashInsert(&ht,1002,5);
    HashInsert(&ht,2002,5);
    Hashprintf(&ht,"插入俩个");
    HashRemove(&ht,1002);
    Hashprintf(&ht,"删除一个");
    return;
    ;
}
//主函数
int main(){
    TestInit();
    TestDestroy();
    TestHashInsert();
    testHashFind();
    TestHashRemove();
    TestHashEmpty();
    TextHashSize();
    return 0;
}
