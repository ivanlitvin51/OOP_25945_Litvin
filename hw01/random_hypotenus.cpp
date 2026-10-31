#include <random>

int random_hypotenuse(int x, int y) {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    int num = std::uniform_int_distribution<int>(1, 100)(gen);

    if (num % 2 == 0) {
        return std::sqrt(x * x + y * y);
    }
    x += num;
    y -= num;

    return std::sqrt(x * x + y * y);
}