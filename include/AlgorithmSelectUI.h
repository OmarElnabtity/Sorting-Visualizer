#pragma once
#include <SFML/Graphics.hpp>
#include "SortAlgorithm.h"
#include "Button.h"
using namespace std;

class AlgorithmSelectUI {
public:
    AlgorithmSelectUI(int width, int height);

    SortAlgorithm run();    //runs sorting algorithm options

private:
    int width, height;

    //buttons
    Button bubbleBtn;
    Button insertionBtn;
    Button selectionBtn;

    Button mergeBtn;
    Button quickBtn;

    //selected algorithm
    SortAlgorithm selected;
};