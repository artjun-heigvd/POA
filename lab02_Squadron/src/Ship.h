#pragma once

#include <optional>
#include <ostream>
#include <string>

/**
 * The abstract class representing our ships so that we can manipulate all kinds
 * easily
 *
 * @author Haeffner Edwin
 * @author Junod Arthur
 * @author Roland Samuel
 */
class Ship;
std::ostream& operator<<(std::ostream& os, const Ship& ship);

class Ship {
public:
    /**
     * Constructor
     * @param id id of our ship
     */
    explicit Ship(unsigned int id);

    /**
     * Destructor
     */
    virtual ~Ship() = default;

    /**
     * Format our ship to display into an output stream
     * @param os the output stream we modify
     * @return the modified output stream
     */
    virtual std::ostream& formatToStream(std::ostream& os) const;

    /**
     * Get the consumption of fuel by our ship for a given journey and speed
     * @throw invalid_argument if the given speed is higher that our ship's
     * speed
     * @param distance the distance we travel
     * @param speed the speed
     * @return fuel consumption
     */
    [[nodiscard]] long double getConsommation(long double distance,
                                              unsigned int speed) const;

    /**
     * Set the nickname of our ship
     * @param nick the nickname we give to our ship
     */
    void setNickname(const std::string& nick);

    /**
     * The total weight of our ship
     * @return total weight
     */
    [[nodiscard]] virtual long double getTotalWeight() const = 0;

    /**
     * Speed of our ship
     * @return speed
     */
    [[nodiscard]] virtual unsigned int getSpeed() const = 0;

private:
    unsigned int id;
    std::optional<std::string> nickName;

    /**
     * Model of our ship
     * @return model
     */
    [[nodiscard]] virtual std::string getModel() const = 0;
};

/**
 * Allow us to generate id for our ships easily, it will be called in their
 * constructor
 * @tparam T the concrete ship for which we create the id
 * @return a new id for this concrete ship
 */
template <typename T>
unsigned int counterId() {
    static unsigned int countId = 1;
    return countId++;
}
