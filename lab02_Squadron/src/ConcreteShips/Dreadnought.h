#pragma once

#include "../ShipCargo.h"

/**
 * Class Dreadnought
 *
 * @author Haeffner Edwin
 * @author Junod Arthur
 * @author Roland Samuel
 */
class Dreadnought : public ShipCargo {
public:
    explicit Dreadnought(long double load);

    /**
     * @return the capacity of our Dreadnought
     */
    [[nodiscard]] long double getCapacity() const override;
    /**
     * @return the total weight of the cargo ship
     */
    [[nodiscard]] long double getWeight() const override;

private:
    /**
     * @return the class of the object as a std::string
     */
    [[nodiscard]] std::string getClass() const override;

    /**
     * @return the model name of the object as a std::string
     */
    [[nodiscard]] std::string getNameModel() const override;

    /**
     * @return the speed of the ship
     */
    [[nodiscard]] unsigned int getSpeed() const override;
};
