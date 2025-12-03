#include "UIManager.h"
#include "Controller.h"

UIManager::UIManager()  //define buttons and their positions
        : playBtn("Play", {20, 520}),
          pauseBtn("Pause", {140, 520}),
          resetBtn("Reset", {260, 520}),
          prevBtn("Prev", {410, 520}),
          nextBtn("Next", {530, 520}),
          speedSlow("Slow", {680, 520}),
          speedMedium("Medium", {780, 520}),
          speedFast("Fast", {880, 520})
{
    //configures status options
    font.loadFromFile("resources/OpenSans-Regular.ttf");

    statusText.setFont(font);
    statusText.setCharacterSize(18);
    statusText.setFillColor(sf::Color::White);
    statusText.setPosition(20, 580);
    statusText.setString("Status: Idle");
}

void UIManager::draw(sf::RenderWindow &window) {    //draw everything on the window
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

void UIManager::updateStatus(const string& s)       //update status
{
    statusText.setString(s);
}

void UIManager::handleClick(sf::Vector2i mouse, Controller& controller, ArrayManager& arr)
{
    if (playBtn.isClicked(mouse))
        controller.play();

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