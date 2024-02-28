#include <iostream>
#include "BigInt.h"

int main(int, char **)
{
    unsigned int input_1;
    unsigned int input_2;

    std::cin >> input_1;
    std::cout << BigInt::factorial(input_1) << std::endl;

    std::cin >> input_1;
    std::cout << BigInt::power(2, input_1) << std::endl;

    std::cin >> input_1 >> input_2;
    std::cout << BigInt::power(2, input_1) + BigInt::power(2, input_2) << std::endl;

    std::cin >> input_1 >> input_2;
    while (input_1 < input_2)
    {
        std::cout << "The first number should be greater or equal than the second number!" << std::endl;
        std::cin >> input_1 >> input_2;
    }
    std::cout << BigInt::power(2, input_1) - BigInt::power(2, input_2) << std::endl;

    std::cin >> input_1;
    std::cout << BigInt::fibonacci(input_1) << std::endl;

    return 0;
}