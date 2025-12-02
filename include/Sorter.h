#pragma once
#include <vector>

struct SortStep {
    std::vector<int> arr;
    int a, b;
    bool swap;
};

class Sorter {
public:
    std::vector<SortStep> bubbleSort(const std::vector<int>& arr);
};