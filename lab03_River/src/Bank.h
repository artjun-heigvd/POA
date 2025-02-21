#ifndef BANK_H
#define BANK_H
#include "Container.h"

/**
 * Container with all the persons on the bank
 *
 * @authors Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class Bank : public Container {
public:

    /**
     * Constructor
     *
     * @param name the name of the bank
     */
    explicit Bank(std::string name);
};

#endif  // BANK_H
