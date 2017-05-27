#ifndef ELEVATOR_INCLUDED
#define ELEVATOR_INCLUDED

#include <iostream>
#include <list>

#include "Simulatable.hpp"

using namespace std;
/**
 * STOP: elevator is stopping
 * STOP_UP: elevator is moving up but it's stopping for 
 * taking or releasing passengers
 *
 */
enum Etat {STOP, GOING_UP, GOING_DOWN, STOP_UP, STOP_DOWN};

class Elevator: public Simulatable
{
    private:
        #if 0
        int weight;
        #endif
        // currenFloor 1-40
        // 1-20 means elevator is in currentFloor going up
        int currentFloor; 
        /**
         * if movePlan[i] == 1 , elevator'll stop at 
         * date i (or i-20 or i-60)
         * movePlan[0] presents current Etat 
         */
         list<int> movePlan [60];     
         Etat etat;
         Etat nextEtat;
         int waitedTime;
    public:
        Elevator();
        ~Elevator();
        virtual void run();
        virtual void draw();
        virtual void reset();
        int getCurrentFloor();

};

#endif // ELEVATOR_INCLUDED
