#include <SFML/Graphics.hpp>
#include "ArrayManager.h"
#include "Sorter.h"
#include "Visualizer.h"
#include "UIManager.h"
#include "Controller.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 600), "Sorting Visualizer", sf::Style::Close);
    window.setFramerateLimit(60);

    ArrayManager array(80);
    Sorter sorter;
    Visualizer visualizer(900, 500);
    UIManager ui;
    Controller controller(array, sorter, visualizer, ui);

    sf::Clock deltaClock;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                ui.handleClick(sf::Mouse::getPosition(window), controller, array, sorter);
            }
        }

        float dt = deltaClock.restart().asSeconds();
        controller.update(dt);

        ui.updateStatus(
        "Status: " + controller.getStateString() +
        "   Step " + std::to_string(controller.getStepIndex()) +
        "/" + std::to_string(controller.getTotalSteps())
        );

        window.clear(sf::Color(30, 30, 30));
        controller.draw(window);
        ui.draw(window);
        window.display();
    }

    return 0;
}
