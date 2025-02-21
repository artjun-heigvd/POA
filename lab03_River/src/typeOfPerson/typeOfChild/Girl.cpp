#include "Girl.h"

#include <utility>

Girl::Girl(std::string name, std::shared_ptr<Parent> mother, std::shared_ptr<Parent> father) : Child(std::move(name), std::move(mother), std::move(father)) {}

Result Girl::isValid(const Container& container) const {
    if (parentsPresenceValid(container))
        return Result::correct();

    return Result::invalid("fille avec son pere sans sa mere");
}
