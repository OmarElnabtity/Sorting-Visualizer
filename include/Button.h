#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:
    Button(const std::string& text, sf::Vector2f pos);

    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Vector2i& mousePos);

private:
    sf::RectangleShape box;
    sf::Text label;
    sf::Font font;
};