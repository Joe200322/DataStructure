#include "CircularLinkedList.h"
using namespace std;



int main() {
   circularLinkedList<int > list;
   list.insertInHead(4);//3
   list.insertInHead(3);//2
    list.insertInHead(2);//1
   list.insertInHead(1);//0
    list.print();
    list.swap(1,3);
    list.insertInHead(3);//0
    list.insertAtEnd(9);
    list.insertAtEnd(68);
    list.clear();
   list.print();





}
