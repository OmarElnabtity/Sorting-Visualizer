#include "Sorter.h"

vector<SortStep> Sorter::bubbleSort(const vector<int>& arr) {
    vector<SortStep> steps;                                 //initialize array of steps
    vector<int> a = arr;                                 //copy of the given array

    int n = a.size();

    for (int i = 0; i < n - 1; i++) {                       //loop from 0 -> n - 1
        for (int j = 0; j < n - i - 1; j++) {               //loop from 0 -> n - i - 1

            steps.push_back({a, j, j + 1 ,false});      //push the comparison of two bars

            if (a[j] > a[j + 1]) {                          //checks whether two consecutive bars are out of order
                swap(a[j], a[j + 1]);             //swap bars locations
                steps.push_back({a, j, j + 1, true});   //push the swapping step
            }
        }
    }

    return steps;   //returns vector of steps in order
}

vector<SortStep> Sorter::insertionSort(const vector<int> &arr) {
    vector<SortStep> steps;                                 //initialize array of steps
    vector<int> a = arr;                                 //copy of the given array

    for (int i = 1; i < a.size(); i++) {                    //loop from 1 -> end
        steps.push_back({a, i, i - 1, false});          //push the comparison of two bars

        for (int j = i; (j > 0) && (a[j - 1] > a[j]); j--) {    //loop back if two bars are out of order
            swap(a[j], a[j - 1]);                     //swap locations of the two consecutive bars
            steps.push_back({a, j - 1, -1, true});      //push the swapping step
        }
    }

    return steps;   //returns vector of steps in order
}

vector<SortStep> Sorter::selectionSort(const vector<int>& arr) {
    vector<SortStep> steps;                                 //initialize array of steps
    vector<int> a = arr;                                 //copy of the given array

    int n = a.size();

    for (int i = 0; i < n - 1; i++) {                       //loop from 0 -> n - 1
        int min = i;                                        //initialize min to index i (first element of iteration)

        for (int j = i + 1; j < n; j++) {                   //loop from i + 1 -> n
            steps.push_back({a, i, j, false});          //push the comparison step

            if (a[j] < a[min]) min = j;                     //update min if current element is less than a[min]
        }

        swap(a[i], a[min]);                       //swap a[min] to correct position
        steps.push_back({a, i, min, true});             //push the swapping step
    }

    return steps;   //returns vector of steps in order
}

vector<SortStep> Sorter::mergeSort(const vector<int>& arr) {
    vector<SortStep> steps;                                 //initialize array of steps
    vector<int> a = arr;                                 //copy of the given array

    mergeSortRecursive(a, 0, a.size() - 1, steps);
    return steps;   //returns vector of steps in order
}

void Sorter::mergeSortRecursive(vector<int>& a, int left, int right, vector<SortStep>& steps) {
    if (left >= right) return;              //base case left >= right

    int mid = left + (right - left) / 2;    //calculate mid index

    mergeSortRecursive(a, left, mid, steps);        //call merge sort recursively on left part
    mergeSortRecursive(a, mid + 1, right, steps);    //call merge sort recursively on right part

    merge(a, left, mid, right, steps);                   //merge left and right in order
}

void Sorter::merge(vector<int>& a, int left, int mid, int right, vector<SortStep>& steps) {
    int n1 = mid - left + 1;                //initialize number of left elements
    int n2 = right - mid;                   //initialize number of right elements

    vector<int> L(n1), R(n2);               //initialize temp vectors to hold data of two parts

    for (int i = 0; i < n1; i++) L[i] = a[left + i];    //copy left part from "a" to "L"
    for (int i = 0; i < n2; i++) R[i] = a[mid + 1 + i]; //copy right part from "a" to "R"

    int i = 0, j = 0, k = left;             //initialize i -> starting index of L
                                            //           j -> starting index of R
                                            //           k -> starting index of a

    while (i < n1 && j < n2) {              //loop as long as no index overflows from their range

        if (L[i] <= R[j]) {                 //compare "L" and "R" elements
            a[k] = L[i];                    //add "L" element if it is smaller
            i++;                            //increment "L" index
        } else {
            a[k] = R[j];                    //add "R" element if it is smaller
            j++;                            //increment "R" index
        }

        steps.push_back({a, k, -1, true});  //push the swapping step
        k++;                                //increment "a" index
    }

    while (i < n1) {                        //if index j overflows first, remaining elements in "L" must be added
        a[k] = L[i];                        //add "L" element
        steps.push_back({a, k, -1, true});  //push the swapping step
        i++;                                //increment "L" index
        k++;                                //increment "a" index
    }

    while (j < n2) {                        //if index i overflows first, remaining elements in "R" must be added
        a[k] = R[j];                        //add "R" element
        steps.push_back({a, k, -1, true});  //push the swapping step
        j++;                                //increment "R" index
        k++;                                //increment "a" index
    }
}

vector<SortStep> Sorter::quickSort(const vector<int> &arr) {
    vector<SortStep> steps;                                 //initialize array of steps
    vector<int> a = arr;                                 //copy of the given array

    quickSortRecursive(a, 0, a.size() - 1, steps);

    return steps;   //returns vector of steps in order
}

void Sorter::quickSortRecursive(vector<int>& arr, int l, int r, vector<SortStep>& steps) {
    if (l < r) {    //base case l >= r
        int p = partition(arr, l, r, steps);            //get the index of p

        quickSortRecursive(arr, l, p - 1, steps);     //call quick sort recursively on left partition
        quickSortRecursive(arr, p + 1, r, steps);     //call quick sort recursively on right partition
    }
}

int Sorter::partition(vector<int>& arr, int l, int r, vector<SortStep>& steps) {
    int p = arr[r];         //initialize p to last element of partition
    int i = l - 1;          //initialize position index

    for (int j = l; j < r; j++) {               //loop from l -> r

        steps.push_back({arr, j, r, false});        //push the comparison step
        if (arr[j] <= p) {                      //check if element is less than p
            i++;            //increment position index
            swap(arr[i], arr[j]);     //swap arr[j] to the left partition
            steps.push_back({arr, i, j, true});     //push the swapping step
        }
    }

    swap(arr[i + 1], arr[r]);         //swap the partitioner "p" to the correct position
    steps.push_back({arr, i + 1, r, true});         //push the swapping step
    return i + 1;           //return the index of partitioner
}