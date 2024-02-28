#include <iostream>


int divide(int numerator, int denominator){
    if (denominator == 0){
        throw;
    }
    if (numerator == 0){
        return 0;
    }
    if (numerator == INT_MIN && denominator == -1){
        return INT_MAX;
    }

    bool negative_flag = (numerator < 0) != (denominator < 0);
    
    if (numerator < 0) numerator = -numerator;
    if (denominator > 0) denominator = -denominator;

    int result = 0;
    while(numerator > -denominator){
        numerator += denominator;
        ++result;
    }

    if (negative_flag){
        return -result;
    }else{
        return result;
    }


}

int main(int, char**){
    std::cout << divide(INT_MIN, -1);
}