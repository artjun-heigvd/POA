#include "Renderer.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Field.h"
#include "Humanoid.h"
#include "cstring"

void Renderer::runSimulationsAndPrintStats(size_t width, size_t height, size_t nbVampire, size_t nbHuman) {
    size_t nbWin = 0;
    for (size_t i = 0; i < NUMBER_OF_SIMULATIONS; ++i) {
        Field f(width, height, nbVampire, nbHuman);
        while (f.nextTurn()) {
            // Do nothing since the logic is done in the nextTurn method
        }
        if (f.getNbHuman()) { // If there are still humans alive
            ++nbWin;
        }
    }

    std::cout << std::fixed << std::setprecision(2);  // Set output format
    std::cout << "Win rate: " << static_cast<double>((double)nbWin / (double)NUMBER_OF_SIMULATIONS * 100) << "%" << std::endl;
    // Reset output format
    std::cout.unsetf(std::ios_base::fixed);
    std::cout << std::setprecision(6);
}

void Renderer::print(const Field& field) {
    printLine(field.getWidth() + 2);
    std::vector<std::vector<char>> grid(field.getHeight(), std::vector<char>(field.getWidth(), ' '));

    // Building grid
    for (const auto& humanoid : field.getHumanoids()) {
        auto position = humanoid->getPosition();
        grid.at(position.y).at(position.x) = LETTERS.at(humanoid->getType());
    }

    // Printing full grid
    std::string gridAsText;
    for (const auto& line : grid) {
        gridAsText += VERTICAL_BORDER;
        for (const auto cell : line) {
            gridAsText += cell;
        }
        gridAsText += VERTICAL_BORDER;
        gridAsText += "\n";
    }
    std::cout << gridAsText;
    printLine(field.getWidth() + 2);
}

void Renderer::printLine(size_t length) {
    std::string line;
    for (size_t i = 0; i < length; ++i) {
        line += HORIZONTAL_BORDER;
    }
    std::cout << line << std::endl;
}
