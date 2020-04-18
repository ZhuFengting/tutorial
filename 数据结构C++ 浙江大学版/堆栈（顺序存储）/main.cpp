#include <iostream>

#define Element int
#define MaxSize 100

typedef struct SNode *Stack;

struct SNode{
    Element Date[MaxSize];
    int Top;
};

void push(Stack PtrS,Element X){
    if(PtrS->Top==MaxSize){
        printf("堆栈满")；
        return;
    }else{
        PtrS->Date[++(PtrS->Top)]=X;
        return;
    }
}

Element pop(Stack PtrS){
if(PtrS->Top==-1){
    printf("堆栈空")；
    return;
}else{
    return (PtrS->Date[(PtrS->Top)--]);
}
};


//用一个数组实现两个堆栈
struct test{
    Element Data[MaxSize];
    int left=-1;
    int right=MaxSize;
};
void push_test(bool tag,struct test *PtrS,Element X){
    if(PtrS->left+1==PtrS->right){
        printf("堆栈满")；
        return;
    }
    if(!tag){
        PtrS->Data[++(PtrS->left)]=X;
    } else{
        PtrS->Data[--(PtrS->right)]=X;
    }

}
Element pop_test(bool tag, struct test *PtrS){
    if(!tag){
        if(PtrS->left==-1){
            printf("堆栈空")
        }else{
        return PtrS->Data[(PtrS->left)--];
    } else{
        if(PtrS->right==MaxSize){
            printf("堆栈空")；
        } else{
            return  PtrS->Data[PtrS->right++];
        }
        }
    }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}