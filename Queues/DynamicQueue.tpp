

#ifndef DYNAMIC_QUEUE_IMPL
#define DYNAMIC_QUEUE_IMPL
#include "DynamicQueue.h"

namespace gb_datastructures {
    template<typename T>
    DynamicQueue<T>::DynamicQueue() {
        q = new StaticQueue<T>(1);
        q_count = new int;
        *q_count = 1;
        s = 0;
        c = 1;
    }

    template<typename T>
    DynamicQueue<T>::~DynamicQueue() {
        *q_count -= 1;
        if (*q_count == 0) {
            delete q;
            delete q_count;
        }
    }

    template<typename T>
    DynamicQueue<T>::DynamicQueue(const DynamicQueue<T> &copy):
        q(copy.q), q_count(copy.q_count), s(copy.s), c(copy.c) {
        *q_count++;
    }

    template<typename T>
    DynamicQueue<T> &DynamicQueue<T>::operator=(const DynamicQueue<T> &other) {
        if(&other != this){
            *q_count -= 1;
            if (*q_count == 0) {
                delete q;
                delete q_count;
            }

            q = other.q;
            q_count = other.q_count;
            s = other.s;
            c = other.c;
        }
        return *this;
    }

    template<typename T>
    void DynamicQueue<T>::queue(T key) {
        // If we're at full capacity, resize the underlying queue
        if (s == c) {
            auto *new_queue = new StaticQueue<T>(2 * c);
            c = 2 * c;
            // Copy the old queue into the new queue
            while (!q->empty()) {
                new_queue->queue(q->dequeue());
            }
            delete q;
            q = new_queue;
        }
        // Queue the new element
        q->queue(key);
        s++;
    }

    template<typename T>
    T DynamicQueue<T>::dequeue() {
        // If there's nothing to dequeue, throw out of range
        if (this->empty()) {
            throw std::out_of_range("Nothing to dequeue");
        }
        // Store the dequeued value, if we are less than 1/4 capacity, resize the queue, then return the value
        T ret = q->dequeue();
        s--;
        if ((s <= c / 4) && (s > 0)) {
            auto *new_queue = new StaticQueue<T>(c / 2);
            c = c / 2;
            while (!q->empty()) {
                new_queue->queue(q->dequeue());
            }
            delete q;
            q = new_queue;
        }
        return ret;
    }

    template<typename T>
    bool DynamicQueue<T>::empty() {
        return s == 0;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, DynamicQueue<T> q) {
        os << "getSize : " << q.s << std::endl;
        os << "getCapacity : " << q.c << std::endl;
        os << *q.q;
        return os;
    }
}
#endif
