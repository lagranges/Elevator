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

Passenger *Elevator::getLast()
{
    Passenger *p;
    for(list<Passenger*>::iterator it = listPassengers.begin();
        it != listPassengers.end(); it ++)
        p = (*it);
    return p;
}

void Elevator::run()
{
    StateElevator nextState = state;
    switch(state)
    {
        case STOP:
            if(listPassengers.size() != 0)
            {
                // the first one request
                int destFloor = 
                    getLast()->getDepartFloor();
                if(destFloor < currentFloor)
                {
                    nextState = GOING_DOWN;
                    for(list<Passenger*>::iterator it 
                            = listPassengers.begin();
                            it != listPassengers.end(); it ++)
                    // there a "go down " request at current floor
                    if((*it)->getDepartFloor()==currentFloor 
                            && !(*it)->goingUp())
                        nextState = STOP_DOWN;
                }
                else if(destFloor > currentFloor) 
                {
                    nextState = GOING_UP;
                    for(list<Passenger*>::iterator it 
                            = listPassengers.begin();
                            it != listPassengers.end(); it ++)
                    // there a "go up " request at current floor
                    if((*it)->getDepartFloor()==currentFloor 
                            && (*it)->goingUp())
                        nextState = STOP_DOWN;
                }
                else {
                    if(getLast()->goingUp()){
                        nextState = STOP_UP;
                        _waitedTime = 3;
                    }
                    else {
                        nextState = STOP_DOWN;
                        _waitedTime = 3;
                    }
                }
            }            
            break;
        case GOING_UP:
                currentFloor++;
                if(currentFloor == 20) {
                    nextState = STOP_DOWN;
                    _waitedTime = 3;
                }
                else if(checkCurrent(true)){
                    nextState = STOP_UP;
                    _waitedTime = 3;
                }
            break;
        case GOING_DOWN:
                currentFloor--;
                if(currentFloor == 0){
                    nextState = STOP_UP;
                    _waitedTime = 3;
                }
                else if(checkCurrent(false)){
                    nextState = STOP_DOWN;
                    _waitedTime = 3;
                }
            break;
        case STOP_UP:
            // for out or in (but to go up)
            if(_waitedTime != 0){
                 
                for(list<Passenger*>::iterator it = 
                        listPassengers.begin(); 
                        it != listPassengers.end() ; it++)
                {
                    if(interrestedFloor((*it), true) == currentFloor)
                    {
                        if((*it)->getState() == IN ){
                            (*it)->setState(DONE);
                            removePassenger(*it);
                        }
                        else if((*it)->getState() == OUT) {
                            (*it)->setState(IN); 
                        }

                    }
                    
                }
                _waitedTime --;
            }
            else if(listPassengers.size() == 0)
                nextState = STOP;
            else 
                nextState = GOING_UP;
            break;
        case STOP_DOWN:
            if(_waitedTime != 0){
                 
                for(list<Passenger*>::iterator it = 
                        listPassengers.begin(); 
                        it != listPassengers.end() ; it++)
                {
                    if(interrestedFloor((*it), false) == currentFloor)
                    {
                        if((*it)->getState() == IN ){
                            (*it)->setState(DONE);
                            removePassenger(*it);
                        }
                        else if((*it)->getState() == OUT) {
                            (*it)->setState(IN); 
                        }

                    }
                    
                }
                _waitedTime --;
            }
            else if(listPassengers.size() == 0)
                nextState = STOP;
            else 
                nextState = GOING_DOWN;
            break;
    }
    state = nextState;
}



// interrested floor : the floor elevator have to go there
// above = true -> return nearest interested floor above
// above = false -> return nearest interested floor below
//int getNearest(bool above, bool )
//{
//    int returnUp , returnDown;
//    int minUp = returnUp - currentFloor,
//        minDown = currentFloor - returnDown; 
//    for(list<Passenger*>::iterator it = listPassengers.begin();
//            it != listPassengers.end(); i ++)
//    {
//       if() 
//    }
//}

int Elevator::nbPassengerIn()
{
    int nb = 0;
    for(list<Passenger*>::iterator it = listPassengers.begin()
            ; it != listPassengers.end() ; it++)
    {
        if((*it)->getState() == IN)
            nb++;
    }
    return nb;
}

bool Elevator::checkCurrent(bool up)
{
    for(list<Passenger*>::iterator it = listPassengers.begin()
            ; it != listPassengers.end() ; it++)
    {
        if(interrestedFloor((*it), up) == currentFloor)
            return true;
    }
    return false;
}

int Elevator::interrestedFloor(Passenger *p, bool up){
    if(p->getState() == IN)
    {
        return p->getDestFloor();
    } else if(p->getState() == OUT) 
    {
        if(p->goingUp()==up)
        return p->getDepartFloor();
    }
    return 0;
}

void Elevator::draw()
{
    cout << "  [Elevator] " << name
        << " [Current Floor] " << currentFloor 
        << " [State] " << stateEString[state] << endl;
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

void Elevator::removePassenger(Passenger *p)
{
    for(list<Passenger*>::iterator it = listPassengers.begin()
            ; it != listPassengers.end() ; it++)
    {
        if((*it) == p)
        {
            listPassengers.erase(it);
            return;
        }
    }
}
