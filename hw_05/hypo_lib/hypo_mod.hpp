#pragma once
#include "hypo.hpp"
#include <random>

namespace hypo_random {
    template <typename T>
    double hypotenuse(T a, T b) {
        double res = hypo_basic::hypotenuse(a, b);

        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> coin(0, 1);
        static std::uniform_real_distribution<double> bonus(1.0, 10.0);

        if (coin(gen) == 1) {
            res += bonus(gen);
        }
        return res;
    }
}
