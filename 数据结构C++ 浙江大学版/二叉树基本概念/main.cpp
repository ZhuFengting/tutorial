#include <iostream>

//数的表示
//儿子兄弟表示法
//只有第一个指针指向下一次的结构。结构统一
//旋转度可以观察到是二叉树

#define ElementType int

//二叉树的存储
typedef struct TreeNode *BinTree

 struct TreeNode{
    ElementType data;
    BinTree left;
    BinTree Right;
};

//二叉树的遍历
//先序列遍历
void PreOrderTraversal(BinTree BT){
    if(BT){
        printf("%d",BT->data);
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->Right);
    }
}

//中序遍历
void PreOrderTraversal(BinTree BT){
    if(BT){
        PreOrderTraversal(BT->left);
        printf("%d",BT->data);
        PreOrderTraversal(BT->Right);
    }
}

//后序遍历
void PreOrderTraversal(BinTree BT){
    if(BT){
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->Right);
        printf("%d",BT->data);
    }
}

//堆栈操作
typedef struct node{
    ElementType data;
    struct node *next;
} *Stack;

//创建堆栈的头节点
Stack CreateStack(){
    Stack S;
    S = (Stack)malloc(typeof(struct node));
    S->next = NULL;
    return S;
}

int IsEmpty(Stack S){
    return (S->next == NULL);
}

void push(Stack S,ElementType item){
    Stack temp;
    temp = (Stack)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = S->next;
    S->next = temp;
}

ElementType pop(Stack S){
    Stack temp;
    ElementType out;


    if(S->next==NULL){
        printf("堆栈空");
        return NULL;
    }
    else{
        temp = S->next;
        out = temp->data;
        S->next = temp->next;
        free(temp);
        return out;
    }
}
//走的路径都相同，输出的方式不一样
//二叉树的非递归调用 中序采用堆栈操作

//


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}