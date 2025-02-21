#include "Controller.h"

#include <iostream>
#include <array>
#include <memory>
#include "typeOfPerson/Cop.h"
#include "typeOfPerson/Thief.h"
#include "typeOfPerson/typeOfChild/Boy.h"
#include "typeOfPerson/typeOfChild/Girl.h"


Controller::Controller()
        : _banks{Bank("Gauche"), Bank("Droite")}, _boat("Bateau", nullptr) { // Init _persons of the game

    _boat.setNewBank(&_banks.at(LEFT));
    auto pere = std::make_shared<Parent>("pere");
    auto mere = std::make_shared<Parent>("mere");
    auto policier = std::make_shared<Cop>("policier");
    _persons = {pere,
                mere,
                std::make_shared<Boy>("paul", mere, pere),
                std::make_shared<Boy>("piere", mere, pere),
                std::make_shared<Girl>("julie", mere, pere),
                std::make_shared<Girl>("jeanne", mere, pere),
                policier,
                std::make_shared<Thief>("voleur", policier)};

    fillLeftBank();
}

Result Controller::movePerson(const std::string& name, Container& from, Container& to){
    const size_t FROM_INDEX = 0;
    const size_t TO_INDEX = 1;

    if (name.empty())
        return Result::invalid("Aucune personne n'a été spécifiée");
    std::shared_ptr person = from.findByName(name);
    if (!person)
        return Result::invalid(personNotFoundMessage(name,from));

    //Making a copy of from and to, so we can simulate what's happening in them
    std::array<Container, 2> simulis{Container(from), Container(to)};

    simulis.at(FROM_INDEX).remove(person);
    simulis.at(TO_INDEX).add(person);

    for(auto& simul : simulis){
        Result res = simul.isValid();
        if(!res.status){
            return res;
        }
    }

    std::swap(from, simulis.at(FROM_INDEX));
    std::swap(to, simulis.at(TO_INDEX));

    return Result::correct();
}

std::string Controller::personNotFoundMessage(const std::string& name, const Container& from) const{
    return "La personne du nom de " + name + " n'a pas été trouvée sur le " + (&from == &_boat ? "bateau" : "bord actuel");
}


Result Controller::embark(const std::string& name) {

    if(_boat.getSize() == Boat::getMaxCapacity()){
        return Result::invalid("Le bateau ne peut pas contenir plus de 2 personnes");
    }
    return movePerson(name, *_boat.getCurrentBank(), _boat);
}

Result Controller::disembark(const std::string& name) {
    return movePerson(name, _boat, *_boat.getCurrentBank());
}

Result Controller::moveBoat() {
    if(_boat.canMove()) {
        _boat.setNewBank(&_banks.at(&_banks.at(LEFT) == _boat.getCurrentBank() ? RIGHT : LEFT));
        return Result::correct();
    } else return Result::invalid("Aucune personne embarquée ne peut conduire le bateau");
}

void Controller::print() const {
    static const std::string DELIMITER(LINE_LENGTH, '-');
    static const std::string RIVER(LINE_LENGTH, '=');

    std::cout << DELIMITER << std::endl << _banks.at(LEFT).toString() << std::endl << DELIMITER << std::endl;

    if (_boat.getCurrentBank() == &_banks.at(RIGHT)) {
        std::cout << RIVER << std::endl << _boat.toString() << std::endl;
    } else {
        std::cout << _boat.toString() << std::endl << RIVER << std::endl;
    }

    std::cout << DELIMITER << std::endl << _banks.at(RIGHT).toString() << std::endl << DELIMITER << std::endl;
}

void Controller::reset() {
    for(auto& bank : _banks)
        bank.clear();
    _boat.clear();

    fillLeftBank();
}

void Controller::fillLeftBank() {
    for (const auto& person : _persons) {
        _banks.at(LEFT).add(person);
    }
}

bool Controller::hasWon() const {  return _banks.at(RIGHT).getSize() == _persons.size();}

Controller& Controller::getInstance() {
    static Controller instance;
    return instance;
}