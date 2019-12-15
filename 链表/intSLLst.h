#ifndef INI_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode{
public:
    int info;
    IntSLLNode *next;
    IntSLLNode (int el,IntSLLNode *ptr=0){
    info = el; next = ptr;
    }
}

class IntSLList{
public:
    IntSLList(){
      head =tail= nullptr;
    }
    ~IntSLList();
    int isEmpty(){
        return head==0;
    }
private:
    IntSLLNode *head,*tail;
};