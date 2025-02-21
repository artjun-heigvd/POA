#include "Field.h"
#include <list>
#include "humanoids/Buffy.h"
#include "humanoids/Human.h"
#include "humanoids/Vampire.h"
#include "utilities/Random.h"

const std::list<std::shared_ptr<Humanoid>>& Field::getHumanoids() const {
    return _humanoids;
}
Field::Field(size_t width, size_t height, size_t nbVampire, size_t nbHuman) {

    _turn = 0;
    _width = width;
    _height = height;
    _nbHuman = nbHuman;
    _nbVampire = nbVampire;

    for (size_t i = 0; i < nbHuman; ++i) {
        _humanoids.emplace_back(std::make_shared<Human>(width, height));
    }
    for (size_t i = 0; i < nbVampire; ++i) {
        _humanoids.emplace_back(std::make_shared<Vampire>(width, height));
    }
    _humanoids.emplace_back(std::make_shared<Buffy>(width, height));
}

bool Field::nextTurn() {
    // Déterminer les prochaines actions
    for (std::list<std::shared_ptr<Humanoid>>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++)
        (*it)->setAction(*this);
    // Executer les actions
    for (std::list<std::shared_ptr<Humanoid>>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++)
        (*it)->executeAction(*this);
    // Enlever les humanoides tués
    for (std::list<std::shared_ptr<Humanoid>>::iterator it = _humanoids.begin(); it != _humanoids.end();) {
        if (!(*it)->isAlive()) {
            std::shared_ptr<Humanoid> toDelete = *it;
            it = _humanoids.erase(it);  // suppression de l’élément dans la liste

            if (toDelete->getType() == Humanoid::Type::VAMPIRE){
                --_nbVampire;
            }
            else if (toDelete->getType() == Humanoid::Type::HUMAN){
                --_nbHuman;
            }
            toDelete.reset(); // destruction de l’humanoide référencé
        } else
            ++it;
    }
    ++_turn;

    return _nbVampire != 0;
}



std::shared_ptr<Humanoid> Field::getClosest(const std::shared_ptr<Humanoid>& from, Humanoid::Type type) const {
    Point posFrom = from->getPosition();
    size_t minDist = std::numeric_limits<size_t>::max();
    std::shared_ptr<Humanoid> minHum;

    for (const auto& hum : _humanoids) {
        if(hum == from)
            continue;
        if (hum->getType() == type) {
            size_t humDist = posFrom.distance(hum->getPosition());
            if (humDist < minDist) {
                minHum = hum;
                minDist = humDist;
            }
        }
    }
    return minHum;
}

void Field::incrementVampireCount() {
    ++_nbVampire;
}

size_t Field::getWidth() const {
    return _width;
}

size_t Field::getHeight() const {
    return _height;
}
void Field::addHumanoid(const std::shared_ptr<Humanoid>& hum) {
    _humanoids.push_back(hum);
}

size_t Field::getNbVampire() const {
    return _nbVampire;
}

size_t Field::getNbHuman() const {
    return _nbHuman;
}

int Field::getTurn() const {
    return _turn;
}

