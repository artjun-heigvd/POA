#ifndef BUFFY_BITEACTION_H
#define BUFFY_BITEACTION_H

#include "KillAction.h"

/**
 * This class derives from KillAction and allow us to maybe transform our target instead of killing it.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class BiteAction : public KillAction {
public:
    /**
     * Constructor for a new BiteAction.
     *
     * @param target    the humanoïd on which we apply the action
     */
    explicit BiteAction(const std::weak_ptr<Humanoid>& target);

    /**
     * Executes the action.
     * One chance out of 2 that it transforms the target into a Vampire or kills it.
     *
     * @param f the field of the simulation
     */
    void execute(Field &f) override;
};

#endif  // BUFFY_BITEACTION_H
