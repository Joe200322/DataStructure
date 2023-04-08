/*
Author : Youssef Refaat Samir
Faculty of computers and artificial intelegance
implementing Queue based on Linked list
*/
#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;
};
template <class T>
class Queue
{

    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        head = tail = NULL;
        size = 0;
    }
    void enqueue(T value)
    {
        // same implementation of insert at tail in linked list
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
        size++;
    }
    T dequeue()
    {
        // same implementation of remove first in linked list but the difference is we return the value of the head first
        T element;
        if (head == NULL)
        {
            cout << "can't remove bacuase Linked List is empty " << endl;
        }
        else if (head->next == NULL)
        {
            element = head->data;
            delete head;
            tail = head = NULL;
        }
        else
        {
            element = head->data;
            Node<T> *current = new Node<T>;
            current = head;
            head = head->next;
            delete current;
        }
        size--;
        return element;
    }
    T first()
    {
        return head->data;
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    int Size()
    {
        return size;
    }
    void clear()
    {
        if (head == NULL)
        {
            cout << "Queue is Emplty." << endl;
            return;
        }
        Node<T> *current = new Node<T>;
        while (head != NULL)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    void print()
    {

        if (head == NULL)
        {
            cout << "Queue Is Empty." << endl;
        }
        else
        {
            Node<T> *newNode = new Node<T>;
            newNode = head;
            cout << "[";
            while (newNode != NULL)
            {
                cout << newNode->data;
                if (newNode->next != NULL)
                {
                    cout << " - ";
                }
                newNode = newNode->next;
            }
            cout << "]" << endl;
        }
    }
};