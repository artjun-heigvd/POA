#include "Random.h"

std::mt19937 Random::rng(std::random_device{}());

Point Random::getRandomPos(std::size_t minX, std::size_t maxX, std::size_t minY, std::size_t maxY) {
    std::uniform_int_distribution<std::size_t> posX_dist{minX, maxX};
    std::uniform_int_distribution<std::size_t> posY_dist{minY, maxY};
    return Point{posX_dist(rng), posY_dist(rng)};
}
std::size_t Random::getRandom(std::size_t min, std::size_t max) {
    return std::uniform_int_distribution<std::size_t>{min, max}(rng);
}
