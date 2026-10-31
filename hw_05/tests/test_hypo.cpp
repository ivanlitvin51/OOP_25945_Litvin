#include <gtest/gtest.h>
#include <cmath>
#include "hypo.hpp"
#include "hypo_mod.hpp"

// 1. Тесты базовой функции (int и double)
TEST(HypoBasicTest, IntValues) {
    EXPECT_DOUBLE_EQ(hypo_basic::hypotenuse(3, 4), 5.0);
    EXPECT_DOUBLE_EQ(hypo_basic::hypotenuse(6, 8), 10.0);
}

TEST(HypoBasicTest, DoubleValues) {
    EXPECT_DOUBLE_EQ(hypo_basic::hypotenuse(2.5, 6.0), 6.5);
    EXPECT_NEAR(hypo_basic::hypotenuse(1.0, 1.0), std::sqrt(2.0), 1e-9);
}

// 2. Тест функции со случайным бонусом
TEST(HypoRandomTest, RangeCheck) {
    for (int i = 0; i < 50; ++i) {
        double res = hypo_random::hypotenuse(3, 4);
        EXPECT_GE(res, 5.0);
        EXPECT_LE(res, 15.0);
    }
}

// 3. Демонстрация различия EXPECT и ASSERT (Задание 5.III.4)

// EXPECT: тест регистрирует ошибку на 1-й строке, но ПРОДОЛЖАЕТ работу и проверяет 2-ю строку
TEST(ExpectVsAssert, ExpectFailsAndContinues) {
    EXPECT_DOUBLE_EQ(hypo_basic::hypotenuse(3, 4), 999.0); // упадет
    EXPECT_DOUBLE_EQ(hypo_basic::hypotenuse(3, 4), 5.0);   // выполнится
}

// ASSERT: тест регистрирует ошибку на 1-й строке и МГНОВЕННО прерывает тест (2-я строка не вызовется)
TEST(ExpectVsAssert, AssertFailsAndStops) {
    ASSERT_DOUBLE_EQ(hypo_basic::hypotenuse(3, 4), 999.0); // упадет и сделает return
    EXPECT_DOUBLE_EQ(hypo_basic::hypotenuse(3, 4), 5.0);   // не выполнится
}
