#pragma once
#include <vector>
using namespace std;

struct SortStep {
    vector<int> arr;
    int a, b;
    bool swap;
};

class Sorter {
public:
    vector<SortStep> bubbleSort(const vector<int>& arr);
    vector<SortStep> insertionSort(const vector<int>& arr);
    
    vector<SortStep> mergeSort(const vector<int>& arr);
    void mergeSortRecursive(vector<int>& arr, int left, int right, vector<SortStep>& steps);
    void merge(vector<int>& arr, int left, int mid, int right, vector<SortStep>& steps);

    vector<SortStep> quickSort(const vector<int>& arr);
};