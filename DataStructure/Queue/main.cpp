#include <iostream>
#include "Queue.h"
using namespace std;
int main()
{
    int x;
    Queue<int> a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    x = a.dequeue();
    a.print();
    cout << a.first() << endl;
    cout << "------------------" << endl;
    a.clear();
    a.print();
}