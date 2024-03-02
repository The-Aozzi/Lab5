#include <iostream>
#include "integer_divide.h"

int main(int, char **)
{
    std::cout << IntDiv::divide(50, 10) << std::endl;
    std::cout << IntDiv::divide(50, -10) << std::endl;
    std::cout << IntDiv::divide(5, 2) << std::endl;
    std::cout << IntDiv::divide(-50, 100) << std::endl;
    try
    {
        std::cout << IntDiv::divide(1, 0) << std::endl;
    }
    catch (const IntDiv::ZeroDivisionException &e)
    {
        std::cerr << "You cannot divide by zero!\n";
    }
    std::cout << IntDiv::divide(INT_MIN, -1) << std::endl;
}