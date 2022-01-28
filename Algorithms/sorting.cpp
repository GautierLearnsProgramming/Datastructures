//
// Created by gautier on 22/12/2021.
//
#include "sorting.h"

void swap(std::vector<int>* v, unsigned long i, unsigned long j){
    int v_i = v->at(i);
    v->at(i) = v->at(j);
    v->at(j) = v_i;
}

void selection_sort(std::vector<int>* v){
    for(int i = 0; i < v->size(); i++){
        int min = v->at(i);
        unsigned long min_index = i;
        for(unsigned long j = i; j < v->size(); j++){
            if (v->at(j) < min){
                min_index = j;
                min = v->at(j);
            }
        }
        swap(v, min_index, i);
    }
}

void insertion_sort(std::vector<int>* v){
    for(int i = 0; i < v->size(); i++){
        // Swap until we are at 0 or we are bigger than the previous element
        int j = i;
        while (true){
            if(j == 0) break;
            if(v->at(j) >= v->at(j-1)) break;
            swap(v, j, j-1);
            j--;
        }
    }
}

void insertion_sort(std::vector<int>*v, unsigned long lo, unsigned long hi){
    for(auto i = lo; i <= hi; i++){
        // Swap until we are at 0 or we are bigger than the previous element
        auto j = i;
        while (true){
            if(j == lo) break;
            if(v->at(j) >= v->at(j-1)) break;
            swap(v, j, j-1);
            j--;
        }
    }
}

std::vector<int>* merge(std::vector<int>* left, std::vector<int> *right){
    auto* merged = new std::vector<int>();
    unsigned long left_index = 0;
    unsigned long right_index = 0;
    while(left_index < left->size() || right_index < right->size()){
        if(left_index == left->size()){
            merged->push_back(right->at(right_index));
            right_index++;
        } else if (right_index == right->size()){
            merged->push_back(left->at(left_index));
            left_index++;
        } else if (left->at(left_index) <= right->at(right_index)){
            merged->push_back(left->at(left_index));
            left_index++;
        } else {
            merged->push_back(right->at(right_index));
            right_index++;
        }
    }
    delete left;
    delete right;
    return merged;
}

std::vector<int>* merge_sort_with_return(std::vector<int>* vector){
    if(vector->size() <= 10){
        insertion_sort(vector);
    } else {
        auto* left = new std::vector<int>();
        auto* right = new std::vector<int>();
        for(unsigned long i = 0; i < vector->size() / 2; i++){
            left->push_back(vector->at(i));
        }
        for(unsigned long i = vector->size() / 2; i < vector->size(); i++){
            right->push_back(vector->at(i));
        }
        delete vector;
        vector = merge(merge_sort_with_return(left), merge_sort_with_return(right));
    }
    return vector;
}

void merge_sort(std::vector<int>* v){
    auto* merge_helper = new std::vector<int>();
    for(int &i : *v){
        merge_helper->push_back(i);
    }
    merge_helper = merge_sort_with_return(merge_helper);
    for(unsigned long i = 0; i < v->size(); i++){
        v->at(i) = merge_helper->at(i);
    }
    delete merge_helper;
}

long partition(std::vector<int>* v, long lo, long hi){
    long i = lo + 1;
    long j = hi;
    while(true) {
        while (v->at(i) < v->at(lo)) {
            if(i >= hi) break;
            i++;
        }
        while (v->at(j) >  v->at(lo)) {
            if(j == lo) break;
            j--;
        }
        if(i >= j) break;
        swap(v, i, j);
    }
    swap(v, lo, j);
    return j;
}

void qs(std::vector<int> *v, long lo, long hi){
    if(hi - lo <= 7){
        insertion_sort(v, lo, hi);
        return;
    }
    long in_place = partition(v, lo, hi);
    if(in_place > 0) qs(v, lo, in_place-1);
    qs(v, in_place+1, hi);
}

void quick_sort(std::vector<int>* v){
    if(v->size() <= 1) return; // An empty array or an array containing only one element is already sorted

    knuth_shuffle(v);
    qs(v, 0, v->size() - 1);
}

bool test_correct(std::vector<int> *vector){
    bool correct = true;
    for(int i = 0; i < vector->size(); i++){
        if(vector->at(i) != i) correct = false;
    }
    return correct;
}

void sorting_test(int v_size, bool selection_srt, bool insert_srt, bool merge_srt, bool quick_srt){
    auto begin = GetTimeMs64();
    auto end = begin;

    std::vector<int> vector{};
    vector.reserve(v_size);
    for(int i = 0; i < v_size; i++){
        vector.push_back(i);
    }
    knuth_shuffle(&vector);

    end = GetTimeMs64();
    std::cout << "Vector creation and shuffle " << end - begin << "ms" << std::endl;

    if (selection_srt) {
        begin = GetTimeMs64();
        selection_sort(&vector);
        end = GetTimeMs64();
        std::cout << "Selection sort " << end - begin << "ms" << std::endl;
        std::cout << "Selection sort correct: " << test_correct(&vector) << std::endl;

        knuth_shuffle(&vector);
    }

    if (insert_srt) {
        begin = GetTimeMs64();
        insertion_sort(&vector);
        end = GetTimeMs64();
        std::cout << "Insertion sort " << end - begin << "ms" << std::endl;
        std::cout << "Insertion sort correct: " << test_correct(&vector) << std::endl;

        knuth_shuffle(&vector);
    }

    if (merge_srt) {
        begin = GetTimeMs64();
        merge_sort(&vector);
        end = GetTimeMs64();
        std::cout << "Merge sort " << end - begin << "ms" << std::endl;
        std::cout << "Merge sort correct: " << test_correct(&vector) << std::endl;

        knuth_shuffle(&vector);
    }

    if (quick_srt) {
        begin = GetTimeMs64();
        quick_sort(&vector);
        end = GetTimeMs64();
        std::cout << "Quick sort " << end - begin << "ms" << std::endl;
        std::cout << "Quick sort correct: " << test_correct(&vector) << std::endl;
    }
}