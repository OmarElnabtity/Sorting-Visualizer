#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Visualizer {
public:
    Visualizer(int width, int height);

    void drawArray( sf::RenderWindow& window,
                    const vector<int>& arr,
                    int highlightA,
                    int highlightB,
                    bool isSwap
                    );

private:
    int windowWidth, windowHeight;
};