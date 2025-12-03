#pragma once
#include <vector>
using namespace std;

#include "Sorter.h"

class ArrayManager {
public:
    ArrayManager(int size);

    void generateRandom();                  //generates a random array
    void reset();                           //resets the array
    void applyStep(const SortStep& step);   //progress a single step
    void undoStep(const SortStep& step);    //undo a single step

    const vector<int>& get();               //get the generated array
    void set(const std::vector<int>& arr);  //set the array

private:
    vector<int> arr;
    vector<int> original;
};