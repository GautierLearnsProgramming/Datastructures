//
// Created by gautier on 07/12/2021.
//

#include <iostream>
#include "doubly_linked_list.h"
#include "linked_list_main.h"

using namespace linked_list;

int linked_list_main() {
    auto *b = new DoublyLinkedList<int>;
    std::cout << *b;
    std::cout << "List empty ? " << b->empty() << std::endl;
    b->push_front(1);
    std::cout << *b;
    b->push_front(2);
    std::cout << *b;
    b->push_back(3);
    b->push_back(4);
    std::cout << *b;
    std::cout << "Current size of the list : " << b->size() << std::endl;
    std::cout << "List empty ?" << b->empty() << std::endl;
    std::cout << "Value at 2 : " << b->value_at(2) << std::endl;
    std::cout << "pop front " << b-> pop_front() << std::endl;
    std::cout << "pop back " << b->pop_back() << std::endl;
    std::cout << *b;
    std::cout << "front " << b->front() << std::endl;
    std::cout << "back " << b->back() << std::endl;
    b->insert(0, 5);
    std::cout << *b;
    b->insert(2, 6);
    std::cout << *b;
    b->insert(4, 7);
    std::cout << *b;
    b->erase(0);
    std::cout << *b;
    b->erase(2);
    std::cout << *b;
    try{
        b->erase(3);
    } catch (const std::out_of_range& e){
        std::cout << "Caught out of range" << std::endl;
    }
    b->reverse();
    std::cout << *b;
    std::cout << "removed value ? " << b->remove_value(8) << std::endl;
    std::cout << "removed value ? " << b->remove_value(1) << std::endl;
    std::cout << *b;
    b->erase(0);
    b->erase(0);
    delete b;
    return 0;
}
