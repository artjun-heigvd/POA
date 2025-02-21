#include "Thief.h"

#include <utility>

Thief::Thief(std::string name, std::shared_ptr<Cop> designatedCop)
    : Person(std::move(name)), designatedCop(std::move(designatedCop)) {}

Result Thief::isValid(const Container& container) const {
    if (container.getSize() == 1 || container.contains(designatedCop)){
        return Result::correct();
    } else {
        return Result::invalid(getName() + " présent avec d'autres membres sans " + designatedCop->getName());
    }
}
