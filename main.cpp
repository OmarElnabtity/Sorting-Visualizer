#include <SFML/Graphics.hpp>

#include "AlgorithmSelectUI.h"
#include "ArrayManager.h"
#include "Sorter.h"
#include "Visualizer.h"
#include "UIManager.h"
#include "Controller.h"
using namespace std;

int main() {
    AlgorithmSelectUI menu(400, 600);
    SortAlgorithm chosen = menu.run();

    sf::RenderWindow window(sf::VideoMode(1000, 620), "Sorting Visualizer", sf::Style::Close);
    window.setFramerateLimit(60);

    ArrayManager array(120);
    Sorter sorter;
    Visualizer visualizer(1000, 500);
    UIManager ui;
    Controller controller(array, sorter, visualizer, ui);

    controller.setAlgorithm(chosen);

    sf::Clock deltaClock;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                ui.handleClick(sf::Mouse::getPosition(window), controller, array);
            }
        }

        float dt = deltaClock.restart().asSeconds();
        controller.update(dt);

        ui.updateStatus(
        "Status: " + controller.getStateString() +
        "   Step " + to_string(controller.getStepIndex()) +
        "/" + to_string(controller.getTotalSteps())
        );

        window.clear(sf::Color(30, 30, 30));
        controller.draw(window);
        ui.draw(window);
        window.display();
    }

    return 0;
}