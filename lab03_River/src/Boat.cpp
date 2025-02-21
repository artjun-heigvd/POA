#include "Boat.h"
#include "Container.h"
#include "Controller.h"
#include <iostream>


Boat::Boat(std::string name, Bank* current) : Container(std::move(name)), _current(current) {}

std::string Boat::toString() const {
    return "Bateau < " + listToString() + " >";
}

void Boat::setNewBank(Bank* current) {
    this->_current = current;
}

Bank* Boat::getCurrentBank() const {
    return _current;
}

bool Boat::canMove() const {
    return std::any_of(getOccupants().begin(), getOccupants().end(), [](const std::shared_ptr<Person>& person) {
        return person->canDrive();
    });
}

unsigned int Boat::getMaxCapacity() {
    return 2;
}