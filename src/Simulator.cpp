#include "Simulator.hpp"

Simulator::Simulator()
{
}
    
Simulator::~Simulator()
{
    // empty
}
 
Simulator* Simulator::getInstance()
{
    if(_singleton == NULL){
        _singleton = new Simulator;
    } 
    return _singleton;
}

void Simulator::addSimulatable(Simulatable *s)
{
    listSimulatables.insert(listSimulatables.begin(),s);
}

void Simulator::draw() 
{
    
    for(std::list<Simulatable*>::iterator it = listSimulatables.begin();
            it != listSimulatables.end(); it++){
        (*it)->draw();
    }
}

void Simulator::next() 
{
    
    for(std::list<Simulatable*>::iterator it = listSimulatables.begin();
            it != listSimulatables.end(); it++){
        (*it)->run();
    }
    simulationDate++;
    cout << "Step " << simulationDate << endl;
    draw();
}


void Simulator::restart() 
{
    
    for(std::list<Simulatable*>::iterator it = listSimulatables.begin();
            it != listSimulatables.end(); it++){
        (*it)->reset();
    }
    simulationDate = 0;
    cout << "Step " << simulationDate << endl;
    draw();
}

Simulator *Simulator::_singleton = NULL;
