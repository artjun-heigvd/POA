//
// Created by ajun on 5/20/24.
//

#include <iostream>
#include <regex>
#include "RiverGame.h"

RiverGame::RiverGame() : _shouldExit(false), _prompt(0), _gameWon(), _controller(Controller::getInstance()){
    _actions = {
            {'p', [this](const std::string& param) { _controller.print(); }},
            {'e', [this](const std::string& param) { logResultErrorOrPrintController(_controller.embark(param)); _prompt++;}},
            {'d', [this](const std::string& param) {
                logResultErrorOrPrintController(_controller.disembark(param));
                _gameWon = _controller.hasWon();
                _prompt++;
            }},
            {'m', [this](const std::string& param) { logResultErrorOrPrintController(_controller.moveBoat()); _prompt++;}},
            {'r', [this](const std::string& param) { _controller.reset(); _prompt = 0;}},
            {'q', [this](const std::string& param) { _shouldExit = true; }},
            {'h', [](const std::string& param) { showMenu(); }},
    };
}

void RiverGame::logResultErrorOrPrintController(const Result &result) const {
    if (!result.status && result.reason.has_value()) {
        std::cout << "### " << result.reason.value() << std::endl;
    }else{
        _controller.print();
    }
}

void RiverGame::run() {
    std::string request;
    std::regex validateWithName("^[ed] [a-zA-Z]+$"); //Makes sure we cannot have multiple space before the name
    showMenu();
    _controller.print();

    do {
        std::cout << _prompt << "> ";
        getline(std::cin, request);

        if (request.empty())
            continue;

        char action = request.at(0);
        std::string param;

        if (request.length() > 2 && std::regex_match(request, validateWithName)) {
            param = request.erase(0, 2);
        } else if (request.length() != 1) {
            std::cout << "invalid action !" << std::endl;
            continue;
        }

        auto foundAction = _actions.find(action);
        if (foundAction != _actions.cend()) {
            foundAction->second(param);
        } else {
            std::cout << "action not found !" << std::endl;
        }
    } while(!_shouldExit && !_gameWon);

    if(_gameWon){
        _controller.print();
        std::cout << "Tout le monde est du bon côté, bien joué champion !!" << std::endl;
    }
}

void RiverGame::showMenu() {
    std::cout << "p : afficher" << std::endl
              << "e <nom>: embarquer <nom>" << std::endl
              << "d <nom>: debarquer <nom>" << std::endl
              << "m : deplacer bateau" << std::endl
              << "r : reinitialiser" << std::endl
              << "q : quitter" << std::endl
              << "h : menu" << std::endl;
}