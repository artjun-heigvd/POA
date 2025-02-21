#ifndef BUFFY_HUMAN_H
#define BUFFY_HUMAN_H

#include "../Humanoid.h"

/**
 * This class represents a Human.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class Human : public Humanoid {

public:

    /**
     * Constructor for a new Human
     *
     * @param maxX  maximum value of x position
     * @param maxY  maximum value of y position
     */
    Human(size_t maxX, size_t maxY);

    /**
     * The type of Human in enum Humanoid::Type
     *
     * @return type HUMAN from enum Humanoid::Type
     */
    Type getType() const override;

    /**
     * The number of cells it moves
     *
     * @return number of cells each move
     */
    std::size_t getMoveAmount() const override;

    /**
     * Set the action of our Human given the context (field)
     *
     * @param f the field of the simulation
     */
    void setAction(Field &f) override;

};

#endif  // BUFFY_HUMAN_H
