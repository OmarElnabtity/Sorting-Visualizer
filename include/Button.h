#pragma once
#include <SFML/Graphics.hpp>
using namespace std;

class Button {
public:
    Button(const string& text, sf::Vector2f pos);

    void draw(sf::RenderWindow& window);            //draws the button
    bool isClicked(const sf::Vector2i& mousePos);   //checks if button is clicked

private:
    sf::RectangleShape box;
    sf::Text label;
    sf::Font font;
};