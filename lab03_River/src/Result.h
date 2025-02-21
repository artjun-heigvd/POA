#ifndef RESULT_H
#define RESULT_H

#include <optional>
#include <string>
#include <utility>

/**
 * Represents the results of operations.
 *
 * @authors Junod Arthur, Roland Samuel, Häffner Edwin
 * @date 18.04.2024
 */
class Result {
public:
    const std::optional<std::string> reason;
    const bool status;

    static Result invalid(std::string reason);
    static const Result& correct();
private:

    /**
     * Constructor of a Result object.
     * @param reason the reason of the result.
     */
    explicit Result(std::string reason);
    Result();
};

#endif  // RESULT_H
