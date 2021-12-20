//
// Created by gautier on 13/12/2021.
//

#include "hash_table_demo.h"

void hash_table_demo(){
    auto* map = new HashMap<int>();
    map->set("a", 1);
    std::cout << *map << std::endl;
    map->set("a", 3);
    std::cout << *map << std::endl;
    map->set("b", 2);
    std::cout << *map << std::endl;
    map->set("c", 4);
    std::cout << *map << std::endl;
    map->set("d", 5);
    map->set("e", 6);
    map->set("f", 7);
    map->set("g", 8);
    map->set("h", 9);
    map->set("i", 10);
    map->set("j", 11);
    map->set("k", 12);
    map->set("l", 13);
    map->set("m", 14);
    map->set("n", 14);
    std::cout << *map << std::endl;
    std::cout << "l " << strHash("l", 16) << std::endl;
    std::cout << "d " << strHash("d", 16) << std::endl;
    std::cout << "n " << strHash("n", 16) << std::endl;
    std::cout << "a " << strHash("a", 16) << std::endl;
    std::cout << "g " << strHash("g", 16) << std::endl;
    std::cout << "m " << strHash("m", 16) << std::endl;
    std::cout << "j " << strHash("j", 16) << std::endl;
    map->remove("k");
    std::cout << *map << std::endl;
}