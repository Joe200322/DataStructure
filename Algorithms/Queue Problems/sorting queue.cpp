#include <iostream>
#include "../../DataStructure/Queue/Queue.h"
using namespace std;
 Queue<int> sortQueue(Queue<int> list){
     Queue<int> newQueue;
     Queue<int> tempQueue;
     int min;
     int temp;
     while (!list.isEmpty()) {
         min = list.dequeue();
         tempQueue.clear();
         while (!list.isEmpty()) {
              temp = list.dequeue();
             if (min > temp) {
                 tempQueue.enqueue(min);
                 min = temp;
             } else {
                 tempQueue.enqueue(temp);
             }
         }
         newQueue.enqueue(min);
         list = tempQueue;
     }
     return newQueue;
 }

int main() {
    Queue<int> list ;
    Queue<int> list2 ;
   list.enqueue(3);
    list.enqueue(15);
    list.enqueue(2);
    list.enqueue(4);
    list2 = sortQueue(list);
    list2.print();

}
