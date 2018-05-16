#include "SearchTree.h"


//搜索二叉树的初始化
void SearchTreeInit(SearchTreeNode** root){
    //判断是否为非法输入
    if(root == NULL){
        //非法输入
        return;
    }
    //判断是否为空树
    if(*root == NULL){
        //空树
        return;
    }
    *root = NULL;
}
//搜索二叉树的中序遍历
void InOrder_SearchTree(SearchTreeNode* root){
    if(root == NULL){
        //空树
        return;
    }
    InOrder_SearchTree(root->lchild);
    printf("%c ",root->key);
    InOrder_SearchTree(root->rchild);
}
//搜索二叉树的先序遍历
void PreOrder_SearchTree(SearchTreeNode* root){
    if(root == NULL){
        //空树
        return;
    }
    printf("%c ",root->key);
    PreOrder_SearchTree(root->lchild);
    PreOrder_SearchTree(root->rchild);
}
//创建结点
SearchTreeNode* CreateSearchTreeNode(SearchTreeType value){
    SearchTreeNode* new_node = (SearchTreeNode*)malloc(sizeof(SearchTreeNode));
    new_node->key = value;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    return new_node;
}

//搜索二叉树的插入（递归实现）
void SearchTreeInsert(SearchTreeNode** root, SearchTreeType key){
    //判断是否为非法输入
    if(root == NULL){
        return;
    }
    //判断是否为空树
    if(*root == NULL){
        //空树
        SearchTreeNode* ret = CreateSearchTreeNode(key);
        *root = ret;
    }else{
        //非空
        if(key < (*root)->key){
            SearchTreeInsert(&(*root)->lchild,key);
        }else if(key > (*root)->key){
            SearchTreeInsert(&(*root)->rchild,key);
        }else{
            //规定搜索二叉树中无相同项，，出现相同情况，，直接返回
            return;
        }
    }
}

//搜索二叉树的查找(递归实现)
SearchTreeNode* SearchTreeFind(SearchTreeNode* root,SearchTreeType to_find){
    //判断是否为空树
    if(root == NULL){
        //空树
        return NULL;
    }else{
        //非空
        if(to_find > root->key){
            SearchTreeFind(root->rchild,to_find);
        }else if(to_find < root->key){
            SearchTreeFind(root->lchild,to_find);
        }else{
            //找到了
            return root;
        }
    }
} 
//搜索二叉树的删除（非递归实现）
void SearchTreeRemove(SearchTreeNode** root, SearchTreeType key){
    if(root == NULL){
        //非法输入
        return;
    }
    if(*root == NULL){
        //空树
        return;
    }
    //查找
    SearchTreeNode* parent = NULL;
    SearchTreeNode* cur = (*root);
    while(cur != NULL){
        if(cur->key == key){
            //要删除值等于根结点的关键字，判断根结点的孩子情况
            if(cur->lchild!= NULL&& cur->rchild ==NULL){
                //1.只有左子树
                if(parent->rchild == cur){
                    parent->rchild =cur->lchild;
                    free(cur);
                    return;
                }else{
                    parent->lchild = cur->lchild;
                    free(cur);
                    return;
                }
                //
            }else if(cur->lchild == NULL&&cur->rchild !=NULL) {
                //2.只有右子树
                if(parent->rchild == cur){
                    parent->rchild =cur->rchild;
                    free(cur);
                    return;
                }else{
                    parent->lchild = cur->rchild;
                    free(cur);
                    return;
                }
            }else if(cur->lchild != NULL&&cur->rchild != NULL){
                //3.既有左子树、又有右子树
                //这里右俩中方法：一、用该结点的右子树的最左下结点的值来替换该结点的值，最左下结点无左孩子，同2；
                //                二、用该结点的左子树的最右下结点的值来替换该结点的值，最右下结点无右孩子，同1.
                parent = cur; 
                SearchTreeNode* min = cur->rchild;
                while(min->lchild != NULL){
                    parent = min;
                    min = min->lchild;
                }
                cur->key = min->key;
                if(parent->rchild == min){
                    parent->rchild =min->rchild;
                    free(min);
                    return;
                }else{
                    parent->lchild = min->rchild;
                    free(min);
                    return;
                }
            }else{
                //4.即没有左子树、又没有右子树
                if(parent->rchild == cur){
                    parent->rchild =NULL;
                    free(cur);
                    return;
                }else{
                    parent->lchild = NULL;
                    free(cur);
                    return;
                }
            }

        }else if(cur->key <key){
            //要删除值大于根结点的关键字，在根结点的右子树中查找
            parent = cur;
            cur = cur->rchild;
        }else{
            //要删除值小于根结点的关键字，在根结点的左子树中查找
            parent = cur;
            cur = cur->lchild;
        }
    }
    return;
}
//搜索二叉树删除的检测
void textSearchTreeRemove(){
    SearchTreeNode* root = (SearchTreeNode*)malloc(sizeof(SearchTreeNode));
    SearchTreeInit(&root);
    printf("\n********搜索二叉树删除的检测*****************\n");
    SearchTreeInsert(&root,'b');
    SearchTreeInsert(&root,'a');
    SearchTreeInsert(&root,'c');
    SearchTreeInsert(&root,'d');
    SearchTreeRemove(&root,'c');
    printf("先序遍历：");
    PreOrder_SearchTree(root);
    printf("\n");
    printf("中序遍历：");
    InOrder_SearchTree(root);
    printf("\n");
    return;
}
//搜索二叉树查找的检测
void textSearchTreeFind(){
    SearchTreeNode* root = (SearchTreeNode*)malloc(sizeof(SearchTreeNode));
    SearchTreeInit(&root);
    printf("\n********搜索二叉树查找的检测*****************\n");
    SearchTreeInsert(&root,'b');
    SearchTreeInsert(&root,'a');
    SearchTreeInsert(&root,'c');
    SearchTreeInsert(&root,'d');
    SearchTreeNode* ret = SearchTreeFind(root,'a');
    if(ret == NULL){
        printf("未找到\n");
    }else{
        printf("ret->key = %c \n",ret->key);
    }
    printf("\n");
}
//搜索二叉树插入的检测
void textSearchTreeInsert(){
    SearchTreeNode* root = (SearchTreeNode*)malloc(sizeof(SearchTreeNode));
    SearchTreeInit(&root);
    printf("\n********搜索二叉树插入的检测*****************\n");
    SearchTreeInsert(&root,'b');
    SearchTreeInsert(&root,'a');
    SearchTreeInsert(&root,'c');
    SearchTreeInsert(&root,'d');
    printf("先序遍历：");
    PreOrder_SearchTree(root);
    printf("\n");
    printf("中序遍历：");
    InOrder_SearchTree(root);
    printf("\n");
    return;
}
//搜索二叉树初始化的检测
void textPreOrder_SearchTreeInit(){
    SearchTreeNode* root = (SearchTreeNode*)malloc(sizeof(SearchTreeNode));
    SearchTreeInit(&root);
    printf("\n********搜索二叉树初始化的检测*****************\n");
    PreOrder_SearchTree(root);
    printf("\n");
}
//主函数
int main(){
    textPreOrder_SearchTreeInit();
    textSearchTreeInsert();
    textSearchTreeFind();
    textSearchTreeRemove();
    return 0;
}
