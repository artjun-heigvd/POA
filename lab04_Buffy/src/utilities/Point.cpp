#include "Point.h"
#include <cmath>
#include <cstddef>

Point::Point(size_t x, size_t y) : x(x), y(y) {}

size_t Point::distance(Point a, Point b) {
    int dx = std::abs(static_cast<int>(a.x) - static_cast<int>(b.x));
    int dy = std::abs(static_cast<int>(a.y) - static_cast<int>(b.y));
    return std::max(dx, dy);
}

size_t Point::distance(Point other) {
    return distance(*this, other);
}

Point Point::direction(Point other) const {
    size_t xDir = other.x - x;
    size_t yDir = other.y - y;
    return {xDir, yDir};
}
