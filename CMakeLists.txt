cmake_minimum_required(VERSION 3.21)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure main.cpp)
add_executable(SingleLinkedList "DataStructure/LinkedList/main.cpp")
add_executable(DoubleLinkedList "DataStructure/DoublyLinkedList/main.cpp")
add_executable(Queue "DataStructure/Queue/main.cpp")
add_executable(Stack "DataStructure/Stack/main.cpp")