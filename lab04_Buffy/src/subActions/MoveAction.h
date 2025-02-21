#include "../Action.h"
#include "../utilities/Point.h"

#ifndef BUFFY_MOVEACTION_H


/**
 * This class allow it's derived class to use the moveToPosition function.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class MoveAction : public Action {
public:
    /**
     * Constructor for a new MoveAction.
     *
     * @param target    the humanoïd on which we apply the action
     */
    explicit MoveAction(const std::weak_ptr<Humanoid>& target);

    /**
     * Move towards the position given.
     *
     * @param targetPos the position we want to move towards
     */
    void moveToPosition(const Point& targetPos);
};
#define BUFFY_MOVEACTION_H

#endif  // BUFFY_MOVEACTION_H
