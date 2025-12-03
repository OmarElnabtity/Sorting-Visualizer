#pragma once
#include <vector>
#include "ArrayManager.h"
#include "SortAlgorithm.h"
#include "Sorter.h"
#include "Visualizer.h"
using namespace std;

class UIManager;

class Controller {
public:
    Controller(ArrayManager&, Sorter&, Visualizer&, UIManager&);

    void play();
    void pause();
    void reset(ArrayManager& arr);
    void nextStep();
    void previousStep();

    void update(float dt);
    void draw(sf::RenderWindow& window);

    void setSpeed(float speed);
    void setAlgorithm(SortAlgorithm a) {algorithm = a;}

    int getStepIndex() const { return stepIndex; }
    int getTotalSteps() const { return steps.size(); }
    string getStateString() const;


private:
    enum State {Idle, Playing, Paused} state;

    vector<SortStep> steps;
    int stepIndex;
    float timer;
    float timePerStep = 0.05f;

    ArrayManager& array;
    Sorter& sorter;
    Visualizer& visualizer;
    UIManager& ui;
    SortAlgorithm algorithm;
};