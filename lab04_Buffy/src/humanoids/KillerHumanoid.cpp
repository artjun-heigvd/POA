#include "KillerHumanoid.h"

KillerHumanoid::KillerHumanoid(size_t maxX, size_t maxY) : Humanoid(maxX, maxY) {}

KillerHumanoid::KillerHumanoid(const Point& pos) : Humanoid(pos) {}

std::pair<std::shared_ptr<Humanoid>, bool> KillerHumanoid::findHumanoidToAffect(const Field& f, Humanoid::Type type) const {
    // Get the current position of the Killer
    Point currPos = this->getPosition();

    //Get the closest type of humanoid
    std::shared_ptr<Humanoid> human = f.getClosest(std::const_pointer_cast<Humanoid>(shared_from_this()), type);

    //Return the closest humanoid and if it is in range
    return std::make_pair(human, human->getPosition().distance(currPos) <= _range);
}

