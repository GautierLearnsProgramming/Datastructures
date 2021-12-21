
#ifndef STATIC_QUEUE_IMPL
#define STATIC_QUEUE_IMPL
#include "static_queue.h"

namespace gb_datastructures {
    template<typename T>
    StaticQueue<T>::StaticQueue(int capacity) {
        a = new T[capacity + 1];
        this->ri = 0;
        this->wi = 0;
        this->s = 0;
        this->c = capacity;
        a_count = new int;
        *a_count = 1;
    }

    template<typename T>
    void StaticQueue<T>::queue(T key) {
        // Throw an error if we have reached the size limit
        if (s == c) throw std::length_error("");
        // Otherwise, write at the write index and increment it, and increment the size
        a[wi] = key;
        wi = this->increment(wi);
        s++;
    }

    template<typename T>
    T StaticQueue<T>::dequeue() {
        // Throw out of range if there is nothing to dequeue
        if (this->empty()) throw std::out_of_range("");
        // Store the value to return before incrementing the read index
        T ret = a[ri];
        // Increment read index and decrement the size
        ri = this->increment(ri);
        s--;
        return ret;
    }

    template<typename T>
    bool StaticQueue<T>::empty() {
        return ri == wi;
    }

    template<typename T>
    int StaticQueue<T>::increment(int i) {
        return (i + 1) % (c + 1);
    }

    template<typename T>
    StaticQueue<T>::~StaticQueue() {
        *a_count -= 1;
        if (*a_count == 0) {
            delete[] a;
            delete a_count;
        }
    }

    template<typename T>
    StaticQueue<T>::StaticQueue(const StaticQueue<T> &other): a(other.a), a_count(other.a_count), ri(other.ri),
                                                              wi(other.wi), s(other.s),
                                                              c(other.c) {
        *a_count += 1;
    }

    template<typename T>
    StaticQueue<T> &StaticQueue<T>::operator=(const StaticQueue<T> &other) {
        return new StaticQueue<T>(other);
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, StaticQueue<T> q) {
        os << "read index : " << q.ri << std::endl;
        os << "write index : " << q.wi << std::endl;
        int i = q.ri;
        while (i != q.wi) {
            os << " " << q.a[i] << " ";
            i = q.increment(i);
        }
        os << std::endl;
        return os;
    }
}
#endif
