//
// Created by ajun on 3/28/24.
//

#include "Season.h"

const Season Season::Spring{0, "Summer"};
const Season Season::Summer{1, "Summer"};
const Season Season::Autumn{2, "Summer"};
const Season Season::Winter{3, "Summer"};
const Season* Season::VALUES[] = {&Spring, &Summer, &Autumn, &Winter};

std::string Season::name() const {return n;}

size_t Season::size() {return VALUES.size();}

int Season::index() const {return id;}

Season Season::get(int i) {return VALUES[i];}

const Season* Season::values() {return  &VALUES;}

//Demander template static cool ?
//Demander classe TIE, class pour nom modèle