//
// Created by gautier on 22/12/2021.
//

#ifndef DATASTRUCTURES_SORTING_H
#define DATASTRUCTURES_SORTING_H
#include <vector>
#include <iostream>
#include "shuffle.h"
#include "stopwatch.h"

void selection_sort(std::vector<int>* v);

void insertion_sort(std::vector<int>* v);
void insertion_sort(std::vector<int>* v, unsigned long lo, unsigned long hi);

void merge_sort(std::vector<int>* v);

void quick_sort(std::vector<int>* v);

void sorting_test(int v_size, bool selection_srt, bool insert_srt, bool merge_srt, bool quick_srt);

#endif //DATASTRUCTURES_SORTING_H
