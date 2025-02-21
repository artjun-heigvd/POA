#include "TIEModel.h"

TIEModel::TIEModel(unsigned int id) : Ship(id) {}

std::string TIEModel::getModel() const {
    return "TIE/" + typeTIE();
}