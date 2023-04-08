#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack<string> stack1(1);
    Stack<int> stack2;
    stack1.push("m");
    stack1.push("a");
    stack1.push("r");
    stack1.push("i");
    stack1.push("o");

    cout << stack1 << endl;

    cout << "top : " << stack1.top() << endl;

    cout << stack1[0] << endl;
    cout << stack1[1] << endl;
    cout << stack1[2] << endl;
    cout << stack1[3] << endl;

    cout << stack1.pop() << endl;
    cout << stack1.pop() << endl;
    cout << stack1.pop() << endl;
    cout << stack1.pop() << endl;
    cout << stack1.pop() << endl;

    cout << "is empty : " << stack1.isEmpty() << endl;

    cout << "size : " << stack1.size() << endl;

    cout << stack1 << endl;


    stack2.push(0);
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);
    stack2.push(4);
    stack2.push(5);

    cout << "size : " << stack2.size() << endl;


    cout << stack2 << endl;

    stack2.clear();


    cout << "size : " << stack2.size() << endl;
    cout << stack2 << endl;


    return 0;
}
