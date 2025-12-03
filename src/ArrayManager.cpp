#include "ArrayManager.h"
#include <cstdlib>

ArrayManager::ArrayManager(int size) {
    arr.resize(size);
    generateRandom();
}

void ArrayManager::generateRandom() {
    for (int& v : arr)
        v = rand() % 500 + 10;

    original = arr;
}

void ArrayManager::applyStep(const SortStep &step) {
    arr = step.arr;
}

void ArrayManager::undoStep(const SortStep &step) {
    arr = step.arr;
}

void ArrayManager::reset() {
    arr = original;
}

const vector<int>& ArrayManager::get() {
    return arr;
}

void ArrayManager::set(const vector<int>& newArr) {
    arr = newArr;
}