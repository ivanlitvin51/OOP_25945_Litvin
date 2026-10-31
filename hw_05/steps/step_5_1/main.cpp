#include <iostream>
#include "hypo.hpp"
#include "hypo_mod.hpp"

int main() {
    std::cout << "=== Задание 5.I: Сборка в одной директории ===\n";

    int a = 3;
    int b = 4;

    std::cout << "Базовая гипотенуза (" << a << ", " << b << "): "
              << hypo_basic::hypotenuse(a, b) << "\n";

    std::cout << "Модифицированная гипотенуза (рандом) (" << a << ", " << b << "): "
              << hypo_random::hypotenuse(a, b) << "\n";

    return 0;
}
