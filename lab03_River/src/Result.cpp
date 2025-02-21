#include "Result.h"

Result::Result() : reason(), status(true) {}

Result::Result(std::string reason) : reason(std::move(reason)), status(false) {}

const Result &Result::correct() {
    static Result ok;
    return ok;
}

Result Result::invalid(std::string reason) {
    return Result(std::move(reason));
}


