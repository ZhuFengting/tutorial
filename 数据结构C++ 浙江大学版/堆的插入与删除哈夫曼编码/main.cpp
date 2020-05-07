#include <iostream>

#define ElementType int
#define MaxData 1000    //注意MaxData要比所有的树都要大
//堆
typedef struct HeapStruct *MaxHeap;

struct HeapStruct{
    ElementType *Elements;
    int size;
    int Capacity;
};

MaxHeap Create(int Maxsize){
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements =(int*)malloc(sizeof(ElementType)*(Maxsize+1));
    H->size = 0;
    H->Capacity = Maxsize;
    H->Elements[0] = MaxData;
    return H;
}

//二叉树的插入
//先保证结构性，在保证有序性
//上浮操作
void Insert(MaxHeap H,ElementType item){
    //判断空不空
    int i;
    if(H->size == H->Capacity){
        printf("堆栈满");
    }
    i=++(H->size);
    for(;H->Elements[i/2] < item; i =i /2){
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = item;
}

//堆的删除
//用最后一个元素去替换第一个位置
//下沉操作

ElementType Delete(MaxHeap H){
    int Parent,Child;
    ElementType MaxItem,temp;
    if(H->size <1){
        printf("堆栈为空");
        return -1;
    }
    //判断是否有左儿子
    MaxItem = H->Elements[1];
    temp = H->Elements[H->size--];
    //做一个下沉操作
    for(Parent=1;Parent*2<=H->size;Parent=Child){
        Child = Parent*2;
        if(Child!=H->size&&H->Elements[Child]<H->Elements[Child+1]){
            Child++;
        }
        if(H->Elements[Child]<temp) break;
        else{
            H->Elements[Parent] = H->Elements[Child];
        }
        H->Elements[Parent] = temp;
    }
    return MaxItem;

}
//最大堆的建立
//最大堆排序
//方法一　不段插入

//哈夫曼树哈夫曼树编码　　根据频率进行编码
//判定树　　　带权路径

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}