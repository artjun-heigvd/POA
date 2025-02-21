#ifndef CONTAINER_H
#define CONTAINER_H
#include <iterator>
#include <list>
#include <string>
#include <vector>
#include <memory>
#include "Result.h"
class Person;

/**
 *  Container that can have occupants and methods to get its properties and check its validity.
 *
 *  @authors Junod Arthur, Roland Samuel, Häffner Edwin.
 *  @date 18.04.2024
 */
class Container {
private:
    std::string _name;
    std::list<std::shared_ptr<Person>> _occupants;

protected :
    /**
     * Getter for the list of occupants of the container.
     *
     * @return The list of occupants.
     */
    [[nodiscard]] const std::list<std::shared_ptr<Person>>& getOccupants() const;

    /**
     * Create a string to represent the list of occupants.
     *
     * @return A string representative of the occupants.
     */
    [[nodiscard]] std::string listToString() const;

public:
    /**
     * Constructor.
     *
     * @param name Name of the container.
     */
    explicit Container(std::string name);

    /**
     * Check that all of the rules of the container are respected.
     *
     * @return A Result with the validity of the container (if not valid it will give the reason through it).
     */
    [[nodiscard]] Result isValid() const;

    /**
     * Add a person to the container.
     *
     * @param p The person we want to add.
     */
    void add(const std::shared_ptr<Person>&);

    /**
     * Remove a person to the container.
     *
     * @param p The person we want to remove.
     */
    void remove(const std::shared_ptr<Person>&);

    /**
     * Find a person in the list of the occupants of the container.
     *
     * @param name Name of the person we want to find.
     * @return The person if we found it otherwise nullptr.
     */
    [[nodiscard]] std::shared_ptr<Person> findByName(const std::string& name) const;

    /**
     * Get the number of occupants of the container.
     *
     * @return The number of occupants
     */
    [[nodiscard]] std::size_t getSize() const;

    /**
     * Check if the person given is in this container.
     *
     * @param searched The person we search in the container.
     * @return true if the person was found.
     */
    [[nodiscard]] bool contains(std::shared_ptr<Person> searched) const;

    /**
     * Create a string to represent the container.
     *
     * @return A string representative of the container.
     */
    [[nodiscard]] virtual std::string toString() const;

    /**
     * Empty the list of occupants
     */
    void clear();
};

#include "Person.h"  //after class declaration

#endif  // CONTAINER_H
