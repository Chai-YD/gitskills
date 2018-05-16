#include "Heap.h"

int Less(HeapType a,HeapType b){
    return a<b?1:0;
}
int Greater(HeapType a,HeapType b){
    return a>b?1:0;
}
//堆的初始化
void HeapInit(Heap* heap, Compare cmp){
    if(heap == NULL){
        //非法输入
        return;
    }
    heap->size = 0;
    heap->cmp = cmp;
    return;
}
//层序遍历堆
void print_Heap(Heap heap,char* msg){
    printf("\n*******%s***********\n",msg);
    int i = 0;
    for(;i<heap.size;++i){
        printf("%d ",heap.data[i]);
    }
    printf("\n");
    return;
}
//，交换函数 
void swap(int * a,int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
//往堆里插入元素
void HeapInsert(Heap* heap, HeapType value){
    //1.判断是否为非法输入
    if(heap == NULL){
        //非法输入
        return ;
    }
    //2.判断堆是否为空
    if(heap->size == 0){
        //堆位空
        heap->data[heap->size] = value;
    }else{
        //堆不为空
        heap->data[heap->size] = value;
        int cur = heap->size;
        int parent = ( cur - 1 )/2;
        while(parent >= 0){
            if ( heap->cmp(heap->data[cur], heap->data[parent]) ){
                swap(&heap->data[cur],&heap->data[parent]);
                cur = parent;
                parent = (cur - 1)/2;
            }else{
                break;
            }
        }
    }
    ++heap->size;
    return;
}
//取堆顶元素
int HeapRoot(Heap* heap, HeapType* value){
    //1.判断是否为非法输入
    if(heap == NULL){
        //非法输入
        return 0;
    }
    //1.判断堆是否为空，空堆返回0，否则返回1
    if(heap->size == 0){
        //空堆 
        return 0;
    }else{
        //非空
        *value = heap->data[0];
        return 1;
    }
}
//取堆顶元素的检测函数
void textHeapRoot(){
    Heap heap ;
    HeapInit(&heap,Greater);
    HeapInsert(&heap,1);
    HeapInsert(&heap,2);
    HeapInsert(&heap,3);
    HeapInsert(&heap,4);
    HeapType value;
    int ret = HeapRoot(&heap,&value);
    printf("\n*******取堆顶元素***********\n");
    printf("ret except:1  actual:%d\n",ret);
    printf("value except:4   actual:%d\n",value);
}
//堆插入的检测函数
void textHeapInsert(){
    Heap heap ;
    HeapInit(&heap,Greater);
    HeapInsert(&heap,1);
    HeapInsert(&heap,2);
    HeapInsert(&heap,3);
    HeapInsert(&heap,4);
    print_Heap(heap,"堆插入四个元素");
    return;
}
//堆初始化的检测函数 
void textHeapInit(){
    Heap heap ;
    HeapInit(&heap ,Greater);
    print_Heap(heap,"对堆进行初始化");
    return;
}


//主函数
int main(){
    textHeapInit();//堆初始化的检测函数
    textHeapInsert();//堆插入一个元素
    textHeapRoot();//取堆顶元素的检测函数
    return 0;
}
