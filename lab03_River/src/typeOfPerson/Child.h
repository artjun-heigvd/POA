#ifndef ENFANT_H
#define ENFANT_H
#include "../Person.h"
#include "Parent.h"

/**
 * Represents a child, which is a person with two parents.
 *
 * @Authors: Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class Child : public Person {
private:
    // Pointer because we need to compare them with the container list of pointers
    std::shared_ptr<Parent> main;
    std::shared_ptr<Parent> second;
protected:

    /**
     * Checks if the main parent is present in the container. If not, it checks if the second parent is present.
     *
     * @param container The container to check for the presence of the child's parents.
     * @return true if the primary parent is present, false if the secondary parent is present without the primary one.
     */
    [[nodiscard]] bool parentsPresenceValid(const Container& container) const;

public:

    /**
     * Constructor for the Child class.
     *
     * @param name The name of the child.
     * @param main The main parent of the child.
     * @param second The secondary parent of the child.
     */
     Child(std::string name, std::shared_ptr<Parent> main, std::shared_ptr<Parent> second);
};

#endif  // ENFANT_H
