#include "ShipCargo.h"
#include <iomanip>

ShipCargo::ShipCargo(long double load, unsigned int id, long double capacity)
    : Ship(id), load(validateLoad(load, capacity)) {}

std::ostream& ShipCargo::formatToStream(std::ostream& os) const {
    Ship::formatToStream(os);  // Call base class toString
    os << "\ncargo: " << load << " (max : " << std::fixed
       << std::setprecision(1) << getCapacity() << ")";
    return os;
}

long double ShipCargo::getTotalWeight() const {
    return getWeight() + load;
}
long double ShipCargo::validateLoad(long double loadTest,
                                    long double capacity) {
    if (loadTest <= capacity && loadTest >= 0) {
        return loadTest;
    } else {
        throw std::invalid_argument(
            "Load of a ship cannot be negative or higher than it's capacity");
    }
}

std::string ShipCargo::getModel() const {
    return getClass() + "-class " + getNameModel();
}