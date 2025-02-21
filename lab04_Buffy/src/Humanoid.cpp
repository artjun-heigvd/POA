#include "Humanoid.h"
#include "utilities/Random.h"

Humanoid::Humanoid(size_t maxX, size_t maxY) : _position(Random::getRandomPos(0, maxX - 1, 0, maxY - 1)), _alive(true) {}
Humanoid::Humanoid(const Point& pos) : _position(pos), _alive(true) {}

Point Humanoid::getPosition() const {
    return _position;
}

void Humanoid::setPosition(Point position) {
    _position = position;
}

bool Humanoid::isAlive() const {
    return _alive;
}

void Humanoid::dies() {
    _alive = false;
}

void Humanoid::executeAction(Field& f) {
    if (isAlive()) {
        if (_action)
            _action->execute(f);
    }
}
