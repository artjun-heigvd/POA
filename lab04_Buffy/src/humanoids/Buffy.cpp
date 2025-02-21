#include "Buffy.h"
#include "../subActions/ChaseAction.h"
#include "../subActions/KillAction.h"
#include "../subActions/MoveRandomAction.h"

Buffy::Buffy(size_t maxX, size_t maxY) : KillerHumanoid(maxX, maxY) {}

Humanoid::Type Buffy::getType() const {
    return Humanoid::Type::BUFFY;
}

std::size_t Buffy::getMoveAmount() const {
    return 2;
}
void Buffy::setAction(Field& f) {
    if (!f.getNbVampire()) {
        _action = std::make_unique<MoveRandomAction>(std::weak_ptr<Humanoid>(shared_from_this()));
    } else {
        std::pair<std::shared_ptr<Humanoid>, bool> vampire = findHumanoidToAffect(f, Humanoid::Type::VAMPIRE);
        if (vampire.second) {
            _action = std::make_unique<KillAction>(vampire.first);
        } else {
            _action = std::make_unique<ChaseAction>(std::weak_ptr<Humanoid>(shared_from_this()), vampire.first);
        }
    }
}
