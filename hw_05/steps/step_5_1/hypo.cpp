#include "hypo.hpp"
#include <cmath>

namespace hypo_basic {
    double hypotenuse(int a, int b) {
        return std::sqrt(static_cast<double>(a * a + b * b));
    }
}
