//
// Created by gautier on 09/12/2021.
//

#ifndef DATASTRUCTURES_DYNAMIC_QUEUE_H
#define DATASTRUCTURES_DYNAMIC_QUEUE_H
#include <iostream>
#include "static_queue.h"

using namespace static_queue;

namespace dynamic_queue {
    template<typename T>
    class DynamicQueue {
    public:
        DynamicQueue();
        // Rule of three
        DynamicQueue(const DynamicQueue<T>& copy);
        ~DynamicQueue();
        DynamicQueue<T>& operator=(const DynamicQueue<T>& other);

        void queue(T key);
        T dequeue();
        bool empty();

        template<typename U>
        friend std::ostream &operator<<(std::ostream &os, DynamicQueue<U> q);
    private:
        // Underlying static queue
        StaticQueue<T> *q;
        // Number of references to the q object, used for copy constructor and assignement operator
        int *q_count;
        // Current size of the queue
        int s;
        // Current capacity of the queue
        int c;
    };

#include "dynamic_queue.tpp"
}

#endif //DATASTRUCTURES_DYNAMIC_QUEUE_H
