#ifndef POINT_H
#define POINT_H
#include <cstddef>

/**
 * This class contains the data of a point in a 2D space.
 * It has some functions to calculate distance and direction to a point.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class Point {
public:
    // x and y values in a 2D space
    size_t x;
    size_t y;

    /**
     * Constructor for a new Point.
     *
     * @param x x value of our Point
     * @param y y value of our Point
     */
    Point(size_t x, size_t y);

    /**
     * Gives us the distance between two given points.
     *
     * @param a first Point
     * @param b second Point
     * @return  the distance between Point a and Point b
     */
    static size_t distance(Point a, Point b);

    /**
     * Gives us the distance between this Point and another.
     *
     * @param other the other Point
     * @return      the distance between this and the other
     */
    size_t distance(Point other);

    /**
     * The direction we have to follow to ge to the other Point from this Point.
     *
     * @param other the Point where we want to go
     * @return      the direction to the other Point
     */
    [[nodiscard]] Point direction(Point other) const;
};


#endif  // POINT_H
