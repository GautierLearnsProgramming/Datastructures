//
// Created by gautier on 06/12/2021.
//

#ifndef DYNAMIC_ARRAY_IMPL
#define DYNAMIC_ARRAY_IMPL
#include "Vector.h"



template<typename T>
Vector<T>::~Vector() {
    *a_count -= 1;
    if(*a_count <= 0){
        delete[] a;
        delete a_count;
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T> &other):
a(other.a), a_count(other.a_count), size(other.size), capacity(other.capacity)
{
    *a_count += 1;
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
    if(&other != this){
        *a_count -= 1;
        if(*a_count <= 0){
            delete[] a;
            delete a_count;
        }

        a_count = other.a_count;
        *a_count += 1;
        a = other.a;
        size = other.size;
        capacity = other.capacity;
    }
    return *this;
}


template<typename T>
Vector<T>::Vector() {
    a = new T[1];
    a_count = new int;
    *a_count = 1;
    size = 0;
    capacity = 1;
}

template<typename T>
Vector<T>::Vector(T arr[], int size) {
    a_count = new int;
    *a_count = 1;
    capacity = 1;
    while (capacity < size){
        capacity = capacity << 1;
    }
    a = new T[capacity];
    for(int i = 0; i < size; i++){
        a[i] = arr[i];
    }
    this->size = size;
}

template<typename T>
int Vector<T>::getSize() {
    return this->size;
}

template<typename T>
int Vector<T>::getCapacity() {
    return this->current_capacity;
}

template<typename T>
bool Vector<T>::isEmpty() {
    return size == 0;
}

template<typename T>
T Vector<T>::get(int index) {
    return a[index];
}

template<typename T>
void Vector<T>::append(T item) {
    insertion();
    a[size - 1] = item;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, Vector<T> v) {
    os << "Size: " << v.size << std::endl;
    os << "Capacity: " << v.capacity << std::endl;
    os << "Content: ";
    for(int i = 0; i < v.size; i++){
        os << v.get(i) << " ";
    }
    os << std::endl;
    return os;
}

template<typename T>
void Vector<T>::resize(int new_capacity) {
    T *n = new T[new_capacity];
    for (int i = 0; i < size; i++){
        n[i] = a[i];
    }
    delete a;
    a = n;
    capacity = new_capacity;
}

template<typename T>
void Vector<T>::insert(int index, T item) {
    check_index_in_range(index);
    insertion();
    //Push every element after the index of one to the right
    for(int i = size; i >= index; i--){
        a[i] = a[i - 1];
    }
    //Set the element at index to be item
    a[index] = item;
}

template<typename T>
void Vector<T>::insertion() {
    if (size + 1 > capacity) resize(2 * capacity);
    size++;
}

template<typename T>
void Vector<T>::removal() {
    a[size] = NULL;
    if ((size - 1 <= capacity / 4) && (size - 1) > 0) resize(capacity / 2);
    size--;
}

template<typename T>
void Vector<T>::prepend(T item) {
    insert(0, item);
}

template<typename T>
T Vector<T>::pop() {
    T item = a[size - 1];
    removal();
    return item;
}

template<typename T>
void Vector<T>::removeIndex(int index) {
    check_index_in_range(index);
    for(int i = index; i < size; i++) {
        a[i] = a[i+1];
    }
    removal();
}

template<typename T>
void Vector<T>::check_index_in_range(int index) {
    if (index > size) throw std::out_of_range("Index is out of range of the current array");
}

template<typename T>
void Vector<T>::remove(T item) {
    for (int i = 0; i < size; i++){
        if(a[i] == item){
            removeIndex(i);
            i--;
        }
    }
}

template<typename T>
int Vector<T>::find(T item) {
    for (int i = 0; i < size; i++){
        if (a[i] == item){
            return i;
        }
    }
    return -1;
}

template<typename T>
void Vector<T>::set(int index, T item) {
    check_index_in_range(index);
    a[index] = item;
}

#endif