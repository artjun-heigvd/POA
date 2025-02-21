#pragma once

#include "../TIEModel.h"

/**
 * TIE hunter class
 *
 * @author Haeffner Edwin
 * @author Junod Arthur
 * @author Roland Samuel
 */
class TIE : public TIEModel {
public:
    /**
     * Constructor of our TIE hunter
     */
    TIE();
    /**
     * The weight of our TIE hunter
     * @return the weight
     */
    [[nodiscard]] long double getTotalWeight() const override;

    /**
     * The speed of our TIE hunter
     * @return the speed
     */
    [[nodiscard]] unsigned int getSpeed() const override;

private:
    /**
     * The type "hunter" (LN) in string
     * @return type "hunter"
     */
    [[nodiscard]] std::string typeTIE() const override;
};
