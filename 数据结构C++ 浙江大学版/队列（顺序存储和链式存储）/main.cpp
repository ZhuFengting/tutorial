#include <iostream>

#define MaxSize 100
#define ElementType int

typedef struct QNode *Queue;

struct QNode{
    ElementType Data[MaxSize];
    int rear;
    int front;
};

//创建队列
Queue CreatQueue(int Maxsize){

}

//入队列
void AddQ(Queue PtrQ,ElementType item){
    if((PtrQ->rear+1)%MaxSize==PtrQ->front){
        printf("队列满")；
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)%MaxSize;
    PtrQ->Data[(PtrQ->rear)]=item;
}

//出队列
ElementType DelQ(Queue PtrlQ){
 if(PtrlQ->rear==PtrlQ->front){
     printf("队列空");
     return false;
 }
 PtrlQ->front=(PtrlQ->front+1)%MaxSize;
    return PtrlQ->Data[PtrlQ->front];
}

//队列的链式存储
struct Node_{
    ElementType Data;
    struct Node_ *Next;
};

struct QNode_{
    struct Node_ *rear;
    struct Node_ *front;
};

typedef struct QNode_ *Queue_;

//删除队列中的元素
//前面删除，后面插入
//单项链表无法由后面找到前面的指针
ElementType DeleteQ(Queue_ Ptrl){
//判断链表是否为空
    struct Node_ *temp;
    ElementType item;
    temp = Ptrl->front;
    if(temp==NULL){
        printf("列队空")；
        return false;
    }

    if(Ptrl->front==Ptrl->rear){
        Ptrl->front=Ptrl->rear=NULL;
    }else{
        Ptrl->front=temp->Next;
    }
    item = temp->Data;
    malloc(temp);
    return item;
}
//入队操作

void AddQ_(Queue_ Ptrl,ElementType item){
    struct Node_ *temp;
    temp = malloc(typeof(struct Node_));
    temp->Data = item;
    if(Ptrl->rear == NULL){
        Ptrl->front=temp;
        Ptrl->rear=temp;
    } else{
        Ptrl->rear->Next=temp;
        Ptrl->rear=temp;
    }

}




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}