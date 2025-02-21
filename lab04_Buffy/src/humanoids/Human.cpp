#include "Human.h"
#include "../subActions/MoveRandomAction.h"

Human::Human(size_t maxX, size_t maxY) : Humanoid(maxX, maxY) {}

Humanoid::Type Human::getType() const {
    return Humanoid::Type::HUMAN;
}

std::size_t Human::getMoveAmount() const {
    return 1;
}
void Human::setAction(Field& f) {
    _action = std::make_unique<MoveRandomAction>(std::weak_ptr<Humanoid>(shared_from_this()));
}
