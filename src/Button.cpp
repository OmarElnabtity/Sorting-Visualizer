#include "Button.h"

Button::Button(const string& text, sf::Vector2f pos) {
    font.loadFromFile("resources/OpenSans-Regular.ttf");

    box.setSize({100, 40});
    box.setPosition(pos);
    box.setFillColor(sf::Color(50, 50, 50));
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::White);

    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(18);
    label.setFillColor(sf::Color::White);
    label.setPosition(pos.x + 10, pos.y + 5);
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(box);
    window.draw(label);
}

bool Button::isClicked(const sf::Vector2i &mousePos) {
    return box.getGlobalBounds().contains(mousePos.x, mousePos.y);
}