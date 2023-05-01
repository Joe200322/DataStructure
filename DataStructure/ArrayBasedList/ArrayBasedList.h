
#ifndef ARRAYBASEDLIST_H
#define ARRAYBASEDLIST_H
#include <iostream>
using namespace std;

template<class T>
class AList{
private:
    int maxSize;
    int size;
    T *array;
public:
    AList(){
        size = 0;
        array = new T [size];
    }
    AList(int size){
        this-> maxSize = size;
        this->size = 0;
        array = new T [maxSize];
    }
    void insert(T element){
        size++;
        T *newArray = new T [size];
        for (int i = 0; i < size;i++){
            newArray[i] = array[i];
        }
        newArray[size-1] = element;
        array = newArray;

    }
    void insertAt(T elemnt , int index){
        size++;
        T *newArray = new T [size];
        for (int i = 0; i < index;i++){
            newArray[i] = array[i];
        }
        newArray[index] = elemnt;
        for (int i = index; i < size;i++){
            newArray[i+1] = array[i];
        }
        array = newArray;

    }
    T retrieveAt(int index){
        for(int i = 0; i<size; i++){
            if(index==i){
                return array[i];
            }
        }
    }
    void removeAt(int index){
        size--;
        T *newArray = new T [size];
        for (int i = 0; i < index;i++){
            newArray[i] = array[i];
        }

        for (int i = index; i < size;i++){
            newArray[i] = array[i+1];
        }
        array = newArray;


    }
    void replaceAt(T element , int index){
        for(int i = 0; i<size; i++){
            if(index == i){
                array[i] = element;
            }
        }
    }
    bool isItemAtEqual(T element , int index){
        for(int i = 0; i<size; i++){
            if(index == i && element == array[i]){
                return true;
            } else{
                return false;
            }
        }
    }
    bool isEmpty(){
        if (size == 0){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if (maxSize == size){
            return true;
        } else{
            return false;
        }

    }
    int listSize(){
        return size;
    }
    int maxListSize(){
        return maxSize;

    }
    void clear(){
        delete array;
    }






    void print(){
        for (int i = 0; i < size;i++){
            cout<< array[i]<<endl;
        }
    }
};

#endif //CIRCULAR_LINKED_LIST_ARRAYBASEDLIST_H
