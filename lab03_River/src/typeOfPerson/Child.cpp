#include "Child.h"

#include <utility>

Child::Child(std::string name, std::shared_ptr<Parent> main, std::shared_ptr<Parent> second) : Person(std::move(name)), main(std::move(main)), second(std::move(second)) {}

bool Child::parentsPresenceValid(const Container& container) const {
    //We assume the child is in the container since we only call this function from the Boy or Girl's "isValid()"
    if (container.getSize() <= 1)
        return true;

    // If the primary parent is here, there is no problem
    if (container.contains(main))
        return true;

    // If the primary parent is not here, this is only valid
    //  if the secondary one is not present
    return !container.contains(second);
}
