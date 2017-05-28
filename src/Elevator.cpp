#include <iostream>

#include "Elevator.hpp"
#include "Simulator.hpp"

Elevator::Elevator(string name)
{
    this->name = name;
    reset();
}

Elevator::~Elevator()
{
   // empty     
}

void Elevator::run()
{
    static bool up = true;
    if(up ){
        if(currentFloor == 19)
            up = false;
        currentFloor++;
    }
    else
        currentFloor--;
}

void Elevator::draw()
{
    cout << "  [Elevator] " << name
        << " [Current Floor] " << currentFloor << endl;
    for(list<Passenger*>::iterator it = listPassengers.begin()
            ; it != listPassengers.end() ; it++)
    {
        (*it)->toString();
    }
}

void Elevator::reset()
{
    currentFloor = 1;
    state = STOP;
}

int Elevator::getCurrentFloor()
{
    return currentFloor;  
}

void Elevator::addPassenger(Passenger *p)
{
    listPassengers.insert(listPassengers.begin(),p);
}

void Elevator::setState(StateElevator s)
{
   state = s; 
}

StateElevator Elevator::getState()
{
    return state;
}

string Elevator::getName()
{
    return name;
}
