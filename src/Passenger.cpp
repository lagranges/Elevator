#include <iostream>

#include "Passenger.hpp"
#include "Simulator.hpp"

using namespace std;

Passenger::Passenger(int departFloor, int destFloor, 
        int weight)
{
    this->currentFloor = departFloor;
    this->departFloor = departFloor;
    this->destFloor = destFloor;
    this->weight = weight;

    departDate = Simulator::getInstance()->getDate();
    listPassenger->insert(listPassenger->begin(), this);
    state = INIT;
    id = listPassenger->size();
    
}

Passenger::Passenger(int departDate, int departFloor
        , int destFloor, int weight)
{
    this->departDate = departDate;
    this->currentFloor = departFloor;
    this->departFloor = departFloor;
    this->destFloor = destFloor;
    this->weight = weight;

    listPassenger->insert(listPassenger->begin(), this);
    state = INIT;
    id = listPassenger->size();
}

Passenger::~Passenger()
{
    //empty
}
void Passenger::run()
{
}

void Passenger::reset()
{
    state = INIT;
   // departDate = Simulator::getInstance()->getDate();
}

void Passenger::draw()
{
    //empty
}

list<Passenger*> *Passenger::getList(){
    return listPassenger;
}

void Passenger::setElevator(Elevator *e)
{
    elevator = e;
}

int Passenger::getDepartDate()
{
    return departDate;
}

StatePassenger Passenger::getState()
{
    return state;
}

void Passenger::setState(StatePassenger s)
{
    state = s;
}

int Passenger::getDepartFloor()
{
    return departFloor;
}

int Passenger::getDestFloor()
{
    return destFloor;
}

int Passenger::getWeight()
{
    return weight;
}

Elevator *Passenger::getElevator()
{
    return elevator;
} 

bool Passenger::goingUp()
{
    return (destFloor - departFloor) > 0;
}

void Passenger::toString()
{ 
        cout <<"        [Passenger ID ] " << id << " [Kg ] " << weight 
        << " [depart time] " << departDate << "  [from floor] " 
        << departFloor << " [to go to floor] " << destFloor 
        <<  " [state] " << stateString[state] 
        << " [elevator] " << getElevator()->getName() << endl;
}

list<Passenger*> *Passenger::listPassenger = new list<Passenger*>;
