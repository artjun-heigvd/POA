#ifndef RIVER_RIVERGAME_H
#define RIVER_RIVERGAME_H


#include <functional>
#include <string>
#include <map>
#include "Controller.h"

/**
 * Contains the logic for the river game and the map of actions.
 *
 * @authors Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class RiverGame {
private:
    int _prompt;
    bool _gameWon;
    Controller& _controller;
    bool _shouldExit; // Boolean that is put to true when we end the game.
    // The map linking the string representation of the _actions to a function that executes it.
    std::unordered_map<char, std::function<void(std::string param)>> _actions;

    /**
     * Display the error if we give it a Result that is invalid.
     *
     * @param result The Result we want to log if invalid
     */
    void logResultErrorOrPrintController(const Result& result) const;

    /**
     * Show the menu of actions
     */
    static void showMenu();
public:
    /**
     * Constructor for the RiverGame.
     */
    RiverGame();

    /**
     * Run the game logic.
     */
    void run();
};




#endif //RIVER_RIVERGAME_H
