#ifndef GIRL_H
#define GIRL_H
#include "../Child.h"
#include "../Parent.h"

/**
 * Represents a Girl, which is a Child with its main parent being the mother.
 *
 * @authors Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class Girl : public Child {
public:

    /**
     * Constructor for the Girl class.
     *
     * @param name The name of the child.
     * @param mother The main parent of the child.
     * @param father The secondary parent of the child.
     */
    Girl(std::string name, std::shared_ptr<Parent> mother, std::shared_ptr<Parent> father);

    /**
     * @brief Tells us if the Girl's placement in the container is valid
     * @param container to check the validity of
     * @return a Result object containing a message indicating if the Girl is alone with her dad or not.
     */
    [[nodiscard]] Result isValid(const Container& container) const override;
};

#endif  // GIRL_H
