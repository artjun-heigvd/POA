#include "Parent.h"

Parent::Parent(std::string name) : Person(std::move(name)) {}

bool Parent::canDrive() const {
    return true;
}

