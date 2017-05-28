#ifndef SIMULATOR_INCLUDED
#define SIMULATOR_INCLUDED

#include <iostream>
#include <list>
#include "Elevator.hpp"
#include "Simulatable.hpp"

using namespace std;
class Simulator
{
    private:
        static Simulator* _singleton; // unique instance
        int simulationDate;
        //int lastDate;
        list<Simulatable*> listSimulatables;
    public:
        Simulator();
        ~Simulator();
        static Simulator* getInstance();
        void addSimulatable(Simulatable *s);
        void draw();
        void next();
        void restart();
        int getDate();
};

#endif // SIMULATOR_INCLUDED
