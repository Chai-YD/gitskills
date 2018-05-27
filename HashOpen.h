#pragma once 

#include<stdio.h> 
#include<stdlib.h>

#define HashMaxSize 1000 

typedef int KeyType; 
typedef int ValType; 

typedef size_t (*HashFunc)(KeyType key); 

typedef struct HashElem { 
KeyType key; 
ValType value; 
struct HashElem* next; 
} HashElem; 

// 数组的每一个元素是一个不带头结点的链表 
// 对于空链表, 我们使用 NULL 来表示 
 typedef struct HashTable { 
 HashElem* data[HashMaxSize]; 
 size_t size; 
 HashFunc func; 
 } HashTable; 

 void HashInit(HashTable* ht, HashFunc hash_func); 

 // 约定哈希表中不能包含 key 相同的值. 
 void HashInsert(HashTable* ht, KeyType key, ValType value); 

 int HashFind(HashTable* ht, KeyType key, ValType* value); 

 void HashRemove(HashTable* ht, KeyType key); 

 size_t HashSize(HashTable* ht); 

 int HashEmpty(HashTable* ht); 

 void HashDestroy(HashTable* ht); 
