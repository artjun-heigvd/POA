#include "ChaseAction.h"

ChaseAction::ChaseAction(const std::weak_ptr<Humanoid>& target,const std::weak_ptr<Humanoid>& chasedTarget) : MoveAction(target), _chasedTarget(chasedTarget) {}

void ChaseAction::execute(Field& field) {
    std::shared_ptr<Humanoid> hum = _chasedTarget.lock();
    if (hum) {
        moveToPosition(hum->getPosition());
        return;
    }
}
