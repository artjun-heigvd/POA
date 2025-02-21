#ifndef BUFFY_BUFFY_H
#define BUFFY_BUFFY_H

#include "KillerHumanoid.h"

/**
 * This class represents Buffy.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class Buffy : public KillerHumanoid {

public:
    /**
     * Constructor for a new Buffy
     *
     * @param maxX  maximum value of x position
     * @param maxY  maximum value of y position
     */
    Buffy(size_t maxX, size_t maxY);

    /**
     * The type of Buffy in enum Humanoid::Type
     *
     * @return type BUFFY from enum Humanoid::Type
     */
    [[nodiscard]] Type getType() const override;

    /**
     * The number of cells it moves
     *
     * @return number of cells each move
     */
    [[nodiscard]] std::size_t getMoveAmount() const override;

    /**
     * Set the action of Buffy given the context (field)
     *
     * @param f the field of the simulation
     */
    void setAction(Field &f) override;

};

#endif  // BUFFY_BUFFY_H
