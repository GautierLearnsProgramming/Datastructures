//
// Created by gautier on 07/12/2021.
//

#include <iostream>
#include "doubly_linked_list_impl.h"

using namespace linked_list;

int main() {
    auto *list = new DoublyLinkedList<int>;
    std::cout << "List empty ?" << list->empty() << std::endl;
    list->push_front(1);
    std::cout << *list;
    list->push_front(2);
    std::cout << *list;
    list->push_back(3);
    list->push_back(4);
    std::cout << *list;
    std::cout << "Current size of the list : " << list->size() << std::endl;
    std::cout << "List empty ?" << list->empty() << std::endl;
    std::cout << "Value at 2 : " << list->value_at(2) << std::endl;
    std::cout << "pop front " << list-> pop_front() << std::endl;
    std::cout << "pop back " << list->pop_back() << std::endl;
    std::cout << *list;
    std::cout << "front " << list->front() << std::endl;
    std::cout << "back " <<list->back() << std::endl;
    list->insert(0, 5);
    std::cout << *list;
    list->insert(2, 6);
    std::cout << *list;
    list->insert(4, 7);
    std::cout << *list;
    list->erase(0);
    std::cout << *list;
    list->erase(2);
    std::cout << *list;
    try{
        list->erase(3);
    } catch (const std::out_of_range& e){
        std::cout << "Caught out of range" << std::endl;
    }
    list->reverse();
    std::cout << *list;
    std::cout << "removed value ? " << list->remove_value(8) << std::endl;
    std::cout << "removed value ? " << list->remove_value(1) << std::endl;
    std::cout << *list;
    return 0;
}
