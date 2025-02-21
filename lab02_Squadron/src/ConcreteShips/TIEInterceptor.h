#pragma once

#include "../TIEModel.h"

/**
 * The TIE interceptor class
 * @author Haeffner Edwin
 * @author Junod Arthur
 * @author Roland Samuel
 */
class TIEInterceptor : public TIEModel {
public:
    /**
     * The constructor of our TIE interceptor
     */
    TIEInterceptor();

    /**
     * The weight of our TIE interceptor
     * @return the weight
     */
    [[nodiscard]] long double getTotalWeight() const override;

    /**
     * The speed of our TIE interceptor
     * @return the speed
     */
    [[nodiscard]] unsigned int getSpeed() const override;

private:
    /**
     * The type "interceptor" (IN) in string
     * @return type "interceptor"
     */
    [[nodiscard]] std::string typeTIE() const override;
};
