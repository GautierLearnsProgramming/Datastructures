//
// Created by gautier on 21/12/2021.
//

#ifndef DATASTRUCTURES_MAX_HEAP_H
#define DATASTRUCTURES_MAX_HEAP_H
#include "../Vector/Vector.h"
#include <iostream>
#include <cmath>



    template<typename T>
    class MaxHeap {
    public:
        // Constructors
        explicit MaxHeap(Vector<T>* unsorted);
        MaxHeap();

        // Methods
        bool isEmpty();
        void insert(T element);
        T getMax();
        T popMax();
        void remove(T element);
        void remove_at_index(int index);

        // Rule of three
        ~MaxHeap();
        MaxHeap(const MaxHeap<T>& other);
        MaxHeap& operator=(const MaxHeap& other);

        //Operators
        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const MaxHeap<U>& maxHeap);
    private:
        // Helpers
        int left(int index);
        int right(int index);
        int parent(int index);

        struct IndexedElement {
            int index;
            T* element;
        };
        IndexedElement max(IndexedElement el1, IndexedElement el2);

        void max_heapify(int index);

        // Fields
        Vector<T>* vector;
        int* vector_count;
        int size;
    };

#include "max_heap.tpp"
#endif //DATASTRUCTURES_MAX_HEAP_H
