#include "ArrayBasedList.h"


int main() {
    AList<int> list(5);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insertAt(1,0);
    list.replaceAt(77,0);
    list.print();
    cout<< list.maxListSize();



}
