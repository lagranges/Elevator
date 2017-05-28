#include "Controller.hpp"

Controller::Controller()
{
    //empty
}

Controller::~Controller()
{
    //empty
}

Controller *Controller::getInstance()
{
    if(_singleton ==  NULL)
    {
        _singleton = new Controller;
        e1 = new Elevator("In the left");
        e2 = new Elevator("In the right") ;
    }
    return _singleton;
}

void Controller::run()
{
    for(list<Passenger*>::iterator it = Passenger::getList()->begin(); 
            it != Passenger::getList()->end(); it++)
    {
        StatePassenger state = (*it)->getState();
        switch(state)
        {
            case INIT:
                if((*it)->getDepartDate() == 
                        Simulator::getInstance()->getDate())
                {
                    if((*it)->getDepartFloor() % 2 == 0)
                    {
                        e2->addPassenger(*it);
                        (*it)->setElevator(e2);
                        (*it)->setState(OUT);
                    }
                    else
                    { 
                        e1->addPassenger(*it);
                        (*it)->setElevator(e1);
                        (*it)->setState(OUT);
                    }
                }
                break;
            case OUT:
                //Elevator *e = (*it).getElevator(); 
                //if(((*it)->getDepartFloor() == e->getCurrentFloor()) &&
                 //       (e->getState() ==  ))
                    break;
            case IN:
                break;
            case DONE:
                break;
        }
    } 
}

Controller *Controller::_singleton = NULL;
Elevator *Controller::e1 = NULL;
Elevator *Controller::e2 = NULL;

