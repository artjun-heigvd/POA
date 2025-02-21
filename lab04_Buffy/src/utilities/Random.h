#ifndef BUFFY_RANDOM_H
#define BUFFY_RANDOM_H

#include <random>
#include "../Field.h"
#include "Point.h"

/**
 * This class allow us to get random Point and random value between boundaries
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class Random {
private:
    // Static variable to get random numbers
    static std::random_device dev;
    static std::mt19937 rng;

public:
    /**
     * Give a random Point within the boundaries given ([min, max])
     *
     * @param minX  the minimum for the x value
     * @param maxX  the maximum for the x value
     * @param minY  the minimum for the y value
     * @param maxY  the maximum for the y value
     * @return      a new random Point
     */
    static Point getRandomPos(std::size_t minX, std::size_t maxX, std::size_t minY, std::size_t maxY);

    /**
     * Give a random size_t within the boundaries given ([min, max])
     *
     * @param min   minimum for size_t
     * @param max   maximum for size_t
     * @return      a random size_t
     */
    static std::size_t getRandom(std::size_t min, std::size_t max);
};

#endif  // BUFFY_RANDOM_H
