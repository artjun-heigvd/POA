#ifndef BUFFY_VAMPIRE_H
#define BUFFY_VAMPIRE_H

#include "KillerHumanoid.h"

/**
 * This class represents a Vampire.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class Vampire : public KillerHumanoid {

public:
    /**
     * Constructor for a new Vampire.
     *
     * @param maxX  maximum value of it's x position
     * @param maxY  maximum value of it's y position
     */
    Vampire(size_t maxX, size_t maxY);

    /**
     * Constructor for a new Vampire.
     *
     * @param pos   the position of our new Vampire
     */
    explicit Vampire(Point pos);

    /**
     * The type of Vampire in enum Humanoid::Type
     *
     * @return type VAMPIRE from enum Humanoid::Type
     */
    Type getType() const override;

    /**
     * The number of cells it moves
     *
     * @return number of cells each move
     */
    std::size_t getMoveAmount() const override;

    /**
     * Set the action of our Vampire given the context (field)
     *
     * @param f the field of the simulation
     */
    void setAction(Field& f) override;


};

#endif  // BUFFY_VAMPIRE_H
