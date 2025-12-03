#include "Visualizer.h"

Visualizer::Visualizer(int width, int height)
    : windowWidth(width), windowHeight(height) {}

void Visualizer::drawArray(sf::RenderWindow& window,
                            const vector<int> &arr,
                            int a, int b,
                            bool isSwap)
{
    float barWidth = (float) windowWidth / arr.size();

    for (int i = 0; i < arr.size(); i++) {
        sf::RectangleShape bar;
        bar.setSize(sf::Vector2f(barWidth - 2, -arr[i]));
        bar.setPosition(i * barWidth, windowHeight);

        if (i == a || i == b)
            bar.setFillColor(isSwap ? sf::Color::Red : sf::Color::Yellow);
        else
            bar.setFillColor(sf::Color::White);

        window.draw(bar);
    }
}