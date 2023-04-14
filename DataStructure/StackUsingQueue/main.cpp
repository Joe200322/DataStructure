#include <iostream>
#include "StackUsingQueue.h"
using namespace std;
int main()
{
    StackUsingQueue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.print();
    cout<<"-------------------------"<<endl;
    a.pop();
    a.print();
    cout<<"-------------------------"<<endl;
    cout <<"Top: " <<a.top();
}