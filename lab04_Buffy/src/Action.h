#ifndef BUFFY_ACTION_H
#define BUFFY_ACTION_H

#include <cstddef>
#include "Humanoid.h"
#include "utilities/Point.h"
class Field;

/**
 * This class represents an Action.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class Action {
protected:
    // The humanoïd on which we want to apply the action
    std::weak_ptr<Humanoid> _target;

public:
    /**
     * Executes the action.
     *
     * @param f the field of the simulation
     */
    virtual void execute(Field& f) = 0;

    /**
     * Virtual destructor.
     */
    virtual ~Action() = default;

    /**
     * Constructor for a new Action.
     *
     * @param target the humanoïd on which we want to apply the action
     */
    explicit Action(const std::weak_ptr<Humanoid>& target);
};

#include "Field.h"

#endif  // BUFFY_ACTION_H
