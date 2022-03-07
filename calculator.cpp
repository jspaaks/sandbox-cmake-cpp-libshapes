#include <iostream>
#include "addition.hpp"
#include "subtraction.hpp"


int main()
{
    int a = 6;
    int b = 9;
    int sum = operations::add(a, b);
    int diff = operations::subtract(a, b);
    std::cout << "Adding " << a << " to " << b << " is equal to " << sum << ".\n";
    std::cout << "Subtracting " << a << " from " << b << " is equal to " << diff << ".\n";
}
