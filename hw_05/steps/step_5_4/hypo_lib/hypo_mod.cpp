#include "hypo_mod.hpp"
#include "hypo.hpp"
#include <random>

namespace hypo_random {
    double hypotenuse(int a, int b) {
        double res = hypo_basic::hypotenuse(a, b);

        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> coin(0, 1);
        static std::uniform_real_distribution<double> bonus(1.0, 10.0);

        if (coin(gen) == 0) {
            res += bonus(gen);
        }

        return res;
    }
}
