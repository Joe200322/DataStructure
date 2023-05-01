
#ifndef CIRCULAR_LINKED_LIST_CIRCULARLINKEDLIST_H
#define CIRCULAR_LINKED_LIST_CIRCULARLINKEDLIST_H
#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* next;
};
template <class T>
class circularLinkedList{
private:
    int size;
    Node* head ;
    Node* tail ;
public:

    circularLinkedList(){
        size = 0;
        head =new Node();
        tail = new Node();
        head->next = tail;
        tail->next = head;

    }
    void insertInHead(T element){
        if (size == 0) {
            Node *newNode = new Node();
            newNode->data = element;
            newNode->next = head;
            head = newNode;
            head->next = tail;
            tail->next = head;
            size++;

        }
        else {
            Node* current ;
            current = head;
            Node *newNode = new Node();
            newNode->data = element;
            newNode->next = head;
            head = newNode;
            tail->next = head;
            size++;
            for (int i = 0; i < size-2; i++) {
                current = current->next;
            }
            tail = current;
        }

    }
    void insertAtEnd(T element){
        Node* current ;
        current = head;
        Node *newNode = new Node();
        newNode->data = element;
        newNode->next = head;
        tail = newNode;
        size++; for (int i = 0; i < size-2; i++) {
            current = current->next;
        }
        current->next = tail;


    }
    void insertAt(T element , int index){
        Node* current ;
        current = head;
        for (int i = 0; i < index-1; i++){
            current = current->next;
        }
        if (index ==0){

            insertInHead(element);
        }
        else {
            Node *newNode = new Node();
            newNode->data = element;
            newNode->next = current->next;
            current->next = newNode;
            size++;

        }


    }
    void removeAtHead(){
        head = head->next;
        size--;
    }
    void removeAtEnd(){
        Node* current = head;
        for (int i = 0; i < size-2;i++){
            current = current->next;
        }
        current->next = head;
        size--;
    }
    void removeAt(int index){
        Node* current = head;

        if (index == 0 ){
            removeAtHead();
        }
        else{
            for (int i = 0 ; i < index-1;i++){
                current =current->next;
            }
        }
        current->next = current->next->next;
        size--;
    }
    T retrieveAt(int index){
        Node* current = head;
        for (int i = 0 ; i < index;i++){
            current =current->next;
        }
        return current->data ;
    }
    void replaceAt(T element , int index){
        Node* current = head;
        for (int i = 0 ; i < index;i++){
            current = current->next;
        }
        current ->data =element;
    }
    bool isExist(T element){
        Node* current = head;
        for (int i = 0 ; i < size;i++){
            if(element == current->data){
                return true;
            }
            else{
                current =current->next;
            }
        }
        return false;
    }
    bool isItemIsEqual(T element , int index){
        Node* current = head;
        for (int i = 0 ; i < index;i++){
            current =current->next;
        }
        if (current->data == element){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(size==0){
            return true;
        } else
            return false;
    }
    int circularLinkedListSize(){
        return size;
    }
    void clear(){
        size = 0;
        delete head;

    }



    void swap( int firstIndex,int secIndex) {
        Node *first;
        first = head;
        if(secIndex == size-1){

            for (int i = 0; i < firstIndex-1; i++) {
                first = first->next;
            }
            Node *second;
            second = first;
            for (int i = firstIndex; i < secIndex; i++) {
                second = second->next;
            }
            Node *waiting;
            waiting = first->next;


            first->next = second->next;
            second->next->next = first->next->next;
            second->next = waiting;
            first->next->next = waiting->next;
            tail = second->next;




        }



        else {

            for (int i = 0; i < firstIndex - 1; i++) {
                first = first->next;
            }
            Node *second;
            second = first;
            for (int i = firstIndex; i < secIndex; i++) {
                second = second->next;
            }
            Node *waiting;
            waiting = first->next;


            first->next = second->next;
            second->next->next = first->next->next;
            second->next = waiting;
            first->next->next = waiting->next;

        }



    }


    void print () {
        Node *current;
        current = head;
        for (int i =0; i<size; i++){
            cout << current->data << endl;
            current= current->next;

        }
    }
    


};


#endif //CIRCULAR_LINKED_LIST_CIRCULARLINKEDLIST_H
