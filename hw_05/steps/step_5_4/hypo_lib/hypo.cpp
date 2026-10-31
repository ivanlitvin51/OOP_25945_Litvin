#include "hypo.hpp"
#include <cmath>

namespace hypo_basic {
    // Реализация функции: sqrt(a^2 + b^2)
    double hypotenuse(int a, int b) {
        return std::sqrt(static_cast<double>(a * a + b * b));
    }
}
