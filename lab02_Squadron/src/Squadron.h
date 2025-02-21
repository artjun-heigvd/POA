#pragma once

#include <string>
#include "Ship.h"

/**
 * Class Squadron
 *
 * @author Haeffner Edwin
 * @author Junod Arthur
 * @author Roland Samuel
 */
class Squadron {
private:
    struct Node {
        Ship* ship;
        Node* next;
    };

    std::string name;
    Ship* headShip{};  // Leader of the squadron
    Node* first{};
    Node* last{};  // Allow us to add a ship to the squadron
    size_t size{};

    /**
     * Return the max speed of the squadron (Slowest ship) by iterating on all
     * ships
     * @return max speed of squadron
     */
    [[nodiscard]] unsigned int getMaxSpeed() const;

    /**
     * Return the total weight of the squadron
     * @return total weight of squadron
     */
    [[nodiscard]] long double getTotalWeight() const;

    /**
     * Verify that a ship belongs to this squadron
     * @return true if ship belongs to squadron
     */
    [[nodiscard]] bool belongToSquadron(const Ship& ship) const;

    void init();

    /**
     * Copy the ships of the given squadron into this
     * @param other the other squadron
     * @throw std::bad_alloc if memory allocation fails
     */
    void copyShips(const Squadron& other);

    /**
     * Delete all the nodes of our squadron
     */
    void deleteNodes();

public:
    /**
     * Constructor
     * @param name the name of the squadron
     */
    explicit Squadron(std::string name);

    /**
     * Sends to the stream the informations linked to the squadron
     * @param os the stream to write in
     * @return the stream
     */
    std::ostream& formatToStream(std::ostream& os) const;

    /**
     * Destructor
     */
    ~Squadron();

    /**
     * Copy constructor
     * @param other the Squadron to copy from
     */
    Squadron(const Squadron& other);

    /**
     * Move constructor
     * @param other the Squadron to move from
     */
    Squadron(Squadron&& other) noexcept;

    /**
     * Copy assignment operator
     * @param other the Squadron to copy from
     * @return the copied Squadron
     */
    Squadron& operator=(const Squadron& other);

    /**
     * Move assignment operator
     * @param other the Squadron to move from
     * @return the moved Squadron
     */
    Squadron& operator=(Squadron&& other) noexcept;

    /**
     * Get a ship in the squadron by its index number
     * @param index The index of the ship we want
     * @return A reference to the ship at the given index
     * @throw std::out_of_range if the index is out of range.
     */
    [[nodiscard]] Ship& getShip(size_t index) const;

    /**
     * Sets the leader of the squadron.
     * @param leader The ship to set as the leader.
     * @throw std::invalid_argument if the given ship does not belong to the
     * squadron.
     */
    void setLeader(Ship& leader);

    /**
     * Unset the leader (value is back to nullptr)
     */
    void dethroneLeader();

    /**
     * Checks if the squadron is empty.
     * @return True if the squadron is empty, false otherwise.
     */
    [[nodiscard]] bool isEmpty() const;

    /**
     * Returns the fuel consumption of the squadron for a given distance and
     * speed.
     * @param speed The speed at which to travel.
     * @param distance The distance to travel.
     * @return The fuel consumption of the squadron.
     * @throw std::invalid_argument if the given speed is not reachable by the
     * squadron.
     */
    [[nodiscard]] long double fuelConsRide(unsigned int speed,
                                           long double distance) const;

    /**
     * Return a new Squadron with the ship added
     * @param ship the ship to add
     * @return the new Squadron
     */
    Squadron* addShip(Ship& ship);

    /**
     * Return this Squadron with the ship added
     * @param ship the ship to add
     * @return this Squadron
     */
    Squadron& addShipToThis(Ship& ship);

    /**
     * Remove a given ship from the squadron
     * @param ship the ship we remove from the squadron
     * @return the new squadron
     */
    Squadron* removeShip(Ship& ship);

    /**
     * Remove a given ship from this squadron
     * @param ship the ship to remove
     * @return this squadron
     */
    Squadron& removeShipFromThis(Ship& ship);

    /**
     * uses std::exchange to swap the content of two squadrons
     * @param other the other squadron to exchange with
     */
    void exchange(Squadron& other);

    // Operator overloading
    Squadron& operator+=(Ship& ship);
    Squadron& operator-=(Ship& ship);
    Squadron operator+(Ship& rhs) const;
    Squadron operator-(Ship& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const Squadron& squadron);
    // Used to be able to use the operator+ and operator- the other way around
    friend Squadron operator+(Ship& lhs, const Squadron& rhs);
    friend Squadron operator-(Ship& lhs, const Squadron& rhs);
};