#include <iostream>
#include "addition.hpp"


int main()
{
    int a = 6;
    int b = 9;
    int sum = operations::add(a, b);
    std::cout << "The sum of " << a << " and " << b << " is " << sum << ".\n";
}
