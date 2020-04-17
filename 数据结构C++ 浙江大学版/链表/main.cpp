#include <iostream>

#define ElementType int

typedef struct Lnode *list;

struct Lnode{
    ElementType Data;
    list next;
};

//求表长
//建议使用Ｐ指针表示指向
int Length(list Ptrl){
    int i=0;
    while(Ptrl->next!=NULL){
        i++;
        Ptrl=Ptrl->next;
    }
    return i;
}

//查找地K个元素
int FindKth(int k,list Ptrl){
    list p = Ptrl;
    int i=1;
    //判断数据的长度在不在范围里
    if(k>Length(Ptrl)&&k<1){
        printf("查找范围不正确");
    }
    while(i<k){
        p=p->next;
        i++;
    }
    return p;
}

//按值查找
list FindValue(ElementType X,list Prtl){

    list p=Prtl;
    while(p->Data!=X&&p->next!=NULL){
        p=p->next;
    }
    return p;
}

//插入一个节点，先构造一个节点
//
list insert(list Ptrl,ElementType X,int i){
  list p,temp;
  if(i==1){
      temp = malloc(sizeof(struct Lnode));
      temp->Data = X;
      temp->next = Ptrl;
      return temp;
  }
  p = FindKth(i-1,Ptrl){
      temp = malloc(sizeof(struct Lnode));
      temp->Data = X;
      temp->next=p->next;
      p->next=temp;
        return Ptrl;
  }
}

list Delete(list Ptrl, ElementType X,int i){
    list p,temp;
    if(i==1){
        p=Ptrl;
        if(p->next!=NULL){
            Ptrl=Ptrl->next;
        } else return NULL;
        free(p);
        return Ptrl;
        }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}