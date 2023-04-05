#include <iostream>
#include <string>

/**
 * @brief An Integral class
 *
 * You can use an inline formula: \f$ f(x) = x^{2} \f$
 *
 * Or a display style formula:
 * @f[
 * \int_a^b f(x) dx = F(b) - F(a)
 * @f]
 */
class Integral {
    /**
     * @brief Define a function to be integrated
     * 
     * @param x The argument of the function
     * @return double 
     */
    double func(double x) {
        return(x*x);
    };
};