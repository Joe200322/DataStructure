#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;
};
template <class T>
class DoublyLinkedList
{

    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    DoublyLinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void insertAtHead(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else
        {
            newNode->next = head;
            newNode->prev = NULL;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void insertAtTail(T value)
    {
        if (head == NULL)
        {
            insertAtHead(value);
        }
        else
        {
            Node<T> *newNode = new Node<T>;
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }
    void insertAt(T value, int index)
    {
        if (index > size || index < 0)
        {
            cout << "ERROR: Index Out Of Range" << endl;
        }
        else
        {
            if (index == 0)
            {
                insertAtHead(value);
            }
            else if (index == size)
            {
                insertAtTail(value);
            }
            else
            {
                Node<T> *current = new Node<T>;
                current = head;
                Node<T> *newNode = new Node<T>;
                newNode->data = value;
                for (int i = 1; i < index; i++)
                {
                    current = current->next;
                }
                current->next->prev = newNode;
                newNode->next = current->next;
                newNode->prev = current;
                current->next = newNode;
                size++;
            }
        }
    }
    void forwardTraversal()
    {
        Node<T> *current = new Node<T>;
        current = head;
        cout << "[";
        while (current != NULL)
        {
            cout << current->data;
            if (current->next != NULL)
            {
                cout << "->";
            }
            current = current->next;
        }
        cout << "]" << endl;
    }
    void removeAtHead()
    {
        if (head == NULL)
        {
            cout << "List is already empty" << endl;
        }
        else if (head->next = NULL)
        {
            delete head;
            tail = head = NULL;
        }
        else
        {
            Node<T> *newNode = head;
            head = head->next;
            head->prev = NULL;
            delete newNode;
        }
        size--;
    }
    void removeAtTail()
    {
        if (head == NULL)
        {
            cout << "List is already empty" << endl;
        }
        else if (head->next == NULL)
        {
            delete head;
            tail = head = NULL;
        }
        else
        {
            Node<T> *newNode = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete newNode;
        }
        size--;
    }
    void removeAt(int index)
    {
        if (index > size - 1 || index < 0)
        {
            cout << "ERROR: Index Out Of Range" << endl;
        }
        else
        {
            if (index == 0)
            {
                removeAtHead();
            }
            else if (index == size - 1)
            {
                removeAtTail();
            }
            else
            {
                Node<T> *current = head;
                Node<T> *deletedNode = new Node<T>;
                for (int i = 1; i < index; i++)
                {
                    current = current->next;
                }
                deletedNode = current->next;
                current->next->next->prev = current;
                current->next = deletedNode->next;
                delete deletedNode;
                size--;
            }
        }
    }
    T retrieveAt(int index)
    {
        if (index > size - 1 || index < 0)
        {
            cout << "ERROR: Index Out Of Range" << endl;
            return 0;
        }
        else
        {
            if (index == 0)
            {
                return head->data;
            }
            else if (index == size - 1)
            {
                return tail->data;
            }
            else
            {
                Node<T> *current = head;
                for (int i = 1; i <= index; i++)
                {
                    current = current->next;
                }
                return current->data;
            }
        }
    }
    void replaceAt(T newValue, int index)
    {
        if (index > size - 1 || index < 0)
        {
            cout << "ERROR: Index Out Of Range" << endl;
        }
        else
        {
            if (index == 0)
            {
                head->data = newValue;
            }
            else if (index == size - 1)
            {
                tail->data = newValue;
            }
            else
            {
                Node<T> *current = head;
                for (int i = 1; i <= index; i++)
                {
                    current = current->next;
                }
                current->data = newValue;
            }
        }
    }
    bool isExist(T value)
    {
        Node<T> *current = head;
        while (current != NULL)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    bool isItemAtEqual(T value, int index)
    {
        if (index < size && index >= 0)
        {
            if (index == 0)
            {
                if (head->data == value)
                {
                    return true;
                }
            }
            else if (index == size - 1)
            {
                if (tail->data == value)
                {
                    return true;
                }
            }
            else
            {
                Node<T> *current = head;
                for (int i = 1; i <= index; i++)
                {
                    current = current->next;
                }
                if (current->data == value)
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            cout << "ERROR: Index Out Of Range" << endl;
            return 0;
        }
    }
    void swap(int index1, int index2)
    {

        if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size)
        {
            if (index1 == index2)
            {
                cout << "elements are equal " << endl;
            }
            else
            {
                Node<T> *first = new Node<T>;
                Node<T> *second = new Node<T>;
                Node<T> *firstB = new Node<T>;
                Node<T> *firstA = new Node<T>;
                Node<T> *secondB = new Node<T>;
                Node<T> *secondA = new Node<T>;

                // if the element are head and tail
                if ((index1 == 0 && index2 == size - 1) || (index2 == 0 && index1 == size - 1))
                {
                    cout << "====" << endl;
                    first = head;
                    second = tail;
                    firstA = head->next;
                    secondB = tail->prev;
                    // swap
                    first->next = NULL;
                    first->prev = secondB;
                    secondB->next = first;
                    second->prev = NULL;
                    second->next = firstA;
                    firstA->prev = second;
                    head = second;
                    tail = first;
                }
                // if one of the elements is head
                else if ((index1 == 0 && index2 < size - 1) || (index2 == 0 && index1 < size - 1))
                {
                    first = second = head;
                    int index;
                    if (index1 != 0)
                    {
                        index = index1;
                    }
                    else if (index2 != 0)
                    {
                        index = index2;
                    }
                    for (int i = 1; i <= index; i++)
                    {
                        second = second->next;
                    }
                    firstA = first->next;
                    secondB = second->prev;
                    secondA = second->next;
                    // swap
                    first->prev = secondB;
                    first->next = secondA;
                    firstA->prev = second;
                    second->next = firstA;
                    second->prev = NULL;
                    secondB->next = first;
                    head = second;
                }
                // if one of the is tail
                else if ((index1 == size - 1 && index2 > 0) || (index2 == size - 1 && index1 > 0))
                {
                    int index;
                    second = tail;
                    first = head;
                    secondB = second->prev;

                    if (index1 != size - 1)
                    {
                        index = index1;
                    }
                    else if (index2 != size - 1)
                    {
                        index = index2;
                    }
                    for (int i = 1; i <= index; i++)
                    {
                        first = first->next;
                    }
                    firstA = first->next;
                    firstB = first->prev;
                    // swap
                    first->next = NULL;
                    first->prev = secondB;
                    secondB->next = first;
                    second->next = firstA;
                    second->prev = firstB;
                    firstA->prev = firstB->next = second;
                    tail = first;
                }
                else
                {
                    first = second = head;
                    for (int i = 1; i <= index1; i++)
                    {
                        first = first->next;
                    }
                    for (int i = 1; i <= index2; i++)
                    {
                        second = second->next;
                    }
                    firstB = first->prev;
                    firstA = first->next;
                    secondB = second->prev;
                    secondA = second->next;
                    // swapinng
                    first->next = secondA;
                    first->prev = secondB;
                    second->next = firstA;
                    second->prev = firstB;
                    firstB->next = second;
                    firstA->prev = second;
                    secondA->prev = first;
                    secondB->next = first;
                }
            }
        }

        else
        {
            cout << "ERROR: Index Out Of Range" << endl;
        }
    }
    void reverse()
    {
        Node<T> *prev, *current, *after = new Node<T>;
        prev = NULL;
        current = head;
        after = current->next;
        while (after != NULL)
        {
            after = current->next;
            current->next = prev;
            current->prev = after;
            prev = current;
            current = after;
        }
        // current->next = prev;
        // current->prev = NULL;
        head = prev;
        current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        tail = current;
    }
    bool isEmpty()
    {
        if (size == 0)
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
        Node<T> *current = head;
        Node<T> *prev = NULL;
        while (current != NULL)
        {
            prev = current;
            current = current->next;
            delete prev;
        }
        head = tail = NULL;
    }
    void backwardTraversal()
    {
        Node<T> *current = tail;
        cout << "[";
        while (current != NULL)
        {
            cout << current->data;
            if (current->prev != NULL)
            {
                cout << "->";
            }
            current = current->prev;
        }
        cout << "]" << endl;
    }
};