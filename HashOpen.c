//*****************************
//拉链法解决哈希冲突
//*****************************
#include "HashOpen.h"
size_t HashFuncDefault(KeyType key){
    return key%HashMaxSize;
}
HashElem* CreateNode(KeyType key, ValType value){
    HashElem* NewNode = (HashElem*)malloc(sizeof(HashElem));
    NewNode->value = value;
    NewNode->key = key;
    NewNode->next = NULL;
    return NewNode;
}
void HashInit(HashTable* ht, HashFunc hash_func){
    if(ht == NULL){
        return;
    }
    ht->func = hash_func;
    ht->size = 0;
    int i = 0;
    for(;i<HashMaxSize;++i){
        ht->data[i] = NULL;
    }
    return;
}
void HashInsert(HashTable* ht, KeyType key, ValType value){
    if(ht ==NULL){
        //非法输入
        return;
    }
    if(ht->size > 0.8*HashMaxSize){
        //哈希表已“满”
        return;
    }
    int offset = ht->func(key);
    HashElem* new = CreateNode(key,value);
    while(1){
        if(ht->data[offset] ==NULL){
            ht->data[offset] = new;
            ++ht->size;
            return;
        }else{
            HashElem* cur = ht->data[offset];
            while(cur->next != NULL){
                if(cur->key == key){
                    free(new);
                    return;
                }
                cur = cur->next;
            }
            cur->next = new;
            ++ht->size;
            return;
        }
    }
    return;
} 
void HashPrint(HashTable* ht,char* msg){
    printf("\n*****%s********\n",msg);
    if(ht == NULL){
        return;
    }
    if(ht->size == 0){
        return;
    }
    int i =0;
    for(;i < HashMaxSize;++i){
        if(ht->data[i] != NULL){
            HashElem* cur = ht->data[i];
            for(;cur!=NULL;cur= cur->next){
                printf("[%d  %d:%d]  ",i,cur->key,cur->value);
            }
            printf("\n");
        }
    }//循环结束
    return;
}

int HashFind(HashTable* ht, KeyType key, ValType* value){
    if(ht == NULL){
        //非法输入
        return 0;
    }
    if(ht->size == 0){
        //哈希表为空
        return 0;
    }
    int i = 0;
    for(;i<HashMaxSize;++i){
        if(ht->data[i] != NULL){
            HashElem* cur = ht->data[i];
            for(;cur!=  NULL;cur = cur->next){
                if(cur->key == key){
                    *value = cur->value;
                    return 1;
                }
            }
        }//判断是否为空
    }//循环结束
    return 0;
}

void HashRemove(HashTable* ht, KeyType key){
    if(ht ==NULL){
        //非法输入
        return;
    }
    if(ht->size == 0){
        //哈希表为空
        return;
    }
    int offset = ht->func(key);
    int i = 0;
    for(;i<HashMaxSize;++i){
        if(ht->data[offset] != NULL){
            HashElem* cur = ht->data[offset];
            HashElem* parent = NULL;
            for(;cur!=NULL;cur= cur->next){
                if(cur->key == key){
                    if(parent == NULL){
                        free(cur);
                        --ht->size;
                        ht->data[i] = NULL;
                        return;
                    }else{
                        parent->next = cur->next;
                        free(cur);
                        --ht->size;
                        return;
                    }
                }
                parent = cur;
            }
        }
    }//循环结束
    return;
}

void HashDestroy(HashTable* ht){
    if(ht == NULL){
        //非法输入
        return;
    }
    if(ht->size == 0){
        return;
    }
    int i = 0;
    for(;i<HashMaxSize;++i){
        if(ht->data[i]!= NULL){
            HashElem* cur = ht->data[i];
            HashElem* tmp = NULL;
            while(cur->next != NULL){
                HashElem* tmp = cur;
                cur= cur->next;
                free(tmp);
                --ht->size;
            }
            tmp = cur;
            cur = NULL;
            free(tmp);
            --ht->size;
        }
    }//循环结束
    return;
}

size_t HashSize(HashTable* ht){
    if(ht == NULL){
        //非法输入
        return 0;
    }
    if(ht->size == 0){
        return 0;
    }
    return ht->size;
}

//返回1表示不为空，返回表示为空
int HashEmpty(HashTable* ht){
    if(ht == NULL){
        //非法输入
        return 0;
    }
    if(ht->size == 0){
        return 0;
    }
    return 1;
} 
//检测函数
void TestHashEmpty(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    HashInsert(&ht,2,2);
    HashInsert(&ht,1002,3);
    HashInsert(&ht,2002,4);
    int ret = HashEmpty(&ht);
    printf("except:1 actual:%d\n",ret);
    return;
}
void TestHashSize(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    HashInsert(&ht,2,2);
    HashInsert(&ht,1002,3);
    HashInsert(&ht,2002,4);
    int ret = HashSize(&ht);
    printf("size except:3 actual :%d\n",ret);
}
void TestHashDestroy(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    HashInsert(&ht,2,2);
    HashInsert(&ht,1002,3);
    HashInsert(&ht,2002,4);
    HashPrint(&ht,"三个元素");
    HashDestroy(&ht);
    HashPrint(&ht,"删除全部元素");
    return;
}
void TestHashRemove(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    HashInsert(&ht,2,2);
    HashInsert(&ht,1002,3);
    HashInsert(&ht,2002,4);
    HashPrint(&ht,"三个元素");
    HashRemove(&ht,1002);
    HashPrint(&ht,"删除value=1002元素");
    return;
}
void TestHashFind(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    HashInsert(&ht,2,2);
    HashInsert(&ht,1002,3);
    HashInsert(&ht,2002,4);
    ValType value;
    int ret = HashFind(&ht,1002,&value);
    printf("ret except:1 actual:%d\n",ret);
    printf("value except:3 actual:%d\n",value);
    return;
}
void TestHashInsert(){
    HashTable ht;
    HashInit(&ht,HashFuncDefault);
    HashInsert(&ht,2,2);
    HashInsert(&ht,1002,3);
    HashInsert(&ht,2002,4);
    HashPrint(&ht,"三个元素");
}


//主函数
int main(){
    TestHashInsert();
    TestHashFind();
    TestHashRemove();
    TestHashDestroy();
    TestHashSize();
    TestHashEmpty();
    return 0;
}

