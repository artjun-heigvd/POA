#include "Squadron.h"

#include <iomanip>
#include <limits>
#include <utility>

void Squadron::init() {
    this->first = nullptr;
    this->last = nullptr;
    this->headShip = nullptr;
    this->size = 0;
}

Squadron::Squadron(std::string name) : name(std::move(name)) {
    init();
}

Squadron::~Squadron() {
    deleteNodes();
}

void Squadron::deleteNodes() {
    Node* through = first;
    while (through != nullptr) {
        Node* next = through->next;
        delete through;
        through = next;
    }
    init();  // Reset the values
}

void Squadron::copyShips(const Squadron& other) {
    if (this == &other)
        return;  // Check for self assignment

    try {
        for (const Node* curr = other.first; curr != nullptr;
             curr = curr->next) {
            addShipToThis(*curr->ship);
        }
        headShip = other.headShip;
    } catch (std::bad_alloc&) {
        // If we run out of memory, we need to delete all the ships we have
        // already copied
        deleteNodes();
        throw;
    }
}

void Squadron::exchange(Squadron& other) {
    headShip = std::exchange(other.headShip, nullptr);
    first = std::exchange(other.first, nullptr);
    last = std::exchange(other.last, nullptr);
    size = std::exchange(other.size, 0);
}

Squadron::Squadron(const Squadron& other) : name(other.name) {
    init();
    copyShips(other);
}

Squadron::Squadron(Squadron&& other) noexcept : name(std::move(other.name)) {
    exchange(other);
}

Squadron& Squadron::operator=(const Squadron& other) {
    if (this != &other) {
        name = other.name;
        deleteNodes();
        copyShips(other);
    }
    return *this;
}

Squadron& Squadron::operator=(Squadron&& other) noexcept {
    if (this != &other) {
        std::string thisName = std::move(other.name);
        deleteNodes();
        exchange(other);
    }
    return *this;
}

long double Squadron::getTotalWeight() const {
    long double weightSquadron = 0;
    for (const Node* curr = first; curr != nullptr; curr = curr->next) {
        weightSquadron += curr->ship->getTotalWeight();
    }
    return weightSquadron;
}

unsigned int Squadron::getMaxSpeed() const {
    // If the squadron is empty of ship, just return 0
    if (isEmpty())
        return 0;

    unsigned int maxSpeed = std::numeric_limits<unsigned int>::max();
    for (const Node* curr = first; curr != nullptr; curr = curr->next) {
        maxSpeed = std::min(maxSpeed, curr->ship->getSpeed());
    }
    return maxSpeed;
}

bool Squadron::belongToSquadron(const Ship& ship) const {
    for (const Node* curr = first; curr != nullptr; curr = curr->next) {
        if (curr->ship == &ship) {
            return true;
        }
    }
    return false;
}

void Squadron::setLeader(Ship& leader) {
    if (belongToSquadron(leader)) {
        headShip = &leader;
    } else {
        throw std::invalid_argument(
            "The ship provided doesn't belong to the squadron");
    }
}

void Squadron::dethroneLeader() {
    headShip = nullptr;
}

bool Squadron::isEmpty() const {
    return first == nullptr;
}

long double Squadron::fuelConsRide(unsigned int speed,
                                   long double distance) const {
    if (speed > getMaxSpeed()) {
        throw std::invalid_argument(
            "Speed given is not reachable by this squadron");
    }
    distance = std::abs(distance);  // It doesn't matter if the distance is
                                    // negative, distance is distance...

    if (isEmpty() || distance == 0.0 || speed == 0)
        return 0;  // Shouldn't throw exception if the squadron is empty

    long double fuelCons = 0;

    for (const Node* curr = first; curr != nullptr; curr = curr->next) {
        fuelCons += curr->ship->getConsommation(distance, speed);
    }
    return fuelCons;
}

Ship& Squadron::getShip(size_t index) const {
    if (index >= size) {
        throw std::out_of_range(
            "Index given is out of range for this squadron");
    }
    Node* through = first;
    for (size_t i = 0; i < index; i++) {
        through = through->next;
    }
    return *through->ship;
}

Squadron* Squadron::addShip(Ship& ship) {
    Squadron* nS{this};
    return &nS->addShipToThis(ship);
}

Squadron& Squadron::addShipToThis(Ship& ship) {
    Node* newNode = new Node{&ship, nullptr};
    if (first == nullptr) {
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    ++size;
    return *this;
}

Squadron* Squadron::removeShip(Ship& ship) {
    Squadron* nS{this};
    return &nS->removeShipFromThis(ship);
}

Squadron& Squadron::removeShipFromThis(Ship& ship) {
    Node* through = first;
    Node* previous = nullptr;
    while (through != nullptr) {
        if (through->ship == &ship) {
            if (previous == nullptr) {
                // Ship is in the first node
                first = through->next;
            } else {
                previous->next = through->next;
            }
            delete through;
            --size;
            break;
        }
        previous = through;
        through = through->next;
    }
    // Ship not found in the list
    return *this;
}

Squadron& Squadron::operator+=(Ship& ship) {
    return addShipToThis(ship);
}
Squadron& Squadron::operator-=(Ship& ship) {
    return removeShipFromThis(ship);
}

std::ostream& Squadron::formatToStream(std::ostream& os) const {
    std::stringstream ss;
    ss << "Squadron: " << name << "\n";
    ss << "max speed: " << getMaxSpeed() << " MGLT\n";
    ss << "total weight: " << std::fixed << std::setprecision(2)
       << getTotalWeight() << " tons\n";
    if (!isEmpty()) {
        // Doing a stringstream, so we can edit out the last \n

        if (headShip != nullptr) {
            ss << "-- Leader:\n";
            headShip->formatToStream(ss) << "\n";
        }
        if (headShip == nullptr || first->next != nullptr ||
            headShip != first->ship) {
            ss << "-- Members:\n";
            Node* through = first;
            // Append to ss every and each ships in the squadron that are not
            // the headShip
            while (through != nullptr) {
                if (through->ship != headShip) {
                    through->ship->formatToStream(ss) << "\n";
                }
                through = through->next;
            }
        }
    }
    std::string result = ss.str();
    // remove the last "\n"
    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }
    os << result;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Squadron& squadron) {
    return squadron.formatToStream(os);
}

Squadron Squadron::operator+(Ship& rhs) const {
    Squadron newSquadron{*this};
    newSquadron.addShipToThis(rhs);  // Add the ship to the copy
    return std::move(newSquadron);
}

Squadron Squadron::operator-(Ship& rhs) const {
    Squadron newSquadron{*this};  // Create a copy of the left-hand side object
    newSquadron.removeShipFromThis(rhs);  // Add the ship to the copy
    return std::move(newSquadron);
}

Squadron operator+(Ship& lhs, const Squadron& rhs) {
    return rhs + lhs;
}

Squadron operator-(Ship& lhs, const Squadron& rhs) {
    return rhs - lhs;
}
