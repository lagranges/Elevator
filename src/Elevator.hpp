#ifndef ELEVATOR_INCLUDED
#define ELEVATOR_INCLUDED

#include <iostream>
#include <list>

#include "Simulatable.hpp"
#include "Passenger.hpp"

using namespace std;
/**
 * STOP: elevator is stopping
 * STOP_UP: elevator is moving up but it's stopping for 
 * taking or releasing passengers
 *
 */
enum StateElevator {STOP = 0, GOING_UP, GOING_DOWN, STOP_UP, STOP_DOWN};

static const char* stateEString[] = {"STOP", "GOING UP", "GOING DOWN", "STOP UP", "STOP DOWN"};

class Passenger;

class Elevator: public Simulatable
{
    private:
        // currenFloor 1-40
        // 1-20 means elevator is in currentFloor going up
        int currentFloor;
        string name; 
        StateElevator state;
        int _waitedTime;
        list<Passenger*> listPassengers;
        bool checkCurrent(bool up);
        int interrestedFloor(Passenger *p, bool up);
    public:
        Elevator(string name);
        ~Elevator();
        virtual void run();
        virtual void draw();
        virtual void reset();
        int getCurrentFloor();
        void addPassenger(Passenger *p);
        void removePassenger(Passenger *p);
        StateElevator getState();
        void setState(StateElevator s);
        string getName();
        Passenger *getLast();
        int nbPassengerIn();
};

#endif // ELEVATOR_INCLUDED
