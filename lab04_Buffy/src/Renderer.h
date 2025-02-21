#ifndef BUFFY_RENDERER_H
#define BUFFY_RENDERER_H
#include <cstddef>
#include <map>
#include "Humanoid.h"

const char HORIZONTAL_BORDER = '-';
const char VERTICAL_BORDER = '|';
const size_t NUMBER_OF_SIMULATIONS = 10000;

// Constants for the representation of the game field
static const std::map<Humanoid::Type, char> LETTERS = {
    {Humanoid::Type::BUFFY, 'B'},
    {Humanoid::Type::HUMAN, 'h'},
    {Humanoid::Type::VAMPIRE, 'v'},
};


/**
 * This class represents the Renderer that allow us to run the game and its logic.
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
class Renderer {
public:
    /**
     * @brief Runs a number of simulations and prints the statistics.
     *
     * This method runs a number of simulations and prints the win statistics.
     * The number of simulations is defined by the constant NUMBER_OF_SIMULATIONS.
     *
     * @param width The width of the game field.
     * @param height The height of the game field.
     * @param nbVampire The number of vampires in the game.
     * @param nbHuman The number of humans in the game.
     */
    static void runSimulationsAndPrintStats(size_t width, size_t height, size_t nbVampire, size_t nbHuman);

    /**
     * @brief Prints the game field.
     *
     * This method prints the game field. It uses the LETTERS map to represent each type of humanoid.
     *
     * @param field The game field to print.
     */
    static void print(const Field& field);

    /**
     * @brief Prints a line of a specified length.
     *
     * This method prints a line of a specified length. It uses the HORIZONTAL_BORDER character for the line.
     *
     * @param length The length of the line to print.
     */
    static void printLine(size_t length);
};

#endif  // BUFFY_RENDERER_H
