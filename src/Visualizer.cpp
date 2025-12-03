#include "Visualizer.h"

Visualizer::Visualizer(int width, int height)
    : windowWidth(width), windowHeight(height) {}

void Visualizer::drawArray(sf::RenderWindow& window,
                            const vector<int> &arr,
                            int a, int b,
                            bool isSwap)
{
    float barWidth = (float) windowWidth / arr.size();          //determines bar width

    for (int i = 0; i < arr.size(); i++) {                      //loops to draw each element of the array as a bar
        sf::RectangleShape bar;                                 //define bar shape
        bar.setSize(sf::Vector2f(barWidth - 2, -arr[i]));   //define bar size (barwidth - 2, arr[i])
                                                                  //y value is determined based on the randomly generated values
        bar.setPosition(i * barWidth, windowHeight);        //set bar position

        if (i == a || i == b)                                   //check if current index is one of the bars to be highlighted
            bar.setFillColor(isSwap ? sf::Color::Red : sf::Color::Yellow);  //yellow -> comparing, red -> swapping
        else
            bar.setFillColor(sf::Color::White);                             //white -> normal

        window.draw(bar);                                       //draw the bar
    }
}