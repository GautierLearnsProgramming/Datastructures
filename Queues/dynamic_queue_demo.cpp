//
// Created by gautier on 08/12/2021.
//

#include "static_queue.h"
#include "DynamicQueue.h"

using namespace gb_datastructures;

void dynamic_queue_demo(){
    auto *dq = new DynamicQueue<int>();
    dq->queue(1);
    std::cout << *dq;
    dq->queue(2);
    dq->queue(2);
    dq->queue(2);
    dq->queue(2);
    dq->queue(2);
    std::cout << *dq;
    dq->queue(3);
    dq->queue(4);
    dq->queue(5);
    std::cout << *dq;
    dq->dequeue();
    dq->dequeue();
    dq->dequeue();
    dq->dequeue();
    dq->dequeue();
    std::cout << *dq;
    dq->dequeue();
    std::cout << *dq;
}