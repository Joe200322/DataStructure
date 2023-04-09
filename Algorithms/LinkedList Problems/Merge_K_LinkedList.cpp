#include <iostream>
#include "../../DataStructure/LinkedList/LinkedList.h"
using namespace std;

template<class T>
void Merge_K_LinkedList_In_Order(LinkedList<T> &list){

}

int main(){
    LinkedList<int>lin1;

    lin1.insertFirst(1);
    lin1.insertLast(4);
    lin1.insertLast(5);

    LinkedList<int>lin2;

    lin2.insertLast(1);
    lin2.insertLast(3);
    lin2.insertLast(4);

    LinkedList<int>lin3;

    lin3.insertLast(2);
    lin3.insertLast(6);

    cout << lin1 << endl << lin2 << endl << lin3 << endl;

}

// [1, 3, 5, 7]
//    lin1.insertLast(1);
//    lin1.insertLast(3);
//    lin1.insertLast(5);
//    lin1.insertLast(7);

// [2, 4, 6, 8]
//    lin2.insertLast(2);
//    lin2.insertLast(4);
//    lin2.insertLast(6);
//    lin2.insertLast(8);

//    [0, 9, 10]

//lin3.insertLast(0);
//lin3.insertLast(9);
//lin3.insertLast(10);