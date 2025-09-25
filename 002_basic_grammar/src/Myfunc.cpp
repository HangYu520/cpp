#include <iostream>
#include "Myfunc.h"

int multiply(int a, int b)
{
    return a * b;
}

void multiplyAndlog(int a, int b)
{
    std::cout << multiply(a, b) << std::endl;
}