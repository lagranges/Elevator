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
    departDate = Simulator::getInstance()->getDate();
}

void Passenger::draw()
{
    if(state == INIT)
    {
        cout <<"        Passenger ID = " << id << "weighing " << weight 
        << "kg" << " depart at " << departDate << " at floor " 
        << departFloor << " to go to floor " << destFloor <<  endl;
    }  
}

list<Passenger*> *Passenger::getList(){
    return listPassenger;
}

void Passenger::setElevator(Elevator *e)
{
    elevator = e;
}

list<Passenger*> *Passenger::listPassenger = new list<Passenger*>;
