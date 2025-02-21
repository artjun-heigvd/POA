#pragma once

#include "../ShipCargo.h"

/**
 * The Shuttle class
 * @author Haeffner Edwin
 * @author Junod Arthur
 * @author Roland Samuel
 */
class Shuttle : public ShipCargo {
public:
    /**
     * The constructor of our Shuttle
     * @param load the current load
     */
    explicit Shuttle(long double load);

    /**
     * The weight of only the Shuttle
     * @return weight of only the ship
     */
    [[nodiscard]] long double getWeight() const override;

    /**
     * The speed of our Shuttle
     * @return the speed
     */
    [[nodiscard]] unsigned int getSpeed() const override;

private:
    /**
     * The max capacity Shuttle
     * @return the capacity
     */
    [[nodiscard]] long double getCapacity() const override;

    /**
     * The class "shuttle" in string
     * @return shuttle class
     */
    [[nodiscard]] std::string getClass() const override;

    /**
     * The model name of shuttle
     * @return the model name
     */
    [[nodiscard]] std::string getNameModel() const override;
};
