//
// Created by gautier on 08/12/2021.
//

#include "Vector/Vector.h"
#include "Queues/static_queue.h"
#include "Queues/DynamicQueue.h"
#include "HashTables/hashmap.h"
#include "Algorithms/binarysearch.h"
#include "BinaryTrees/binary_tree.h"
#include "Heaps/max_heap.h"



void print(int i) {
    std::cout << i << " ";
}

int main() {
    int arr[] = {5, 6, 3, 4, 8, 10, 12, 3, 4, 5, 7, 19};
    auto *vector = new Vector<int>(arr, 12);
    auto *heap = new MaxHeap<int>(vector);
    std::cout << *heap << std::endl;
    heap->remove_at_index(0);
    std::cout << *heap << std::endl;
    heap->remove_at_index(10);
    std::cout <<*heap << std::endl;
    heap->insert(17);
    std::cout <<*heap <<std::endl;
    heap->insert(1);
    heap->insert(11);
    std::cout << *heap << std::endl;
    heap->remove(17);
    std::cout << *heap << std::endl;
    heap->popMax();
    std::cout << *heap << std::endl;
    std::cout << "max " << heap->getMax() << std::endl;

    auto* to_sort = new Vector<int>(arr, 12);
    auto* sorted = heap_sort(to_sort);
    std::cout << *sorted;
    return 0;
}
