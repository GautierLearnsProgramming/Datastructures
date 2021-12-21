cmake_minimum_required(VERSION 3.19)
project(Datastructures)

set(CMAKE_CXX_STANDARD 14)

add_executable(Datastructures
        main.cpp
        LinkedLists/linked_list_main.cpp LinkedLists/doubly_linked_list.h LinkedLists/doubly_linked_list.tpp
        Vector/vector_main.cpp Vector/DynamicArray.h Vector/dynamicarray_impl.h
        Vector/vector_main.h LinkedLists/linked_list_main.h
        Queues/static_queue.h Queues/static_queue.tpp
        Queues/dynamic_queue.h Queues/dynamic_queue.tpp Queues/static_queue_demo.cpp Queues/dynamic_queue_demo.cpp
        HashTables/hashmap.h HashTables/hashmap.tpp Algorithms/binarysearch.cpp Algorithms/binarysearch.h
        BinaryTrees/binary_tree.h  BinaryTrees/binary_tree.tpp
        Heaps/max_heap.h Heaps/max_heap.tpp)
