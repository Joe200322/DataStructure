#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;
int main()
{
    DoublyLinkedList<int> a;
    a.insertAtTail(1);
    a.insertAtTail(2);
    a.insertAtTail(3);
    a.insertAtTail(4);
    a.insertAtTail(5);
    a.insertAtHead(0);
    a.forwardTraversal();
    a.swap(2, 4);
    cout << "---------------------\n";
    a.forwardTraversal();
    cout << "---------------------\n";
    a.reverse();
    a.forwardTraversal();
    a.insertAtTail(50);
    cout << "---------------------\n";
    a.forwardTraversal();
    cout << "---------------------\n";
    a.backwardTraversal();
    cout << "---------------------\n";
    a.clear();
    a.forwardTraversal();
}