#ifndef BUFFY_KILLACTION_H
#define BUFFY_KILLACTION_H

#include "../Action.h"

/**
 * This action kills the target it's given.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class KillAction : public Action {
public:
    /**
     * Constructor for a new KillAction.
     *
     * @param target    the humanoïd on which we apply the action
     */
    explicit KillAction(const std::weak_ptr<Humanoid>& target);

    /**
     * Executes the action.
     * Kills the target of this action.
     *
     * @param f the field of the simulation
     */
    void execute(Field &f) override;
};

#endif  // BUFFY_KILLACTION_H
