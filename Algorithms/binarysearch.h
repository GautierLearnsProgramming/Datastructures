//
// Created by gautier on 13/12/2021.
//

#ifndef DATASTRUCTURES_BINARYSEARCH_H
#define DATASTRUCTURES_BINARYSEARCH_H

#include <iostream>

/**
 * The binary search algorithm find the specified value and returns its index in sortedArray in O(log(n)) time, where
 * n is the number of integers in the sorted array.
 * In case the specified value is not in the array, the algorithm instead returns the closest match.
 * @param sortedArray - An array of increasing integers
 * @param arraySize  - The size of the array
 * @param value - The value we are looking for in the array
 * @return  - The index of the value in the sorted array
 */
int binarySearch(const int* sortedArray, int arraySize, int value);

void binarySearchDemo();

#endif //DATASTRUCTURES_BINARYSEARCH_H
