
#include "hashmap.h"

// Function to calculate
// the hash of a string
int polynomialRollingHash(
        std::string const& str)
{
    // P and M
    int p = 53;
    int m = 1e9 + 9;
    int power_of_p = 1;
    int hash_val = 0;

    // Loop to calculate the hash value
    // by iterating over the elements of string
    for (char i : str) {
        hash_val= (hash_val + (i - 'a' + 1) * power_of_p) % m;
        power_of_p = (power_of_p * p) % m;
    }

    //return positive remainder only
    return (hash_val%m + m) % m;
}

int integerHash(int integer){
    int a = 1784846847;
    int b = 954897562;
    int p = 1020000011;
    int r = (a * integer + b) % p;
    return (r + p) % p;
}

int strHash(const std::string& key, int c){
    return (integerHash(polynomialRollingHash(key))%c + c) %c;
}

template<typename T>
HashMap<T>::HashMap() {
    a = new Entry<T>[4];
    a_count = new int;
    *a_count = 1;
    maxLoadFactor = 0.9;
    n = 0;
    c = 4;
}

template<typename T>
void HashMap<T>::setNoResize(const std::string &key, T value) {
    // Hash the string mod the capacity
    int index = strHash(key, c);
    while(true){
        if(a[index].key == ""){
            break;
        }
        if(a[index].key == key){
            break;
        }
        index = (index + 1) % c;
    }
    a[index].key = key;
    a[index].value = value;
}

template<typename T>
void HashMap<T>::set(const std::string& key, T value) {
    // Hash the string mod the capacity
    int index = strHash(key, c);
    while(true){
        if(a[index].key == ""){
            n++;
            break;
        }
        if(a[index].key == key){
            break;
        }
        index = (index + 1) % c;
    }
    a[index].key = key;
    a[index].value = value;

    // Resize in case the maximum acceptable load factor is surpassed
    if((float) n / (float) c > maxLoadFactor){
        resize(2*c);
    }
}

template<typename T>
T HashMap<T>::get(const std::string& key) {
    // Iterate through the hash array, return null if we reach an empty key (the key is therefore not in the hash table)
    // Return true if we reach the key we're looking for
    int hash = strHash(key, c);
    Entry<T> e = a[hash];
    while(e.key != ""){
        if(e.key == key){
            return e.value;
        }
        hash = (hash + 1) % c;
        e = a[hash];
    }
    return NULL;
}

//positive_offset_index
// This function is used to allow order comparison in modular arithmetics.
int poi(int index, int capacity, int offset){
    return ((index - offset + capacity) % capacity);
}

template<typename T>
void HashMap<T>::remove(const std::string& key) {
    // Declarations
    int hash = strHash(key, c);
    Entry<T> e = a[hash];

    // Cleanup helpers
    // available index
    int ai = 0;
    // current index
    int ci = 0;
    // entry hash
    int eh = 0;
    // prev empty index
    int pei = 0;

    //Look for the key to remove, and remove the entry if we find it.
    while(e.key != ""){
        if(e.key == key){
            ai = hash;
            pei = hash;
            a[hash].key = "";
            a[hash].value = NULL;
            n--;
            break;
        }
        hash = (hash + 1) % c;
        e = a[hash];
    }

    // Then, do some cleanup : if there are subsequent keys that would be higher in the hash table if the removed key
    // didnt exist, move them higher in the table. The math with the offset_value is necessary because we use a circular
    // buffer, so we need to offset the indexes in order to keep the gt/lt operators relevant

    // Find the first empty space index in order to build a sensible order relationship for the following indexes
    ci = (ai - 1 + c) % c;
    e = a[ci];
    while(e.key != ""){
        ci = (ci - 1 + c) % c;
        e = a[ci];
    }
    pei = ci;

    // Iterate through the array, starting right after the newly available space, and move elements at lower indexes (offset by pei) if necessary
    ci = (ai + 1) % c;
    e = a[ci];
    while(e.key != "") {
        eh = strHash(e.key, c);
        if(e.key == "n"){
        }
        /* The following condition is met only if :
         * (1) The available index is lower than the entries' hash, so it wont be moved "higher" than where it would be without collisions
         * The poi function is used to allow proper integer comparison, as without it there are problems when collisions occur at the end of
         * the circular buffer and entries are pushed at the beginning of the buffer (i.e, modulo 16, 0 should sometimes
         * be considered greater than 15).
         */
        if (poi(eh, c, pei) <= poi(ai, c, pei)){
            a[ai].key = a[ci].key;
            a[ai].value = a[ci].value;
            a[ci].key = "";
            a[ci].value = NULL;
            ai = ci;
        }
        ci = (ci + 1) % c;
        e = a[ci];
    }

    // If the table size is low, resize it
    if((float) n/ (float) c < maxLoadFactor/4 && n > 0 && c > 7){
        resize(c/2);
    }\
}

template<typename T>
bool HashMap<T>::has(const std::string& key) {
    int hash = strHash(key, c);
    Entry<T> e = a[hash];
    while(e.key != ""){
        if(e.key == key){
            return true;
        }
        hash = (hash + 1) % c;
        e = a[hash];
    }
    return false;
}

template<typename T>
void HashMap<T>::resize(int new_cap) {
    auto* old_a = a;
    int old_cap = c;
    a = new Entry<T>[new_cap];
    c = new_cap;
    for(int i = 0; i < old_cap; i++){
        setNoResize(old_a[i].key, old_a[i].value);
    }
    delete[] old_a;
}

template<typename U>
std::ostream &operator<<(std::ostream &os, HashMap<U> map) {
    os << "n: " << map.n << std::endl;
    os << "c: " << map.c << std::endl;
    for(int i = 0; i  < map.c; i++){
        if(map.a[i].key != ""){
            os << "key : " << map.a[i].key << " value : " << map.a[i].value << " index : " << i << std::endl;
        }
    }
    return os;
}

template<typename T>
HashMap<T>::~HashMap() {
    *a_count -= 1;
    if(*a_count == 0){
        delete[] a;
        delete a_count;
    }
}

template<typename T>
HashMap<T>::HashMap(const HashMap<T>& copy):
        a(copy.a), a_count(copy.a_count),
        n(copy.n), c(copy.c), maxLoadFactor(copy.maxLoadFactor){
    *a_count += 1;
}

template<typename T>
HashMap<T>& HashMap<T>::operator=(const HashMap<T> &other) {
    return new HashMap<T>(other);
}
