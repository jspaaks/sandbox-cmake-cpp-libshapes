#include <shapes/round/circle.hpp>
#include <math.h>

namespace shapes {

    Circle::Circle(double radius)
        : radius(radius)
    {};

    double Circle::calcArea(void) {
        return M_PI * std::pow(radius, 2);
    }
}