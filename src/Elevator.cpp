#include <iostream>

#include "Elevator.hpp"
#include "Simulator.hpp"

Elevator::Elevator()
{
    reset();
    Simulator::getInstance()->addSimulatable(this);
}

Elevator::~Elevator()
{
   // empty     
}

void Elevator::run()
{
    if(currentFloor < 19)
        currentFloor++;
    else
        currentFloor--;
}

void Elevator::draw()
{
    cout << "   I'm in Floor" << currentFloor << endl;
}

void Elevator::reset()
{
    //weight = 0;
    currentFloor = 1;
    etat = STOP;
}

int Elevator::getCurrentFloor()
{
    return currentFloor;  
}
