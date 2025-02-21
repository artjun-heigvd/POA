#ifndef BUFFY_FIELD_H
#define BUFFY_FIELD_H

#include <list>
#include <memory>
#include "Humanoid.h"

class Humanoid;

/**
 * This class represents the Field of the simulation.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class Field {
public:

    /**
     * Constructor for a new Field.
     *
     * @param width     the width of the actual field
     * @param height    the height of the actual field
     * @param nbVampire the number of Vampire at the start of the game
     * @param nbHuman   the number of Human at the start of the game
     */
    Field(size_t width, size_t height, size_t nbVampire, size_t nbHuman);

    /**
     * Advance the simulation of one turn (action).
     *
     * @return  true if there's still humans or vampires in the field, false otherwise, as the game is over.
     */
    bool nextTurn();

    /**
     * Get the closest Humanoïd of type given from the humanoïd given
     *
     * @param from  the humanoïd from which we want to search
     * @param type  the type of humanoïd we research
     * @return      the closest humanoïd from the given one
     */
    [[nodiscard]] std::shared_ptr<Humanoid> getClosest(const std::shared_ptr<Humanoid>& from, Humanoid::Type type) const;

    /**
     * Get the max width of the field
     * @return
     */
    [[nodiscard]] size_t getWidth() const;

    /**
     * Get the max height of the field
     * @return
     */
    [[nodiscard]] size_t getHeight() const;

    /**
     * Get the number of Vampire in the field
     * @return
     */
    [[nodiscard]] size_t getNbVampire() const;

    /**
    * Get the number of Human in the field
    * @return
    */
    [[nodiscard]] size_t getNbHuman() const;

    /**
     * Get the current turn of the simulation
     * @return
     */
    [[nodiscard]] int getTurn() const;

    /**
     * Add a humanoïd to our simulation.
     *
     * @param hum   the humanoïd we want to add to our simulation
     */
    void addHumanoid(const std::shared_ptr<Humanoid>& hum);

    /**
     * Increment our number of Vampire in our simulation.
     */
    void incrementVampireCount();


    void operator=(const Field&) = delete;

    /**
     * Get the list of humanoïds
     * @return
     */
    [[nodiscard]] const std::list<std::shared_ptr<Humanoid>>& getHumanoids() const;

private:
    std::list<std::shared_ptr<Humanoid>> _humanoids;
    int _turn;
    size_t _width;
    size_t _height;
    size_t _nbVampire;
    size_t _nbHuman;
};
#include "Humanoid.h"

#endif  // BUFFY_FIELD_H
