#pragma once
#include <vector>
#include "ArrayManager.h"
#include "Sorter.h"
#include "Visualizer.h"

class UIManager;

class Controller {
public:
    Controller(ArrayManager&, Sorter&, Visualizer&, UIManager&);

    void play(const std::vector<SortStep>& steps);
    void pause();
    void reset(ArrayManager& arr);
    void nextStep();
    void previousStep();

    void update(float dt);
    void draw(sf::RenderWindow& window);

    void setSpeed(float speed);

    int getStepIndex() const { return stepIndex; }
    int getTotalSteps() const { return steps.size(); }
    std::string getStateString() const;


private:
    enum State {Idle, Playing, Paused} state;

    std::vector<SortStep> steps;
    int stepIndex;
    float timer;
    float timePerStep = 0.05f;

    ArrayManager& array;
    Sorter& sorter;
    Visualizer& visualizer;
    UIManager& ui;
};
