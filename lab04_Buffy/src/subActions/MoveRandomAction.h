#ifndef BUFFY_MOVERANDOMACTION_H
#define BUFFY_MOVERANDOMACTION_H

#include "MoveAction.h"

/**
 * This action picks a random position and move towards it.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class MoveRandomAction : public MoveAction {
public:
    /**
     * Constructor for a new MoveRandomAction.
     *
     * @param target    the humanoïd on which we apply the action
     */
    explicit MoveRandomAction(const std::weak_ptr<Humanoid>& target);

    /**
     * Executes the action.
     * Get a random position and move towards it.
     *
     * @param f the field fo the simluation
     */
    void execute(Field& f) override;
};

#endif  // BUFFY_MOVERANDOMACTION_H
