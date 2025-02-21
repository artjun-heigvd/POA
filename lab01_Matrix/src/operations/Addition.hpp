#pragma once

#include "../Operation.hpp"

/**
 * @brief A class to add two long long integers
 * @authors Arthur Junod, Samuel Roland, Edwin Haffner
 * @date 2024-02-29
 */
class Addition : public Operation {
public:
    [[nodiscard]] long long operate(long long first,
                                    long long second) const override;
};
