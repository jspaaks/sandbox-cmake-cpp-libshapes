#include "circle.hpp"


Circle::Circle(double radius)
    : radius_(radius)
{
};


double Circle::calcArea(void) {
    return 3.14 * radius_ * radius_;
}
