//
// Created by gautier on 06/12/2021.
//
#include <iostream>

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

namespace vect{

template <typename T>

class dynamicarray {
public:
    /**
     * Get a new dynamicarray with an empty array of initial capacity 1
     */
    dynamicarray();
    /**
     * Get a new dynamicarray initialized with the specified array
     */
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, dynamicarray<U> v);

    dynamicarray(T arr[], int size);
    /**
     * @return The current size of the array
     */

    int size();
    /**
     * Get the underlying array's current capacity
     * @return An int representing the underlying array's capacity
     */
    int capacity();
    /**
     * Check is the a is empty
     * @return A bool, true if the array is empty, false otherwise
     */
    bool is_empty();
    /**
     * Get the item at the specified index
     * @param index to lookup
     * @return the item at the specified index
     * @throw std:out_of_range if the index is above the current size of the array
     */
    T get(int index);
    /**
     * Add the specified item at the end of the array
     * @param item
     */
    void append(T item);
    /**
     * Insert the specified item at the specified index.
     * @param index
     * @param item
     * @throws std:out_of_range if the index is more than the current size
     */
   void insert(int index, T item);
    /**
     * Insert the specified item at the beginning of the array
     * @param item
     */
  void prepend(T item);
    /**
     * Get the last item and remove it from the array
     * @return the last item of the array
     */
   T pop();
    /**
     * Remove the item at the specified index
     * @param index
     */
   void removeIndex(int index);
    /**
     * Remove any item matching the specified item
     * @param item
     */
   void remove(T item);
    /**
     * Return the index of the first item matching the specified index or -1 if no item matches the search
     * @param item
     * @return the index of the found item
     */
    int find(T item);

private:
    /**
     * Resizes the underlying array to match the new capacity
     * @param new_capacity
     */
   void resize(int new_capacity);
   /**
    * Increment size and increase capacity if necessary. Call at the beginning of any insertion-type function.
    */
   void insertion();
   /**
    * Decrement size and decrease capacity if necessary. Call at the end of any removal-type function.
    */
   void removal();
   /**
    * Check that the specified index is in range and throw an out_of_range exception otherwise
    * @param index
    */
   void check_index_in_range(int index);
   /**
    * Current size (number of initialized elements) of the array
    */
   int s;
   /**
    * Current capacity of the underlying array
    */
   int c;
   /**
    * Pointer to the underlying array
    */
   T* a;
};
}

#endif //VECTOR_VECTOR_H
