#include "circle.hpp"
#include <math.h>


Circle::Circle(double radius)
    : radius(radius)
{
};


double Circle::calcArea(void) {
    return M_PI * std::pow(radius, 2);
}
