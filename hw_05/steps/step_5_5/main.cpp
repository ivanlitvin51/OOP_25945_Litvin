#include <iostream>
#include "hypo.hpp"
#include "hypo_mod.hpp"

int main() {
    // 1. Обычная гипотенуза для целых чисел (int)
    int a_int = 3;
    int b_int = 4;
    std::cout << "hypo_basic (int): " << hypo_basic::hypotenuse(a_int, b_int) << "\n";

    // 2. Обычная гипотенуза для дробных чисел (double)
    double a_dbl = 2.5;
    double b_dbl = 6.0;
    std::cout << "hypo_basic (double): " << hypo_basic::hypotenuse(a_dbl, b_dbl) << "\n";

    // 3. Гипотенуза с рандомным бонусом (несколько запусков для наглядности)
    std::cout << "\nhypo_random:\n";
    for (int i = 1; i <= 5; ++i) {
        std::cout << "запуск " << i << ": " << hypo_random::hypotenuse(a_int, b_int) << "\n";
    }

    return 0;
}
