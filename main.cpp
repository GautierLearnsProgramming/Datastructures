//
// Created by gautier on 08/12/2021.
//

#include "LinkedLists/linked_list_main.h"
#include "Vector/vector_main.h"
#include "Vector/Vector.h"
#include "Queues/static_queue.h"
#include "Queues/DynamicQueue.h"
#include "HashTables/hashmap.h"
#include "Algorithms/binarysearch.h"
#include "BinaryTrees/binary_tree.h"

void print(int i){
    std::cout << i << " ";
}

int main(){
    auto* binaryTree = new gb_datastructures::BinaryTree<int>();
    binaryTree->insert(5);
    std::cout << *binaryTree;
    binaryTree->insert(3);
    binaryTree->insert(8);
    std::cout << *binaryTree;
    binaryTree->insert(1);
    binaryTree->insert(6);
    std::cout << *binaryTree;
    binaryTree->remove(3);
    std::cout << *binaryTree;
    binaryTree->remove(5);
    std::cout << *binaryTree;
    binaryTree->insert(4);
    binaryTree->insert(3);
    binaryTree->insert(5);
    binaryTree->insert(7);
    binaryTree->insert(-1);
    binaryTree->insert(-2);
    binaryTree->insert(2);
    binaryTree->insert(9);
    std::cout << *binaryTree;
    binaryTree->remove(1);
    std::cout << *binaryTree;
    return 0;
}