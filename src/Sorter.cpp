#include "Sorter.h"

vector<SortStep> Sorter::bubbleSort(const vector<int>& arr) {
    vector<SortStep> steps;
    vector<int> a = arr;

    int n = a.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            steps.push_back({a, j, j + 1 ,false});

            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                steps.push_back({a, j, j + 1, true});
            }
        }
    }

    return steps;
}

vector<SortStep> Sorter::mergeSort(const vector<int>& arr) {
    vector<SortStep> steps;
    vector<int> a = arr;

    mergeSortRecursive(a, 0, a.size() - 1, steps);
    return steps;
}

void Sorter::mergeSortRecursive(vector<int>& a, int left, int right, vector<SortStep>& steps) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSortRecursive(a, left, mid, steps);
    mergeSortRecursive(a, mid + 1, right, steps);

    merge(a, left, mid, right, steps);
}

void Sorter::merge(vector<int>& a, int left, int mid, int right, vector<SortStep>& steps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }

        steps.push_back({a, k, -1, true});
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        steps.push_back({a, k, -1, true});
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        steps.push_back({a, k, -1, true});
        j++;
        k++;
    }
}


vector<SortStep> Sorter::insertionSort(const vector<int> &arr) {
    vector<SortStep> steps;
    vector<int> a = arr;

    return steps;
}

vector<SortStep> Sorter::quickSort(const vector<int> &arr) {
    vector<SortStep> steps;
    vector<int> a = arr;

    return steps;
}
