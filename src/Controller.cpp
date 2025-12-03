#include "Controller.h"
#include "UIManager.h"

Controller::Controller(ArrayManager& arr, Sorter& s, Visualizer& v, UIManager& u)
    : state(Idle), stepIndex(0), timer(0), array(arr),
      sorter(s), visualizer(v), ui(u) {}

void Controller::play() {

    if (state == Idle) {
        switch (algorithm) {
            case SortAlgorithm::Bubble:
                steps = sorter.bubbleSort(array.get());
                break;

            case SortAlgorithm::Insertion:
                steps = sorter.insertionSort(array.get());
                break;

            case SortAlgorithm::Merge:
                steps = sorter.mergeSort(array.get());
                break;

            case SortAlgorithm::Quick:
                steps = sorter.quickSort(array.get());
                break;
        }

        stepIndex = 0;
    }

    state = Playing;
}

void Controller::pause() {
    if (state == Playing) state = Paused;
}

void Controller::reset(ArrayManager& arr) {
    arr.generateRandom();
    steps.clear();
    stepIndex = 0;
    state = Idle;
}

void Controller::nextStep() {
    if (state != Paused || stepIndex >= steps.size()) return;

    array.applyStep(steps[stepIndex]);
    stepIndex++;
}

void Controller::previousStep() {
    if (state !=  Paused || stepIndex <= 0) return;

    stepIndex--;
    array.undoStep(steps[stepIndex]);
}

void Controller::update(float dt) {
    if (state != Playing) return;

    timer += dt;
    if (timer > timePerStep) {
        if (stepIndex < steps.size()) {
            array.applyStep(steps[stepIndex]);
            stepIndex++;
        }
        else state = Idle;

        timer = 0;
    }
}

void Controller::draw(sf::RenderWindow& window) {
    int a = -1, b = -1;
    bool swap = false;

    if (state != Idle && stepIndex > 0 && stepIndex <= steps.size())
    {
        a = steps[stepIndex - 1].a;
        b = steps[stepIndex - 1].b;
        swap = steps[stepIndex - 1].swap;
    }

    visualizer.drawArray(window, array.get(), a, b, swap);
}

string Controller::getStateString() const
{
    switch (state) {
        case Idle: return "Idle";
        case Playing: return "Playing";
        case Paused: return "Paused";
    }
    return "Unknown";
}

void Controller::setSpeed(float speed) {
    if (speed <= 0.0f) return;
    timePerStep = speed;
}