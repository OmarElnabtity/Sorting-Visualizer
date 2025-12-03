#include "Controller.h"
#include "UIManager.h"

Controller::Controller(ArrayManager& arr, Sorter& s, Visualizer& v, UIManager& u)
    : state(Idle), stepIndex(0), timer(0), array(arr),
      sorter(s), visualizer(v), ui(u) {}

void Controller::play() {   //plays sorting visualizer

    if (state == Idle) {    //if state were IDLE, calculate steps vector based on sorting algorithm
        switch (algorithm) {
            case SortAlgorithm::Bubble:
                steps = sorter.bubbleSort(array.get());
                break;

            case SortAlgorithm::Insertion:
                steps = sorter.insertionSort(array.get());
                break;

            case SortAlgorithm::Selection:
                steps = sorter.selectionSort(array.get());
                break;

            case SortAlgorithm::Merge:
                steps = sorter.mergeSort(array.get());
                break;

            case SortAlgorithm::Quick:
                steps = sorter.quickSort(array.get());
                break;
        }

        stepIndex = 0;  //initialize step index
    }

    state = Playing;   //update status
}

void Controller::pause() {      //pause visualizer if status were PLAYING
    if (state == Playing) state = Paused;
}

void Controller::reset(ArrayManager& arr) {     //reset array and steps
    arr.generateRandom();
    steps.clear();
    stepIndex = 0;
    state = Idle;       //status is IDLE
}

void Controller::nextStep() {
    if (state != Paused || stepIndex >= steps.size()) return;   //do nothing if status is not PAUSED

    array.applyStep(steps[stepIndex]);      //apply next step
    stepIndex++;                            //increment step index
}

void Controller::previousStep() {
    if (state !=  Paused || stepIndex <= 0) return;            //do nothing if status is not PAUSED

    stepIndex--;                            //decrement step index
    array.undoStep(steps[stepIndex]);       //apply previous step
}

void Controller::update(float dt) {
    if (state != Playing) return;           //do nothing if status is not PLAYING

    timer += dt;                            //add delta time to timer
    if (timer > timePerStep) {              //if timer is over the predefined time per step, then apply next step
        if (stepIndex < steps.size()) {
            array.applyStep(steps[stepIndex]);
            stepIndex++;
        }
        else state = Idle;                  //status is IDLE if stepIndex = steps.size

        timer = 0;                          //reset timer
    }
}

void Controller::draw(sf::RenderWindow& window) {
    int a = -1, b = -1;
    bool swap = false;

    if (state != Idle && stepIndex > 0 && stepIndex <= steps.size())    //get data of last step if sorting is playing
    {
        a = steps[stepIndex - 1].a;
        b = steps[stepIndex - 1].b;
        swap = steps[stepIndex - 1].swap;
    }

    visualizer.drawArray(window, array.get(), a, b, swap);      //draw last step
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

void Controller::setSpeed(float speed) {    //defines time per step to adjust speed of visualizer
    if (speed <= 0.0f) return;
    timePerStep = speed;
}