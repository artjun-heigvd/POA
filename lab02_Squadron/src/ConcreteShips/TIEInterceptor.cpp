#include "TIEInterceptor.h"

TIEInterceptor::TIEInterceptor() : TIEModel(counterId<TIEInterceptor>()) {}

std::string TIEInterceptor::typeTIE() const {
    return "IN";
}

unsigned int TIEInterceptor::getSpeed() const {
    return 110;
}

long double TIEInterceptor::getTotalWeight() const {
    return 5;
}
