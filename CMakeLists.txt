cmake_minimum_required(VERSION 3.19)
project(Datastructures)

set(CMAKE_CXX_STANDARD 14)

add_executable(Datastructures
        LinkedLists/main.cpp LinkedLists/doubly_linked_list.h LinkedLists/doubly_linked_list_impl.h)
