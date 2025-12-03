#pragma once
#include <SFML/Graphics.hpp>

#include "ArrayManager.h"
#include "Button.h"
#include "Sorter.h"
using namespace std;

class Controller;

class UIManager {
public:
    UIManager();

    void draw(sf::RenderWindow& window);
    void handleClick(sf::Vector2i mouse, Controller& controller, ArrayManager& arr);

    void updateStatus(const string& s);

private:
    Button playBtn;
    Button pauseBtn;
    Button resetBtn;

    Button nextBtn;
    Button prevBtn;

    Button speedSlow;
    Button speedMedium;
    Button speedFast;

    sf::Font font;
    sf::Text statusText;
};