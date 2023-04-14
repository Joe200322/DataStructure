#include <iostream>
#include "Queue.h"
using namespace std;
template <class T>
class StackUsingQueue
{
private:
    Queue<T> stackQ1;
    Queue<T> stackQ2;
    T topElement;

public:
    void push(T element)
    {
        stackQ1.enqueue(element);
        topElement = element;
    }
    T pop()
    {
        if (stackQ1.isEmpty())
        {
            cout << "ERROR: Stack Is Already Empty" << endl;
            return -1;
        }
        else
        {
            while (stackQ1.Size() > 1)
            {
                T element = stackQ1.dequeue();
                stackQ2.enqueue(element);
                if (stackQ1.Size() == 1)
                {
                    topElement = element;
                }
            }
            T val = stackQ1.dequeue();
            swap(stackQ1, stackQ2);
            return val;
        }
    }
    void print()
    {
        stackQ1.print();
    }
    bool isEmpty()
    {
        return stackQ1.isEmpty();
    }
    T top()
    {
        return topElement;
    }
};