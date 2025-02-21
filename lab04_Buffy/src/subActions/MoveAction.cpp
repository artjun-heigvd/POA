#include "MoveAction.h"
#include <complex>
#include <iostream>

MoveAction::MoveAction(const std::weak_ptr<Humanoid>& target) : Action(target) {}

void MoveAction::moveToPosition(const Point& targetPos) {
    for(size_t i = 0; i < _target.lock()->getMoveAmount(); i++) {
        // Get the current position of the character
        Point currPos = _target.lock()->getPosition();

        int x_ = static_cast<int>(currPos.x - targetPos.x);
        int y_ = static_cast<int>(currPos.y - targetPos.y);

        Point newPos(currPos.x - (x_ == 0 ? 0 : x_ / std::abs(x_)) ,
                     currPos.y - (y_ == 0 ? 0 : y_ / std::abs(y_)));

        // Move the character to the new position
        _target.lock()->setPosition(newPos);
    }
}

