#ifndef PASSENGER_INCLUDED
#define PASSENGER_INCLUDED

#include <iostream>
#include <list>

#include "Simulatable.hpp"
#include "Elevator.hpp"
using namespace std;

// State transition process for a passenger
// INIT (waitting for control) -> OUT -> IN -> DONE
enum StatePassenger {IN, OUT, INIT, DONE} ;

class Elevator;

class Passenger: public Simulatable
{
    private:
        int currentFloor;
        int departFloor;
        int destFloor;
        int weight;
        
        StatePassenger state;

        int departDate;
        static list<Passenger*> *listPassenger;
        int id;
        Elevator *elevator;   
    public:
        Passenger(int departFloor,int destFloor,
                int weight);
        Passenger(int departDate, 
                int departFloor, int destFloor, int weight);
        ~Passenger();
        static list<Passenger*> *getList();
        void run();
        void reset();
        void draw();
        void setElevator(Elevator *e);
        int getDepartDate();    
        int getDepartFloor();
        int getDestFloor();
        int getWeight();
        Elevator *getElevator();
        StatePassenger getState();
        void setState(StatePassenger s);
        void toString();
        bool goingUp();
};

#endif // PASSENGER_INCLUDED
