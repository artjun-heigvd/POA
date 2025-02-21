#pragma once

#include <string>
#include "Ship.h"
/**
 * An abstract class representing all the TIE model ship
 * @author Haeffner Edwin
 * @author Junod Arthur
 * @author Roland Samuel
 */
class TIEModel : public Ship {
public:
    /**
     * Contructor of TIE model ships
     * @param id id of the ship
     */
    explicit TIEModel(unsigned int id);

    /**
     * Destructor
     */
    ~TIEModel() override = default;

private:
    /**
     * A string of the TIE model
     * @return the model
     */
    [[nodiscard]] std::string getModel() const final;

    /**
     * The type of TIE (after the "TIE/")
     * @return type of TIE
     */
    [[nodiscard]] virtual std::string typeTIE() const = 0;
};
