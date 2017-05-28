#include "Simulator.hpp"
#include "Controller.hpp"

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
    simulationDate++;
    Controller::getInstance()->run();   
    for(std::list<Simulatable*>::iterator it = listSimulatables.begin();
            it != listSimulatables.end(); it++){
        (*it)->run();
    }
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

int Simulator::getDate()
{
    return simulationDate;
}
Simulator *Simulator::_singleton = NULL;
