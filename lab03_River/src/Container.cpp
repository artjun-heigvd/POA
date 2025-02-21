#include "Container.h"

#include <cstddef>
#include <algorithm>
#include "Result.h"

Container::Container(std::string name) : _name(std::move(name)) {}

Result Container::isValid() const {
    for (const auto& person : _occupants) {
        auto result = person->isValid(*this);
        if (!result.status)
            return result;
    }
    return Result::correct();
}

void Container::add(const std::shared_ptr<Person>& p) {
    _occupants.emplace_back(p);
}

void Container::remove(const std::shared_ptr<Person>& p) {
    _occupants.remove(p);
}

std::shared_ptr<Person> Container::findByName(const std::string& name) const {
    for (const auto& person : _occupants) {
        if (person->getName() == name)
            return person;
    }
    return nullptr;
}

size_t Container::getSize() const {
    return _occupants.size();
}

bool Container::contains(std::shared_ptr<Person> searched) const {
    return std::any_of(_occupants.begin(), _occupants.end(), [&](const auto& person) {
        return person == searched;
    });
}

std::string Container::toString() const {
    return  _name + ": " + listToString();
}

std::string Container::listToString() const {
    std::string result;
    int count = 0;
    for (const auto& person : _occupants) {
        if (count++ > 0)
            result += " ";
        result += person->getName();
    }
    return result;
}

const std::list<std::shared_ptr<Person>> &Container::getOccupants() const {
    return _occupants;
}

void Container::clear() {
    _occupants.clear();
}

