#include "AlgorithmSelectUI.h"

AlgorithmSelectUI::AlgorithmSelectUI(int w, int h)
    : width(w), height(h),
      bubbleBtn("Bubble", {150, 120}),
      insertionBtn("Insertion", {150, 180}),
      mergeBtn("Merge", {150, 240}),
      quickBtn("Quick", {150, 300}) {}

SortAlgorithm AlgorithmSelectUI::run() {

    sf::RenderWindow window(sf::VideoMode(width, height),
                            "Select Algorithm", sf::Style::Close);
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

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

        window.clear(sf::Color(30, 30, 30));

        bubbleBtn.draw(window);
        insertionBtn.draw(window);
        mergeBtn.draw(window);
        quickBtn.draw(window);

        window.display();
    }

    return selected;
}