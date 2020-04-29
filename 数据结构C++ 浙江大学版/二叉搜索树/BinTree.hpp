//
// Created by zft on 20-4-27.
//

#ifndef UNTITLED1_BINTREE_HPP
#define UNTITLED1_BINTREE_HPP

#define ElementType int
typedef struct Tree *Bintree;
typedef struct Tree *BinTree;

BinTree CreateTree();
BinTree Insert(BinTree BST,ElementType X);

struct Tree{
    Bintree left;
    Bintree right;
    ElementType data;
};

#endif //UNTITLED1_BINTREE_HPP
