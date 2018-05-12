#include<stdlib.h>
#include<stdio.h>
#define SeqStackType char
#define SeqMax 1000
typedef struct{
	SeqStackType data[SeqMax];
	size_t size;
}SeqStack;
//初始化
void SeqStackInit(SeqStack* seq){
	seq->size = 0;
}
//销毁
void SeqStackDestroy(SeqStack* seq){
	seq->size = 0;
}
//入栈
void SeqStackPush(SeqStack* seq,SeqStackType value){
	if(seq == NULL){
		//非法输入
		return;
	}
	seq->data[seq->size] = value;
	++seq->size;
}
//出栈
void SeqStackPop(SeqStack* seq,SeqStackType* value){
	if(seq == NULL){
		//非法输入
		return;
	}
	if(seq->size == 0){
		//空栈
		return;
	}
	*value = seq->data[seq->size-1];
	--seq->size;
}
//取栈顶元素
int GetStackTop(SeqStack* seq,SeqStackType* value){
	if(seq == NULL){
		//非法输入
		return 0;
	}
	if(seq->size == 0){
		//空栈
		return 0;
	}
	*value = seq->data[seq->size-1];
	return 1;
}
void printStack(SeqStack* seq,char * str){
	printf("\n*******%s************\n",str);
	size_t i=0;
	for(;i<seq->size;i++){
		printf("%c ",seq->data[i]);
	}
	printf("\n");
}
void teststack(){
	SeqStack seq;
	int ret;   //接收成功与否的返回值
	SeqStackType value;
	SeqStackInit(&seq);
	printStack(&seq,"初始化");
	SeqStackPush(&seq,'a');
	SeqStackPush(&seq,'b');
	SeqStackPush(&seq,'c');
	SeqStackPush(&seq,'d');
	ret = GetStackTop(&seq,&value);
	printf("except: 1   actual: %d\n",ret);
	printf("except: d   actual: %c\n",value);
	printStack(&seq,"入栈四个元素");
	SeqStackPop(&seq,&value);
	printStack(&seq,"出栈一个元素");
	printf("value expect: d  actual: %c\n",value);
	ret = GetStackTop(&seq,&value);
	printf("except: 1   actual: %d\n",ret);
	printf("except: d   actual: %c\n",value);
	SeqStackPop(&seq,&value);
	printStack(&seq,"出栈俩个元素");
	printf("value expect: c  actual: %c\n",value);
	ret = GetStackTop(&seq,&value);
	printf("except: 1   actual: %d\n",ret);
	printf("except: d   actual: %c\n",value);
	SeqStackPop(&seq,&value);
	printStack(&seq,"出栈三个元素");
	printf("value expect: b  actual: %c\n",value);
	ret = GetStackTop(&seq,&value);
	printf("except: 1   actual: %d\n",ret);
	printf("except: d   actual: %c\n",value);
	SeqStackPop(&seq,&value);
	printStack(&seq,"出栈四个元素");
	printf("value expect: a  actual: %c\n",value);
	ret = GetStackTop(&seq,&value);
	printf("except: 0   actual: %d\n",ret);
	SeqStackPush(&seq,'c');
	SeqStackPush(&seq,'c');
	SeqStackPush(&seq,'c');
	SeqStackPush(&seq,'c');
	printStack(&seq,"入栈四个元素");
	SeqStackDestroy(&seq);
	printStack(&seq,"销毁");

}

int main(){
	teststack();
}
