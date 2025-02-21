#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include "Field.h"
#include "Renderer.h"

using namespace std;

/**
 * Main function of our simulation, handles the launch arguments,
 *
 * @author Roland Samuel
 * @author Haeffner Edwin
 * @author Junod Arthur
 */
int main(int argc, char** argv) {
    // Game has default values of 50x50, 10 vampires and 20 humans
    size_t width = 50;
    size_t height = 50;
    size_t nbVampire = 10;
    size_t nbHuman = 20;

    if (argc >= 5) {
        width = atoll(argv[1]);
        height = atoll(argv[2]);
        nbVampire = atoll(argv[3]);
        nbHuman = atoll(argv[4]);
    }

    Field field(width, height, nbVampire, nbHuman);
    Renderer::print(field);

    bool quit = false;
    std::map<char, function<void()>> actions = {
        {'q', [&quit]() { quit = true; }}, {'s', [width,height,nbVampire,nbHuman]() { Renderer::runSimulationsAndPrintStats(width,height,nbVampire,nbHuman); }}, {'n', [&field]() {
                                                                                                          field.nextTurn();
                                                                                                          Renderer::print(field);
                                                                                                      }}};

    string action;
    while (!quit) {
        cout << "[" << field.getTurn() << "] q> quit s>tatistics n>ext: ";
        cin >> action;
        char id = action.at(0);
        if (actions.find(id) == actions.end()) {
            cout << "Invalid action" << endl;
            continue;
        }

        actions.at(id)();
    }
}

// Check de type OK ici pour vérifier si c'est un vampire ou non !