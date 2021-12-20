//
// Created by gautier on 13/12/2021.
//

#include "binarysearch.h"

int binarySearch(const int sortedArray[], int arraySize, int value){
    int lo = 0;
    int up = arraySize - 1;
    int mid = 0;
    int ev = 0;
    while(true){
        mid = (lo + up) / 2;
        ev = sortedArray[mid];
        if(ev == value) return mid;
        else if(ev > value){
            up = mid - 1;
        }
        else if (ev < value){
            lo = mid + 1;
        }
        if(lo >= up){
            return lo;
        }
    }
}

void binarySearchDemo(){
    int a[] = {11, 13, 17, 19, 25, 28, 35, 39, 40, 42, 45};
    std::cout << binarySearch(a, 11, 19) << std::endl;
    std::cout << binarySearch(a, 11, 35) << std::endl;
    std::cout << binarySearch(a, 11, 26) << std::endl;
    std::cout << binarySearch(a, 11, 34) << std::endl;
}