#include <iostream>
#include "dynamicarray_impl.h"

int main() {
    vect::dynamicarray<int> v;
    std::cout << v;
    for (int i = 0; i < 10; i++){
        v.append(i);
        std::cout << v;
    }
    v.insert(4, 5);
    std::cout << v;
    try{
        v.insert(14, 5);
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    int popped = v.pop();
    std::cout << "popped: " << popped << std::endl;
    std::cout << v;
    for(int i = 0; i < 6; i++) v.pop();
    std::cout << v;
    v.removeIndex(1);
    std::cout << v;
    v.append(3);
    v.append(4);
    v.append(3);
    std::cout << v;
    v.remove(3);
    std::cout << v;
    std::cout << "Item index: " << v.find(2) << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    vect::dynamicarray<int> w = vect::dynamicarray<int>(arr, 5);
    std::cout << w;
    return 0;
}
