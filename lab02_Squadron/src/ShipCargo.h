#pragma once

#include "Ship.h"

/**
 * The abstract class representing a ship but with a cargo
 * @author Haeffner Edwin
 * @author Junod Arthur
 * @author Roland Samuel
 */
class ShipCargo : public Ship {
public:
    /**
     * The constructor of our ship with cargo, it takes a capacity so that we
     * can give it from our derived ShipCargo and validate the load from it
     * @param load the current load of our ship
     * @param id the id of our ship
     * @param capacity the maximum capacity
     */
    explicit ShipCargo(long double load, unsigned int id, long double capacity);

    /**
     * Destructor
     */
    ~ShipCargo() override = default;

    /**
     * The total weight of our ship (ship's weight + load)
     * @return total weight
     */
    [[nodiscard]] long double getTotalWeight() const final;

    /**
     * Format the ship into an output stream
     * @param os the output stream to modify
     * @return the modified output stream
     */
    std::ostream& formatToStream(std::ostream& os) const override;

private:
    long double load;

    /**
     * Verify that the load is valid and doesn't exceed the capacity
     * @throws std::invalid_argument if the load exceed the capacity
     */
    [[nodiscard]] static long double validateLoad(long double loadTest,
                                                  long double capacity);

    /**
     * Return the entire model of our ship cargo
     * @return model
     */
    [[nodiscard]] std::string getModel() const final;

    /**
     * The name of the class (preceding "-class" in the model)
     * @return name of the class
     */
    [[nodiscard]] virtual std::string getClass() const = 0;

    /**
     * The name of the model (after the class in the model)
     * @return name of the model
     */
    [[nodiscard]] virtual std::string getNameModel() const = 0;

    /**
     * Get the total weight of the ship
     * @return the weight of the cargo ship
     */
    [[nodiscard]] virtual long double getWeight() const = 0;

    /**
     * Get the total capacity of the ship
     * @return the capacity of the cargo ship
     */
    [[nodiscard]] virtual long double getCapacity() const = 0;
};