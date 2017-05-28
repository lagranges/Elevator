#include <iostream>
#include <unistd.h>

#include "Controller.hpp"

using namespace std;

int main()
{
    cout << "Welcome !" << endl;
    Controller *controller = new Controller();
    // passeger(int date, int depart, int destination, int weight)
    Passenger *p1 = new Passenger(3, 10, 19, 75);
    Passenger *p2 = new Passenger(3, 9, 4, 82);
    Passenger *p3 = new Passenger(6, 6, 9, 76);
    Passenger *p4 = new Passenger(10, 1, 18, 100);
    Passenger *p5 = new Passenger(19, 20, 2, 65);
    Passenger *p6 = new Passenger(22, 18, 4, 120);

    p1->reset();
    p2->reset();
    p3->reset();
    p4->reset();
    p5->reset();
    p6->reset();

    Simulator::getInstance()->restart();

    string s;
    while(1){
        cout << "SIMULATION$> ";
        cin >> s;
        Simulator::getInstance()->next();
    }
    
    return 0;
}
