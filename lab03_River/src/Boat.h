#ifndef BOAT_H
#define BOAT_H
#include "Bank.h"
#include "Container.h"

/**
 * Container with all the persons on the boat, it comes with
 * methods to get it's properties or move it from one bank to another.
 *
 * @authors Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class Boat : public Container {
private:
    Bank* _current;  // Current bank on which the boat is docked
public:
    /**
     * Constructor of the boat.
     *
     * @param name Name of the boat.
     * @param current The bank on which it is docked.
     */
    Boat(std::string name, Bank* current);

    /**
     * Create a string that can represent the boat.
     *
     * @return Boat to string..
     */
    [[nodiscard]] std::string toString() const override;

    /**
     * Set the bank on which the boat is docked to a new one.
     *
     * @param current The new bank.
     */
	void setNewBank(Bank* current);

    /**
     * Getter for the current bank.
     *
     * @return The current bank.
     */
    [[nodiscard]] Bank* getCurrentBank() const;

    /**
     * Check if any of the occupants of the boat can drive it.
     *
     * @return True if any of the occupants can drive it.
     */
    [[nodiscard]] bool canMove() const;

    /**
     * Getter for the max capacity of the boat.
     *
     * @return Max capacity.
     */
    static unsigned getMaxCapacity();
};

#endif  // BOAT_H
