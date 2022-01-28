//
// Created by gautier on 23/12/2021.
//

#include "shuffle.h"
void knuth_shuffle(std::vector<int>* v){
    std::random_device dev;
    std::mt19937 rng(dev());


    for(unsigned long i = 0; i < v->size(); i++){
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, i);
        unsigned long r = dist(rng);

        int v_i = v->at(i);
        v->at(i) = v->at(r);
        v->at(r) = v_i;
    }
}
