#ifndef THIEF_H
#define THIEF_H
#include "../Container.h"
#include "../Person.h"
#include "Cop.h"

/**
 * Represents a Thief, which is a Person with special rules.
 *
 * @authors Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class Thief : public Person {
private:
    std::shared_ptr<Cop> designatedCop;

public:

    /**
     * Constructor for a Thief.
     *
     * @param name The name of the Thief.
     * @param designatedCop The Cop that is designated to monitor the Thief.
     */
    Thief(std::string name, std::shared_ptr<Cop> designatedCop);

    /**
     * Checks if the thief is in the same container as the designated cop if the thief isn't alone.
     * @param container to check the validity of
     * @return a Result object containing a message indicating if the placement is valid or not
     */
    [[nodiscard]] Result isValid(const Container& container) const override;
};

#endif  // THIEF_H
