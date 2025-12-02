#pragma once
#include <vector>

#include "Sorter.h"

class ArrayManager {
public:
    ArrayManager(int size);

    void generateRandom();
    void reset();
    void applyStep(const SortStep& step);
    void undoStep(const SortStep& step);

    const std::vector<int>& get();
    void set(const std::vector<int>& arr);

private:
    std::vector<int> arr;
    std::vector<int> original;
};
