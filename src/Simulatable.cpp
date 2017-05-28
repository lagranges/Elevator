#include "Simulatable.hpp"
#include "Simulator.hpp"

Simulatable::Simulatable()
{
    Simulator::getInstance()->addSimulatable(this);
}

Simulatable::~Simulatable(){}

void Simulatable::run(){}

void Simulatable::draw(){}

void Simulatable::reset(){}

