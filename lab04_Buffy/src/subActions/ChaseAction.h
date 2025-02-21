#ifndef BUFFY_CHASEACTION_H
#define BUFFY_CHASEACTION_H

#include "MoveAction.h"

/**
 * This action allow us to chase after a target of a given type.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class ChaseAction : public MoveAction {
public:
    /**
     * Constructor for a new ChaseAction.
     *
     * @param target    the humanoïd on which we apply the action
     * @param chasedTarget the target we're chasing
     */
    ChaseAction(const std::weak_ptr<Humanoid>& target,const std::weak_ptr<Humanoid>& chasedTarget);

    /**
     * Executes the action.
     * Moves towards the chased target.
     *
     * @param field
     */
    void execute(Field& field) override;

private:
    std::weak_ptr<Humanoid> _chasedTarget;
};

#endif  // BUFFY_CHASEACTION_H
