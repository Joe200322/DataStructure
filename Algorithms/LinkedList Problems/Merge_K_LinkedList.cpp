#include <iostream>
#include "../../DataStructure/LinkedList/LinkedList.h"
#include <vector>
using namespace std;

// class that had all functions to sort algorithm
class Algorithm{
private:
    // A utility function to swap two elements

    template<class T>
    static void swap(T& a, T& b)
    {
        T t = a;
        a = b;
        b = t;
    }

    /* This function takes last element as pivot, places the pivot element
    at its correct position in sorted array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right of pivot */
    template<class T>
    static int partition(vector<T>& arr, int low, int high)
    {
        T pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot)
            {
                i++;    // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

public:
    /* The main function that implements QuickSort
 arr --> Vector to be sorted,
 low  --> Starting index,
 high  --> Ending index */
    template<class T>
    static void quickSort(vector<T>& arr, int low, int high)
    {
        if (low < high)
        {
            // pi is partitioning index, arr[p] is now at right place
            int pi = partition(arr, low, high);

            // Separately sort elements before and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};

class MergeOrderList {
private:
    // function to put elements from linked list to vector
    template<class T>
    static void putElementsOfListInVector(vector<T> &vec, LinkedList<T> list) {
        Node<T> *node = list.front();
        while (node != nullptr) {
            vec.push_back(node->value);
            node = node->next;
        }
    }

public:
    // function merge that make the merge operation
    template<class T>
    static void merge_K_LinkedListInOrder(LinkedList<T> &orderedLinkedList, const vector<LinkedList<T>> &lists) {
        // vector that holds all elements that in all lists
        vector<T> elementsInLists;

        // put all elements in all lists in another vector
        for (int i = 0; i < lists.size(); ++i) {
            putElementsOfListInVector(elementsInLists, lists[i]);
        }

        // sort the vector with quick sort algorithm
        Algorithm::quickSort(elementsInLists, 0, elementsInLists.size() - 1);

        // put the vector after sorted in the ordered linked list
        for (int i = 0; i < elementsInLists.size(); ++i) {
            orderedLinkedList.insertLast(elementsInLists[i]);
        }

    }
};

int main(){

    LinkedList<int>list1, list2, list3;

    vector<LinkedList<int>> vec;


    list1.insertFirst(1);
    list1.insertLast(4);
    list1.insertLast(5);

    list2.insertLast(1);
    list2.insertLast(3);
    list2.insertLast(4);

    list3.insertLast(2);
    list3.insertLast(6);


//    list1.insertLast(1);
//    list1.insertLast(3);
//    list1.insertLast(5);
//    list1.insertLast(7);
//
//    list2.insertLast(2);
//    list2.insertLast(4);
//    list2.insertLast(6);
//    list2.insertLast(8);
//
//    list3.insertLast(0);
//    list3.insertLast(9);
//    list3.insertLast(10);


    LinkedList<int> orderedLinkedList;


    vec.push_back(list1);
    vec.push_back(list2);
    vec.push_back(list3);

    MergeOrderList::merge_K_LinkedListInOrder(orderedLinkedList, vec);

    cout << orderedLinkedList << endl;
    cout << list1 << endl;
    cout << list2 << endl;
    cout << list3 << endl;
}
