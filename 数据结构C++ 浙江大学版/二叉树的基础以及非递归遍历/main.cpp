#include <iostream>
#include<stdio.h>
#include <stdlib.h>
//二叉树的存储结构
//顺序查找　完全二叉树　　父节点在左儿子的二分之一的地方
//一般二叉树　用数组存储需要先补齐　但是存在大量的空间浪费
//
//链式存储

typedef struct TreeNode *BinTree;

 struct TreeNode{
    int data;
    BinTree left =NULL;
    BinTree right = NULL;
};

//二叉树的遍历
//先序
void PreOrderTraversal(BinTree BT){
    if(BT){
        printf("%d\n",BT->data);
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
    }
}

void MidOrderTraversal(BinTree BT){
    if(BT){
        PreOrderTraversal(BT->left);
        printf("%d\n",BT->data);
        PreOrderTraversal(BT->right);
    }
}

void OutOrderTraversal(BinTree BT){
    if(BT){
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
        printf("%d\n",BT->data);
    }
}

//创建一个二叉树
BinTree CreateTree(){
    BinTree father,left,right;
    father = (BinTree )malloc(sizeof(struct TreeNode));
    father->data = 20;
    left = (BinTree )malloc(sizeof(struct TreeNode));
    right = (BinTree )malloc(sizeof(struct TreeNode));
    left->data = 12;
    right->data = 28;
    father->left = left;
    father->right = right;
    return father;
}

typedef struct Lnode *Stack;

struct Lnode{
    BinTree data;
    struct Lnode *next;
};

Stack CreatStack(){
    struct Lnode *temp;
    temp = (Stack)malloc(sizeof(struct Lnode));
    temp->next=NULL;
    temp->data=NULL;
    return temp;
}

void push(Lnode *T, BinTree X){
    struct Lnode *temp;
    temp = (Lnode *)malloc(sizeof(struct Lnode));
    temp->data = X;
    if(T->next==NULL){
        T->next = temp;
        temp->next = NULL;
    } else{
        temp->next = T->next;
        T->next = temp;
    }
}

BinTree pop(Lnode *T){
    struct Lnode *temp;
    BinTree X;
    if(T->next == NULL){
        printf("堆栈空");
        return NULL;
    }else{
        temp = T->next;
        T->next = temp->next;
        X = temp->data;
        free(temp);
        return  X;
    }
}

//非递归实现二叉树的遍历
void MidOrder(BinTree BT) {
    Stack test;
    test = CreatStack();
    while (BT || test->next != NULL) {
        while (BT) {
            push(test, BT);
            BT = BT->left;
        }    //访问完全部的左节点
        if (test->next != NULL) {
            BT = pop(test);
            printf("%d\n", BT->data);
            BT = BT->right;
        }
    }

}


int main() {
    BinTree test1;
    test1 = CreateTree();
    MidOrder(test1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
