#include "TIE.h"

TIE::TIE() : TIEModel(counterId<TIE>()) {}

long double TIE::getTotalWeight() const {
    return 6.;
}

unsigned int TIE::getSpeed() const {
    return 100;
}

std::string TIE::typeTIE() const {
    return "LN";
}
