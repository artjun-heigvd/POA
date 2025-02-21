#include "Ship.h"

#include <cmath>
#include <iomanip>
#include <stdexcept>

std::ostream& operator<<(std::ostream& os, const Ship& ship) {
    return ship.formatToStream(os);
}

std::ostream& Ship::formatToStream(std::ostream& os) const {
    os << (nickName.has_value() ? nickName.value() + " " : "") << "["
       << getModel() << " #" << id << "]\n";
    os << "weight : " << std::fixed << std::setprecision(2) << getTotalWeight()
       << " tons\n";
    os << "max speed : " << getSpeed() << " MGLT";
    return os;
}

long double Ship::getConsommation(long double distance,
                                  unsigned int speed) const {
    if (speed > getSpeed()) {
        throw std::invalid_argument(
            "Speed given is higher than the speed of our ship");
    } else {
        return (cbrt(static_cast<double>(getTotalWeight())) / 2) *
               std::log10(getTotalWeight() * speed) * std::log10(distance + 1);
    }
}

void Ship::setNickname(const std::string& nick) {
    nickName =
        nick.empty() ? std::optional<std::string>{} : std::optional{nick};
}

Ship::Ship(unsigned int id) {
    this->id = id;
}