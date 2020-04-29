#include <iostream>
#include "BinTree.hpp"

int add(int n){
    if(n==1){
        return 1;
    }
    return 1+add(n-1);

}

int main() {
    BinTree temp;
    temp = CreateTree();
    Insert(temp,10);
    return 0;
}