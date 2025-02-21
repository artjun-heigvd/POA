#ifndef BOY_H
#define BOY_H
#include "../Child.h"
#include "../Parent.h"

/**
 * Represents a Boy, which is a Child with its main parent being the father.
 *
 * @authors Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class Boy : public Child {
public:

    /**
     * Constructor for the Boy class.
     *
     * @param name The name of the child.
     * @param mother The secondary parent of the child.
     * @param father The main parent of the child.
     */
    Boy(std::string name, std::shared_ptr<Parent> mother, std::shared_ptr<Parent> father);

    /**
     * @brief Tells us if the Boy's placement in the container is valid
     * @param container to check the validity of
     * @return a Result object containing a message indicating if the Boy is alone with her mom or not.
     */
    [[nodiscard]] Result isValid(const Container& container) const override;
};

#endif  // BOY_H
