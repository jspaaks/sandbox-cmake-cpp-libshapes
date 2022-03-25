#include <libshapes/pointy/rectangle.hpp>


namespace shapes {

    Rectangle::Rectangle(double width, double height)
        : width(width)
        , height(height)
    {};

    double Rectangle::calcArea(void) {
        return width * height;
    }
}