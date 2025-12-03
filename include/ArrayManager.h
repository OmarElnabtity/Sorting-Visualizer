#pragma once
#include <vector>
using namespace std;

#include "Sorter.h"

class ArrayManager {
public:
    ArrayManager(int size);

    void generateRandom();
    void reset();
    void applyStep(const SortStep& step);
    void undoStep(const SortStep& step);

    const vector<int>& get();
    void set(const std::vector<int>& arr);

private:
    vector<int> arr;
    vector<int> original;
};