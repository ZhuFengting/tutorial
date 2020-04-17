#include <iostream>

#define maxsize 100
#define ElementType int

typedef struct Lnode *list;

struct Lnode{
    ElementType Data[maxsize];
    int last;
};




//初始化
list MakeEmpty(){
    list Ptrl;     //定义指针后及时分配地址
    Ptrl = (list)malloc(sizeof(struct Lnode));
    Ptrl->last = -1;                //代表没有元素
    return Ptrl;
}

int find(ElementType X,list Ptrl){
    int i = 0;
    while(i<=maxsize&&Ptrl->Data[i]!=X)
        i++;
    if(i>=Ptrl->last)
        return -1;
    else
        return i;

}
//先移动在插入
//线性表从１开始，数组从０开始所以＋２；
void insert(ElementType X, list Ptrl,int i){
    //判断表有没有满
    int j;
    if(Ptrl->last==maxsize){
        std::cout<<"表满"<<std::endl;
        return;
    }
    //检测插入位置是否合法
    if(i<1||i>Ptrl->last+2){
        std::cout<<"插入数据不合法，请重新插入"<<std::endl;
        return;
    }
    for(j=Ptrl->last;j<=i-1;j--){
        Ptrl->Data[Ptrl->last+1]=Ptrl->Data[Ptrl->last];
    }
    Ptrl->Data[i-1]=X;
    Ptrl->last++;
    return;
}

void delet(ElementType X,list Ptrl,int i){
    int j;
//判断位置是否合法
    if(i<1||i>Ptrl->last+1){
        printf("位置不合法")；
        return;
    }
    for(j=i-1;j=<Ptrl->last-1;j--)
        Ptrl->Data[j]==Ptrl->Data[j+1];
    Ptrl->last--;
    return;
}

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}