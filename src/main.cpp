#include <iostream>
#include <unistd.h>

#include "Elevator.hpp"
#include "Simulator.hpp"

using namespace std;

int main()
{
    cout << "Welcome !" << endl;
    Elevator *e1 = new Elevator;
    Elevator *e2 = new Elevator;
    Simulator::getInstance()->restart();
    while(1){
        Simulator::getInstance()->next();
        usleep(500000);
    }
    return 0;
}
