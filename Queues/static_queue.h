//
// Created by gautier on 09/12/2021.
//

#ifndef DATASTRUCTURES_STATIC_QUEUE_H
#define DATASTRUCTURES_STATIC_QUEUE_H

#include <iostream>
#include <memory>

/*
 * The goal of this implementation is to define a static queue implementation with a circular buffer (see : https://en.wikipedia.org/wiki/Circular_buffer).
 */
namespace static_queue {

/**
 * A static queue class implement the basic methods of the queue collection
 * @method void queue(T key)
 * @method T dequeue()
 * @method bool empty()
 * @class StaticQueue
 * @tparam T
 */
template<typename T>
class StaticQueue{
public:
    /**
     * Constructor for the StaticQueue class, returns a static queue with the given capacity
     * @param capacity
     */
    explicit StaticQueue(int capacity);
    /**
     * Copy constructor
     * @param other
     */
    StaticQueue(const StaticQueue<T>& other);
    /**
     * Destructor
     */
    ~StaticQueue();
    /**
     * Assignement overload
     * @param other
     * @return
     */
    StaticQueue<T>& operator=(const StaticQueue<T>& other);
    /**
     * @method void queue(T key) - Add the key to the queue
     * @param key
     */
    void queue(T key);
    /**
     * @method T dequeue() - Remove the oldest key from the queue and return it
     * @return
     */
    T dequeue();
    /**
     * Returns a bool indicating whether the queue is empty or not
     * @return
     */
    bool empty();
    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, StaticQueue<U> q);
private:
    /**
     * Pointer to the underlying array
     */
    T* a;
    /**
     * Pointer to the counter of underlying arrays (used to support fast copy constructor and copy assignement)
     */
    int* a_count;
    /**
     * Read index
     */
    int ri;
    /**
     * Write index
     */
    int wi;
    /**
     * Current size
     */
    int s;
    /**
    * Maximum capacity
    */
    int c;
    /**
     * Increment modulo the capacity, and return the incremented value
     * @param i
     * @return
     */
    int increment(int i);
    /**
     * Decrement modulo the capacity + 1, and return the decremented value
     * @param i
     * @return
     */
};

#include "static_queue.tpp"
}

#endif //DATASTRUCTURES_STATIC_QUEUE_H