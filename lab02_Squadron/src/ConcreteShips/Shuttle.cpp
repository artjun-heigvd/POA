#include "Shuttle.h"

Shuttle::Shuttle(long double load)
    : ShipCargo(load, counterId<Shuttle>(), getCapacity()) {}

long double Shuttle::getWeight() const {
    return 360;
}

long double Shuttle::getCapacity() const {
    return 80;
}

unsigned int Shuttle::getSpeed() const {
    return 54;
}

std::string Shuttle::getClass() const {
    return "Lambda";
}

std::string Shuttle::getNameModel() const {
    return "shuttle";
}
