#include "Vampire.h"
#include <iostream>
#include "../subActions/BiteAction.h"
#include "../subActions/ChaseAction.h"

Vampire::Vampire(size_t maxX, size_t maxY) : KillerHumanoid(maxX, maxY) {}

Vampire::Vampire(Point pos) : KillerHumanoid(pos) {}

Humanoid::Type Vampire::getType() const {
    return Humanoid::Type::VAMPIRE;
}
void Vampire::setAction(Field& f) {
    if(f.getNbHuman()){
        std::pair<std::shared_ptr<Humanoid>, bool> human = findHumanoidToAffect(f, Humanoid::Type::HUMAN);
        if (human.second) {
            _action = std::make_unique<KillAction>(human.first);
        } else {
            _action = std::make_unique<ChaseAction>(std::weak_ptr<Humanoid>(shared_from_this()), human.first);
        }
    } else {
        //Idle
    }

}

std::size_t Vampire::getMoveAmount() const {
    return 1;
}

