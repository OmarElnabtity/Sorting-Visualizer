#pragma once
#include <SFML/Graphics.hpp>
#include "SortAlgorithm.h"
#include "Button.h"
using namespace std;

class AlgorithmSelectUI {
public:
    AlgorithmSelectUI(int width, int height);

    SortAlgorithm run();

private:
    int width, height;

    Button bubbleBtn;
    Button insertionBtn;
    Button mergeBtn;
    Button quickBtn;

    SortAlgorithm selected;
};