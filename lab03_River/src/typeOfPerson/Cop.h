#ifndef COP_H
#define COP_H
#include "../Person.h"

/**
 * Represents a Cop, which is a Person that can monitor a Thief.
 *
 * @authors Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class Cop : public Person {
public:

    /**
     * Constructor of a Cop.
     *
     * @param name The name of the Cop.
     */
    explicit Cop(std::string);

    /**
     * Tells us if the person can drive
     *
     * @return true if the person can drive, false otherwise
     */
    [[nodiscard]] bool canDrive() const override;
};

#endif  // COP_H
