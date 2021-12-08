cmake_minimum_required(VERSION 3.19)
project(Datastructures)

set(CMAKE_CXX_STANDARD 14)

add_executable(Datastructures
        LinkedLists/linked_list_main.cpp LinkedLists/doubly_linked_list.h LinkedLists/doubly_linked_list_impl.h
        Vector/vector_main.cpp Vector/dynamicarray.h Vector/dynamicarray_impl.h main.cpp Vector/vector_main.h LinkedLists/linked_list_main.h)
