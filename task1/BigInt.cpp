#include "BigInt.h"

BigInt::BigInt::BigInt() : BigInt(0) {}

BigInt::BigInt::BigInt(unsigned int number)
{
    do
    {
        storage.push_back(number % 10);
        number /= 10;
    } while (number);
}

BigInt::BigInt::BigInt(std::string str)
{
    for (size_t i = 0; i < storage.size(); ++i)
    {
        storage[str.size() - 1 - i] = str[i] - '0';
    }
}

BigInt::BigInt::operator std::string()
{
    std::string str(storage.size(), 0);
    for (size_t i = 0; i < storage.size(); ++i)
    {
        str[i] = storage[str.size() - 1 - i] + '0';
    }
    return str;
}

    BigInt::BigInt &operator+=(BigInt::BigInt &left, const BigInt::BigInt &right)
    {
        int8_t carry = 0;

        size_t max_size = std::max(left.storage.size(), right.storage.size());
        left.storage.reserve(max_size + 1);
        left.storage.resize(max_size);

        for (size_t i = 0; i < right.storage.size() || carry; ++i)
        {
            if (i < right.storage.size())
            {
                left.storage[i] += right.storage[i] + carry;
            }
            else
            {
                if (i == left.storage.size())
                {
                    left.storage.push_back(carry);
                    break;
                }
                left.storage[i] += carry;
            }
            carry = left.storage[i] / 10;
            left.storage[i] %= 10;
        }
        return left;
    }

    BigInt::BigInt operator+(const BigInt::BigInt &left, const BigInt::BigInt &right)
    {
        BigInt::BigInt result = left;
        result += right;
        return result;
    }

    BigInt::BigInt &operator*=(BigInt::BigInt &left, const BigInt::BigInt &right)
    {
        BigInt::BigInt result;

        result.storage.resize(left.storage.size() + right.storage.size());

        for (size_t i = 0; i < right.storage.size(); ++i)
        {
            int8_t carry = 0;
            for (size_t j = 0; j < left.storage.size() || carry; ++j)
            {
                int8_t product = result.storage[i + j] + (j < left.storage.size() ? right.storage[i] * left.storage[j] : 0) + carry;
                result.storage[i + j] = product % 10;
                carry = product / 10;
            }
        }

        while (result.storage.size() > 1 && result.storage.back() == 0)
            result.storage.pop_back();

        left.storage = std::move(result.storage);
        return left;
    }

    BigInt::BigInt operator*(const BigInt::BigInt &left, const BigInt::BigInt &right)
    {
        BigInt::BigInt result = left;
        result *= right;
        return result;
    }

    BigInt::BigInt &operator-=(BigInt::BigInt &left, const BigInt::BigInt &right)
    {
        int8_t borrow = 0;
        for (size_t i = 0; i < right.storage.size() || borrow; ++i)
        {
            int8_t subtrahend = (i < right.storage.size()) ? right.storage[i] : 0;
            left.storage[i] -= subtrahend + borrow;
            if (left.storage[i] < 0)
            {
                left.storage[i] += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
        }
        while (left.storage.size() > 1 && left.storage.back() == 0)
            left.storage.pop_back();
        return left;
    }

    BigInt::BigInt operator-(const BigInt::BigInt &left, const BigInt::BigInt &right)
    {
        BigInt::BigInt result = left;
        result -= right;
        return result;
    }


BigInt::BigInt BigInt::factorial(int number)
{
    BigInt result = 1;
    while (number)
        result *= number--;
    return result;
}

BigInt::BigInt BigInt::power(BigInt base, int exponent)
{
    BigInt result = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
        {
            result *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    return result;
}

BigInt::BigInt BigInt::fibonacci(int number)
{
    BigInt fibonacci_pair[2] = {0, 1};
    for (; number > 1; number -= 2)
    {
        fibonacci_pair[0] += fibonacci_pair[1];
        fibonacci_pair[1] += fibonacci_pair[0];
    }
    return fibonacci_pair[number];
}

std::istream &operator>>(std::istream &stream, BigInt::BigInt &big_number)
{
    std::string input;
    stream >> input;
    big_number = input;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const BigInt::BigInt &big_number)
{
    for (size_t i = 0; i < big_number.storage.size(); ++i)
    {
        stream << +big_number.storage[big_number.storage.size() - 1 - i];
    }
    return stream;
}
