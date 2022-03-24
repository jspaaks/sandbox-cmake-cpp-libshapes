#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H

#include "../abstract/shape.hpp"

namespace shapes {

    class Circle : public Shape {
        public:
            Circle(double);
            double calcArea(void) override;
            double radius;
        private:

    };
}

#endif