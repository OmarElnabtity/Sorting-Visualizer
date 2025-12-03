#include "AlgorithmSelectUI.h"

AlgorithmSelectUI::AlgorithmSelectUI(int w, int h)
    : width(w), height(h),
        //define buttons and their positions
      bubbleBtn("Bubble", {150, 120}),
      insertionBtn("Insertion", {150, 180}),
      selectionBtn("Selection", {150, 240}),
      mergeBtn("Merge", {150, 300}),
      quickBtn("Quick", {150, 360}) {}

SortAlgorithm AlgorithmSelectUI::run() {

    //initialize window
    sf::RenderWindow window(sf::VideoMode(width, height),
                            "Select Algorithm", sf::Style::Close);
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;    //initialize an event

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            //handle mouse button press event, saves selected algorithm based on mouse click
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mouse = sf::Mouse::getPosition(window);

                if (bubbleBtn.isClicked(mouse)) {
                    selected = SortAlgorithm::Bubble;
                    window.close();
                }
                if (insertionBtn.isClicked(mouse)) {
                    selected = SortAlgorithm::Insertion;
                    window.close();
                }
                if (selectionBtn.isClicked(mouse)) {
                    selected = SortAlgorithm::Selection;
                    window.close();
                }
                if (mergeBtn.isClicked(mouse)) {
                    selected = SortAlgorithm::Merge;
                    window.close();
                }
                if (quickBtn.isClicked(mouse)) {
                    selected = SortAlgorithm::Quick;
                    window.close();
                }
            }
        }

        //clear window
        window.clear(sf::Color(30, 30, 30));

        //draw buttons
        bubbleBtn.draw(window);
        insertionBtn.draw(window);
        selectionBtn.draw(window);
        mergeBtn.draw(window);
        quickBtn.draw(window);

        //display window
        window.display();
    }

    //return selected algorithm
    return selected;
}