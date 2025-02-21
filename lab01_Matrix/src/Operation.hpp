#ifndef OPERATION_HPP
#define OPERATION_HPP

/**
 * @brief A class to represent an operation on two long long integers
 * @authors Arthur Junod, Samuel Roland, Edwin Haffner
 * @date 2024-02-29
 */
class Operation {
public:
    virtual inline ~Operation() = default;

    [[nodiscard]] virtual inline long long operate(long long first,
                                                   long long second) const = 0;
};

#endif  // OPERATION_HPP