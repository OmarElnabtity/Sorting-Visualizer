#include <iostream>
#include <SFML/Graphics.hpp>

#include "AlgorithmSelectUI.h"
#include "ArrayManager.h"
#include "Sorter.h"
#include "Visualizer.h"
#include "UIManager.h"
#include "Controller.h"
using namespace std;

int main() {
    AlgorithmSelectUI menu(400, 600);                        //initialize menu to select algorithm
    SortAlgorithm chosen = menu.run();                                  //get the chosen algorithm

    sf::RenderWindow window(sf::VideoMode(1000, 620), "Sorting Visualizer", sf::Style::Close);
    window.setFramerateLimit(60);                                       //initialize the window configuration

    ArrayManager array(200);                                        //set array size
    Sorter sorter;                                                      //initialize sorter
    Visualizer visualizer(1000, 500);                        //initialize visualizer
    UIManager ui;                                                       //initialize user interface
    Controller controller(array, sorter, visualizer, ui);   //initialize controller

    controller.setAlgorithm(chosen);                                    //set algorithm to the chosen one
    sf::Clock deltaClock;                                               //configure clock to measure time between frames

    while (window.isOpen()) {
        sf::Event event;                                                //initialize an event

        while (window.pollEvent(event)) {                            //handle events
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                ui.handleClick(sf::Mouse::getPosition(window), controller, array); //handle mouse click
            }
        }

        float dt = deltaClock.restart().asSeconds();                    //measure time since last frame
        controller.update(dt);                                          //update the screen one step

        ui.updateStatus(                                                //update screen status
        "Status: " + controller.getStateString() +
        "   Step " + to_string(controller.getStepIndex()) +
        "/" + to_string(controller.getTotalSteps())
        );

        window.clear(sf::Color(30, 30, 30));             //clear the screen
        controller.draw(window);                                     //draw current window
        ui.draw(window);                                             //draw the user interface
        window.display();                                               //display window
    }

    return 0;
}