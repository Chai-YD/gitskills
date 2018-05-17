#include<stdio.h>
#include<stdlib.h>

typedef char DLinkType; //定义参数类型

typedef struct DLinkNode { //定义结点
	DLinkType data; 
	struct DLinkNode* next; 
	struct DLinkNode* prev; 
} DLinkNode; 

//创建新结点
DLinkNode*CreateNewNode(DLinkType value){
	DLinkNode* new_node = (DLinkNode *)malloc(sizeof(DLinkNode));
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}
//对带环双链表进行初始化
void DLinkListInit(DLinkNode** head){
	(*head)->next =(*head);
	(*head)->prev = (*head);
} 

//输入链表
void PrintLinkList(DLinkNode* head,char * str){
	printf("\n*********%s*************\n",str);
	DLinkNode* cur = head->next;
	while(cur != head){
		printf("%c ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//对带环双链表进行尾插
void DLinkListPushBack(DLinkNode** head, DLinkType value){
	DLinkNode* new = CreateNewNode(value);
	DLinkNode* tmp = (*head)->prev;
	tmp->next = new;
	new->prev = tmp;
	new->next = (*head);
	(*head)->prev = new;
	return;
}

//对带环双链表进行尾删
void DLinkListPopBack(DLinkNode** head){
	if(head == NULL){
		//非法输入
		return;
	}
	if((*head)->next == (*head)){
		//空链表
		return;
	}
	DLinkNode* delete = (*head)->prev;
	delete->prev->next = delete->next;
	delete->next->prev = delete->prev;
	free(delete);
}
//对带环双链表进行头插
void DLinkListPushFront(DLinkNode** head, DLinkType value){
	DLinkNode* new = CreateNewNode(value);
	DLinkNode* tmp = (*head)->next;
	tmp->prev = new;
	new->next = tmp;
	new->prev = (*head);
	(*head)->next = new;
	return;
} 
//对带环双链表进行头删
void DLinkListPopFront(DLinkNode** head){
	if(head == NULL){
		//非法输入
		return;
	}
	if((*head)->next == (*head)){
		//空链表
		return;
	}
	DLinkNode* delete = (*head)->next;
	delete->next->prev = (*head);
	delete->prev->next = delete->next;
	free(delete);

}
//对双链表进行指定元素的查找
DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find){
	if(head->next == head){
		return NULL;
	}
	DLinkNode* cur = head->next;
	while(cur != head){
		if(cur->data == to_find){
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//往指定位置之前插入一个元素
void DLinkListInsert(DLinkNode** head,DLinkNode* pos, DLinkType value){
	DLinkNode* new = CreateNewNode(value);
	DLinkNode* cur = (*head)->next;
	while(cur != pos&&cur != (*head)){
		cur = cur->next;
	}
	if(cur == (*head)){
		return;
	}else{
		cur->prev->next = new;
		new->prev = cur->prev;
		new->next = cur;
		cur->prev = new;
	}
} 

//往指定元素之后插入一个元素
void DLinkListInsertAfter(DLinkNode** head,DLinkNode* pos, DLinkType value){

	DLinkNode* new = CreateNewNode(value);
	DLinkNode* cur = (*head)->next;
	while(cur != pos&&cur != (*head)){
		cur = cur->next;
	}
	if(cur == (*head)){
		return;
	}else{
		cur->next->prev = new;
		new->next =cur->next;
		cur->next = new;
		new->prev = cur;
	}
}

//检测函数
void textDLinkListPushBack(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushBack(&head, 'a');
	DLinkListPushBack(&head, 'b');
	DLinkListPushBack(&head, 'c');
	DLinkListPushBack(&head, 'd');
	PrintLinkList(head,"DLinkListPushBack");
}
void textDLinkListPopBack(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushBack(&head, 'a');
	DLinkListPushBack(&head, 'b');
	DLinkListPushBack(&head, 'c');
	DLinkListPushBack(&head, 'd');
	DLinkListPopBack(&head);
	PrintLinkList(head,"DLinkListPopBack");
}
void textDLinkListPushFront(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushFront(&head, 'a');
	DLinkListPushFront(&head, 'b');
	DLinkListPushFront(&head, 'c');
	DLinkListPushFront(&head, 'd');
	PrintLinkList(head,"DLinkListPushFront");
}
void textDLinkListPopFront(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushBack(&head, 'a');
	DLinkListPushBack(&head, 'b');
	DLinkListPushBack(&head, 'c');
	DLinkListPushBack(&head, 'd');
	DLinkListPopFront(&head);
	PrintLinkList(head,"DLinkListPopFront");
}
void textDLinkListFind(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushBack(&head, 'a');
	DLinkListPushBack(&head, 'b');
	DLinkListPushBack(&head, 'c');
	DLinkListPushBack(&head, 'd');
	DLinkNode* ret = DLinkListFind(head,'c');
	printf("\n*******DLinkListFind***********\n");
	printf("expect:1	");
	if(ret == NULL){
		printf("actual:0\n");
	}else{
		printf("actual:1\n");
	}
}
void textDLinkListInsert(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushBack(&head, 'a');
	DLinkListPushBack(&head, 'b');
	DLinkListPushBack(&head, 'c');
	DLinkListPushBack(&head, 'd');
	DLinkListInsert(&head,head->next,'z');
	PrintLinkList(head,"DLinkListInsert");
}
void textDLinkListInsertAfter(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushBack(&head, 'a');
	DLinkListPushBack(&head, 'b');
	DLinkListPushBack(&head, 'c');
	DLinkListPushBack(&head, 'd');
	DLinkListInsertAfter(&head,head->next,'z');
	PrintLinkList(head,"DLinkListInsert");
}
void DLinklistErase(DLinkNode** head,DLinkType value){
	DLinkNode * cur = (*head)->next;
	while(cur->data!=value&&cur!=(*head)){
		cur = cur->next;
	}
	if(cur == (*head)){
		return;
	}else{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	}
}

void DLinkListRemove(DLinkNode** head,DLinkNode * pos){
	DLinkNode* cur = (*head)->next;
	while(cur != pos&&cur!=(*head)){
		cur = cur->next;
	}
	if(cur == (*head)){
		return;
	}else{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	}
}

void DLinkListRemoveAll(DLinkNode** head){
	DLinkNode* cur = (*head);
	while(cur->next != (*head)){
		DLinkListPopFront(head);
	}
}

size_t DLinkListSize(DLinkNode* head){
	size_t count=0;
	if(head->next == head){
		return count;
	}
	DLinkNode* cur = head->next;
	while(cur!= head){
		count++;
		cur = cur->next;
	}
	return count;
}

void DLinkListEmpty(DLinkNode** head){
	if(head == NULL){
		return;
	}
	if((*head)->next == (*head)){
		return;
	}
	DLinkNode* cur = (*head);
	while(cur->next != (*head)){
		DLinkListPopFront(head);
	}
}

void textDLinkListEmpty(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushBack(&head, 'a');
	DLinkListPushBack(&head, 'b');
	DLinkListPushBack(&head, 'c');
	DLinkListPushBack(&head, 'd');
	DLinkListEmpty(&head);
	PrintLinkList(head,"DLinkListEmpty");
}
void textDLinkListSize(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushBack(&head, 'a');
	DLinkListPushBack(&head, 'b');
	DLinkListPushBack(&head, 'c');
	DLinkListPushBack(&head, 'd');
	size_t ret = DLinkListSize(head);
	printf("\n****DLinkListSize***********\n");
	printf("%d\n",ret);
}
void textDLinkListRemoveAll(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushBack(&head, 'a');
	DLinkListPushBack(&head, 'b');
	DLinkListPushBack(&head, 'c');
	DLinkListPushBack(&head, 'd');
	DLinkListRemoveAll(&head);
	PrintLinkList(head,"DLinkListRemoveAll");
}

void textDLinkListRemove(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushBack(&head, 'a');
	DLinkListPushBack(&head, 'b');
	DLinkListPushBack(&head, 'c');
	DLinkListPushBack(&head, 'd');
	DLinkListRemove(&head,head->next);
	PrintLinkList(head,"DLinkListRemove");
}
void textDLinklistErase(){
	DLinkNode* head = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkListInit(&head);
   	DLinkListPushBack(&head, 'a');
	DLinkListPushBack(&head, 'b');
	DLinkListPushBack(&head, 'c');
	DLinkListPushBack(&head, 'd');
	DLinklistErase(&head,'a');
	PrintLinkList(head,"DLinkListErase");
}
//主函数
int main(){
	textDLinkListPushBack();
	textDLinkListPopBack();
	textDLinkListPushFront();
	textDLinkListPopFront();
	textDLinkListFind();
	textDLinkListInsert();
	textDLinkListInsertAfter();
	textDLinklistErase();
	textDLinkListRemove();
	textDLinkListRemoveAll();
	textDLinkListSize();
	textDLinkListEmpty();
}
