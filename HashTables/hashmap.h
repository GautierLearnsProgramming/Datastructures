//
// Created by gautier on 11/12/2021.
//

#ifndef DATASTRUCTURES_HASHMAP_H
#define DATASTRUCTURES_HASHMAP_H

#include <bits/stdc++.h>

int polynomialRollingHash(std::string const& str);
int integerHash(int integer);
int strHash(const std::string& key, int c);
int poi(int index, int capacity, int offset);



template<typename T>
class Entry;

template<typename T>
class HashMap{
public:
    HashMap();
    ~HashMap();
    HashMap(const HashMap<T>& copy);
    HashMap<T>& operator=(const HashMap<T>& other);
    void set(const std::string& key, T value);
    T get(const std::string& key);
    void remove(const std::string& key);
    bool has(const std::string& key);
    template<typename U>
    friend std::ostream &operator<<(std::ostream& os, HashMap<U> map);
private:
    // Pointer to the underlying array
    Entry<T>* a;
    // Capacity of the underlying array
    int c;
    // Current number of stored elements
    int n;
    // Maximum load factor, should be strictly < 1. Amortized cost is proportional to 1/(1-maxLoadFactor), so don't choose too close to 1.
    float maxLoadFactor;
    // counter of a copies for destruction purpose
    int* a_count;
    // Resize the underlying array
    void resize(int new_cap);
    void setNoResize(const std::string& key, T value);
};

template<typename T>
class Entry{
    friend class HashMap<T>;
    Entry(){
        key = "";
    }
public:
    std::string key;
    T value;
};

#include "hashmap.tpp"
#endif //DATASTRUCTURES_HASHMAP_H
