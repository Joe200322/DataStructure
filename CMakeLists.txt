cmake_minimum_required(VERSION 3.21)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure main.cpp)
add_executable(SingleLinkedList "DataStructure/LinkedList/main.cpp")
add_executable(DoubleLinkedList "DataStructure/DoublyLinkedList/main.cpp")
add_executable(Queue "DataStructure/Queue/main.cpp")
add_executable(Stack "DataStructure/Stack/main.cpp")
add_executable(Merge_K_Linked_List "Algorithms/LinkedList Problems/Merge_K_LinkedList.cpp")
add_executable(Generate_Binary_Numbers_from_1_to_n "Algorithms/Queue Problems/Generate_Binary_Numbers_from_1_to_n.cpp")