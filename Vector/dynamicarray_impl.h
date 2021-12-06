//
// Created by gautier on 06/12/2021.
//

#include "dynamicarray.h"

namespace vect {

    template<typename T>
    dynamicarray<T>::dynamicarray() {
        a = new T[1];
        s = 0;
        c = 1;
    }

    template<typename T>
    dynamicarray<T>::dynamicarray(T arr[], int size) {
        c = 1;
        while (c < size){
            c = c<<1;
        }
        a = new T[c];
        for(int i = 0; i < size; i++){
            a[i] = arr[i];
        }
        s = size;
    }

    template<typename T>
    int dynamicarray<T>::size() {
        return this->current_size;
    }

    template<typename T>
    int dynamicarray<T>::capacity() {
        return this->current_capacity;
    }

    template<typename T>
    bool dynamicarray<T>::is_empty() {
        return s == 0;
    }

    template<typename T>
    T dynamicarray<T>::get(int index) {
        return a[index];
    }

    template<typename T>
    void dynamicarray<T>::append(T item) {
        insertion();
        a[s-1] = item;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, dynamicarray<T> v) {
        os << "Size: " << v.s << std::endl;
        os << "Capacity: " << v.c << std::endl;
        os << "Content: ";
        for(int i = 0; i < v.s; i++){
            os << v.get(i) << " ";
        }
        os << std::endl;
        return os;
    }

    template<typename T>
    void dynamicarray<T>::resize(int new_capacity) {
        T *n = new T[new_capacity];
        for (int i = 0; i < s; i++){
            n[i] = a[i];
        }
        delete a;
        a = n;
        c = new_capacity;
    }

    template<typename T>
    void dynamicarray<T>::insert(int index, T item) {
        check_index_in_range(index);
        insertion();
        //Push every element after the index of one to the right
        for(int i = s; i >= index; i--){
            a[i] = a[i - 1];
        }
        //Set the element at index to be item
        a[index] = item;
    }

    template<typename T>
    void dynamicarray<T>::insertion() {
        if (s + 1 > c) resize(2 * c);
        s++;
    }

    template<typename T>
    void dynamicarray<T>::removal() {
        a[s] = NULL;
        if ((s - 1 <= c/4) && (s-1) > 0) resize(c/2);
        s--;
    }

    template<typename T>
    void dynamicarray<T>::prepend(T item) {
        insert(0, item);
    }

    template<typename T>
    T dynamicarray<T>::pop() {
        T item = a[s - 1];
        removal();
        return item;
    }

    template<typename T>
    void dynamicarray<T>::removeIndex(int index) {
        check_index_in_range(index);
        for(int i = index; i < s; i++) {
            a[i] = a[i+1];
        }
        removal();
    }

    template<typename T>
    void dynamicarray<T>::check_index_in_range(int index) {
        if (index > s) throw std::out_of_range("Index is out of range of the current array");
    }

    template<typename T>
    void dynamicarray<T>::remove(T item) {
        for (int i = 0; i < s; i++){
            if(a[i] == item){
                removeIndex(i);
                i--;
            }
        }
    }

    template<typename T>
    int dynamicarray<T>::find(T item) {
        for (int i = 0; i < s; i++){
            if (a[i] == item){
                return i;
            }
        }
        return -1;
    }
}