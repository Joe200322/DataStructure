#include <iostream>
#include "../../DataStructure/LinkedList/LinkedList.h"
using namespace std;

linkedList combineNodes(linkedList list){
    linkedList newList;
    Node * current = list.listHead();
    int sum = 0;
    for (int i =0 ; i < list.listsize();i++){
        if (current->data == 0 && current->next != nullptr){
            while (current->next->data != 0){
                sum = sum + current->next->data;
                current = current ->next;
            }
            newList.pushBack(sum);
            sum=0;
            current =current->next;
        }
        else{
            continue;
        }
    }
    return newList;
}
int main() {
   linkedList list;
   list.pushBack(0);
    list.pushBack(1);
    list.pushBack(0);
    list.pushBack(3);
    list.pushBack(0);
    list.pushBack(2);
    list.pushBack(2);
    list.pushBack(0);
   list = combineNodes(list);
    list.display();
}
