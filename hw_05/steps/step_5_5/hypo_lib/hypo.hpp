#pragma once
#include <cmath>

namespace hypo_basic {
    template <typename T>
    double hypotenuse(T a, T b) {
        double da = static_cast<double>(a);
        double db = static_cast<double>(b);
        return std::sqrt(da * da + db * db);
    }
}
