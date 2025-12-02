#include "UIManager.h"
#include "Controller.h"

UIManager::UIManager()
        : playBtn("Play", {20, 520}),
          pauseBtn("Pause", {140, 520}),
          resetBtn("Reset", {260, 520}),
          prevBtn("Prev", {380, 520}),
          nextBtn("Next", {500, 520}),
          speedSlow("Slow", {650, 520}),
          speedMedium("Medium", {750, 520}),
          speedFast("Fast", {870, 520})
{
    font.loadFromFile("resources/OpenSans-Regular.ttf");

    statusText.setFont(font);
    statusText.setCharacterSize(18);
    statusText.setFillColor(sf::Color::White);
    statusText.setPosition(20, 10);
    statusText.setString("Status: Idle");
}

void UIManager::draw(sf::RenderWindow &window) {
    playBtn.draw(window);
    pauseBtn.draw(window);
    resetBtn.draw(window);
    prevBtn.draw(window);
    nextBtn.draw(window);
    speedSlow.draw(window);
    speedMedium.draw(window);
    speedFast.draw(window);

    window.draw(statusText);
}

void UIManager::updateStatus(const std::string& s)
{
    statusText.setString(s);
}

void UIManager::handleClick(sf::Vector2i mouse, Controller& controller, ArrayManager& arr, Sorter& sorter)
{
    if (playBtn.isClicked(mouse))
        controller.play(sorter.bubbleSort(arr.get()));

    else if (pauseBtn.isClicked(mouse))
        controller.pause();

    else if (resetBtn.isClicked(mouse))
        controller.reset(arr);

    else if (nextBtn.isClicked(mouse))
        controller.nextStep();

    else if (prevBtn.isClicked(mouse))
        controller.previousStep();

    else if (speedSlow.isClicked(mouse))
        controller.setSpeed(0.15f);

    else if (speedMedium.isClicked(mouse))
        controller.setSpeed(0.07f);

    else if (speedFast.isClicked(mouse))
        controller.setSpeed(0.02f);
}