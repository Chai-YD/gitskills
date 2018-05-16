//实现二叉搜索树的递归和非递归版本 

#include<stdio.h>
#include<stdlib.h>
typedef char SearchTreeType; 

typedef struct SearchTreeNode { 
SearchTreeType key; // 关键码 
struct SearchTreeNode* lchild; 
struct SearchTreeNode* rchild; 
} SearchTreeNode; 

void SearchTreeInit(SearchTreeNode** root); 

void SearchTreeInsert(SearchTreeNode** root, SearchTreeType key); 

SearchTreeNode* SearchTreeFind(SearchTreeNode* root,SearchTreeType to_find); 

void SearchTreeRemove(SearchTreeNode** root, SearchTreeType key);

