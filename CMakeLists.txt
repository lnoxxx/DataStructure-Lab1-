cmake_minimum_required(VERSION 3.26)
project(DataStructure_Lab1_)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructure_Lab1_ main.cpp
        HashMap/hashMap.h
        HashMap/hashMap.cpp
        BinarySearchTree/BinarySearchTree.h
        BinarySearchTree/BinarySearchTree.cpp
        SingleLinkedList/SinglyLinkedList.h
        SingleLinkedList/SinglyLinkedList.cpp
        DoubleLinkedList/DblLnkdList.h
        DoubleLinkedList/DblLnkdList.cpp
        Array/Array.h
        Array/Array.cpp)
