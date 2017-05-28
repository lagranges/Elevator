#ifndef PASSENGER_INCLUDED
#define PASSENGER_INCLUDED

#include <iostream>
#include <list>

#include "Simulatable.hpp"
#include "Elevator.hpp"
using namespace std;

// State transition process for a passenger
// INIT (waitting for control) -> OUT -> IN -> DONE
enum statePassenger {IN, OUT, INIT, DONE} ;

class Elevator;

class Passenger: public Simulatable
{
    private:
        int currentFloor;
        int departFloor;
        int destFloor;
        int weight;
        
        statePassenger state;

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
    

};

#endif // PASSENGER_INCLUDED
