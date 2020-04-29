//
// Created by zft on 20-4-27.
//
#include "BinTree.hpp"
#include "stdio.h"
#include <iostream>
/*尾递归可以用循环实现*/
Bintree find(ElementType X,Bintree BT){
    if(!BT) return NULL;
    if(X<BT->data)
        find(X,BT->left);
    else if (X>BT->data)
        find(X,BT->right);
    else
        return BT;
}

Bintree IterFind(ElementType X,Bintree BT){
    //判断一下树空不空
    while(BT){
        if(X<BT->data)
            BT=BT->left;
        else if(X>BT->data)
            BT=BT->right;
        else
            return BT;
    }
    return NULL;
}
//最大查找和最小查找
BinTree Find_Min(Bintree BT){
    if(BT->left)
        Find_Min(BT->left);
    else
        return BT;
}
ElementType Find_Max(Bintree BT){
    while(BT->right){
        BT = BT->right;
    }
    return BT->data;
}
//创建一个二叉树
BinTree CreateTree(){
    BinTree father,left,right;
    father = (BinTree )malloc(sizeof(struct Tree));
    father->data = 20;
    left = (BinTree )malloc(sizeof(struct Tree));
    right = (BinTree )malloc(sizeof(struct Tree));
    left->data = 12;
    right->data = 28;
    father->left = left;
    father->right = right;
    return father;
}
//二叉树的插入
//记住33的位置

BinTree Insert(BinTree BST,ElementType X){
    if(!BST){
        BST = (BinTree)malloc(sizeof(struct Tree));
        BST->data = X;
        BST->left = BST->right = NULL;
    } else if(X<BST->data){
        BST->left = Insert(BST->left,X);
    } else if(X>BST->data){
        BST->right = Insert(BST->right,X);
    }
    //如果Ｘ存在就不需要进行操作
    return BST;
}
//查找树的删除
//主要有３种情况
 BinTree Delete(ElementType X,BinTree BST){
    BinTree Tmp;
    if(!BST) printf("没有找到");
    else if(X<BST->data)
        BST->left = Delete(X,BST->left);
    else if(X>BST->data)
        BST->right = Delete(X,BST->right);
    else if(BST->left && BST->right){
            Tmp = Find_Min(BST->right);
            BST->data = Tmp->data;
            BST->right = Delete(X,BST->right);
    } else{
        Tmp = BST;
        if(!BST->left)
            BST = BST->right;
        else if(!BST->right)
            BST = BST->left;
        free(Tmp);
    }
    return BST;
}

//平衡二叉树的调整
//右旋转，破坏者，与被破坏着直接的关系
//左旋转　LR旋转
//

