#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <array>
#include <list>
#include <functional>
#include <map>
#include <memory>
#include "Boat.h"
#include "Result.h"

const int LINE_LENGTH = 58; // Length of the line we use in the display

/**
 * Represents the _controller that handles the game logic and stores the state of the game
 *
 * @Authors: Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class Controller {
private:
    static const size_t LEFT = 0; // Index in the array for the left bank
    static const size_t RIGHT = 1; // Index int the array for the right bank

    std::list<std::shared_ptr<Person>> _persons; // List of all the persons available
    Boat _boat; // The container boat
    std::array<Bank, 2> _banks; // An array for the two container bank

    /**
     * Allow us to move a person from a container to another by giving the its name.
     *
     * @param name Name of the person we want to move.
     * @param from The container from which we want to find and move the person.
     * @param to The container where we want to move the person.
     * @return A Result that is correct if we could move the person (if invalid it gives the reason: didn't find the person, rules invalid, ...).
     */
    Result movePerson(const std::string& name, Container& from, Container& to);

    /**
     * Create the error message for the person we want to find if it's not found.
     *
     * @param name The name of the person we tried to find.
     * @param from The Container from which we wanted to find the person.
     * @return A String that represent the error for the person not found.
     */
    [[nodiscard]] std::string personNotFoundMessage(const std::string& name, const Container& from) const;

    /**
     * Allow us to easily fill the left bank with all the persons.
     */
    void fillLeftBank();

    Controller();


public:

    /**
     * Allow us to get the Singleton Instance of our Controller.
     * @return The instance of Controller.
     */
    static Controller& getInstance();

    Controller(const Controller& other) = delete;
    Controller(Controller&& other) = delete;
    Controller& operator=(const Controller& other) = delete;
    Controller& operator=(Controller&& other) = delete;

    /**
     * Embark a person to the boat
     * @param name of the person to embark
     * @return Result of the operation
     */
    Result embark(const std::string& name);

    /**
     * Disembark a person from the boat
     * @param name of the person to disembark
     * @return Result of the operation
     */
    Result disembark(const std::string& name);

    /**
     * Move the boat to the other bank
     * @return Result of the operation
     */
    Result moveBoat();

    /**
     * Prints the state of the boat and the banks.
     */
    void print() const;

    /**
     * Reset the game by putting every person in the left bank.
     */
    void reset();

    /**
     * Check if the game is won.
     * @return true if the game is won, false otherwise.
     */
    [[nodiscard]] bool hasWon() const;

};


#endif  // CONTROLLER_H
