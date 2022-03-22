#include "addition.hpp"

namespace operations {

int subtract(int a, int b) {
    return operations::add(b, -1 * a);
}

}