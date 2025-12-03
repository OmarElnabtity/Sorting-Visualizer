#include "ArrayManager.h"
#include <cstdlib>

ArrayManager::ArrayManager(int size) {
    arr.resize(size);
    generateRandom();
}

void ArrayManager::generateRandom() {
    for (int& v : arr)
        v = rand() % 500 + 10;          //generate random values 10 -> 509

    original = arr;                     //save generated array in the original
}

void ArrayManager::applyStep(const SortStep &step) {
    arr = step.arr;                     //set the array to be the array of the next step
}

void ArrayManager::undoStep(const SortStep &step) {
    arr = step.arr;                     //set the array to be the array of the previous step
}

void ArrayManager::reset() {
    arr = original;                     //set the array to be the original one
}

const vector<int>& ArrayManager::get() {
    return arr;                         //returns array
}

void ArrayManager::set(const vector<int>& newArr) {
    arr = newArr;                       //set the array to the new array
}