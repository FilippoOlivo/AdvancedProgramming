#include "linked_list.hpp"

int main(){
    CLinkedList<int> list("num.txt");
    list.print();
    CLinkedList<int> list2(list);
    list2.print();
    return 0;
}