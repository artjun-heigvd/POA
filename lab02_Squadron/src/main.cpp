#include <iostream>
#include "ConcreteShips/Dreadnought.h"
#include "ConcreteShips/Shuttle.h"
#include "ConcreteShips/TIE.h"
#include "Squadron.h"

using namespace std;

int main() {
    TIE blackLeader;
    blackLeader.setNickname("Black leader");
    TIE blackTwo;
    Shuttle shuttle(23.4);  // 23.4 tonnes de marchandises
    Squadron squad("Black Squadron");
    squad += blackLeader;
    cout << "Printing with only one ship in the squadron" << endl
         << squad << endl
         << endl;
    squad.setLeader(blackLeader);
    cout << "Printing with only one leader and nothing else" << endl
         << squad << endl
         << endl;
    squad += blackTwo;
    cout << "Printing with one leader and one member" << endl
         << squad << endl
         << endl;
    squad += shuttle;
    squad.dethroneLeader();
    cout << "Dethroning and printing the whole squadron with three members"
         << endl
         << squad << endl
         << endl;
    squad.setLeader(
        squad.getShip(0));  // Will grab the first ship, aka the blackLeader
    cout << squad << endl;

    cout << endl << "Testing the move constructor" << endl;
    // Test Move Constructor
    Squadron temp(std::move(squad));
    cout << temp << endl;
    cout << "Printing squad after the move (it's now empty)" << endl;
    cout << squad << endl;

    cout << endl << "Testing the assignement operator" << endl;
    // Test Move Assignment Operator
    Squadron timp("Tomp squadron");
    timp += blackLeader;
    timp += blackTwo;
    temp += shuttle;
    timp = temp;
    cout << timp << endl;

    cout << endl << "Testing the operators" << endl;
    // Test operators
    Squadron op("Op squad");
    TIE op1;
    op1.setNickname("op1");
    TIE op2;
    op2.setNickname("op2");

    op = op1 + op;
    op += op2;

    cout << op << endl;
    op = op - op1;
    op -= op2;

    cout << op << endl;

    cout << endl << "Testing fuel consumption" << endl;
    Squadron fuel("Fuel");
    fuel += blackLeader;
    fuel += blackTwo;
    cout << fuel.fuelConsRide(30, 50);
}