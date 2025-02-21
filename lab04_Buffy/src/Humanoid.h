#ifndef BUFFY_HUMANOID_H
#define BUFFY_HUMANOID_H

#include <cstddef>
#include <memory>
#include "utilities/Point.h"

class Field;
class Action;

/**
 * @class Humanoid
 * @brief A class representing a humanoid entity in the game.
 *
 * This class is a base class for different types of humanoid entities in the game.
 * It provides the basic functionalities that all humanoid entities should have.
 *
 * @note This class is designed to be inherited by other classes.
 */
class Humanoid : public std::enable_shared_from_this<Humanoid> {
public:

    /**
     * @class Iterator
     * @brief An iterator class for iterating over Humanoid objects.
     */
    struct Iterator {
        explicit Iterator(Humanoid* ptr) : _ptr(ptr) {}

        Humanoid& operator*() const { return *_ptr; };
        Humanoid* operator->() { return _ptr; };

        Iterator& operator++() {
            _ptr++;
            return *this;
        }
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator& a, const Iterator& b) { return a._ptr == b._ptr; };
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a._ptr != b._ptr; };

    private:
        Humanoid* _ptr;
    };

    /**
     * @enum Type
     * @brief An enumeration of the different types of humanoid entities.
     */
    enum class Type { HUMAN, VAMPIRE, BUFFY };

    Humanoid(size_t maxX, size_t maxY);
    explicit Humanoid(const Point& pos);
    virtual ~Humanoid() = default;

    /**
     * @brief A pure virtual function for setting the action of the humanoid.
     *
     * @param f The field on which the action is to be set.
     */
    virtual void setAction(Field& f) = 0;

    /**
     * @brief Executes the action of the humanoid on a given field.
     *
     * @param f The field on which the action is to be executed.
     */
    void executeAction(Field& f);

    /**
     * @brief Sets the position of the humanoid.
     *
     * @param p The new position of the humanoid.
     */
    void setPosition(Point p);

    /**
     * @brief Gets the position of the humanoid.
     *
     * @return The position of the humanoid.
     */
    [[nodiscard]] Point getPosition() const;

    /**
     * @brief Checks if the humanoid is alive.
     *
     * @return True if the humanoid is alive, false otherwise.
     */
    [[nodiscard]] bool isAlive() const;

    /**
     * @brief A pure virtual function for getting the type of the humanoid.
     *
     * @return The type of the humanoid.
     */
    [[nodiscard]] virtual Type getType() const = 0;

    /**
     * @brief A pure virtual function for getting the amount of movement of the humanoid.
     *
     * @return The amount of movement of the humanoid.
     */
    [[nodiscard]] virtual std::size_t getMoveAmount() const = 0;

    /**
     * @brief Marks the humanoid as dead.
     */
    void dies();

protected:
    Point _position;
    bool _alive;
    std::shared_ptr<Action> _action;
};

#include "Action.h"
#include "Field.h"

#endif  // BUFFY_HUMANOID_H
