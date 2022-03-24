#ifndef SHAPES_RECTANGLE_H
#define SHAPES_RECTANGLE_H

#include "../abstract/shape.hpp"

namespace shapes {

    class Rectangle : public Shape {

        public:
            
            Rectangle(double, double);
            double calcArea(void) override;
            double height;
            double width;

        private:

    };
}

#endif
