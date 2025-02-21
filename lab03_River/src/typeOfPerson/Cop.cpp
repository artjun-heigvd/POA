#include "Cop.h"

Cop::Cop(std::string name) : Person(std::move(name)) {}

bool Cop::canDrive() const {
    return true;
}

