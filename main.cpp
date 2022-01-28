//
// Created by gautier on 08/12/2021.
//

#include <iostream>
#include "Vector/Vector.h"
#include "Queues/static_queue.h"
#include "Queues/DynamicQueue.h"
#include "HashTables/hashmap.h"
#include "Algorithms/binarysearch.h"
#include "BinaryTrees/binary_tree.h"
#include "Heaps/max_heap.h"
#include "Algorithms/sorting.h"
#include "Algorithms/shuffle.h"
#include "Algorithms/stopwatch.h"

void printVector(const std::vector<int>& v) {
    for(int i : v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    sorting_test(1000000, false, false, true, true);
    return 0;
}
