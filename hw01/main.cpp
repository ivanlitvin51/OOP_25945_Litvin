#include "hypotenuse.hpp"
#include "random_hypotenuse.hpp"
#include <iostream>
#include <ostream>

int main() {
    int x, y;
    std::cout << "Katet A and B: ";
    std::cin >> x >> y;

    int res_1 = hypotenuse(x, y);
    int res_2 = random_hypotenuse(x, y);

    std::cout << "Default: " << res_1 << '\n';
    std::cout << "Mod: " << res_2;

    return 0;
}
