#include "Boy.h"

#include <utility>

Boy::Boy(std::string name, std::shared_ptr<Parent> mother, std::shared_ptr<Parent> father) : Child(std::move(name), std::move(father), std::move(mother)) {}

Result Boy::isValid(const Container& container) const {
    if (parentsPresenceValid(container))
        return Result::correct();

    return Result::invalid("garcon avec sa mere sans son pere");
}
