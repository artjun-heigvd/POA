#ifndef PERSON_H
#define PERSON_H
#include <list>
#include <string>

#include "Container.h"
#include "Result.h"

/**
 * Represents a Person
 *
 * @authors Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class Person {
private:
    std::string name;

public:

    /**
     * Construct a new Person object
     *
     * @param name
     */
    explicit Person(std::string name);


    virtual ~Person() = default;

    /**
     * Tells us if the person can drive
     *
     * @return true if the person can drive, false otherwise
     */
    [[nodiscard]] virtual bool canDrive() const;

    /**
     * Tells us if the person's placement in the provided container is valid
     * @param container to check the validity of
     * @return a Result object containing a message indicating if the placement is valid or not
     */
    [[nodiscard]] virtual Result isValid(const Container& container) const;

    /**
     * Get the name of the person
     *
     * @return the name of the person
     */
    [[nodiscard]] std::string getName() const;
};

#endif  // PERSON_H
