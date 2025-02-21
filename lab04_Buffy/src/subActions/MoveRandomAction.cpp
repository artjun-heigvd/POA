#include "MoveRandomAction.h"
#include "../utilities/Random.h"

MoveRandomAction::MoveRandomAction(const std::weak_ptr<Humanoid>& target) : MoveAction(target) {}

void MoveRandomAction::execute(Field& f) {
    moveToPosition(Random::getRandomPos(0, f.getWidth() - 1, 0, f.getHeight() - 1));
}
