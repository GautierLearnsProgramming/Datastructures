//
// Created by gautier on 09/12/2021.
//
#include <iostream>
#include "dynamic_queue.h"

void static_queue_demo(){
    auto* q = new StaticQueue<int>(4);
    q->queue(1);
    std::cout << *q;
    q->queue(2);
    std::cout << *q;
    q->queue(3);
    std::cout << *q;
    q->queue(4);
    std::cout << *q;
    try{
        q->queue(5);
    }catch (std::exception& e){
        std::cout << "A length exception has been caught" << std::endl;
    }
    std::cout << q->dequeue() << std::endl;
    std::cout << *q;
    std::cout << q->dequeue() << std::endl;
    std::cout << *q;
    q->queue(6);
    std::cout << *q;
    q->queue(7);
    std::cout << *q;
}