//
// Created by gautier on 06/12/2021.
//
#include <iostream>

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

namespace gb_datastructures{

template <typename T>
class Vector {
public:
    // Constructors
    Vector();
    Vector(T arr[], int size);

    // Rule of three
    ~Vector();
    Vector(const Vector<T>& other);
    Vector& operator=(const Vector<T>& other);

    /**
     * Get a new dynamicarray initialized with the specified array
     */
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, Vector<U> v);

    /**
     * @return The current getSize of the array
     */

    int getSize();
    /**
     * Get the underlying array's current getCapacity
     * @return An int representing the underlying array's getCapacity
     */
    int getCapacity();
    /**
     * Check is the a is empty
     * @return A bool, true if the array is empty, false otherwise
     */
    bool isEmpty();
    /**
     * Get the item at the specified index
     * @param index to lookup
     * @return the item at the specified index
     * @throw std:out_of_range if the index is above the current getSize of the array
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
     * @throws std:out_of_range if the index is more than the current getSize
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
     * Resizes the underlying array to match the new getCapacity
     * @param new_capacity
     */
   void resize(int new_capacity);
   /**
    * Increment getSize and increase getCapacity if necessary. Call at the beginning of any insertion-type function.
    */
   void insertion();
   /**
    * Decrement getSize and decrease getCapacity if necessary. Call at the end of any removal-type function.
    */
   void removal();
   /**
    * Check that the specified index is in range and throw an out_of_range exception otherwise
    * @param index
    */
   void check_index_in_range(int index);


   int size{};
   int capacity;
   T* a;
   int* a_count;
   //TODO : Add destructor/copy constructor/assignement overload and a_count int field.
};
}

#endif //VECTOR_VECTOR_H
