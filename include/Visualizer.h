#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Visualizer {
public:
    Visualizer(int width, int height);

    void drawArray( sf::RenderWindow& window,
                    const std::vector<int>& arr,
                    int highlightA,
                    int highlightB,
                    bool isSwap
                    );

private:
    int windowWidth, windowHeight;
};