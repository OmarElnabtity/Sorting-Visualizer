#include "Sorter.h"

std::vector<SortStep> Sorter::bubbleSort(const std::vector<int>& arr) {
    std::vector<SortStep> steps;
    std::vector<int> a = arr;

    int n = a.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            steps.push_back({a, j, j + 1 ,false});

            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                steps.push_back({a, j, j + 1, true});
            }
        }
    }

    return steps;
}