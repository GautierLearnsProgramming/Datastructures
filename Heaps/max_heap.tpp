#ifndef MAX_HEAP_IMPL
#define MAX_HEAP_IMPL

#include "max_heap.h"

//Constructors
template<typename T>
MaxHeap<T>::MaxHeap() {
    vector = new Vector<T>();
    size = 0;
    vector_count = new int;
    *vector_count = 1;
}

template<typename T>
MaxHeap<T>::MaxHeap(Vector<T>* unsorted) {
    vector = unsorted;
    size = unsorted->getSize();
    vector_count = new int;
    *vector_count = 1;

    for(int i = size/2; i >= 0; i--){
        max_heapify(i);
    }
}

// Methods
template<typename T>
bool MaxHeap<T>::isEmpty() {
    return size == 0;
}

template<typename T>
void MaxHeap<T>::remove_at_index(int index) {
    // Swap the element at the index with the last element of the heap
    if(index > size){
        throw std::out_of_range("Cannot delete index out of range");
    }
    T value = vector->get(index);
    vector->set(index, vector->get(size-1));
    vector->set(size-1, value);
    // Delete the last element of the heap
    vector->removeIndex(size-1);
    size--;
    // heapify at the index
    max_heapify(index);
}

template<typename T>
void MaxHeap<T>::insert(T element) {
    vector->append(element);
    size++;
    bool element_in_place = false;
    int element_index = size - 1;
    while(!element_in_place){
        // If the parent is bigger than the element, swap it with the element
        if(vector->get(parent(element_index)) < element){
            vector->set(element_index, vector->get(parent(element_index)));
            vector->set(parent(element_index), element);
            element_index = parent(element_index);
        }
        // Otherwise, the element is in place and we can stop the algorithm
        else {
            element_in_place = true;
        }
        // If the element is now the root, we can stop the algorithm
        if(element_index == 0){
            element_in_place = true;
        }
    }
}

template<typename T>
T MaxHeap<T>::getMax() {
    if(size > 0){
        return vector->get(0);
    }
    else {
        throw std::out_of_range("The heap is empty");
    }
}

template<typename T>
T MaxHeap<T>::popMax() {
    if(size > 0){
        T value = vector->get(0);
        remove_at_index(0);
        return value;
    }
    else {
        throw std::out_of_range("The heap is empty");
    }
}

// Naive implementation, but any implementation will be O(n)
template<typename T>
void MaxHeap<T>::remove(T element) {
    for(int i = 0; i < size; i++){
        if(element == vector->get(i)){
            remove_at_index(i);
            return;
        }
    }
}

template<typename T>
int MaxHeap<T>::getSize() {
    return size;
}

// Operators
template<typename U>
std::ostream &operator<<(std::ostream &os, const MaxHeap<U> &maxHeap) {
    int maxContain = 1;
    int contain = 1;
    for (int i = 0; i < maxHeap.size; i++){
        os << maxHeap.vector->get(i) << " ";
        contain--;
        if(contain == 0){
            os << std::endl;
            maxContain *= 2;
            contain = maxContain;
        }
    }
    return os;
}

// Helpers
template<typename T>
int MaxHeap<T>::left(int i){
    return 2*i + 1;
}

template<typename T>
int MaxHeap<T>::right(int i){
    return 2*(i + 1);
}

template<typename T>
int MaxHeap<T>::parent(int i){
    return (i+1)/2 - 1;
}

template<typename T>
typename MaxHeap<T>::IndexedElement MaxHeap<T>::max(MaxHeap::IndexedElement el1, MaxHeap::IndexedElement el2) {
    if(el2.element == nullptr) return el1;
    if(el1.element == nullptr) return el2;
    if(*el1.element >= *el2.element) return el1;
    return el2;
}

template<typename T>
void MaxHeap<T>::max_heapify(int i){
    // Check if the element at index i is lower than either of its children
    T element_value;
    T left_value;
    T right_value;
    IndexedElement element = {i, nullptr};
    IndexedElement left_child = {left(i), nullptr};
    IndexedElement right_child = {right(i), nullptr};
    if(i < size) {
        element_value = vector->get(i);
        element.element = &element_value;
    } else {
        return;
    }
    if(left(i) < size){
        left_value = vector->get(left(i));
        left_child.element = &left_value;
    } else {
        return;
    }
    if(right(i) < size){
        right_value = vector->get(right(i));
        right_child.element = &right_value;
    }
    // If the element is lower than either child, swap with the biggest child.
    // If a swap occurred, heapify the index where the element now is.
    if(max(element, left_child).element == left_child.element || max(element, right_child).element == right_child.element){
        IndexedElement to_swap = max(left_child, right_child);
        vector->set(element.index, *to_swap.element);
        vector->set(to_swap.index, *element.element);
        max_heapify(to_swap.index);
    }
}

// Rule of three
template<typename T>
MaxHeap<T>::~MaxHeap() {
    *vector_count -= 1;
    if(*vector_count <= 0){
        delete vector;
        delete vector_count;
    }
}

template<typename T>
MaxHeap<T>::MaxHeap(const MaxHeap<T> &other):
size(other.size), vector(other.vector), vector_count(other.vector_count)
{
    *vector_count += 1;
}

template<typename T>
MaxHeap<T> &MaxHeap<T>::operator=(const MaxHeap &other) {
    if(&other != this){
        *vector_count -= 1;
        if(*vector_count <= 0){
            delete vector;
            delete vector_count;
        }

        size = other.size;
        vector = other.vector;
        vector_count = other.vector_count;
        *vector_count += 1;
    }
    return *this;
}

// Non class methods
template<typename T>
Vector<T>* heap_sort(Vector<T>* unsorted){
    auto* heap = new MaxHeap<T>(unsorted);
    auto* ret = new Vector<T>();
    while(!heap->isEmpty()){
        ret->append(heap->popMax());
    }
    delete heap;
    return ret;
}

#endif