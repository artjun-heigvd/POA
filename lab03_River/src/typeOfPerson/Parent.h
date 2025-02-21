#ifndef PARENT_H
#define PARENT_H
#include "../Person.h"

/**
 * Represents a Parent, which is a Person.
 *
 * @authors Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class Parent : public Person {
private:
public:

    /**
     * Constructor of the Parent class.
     *
     * @param name The name of the Parent.
     */
    explicit Parent(std::string);

    /**
     * Tells us if the person can drive
     *
     * @return true if the person can drive, false otherwise
     */
    [[nodiscard]] bool canDrive() const override;
};

#endif  // PARENT_H
