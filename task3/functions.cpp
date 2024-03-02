#include "functions.h"
#include <iostream>

void func::second()
{
    std::cout << "2nd function start\n";

    try
    {
        third();
    }
    catch (int e)
    {
        std::cout << "In 2nd function exception of type int was caught (value = " << e << ")\n";
    }
    catch (double e)
    {
        std::cout << "In 2nd function exception of type double was caught (value = " << e << ")\n";
    }
    std::cout << "2nd function end\n";
}

void func::third()
{
    std::cout << "3rd function start\n";

    try
    {
        fourth();
    }
    catch (int e)
    {
        std::cout << "In 3nd function exception of type int was caught (value = " << e << ")\n";
    }
    std::cout << "3rd function end\n";
}

void func::fourth()
{
    std::cout << "4th function start\n";

    fifth();
    std::cout << "4th function end\n";
}

void func::fifth()
{
    std::cout << "5th function start\n";

    sixth();
}


// @throw double
void func::sixth()
{
    std::cout << "6th function start\n";
    throw 3.14;
    std::cout << "6th function end\n";
}
