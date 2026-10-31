#include <iostream>
#include "hypo.hpp"
#include "hypo_mod.hpp"

int main() {
    int a = 3;
    int b = 4;

    std::cout << "hypo_basic(int): " << hypo_basic::hypotenuse(a, b) << "\n";
    std::cout << "hypo_random: " << hypo_random::hypotenuse(a, b) << "\n";

    return 0;
}
