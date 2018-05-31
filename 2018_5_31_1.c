//输入一个链表，，求出链表的倒数第K个结点
#include "2018_5_31_1.h"
//函数实现
//提示：输入的链表是一个带头结点的链表
LinkNode* Find_K_Before_end(LinkNode** Head ,size_t k){
    if(Head == NULL){
        //表示非法输入
        return NULL;
    }
    if((*Head)->next == NULL){
        //表示输入链表为空链表
        return NULL;
    }
    LinkNode* fast = (*Head)->next;
    LinkNode* slow = (*Head)->next;
    while(fast != NULL){
        fast = fast->next;
        if(k != 0){
            --k;
        }else{
            slow = slow->next;
        }
    }
    if(k == 0){
        return slow;
    }else{
        //查询失败
        return NULL;
    }
}
int main(){
	LinkNode* head1 = (LinkNode *)malloc(sizeof(LinkNode));
	LinkListPushFront(&head1,CreateNewNode('a'));		
	LinkListPushFront(&head1,CreateNewNode('b'));		
	LinkListPushFront(&head1,CreateNewNode('c'));		
	LinkListPushFront(&head1,CreateNewNode('d'));		
   LinkNode* ret = Find_K_Before_end(&head1,2);
   if(ret != NULL){
       printf("ret->data = %c\n",ret->data);
   }
   return 0;
}
