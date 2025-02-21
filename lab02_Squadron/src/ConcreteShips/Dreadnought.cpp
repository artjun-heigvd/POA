#include "Dreadnought.h"
#include <cmath>

Dreadnought::Dreadnought(long double load)
    : ShipCargo(load, counterId<Dreadnought>(), getCapacity()) {}

std::string Dreadnought::getClass() const {
    return "Super";
}

std::string Dreadnought::getNameModel() const {
    return "Star Destroyer";
}

unsigned int Dreadnought::getSpeed() const {
    return 40;
}

long double Dreadnought::getCapacity() const {
    return 250 * std::pow(10, 3);
}

long double Dreadnought::getWeight() const {
    return 9 * std::pow(10, 9);
}
