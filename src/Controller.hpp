#ifndef CONTROLLER_INCLUDED
#define CONTROLLER_INCLUDED

#include <iostream>

#include "Elevator.hpp"
#include "Simulator.hpp"
#include "Passenger.hpp"

using namespace std;

class Controller
{
    private:
        Elevator *e1,*e2;
        static Controller *_singleton; 
    public:
        Controller();
        ~Controller();
        static Controller *getInstance();
        void run();
};

#endif //CONTROLLER_INCLUDED
