#include <iostream>

using namespace std;

struct node{
    float num;
    node *next;
};


int main() {
    node *p;
    p = new node;
    /***创建链表起点***/
    p->num=12.5;
    p->next = nullptr;
    /***增加链表点***/
    node *second_list = new node;
    second_list->num = 13.5;
    /***指针赋值操作***/
    second_list->next = nullptr;
    p->next = second_list;

    std::cout << second_list->num<< std::endl;
    return 0;
}
