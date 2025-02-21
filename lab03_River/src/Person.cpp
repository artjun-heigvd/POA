#include "Person.h"

#include <utility>

Person::Person(std::string name) : name(std::move(name)) {}

std::string Person::getName() const {
    return name;
}

bool Person::canDrive() const {
    return false;  // Default is false
}

Result Person::isValid(const Container &container) const {
    return Result::correct(); //By default is OK because no rules
}
