cmake_minimum_required(VERSION 3.19)
project(Datastructures)

set(CMAKE_CXX_STANDARD 17)

add_executable(Datastructures
        main.cpp
        LinkedLists/doubly_linked_list.h LinkedLists/doubly_linked_list.tpp
        Vector/Vector.h Vector/Vector.tpp
        Queues/static_queue.h Queues/static_queue.tpp
        Queues/DynamicQueue.h Queues/DynamicQueue.tpp
        HashTables/hashmap.h HashTables/hashmap.tpp Algorithms/binarysearch.cpp Algorithms/binarysearch.h
        BinaryTrees/binary_tree.h  BinaryTrees/binary_tree.tpp
        Heaps/max_heap.h Heaps/max_heap.tpp)
