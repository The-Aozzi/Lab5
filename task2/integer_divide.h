#pragma once
#include <exception>

namespace IntDiv
{
    class ZeroDivisionException : std::exception
    {
    };

    /**
     * @brief
     * @param numerator
     * @param denominator
     * @return
     * @throw ZeroDivisionException
     */
    int divide(int numerator, int denominator);
}