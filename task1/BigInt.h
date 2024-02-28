#pragma once

#include <iostream>
#include <vector>
#include <cstdint>
namespace BigInt{class BigInt;}

std::istream &operator>>(std::istream &stream, BigInt::BigInt &big_number);

std::ostream &operator<<(std::ostream &stream, const BigInt::BigInt &big_number);

BigInt::BigInt &operator+=(BigInt::BigInt &, const BigInt::BigInt &);
BigInt::BigInt operator+(const BigInt::BigInt &, const BigInt::BigInt &);
BigInt::BigInt &operator*=(BigInt::BigInt &, const BigInt::BigInt &);
BigInt::BigInt operator*(const BigInt::BigInt &, const BigInt::BigInt &);
BigInt::BigInt &operator-=(BigInt::BigInt &, const BigInt::BigInt &);
BigInt::BigInt operator-(const BigInt::BigInt &, const BigInt::BigInt &);

namespace BigInt{
/**
 * @brief Represents an integer with an arbitrary length.
 */
class BigInt
{
public:
    /**
     * @brief Default constructor.
     */
    BigInt();

    /**
     * @brief Construct a BigInt object with an non-negative integer it will represent.
     * @param number The number to initialize BigInt with.
     */
    BigInt(unsigned int number);

    /**
     * @brief Construct BigInt with a string representation of a number. It may ONLY contain decimal digits.
     * @param str The string representation of the non-negative number.
     */
    BigInt(std::string str);

    /**
     * @brief Convert a BigInt to a string representation of the number. It will ONLY contain decimal digits.
     *
     * @return The string representation.
     */
    operator std::string();

    friend BigInt &(::operator+=)(BigInt &, const BigInt &);
    friend BigInt (::operator+)(const BigInt &, const BigInt &);
    friend BigInt &(::operator*=)(BigInt &, const BigInt &);
    friend BigInt (::operator*)(const BigInt &, const BigInt &);
    friend BigInt &(::operator-=)(BigInt &, const BigInt &);
    friend BigInt (::operator-)(const BigInt &, const BigInt &);

    friend std::ostream &::operator<<(std::ostream &, const BigInt &);

private:
    std::vector<int8_t> storage;
};


/**
 * @brief Calculates the factorial of a number.
 * 
 * @param number The number to calculate the factorial for.
 * 
 * @return The factorial of the number represented as BigInt.
 */
BigInt factorial(int number);

/**
 * @brief Calculates the power of a base to an exponent.
 * 
 * @param base The base number.
 * @param exponent The exponent number.
 * 
 * @return The result of exponentiation represented as Bigint.
 */
BigInt power(BigInt base, int exponent);

/**
 * @brief Calculates the `number`th Fibonacci number.
 * 
 * @param number The number.
 * 
 * @return The `number`th number in Fibonacci sequence.
 */
BigInt fibonacci(int number);
}

