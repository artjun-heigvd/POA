#include "BiteAction.h"
#include "../humanoids/Vampire.h"
#include "../utilities/Random.h"

BiteAction::BiteAction(const std::weak_ptr<Humanoid>& target) : KillAction(target){}

void BiteAction::execute(Field &f){
    const auto &human = _target.lock();
    if(!human) {
        return;
    }
    if (human->isAlive()) {
        if(Random::getRandom(0,1)){
            //Make a new vampire
            f.addHumanoid(std::make_shared<Vampire>(human->getPosition()));
            f.incrementVampireCount();
        }
        KillAction::execute(f);
    }
}

