#include <iostream>

#define ElementType Bintree
typedef struct Tree *Bintree;
typedef struct Tree *BinTree;
typedef struct Lnode *Stack;
typedef struct queue *Queue;

struct Tree{
    Bintree left;
    Bintree right;
    int data;
};

struct Lnode{
    ElementType data;
    struct Lnode *next;
};

struct queue{
    Stack rear;
    Stack front;
};

Queue CreatQueue(){
    Queue temp;
    temp = (Queue)malloc(sizeof(struct queue));
    return temp;
}

void push(Queue input,ElementType X){
    Stack temp;
    temp = (Stack)malloc(sizeof(struct Lnode));
    temp->data = X;
    temp->next = NULL;
    //插入一个元素
    if(input->front==NULL){
        input->front = temp;
        input->rear = temp;
    }else{
        input->rear->next = temp;
        input->rear = temp;
    }
}

ElementType DeletQ(Queue input){
    Stack temp;
    Bintree X;
    temp = (Stack)malloc(sizeof(struct Lnode));
    //判断队列是否为空
    if(input->front == NULL){
        printf("队列为空");
        return  NULL;
    }
    temp = input->front;
    if(input->front==input->rear){
        X=temp->data;
        input->rear = input->front = NULL;
    } else{
        X=temp->data;
        input->front=temp->next;
    }
    free(temp);
    return X;
}

void layer(Bintree temp){
    Queue test;
    Bintree T;
    test =  (Queue)malloc(sizeof(struct queue));     //因为野指针的问题所以无法正确输出，如果删除这句话
    push(test,temp);
    while(test != NULL){
        T = DeletQ(test);
        printf("%d\n",T->data);
        if(T->left!=NULL) push(test,T->left);
        if(T->right!=NULL) push(test,T->right);
    }

}
//创建一个二叉树
BinTree CreateTree(){
    BinTree father,left,right;
    father = (BinTree )malloc(sizeof(struct Lnode));
    father->data = 20;
    left = (BinTree )malloc(sizeof(struct Lnode));
    right = (BinTree )malloc(sizeof(struct Lnode));
    left->data = 12;
    right->data = 28;
    father->left = left;
    father->right = right;
    return father;
}
//二叉树遍历的题目
//求出全部的叶子节点　应该在遍历的时候加上if语句
//求二叉树的高度

/*
 *
 */
//二叉树的高度
int PostOrderGetHeight(Bintree BT){
    int HL,HR,MaxH;
    if(BT){
        HL = PostOrderGetHeight(BT->left);
        HR = PostOrderGetHeight(BT->right);
        MaxH = (HL > HR)?HL:HR;
        return (MaxH + 1);
    }
    else return 0;
}
//树的同构造
//二叉树的表示　通过链表　通过用数组表示　按照完全二叉树的表示
//采用结构数组
//数组表示二叉树：静态链表

struct TreeNode2{
    int Element;
    int left,right;
}T1[10],T2[10];

int


int main() {
    Bintree temp;
    int a;
    temp =CreateTree();
    a=PostOrderGetHeight(temp);
    std::cout << a<< std::endl;
    return 0;
}