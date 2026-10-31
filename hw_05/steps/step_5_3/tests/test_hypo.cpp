#include <gtest/gtest.h>
#include "hypo.hpp"
#include "hypo_mod.hpp"

// 1. Тест обычной гипотенузы для int
TEST(HypoBasicTest, IntValues) {
    EXPECT_DOUBLE_EQ(hypo_basic::hypotenuse(3, 4), 5.0);
    EXPECT_DOUBLE_EQ(hypo_basic::hypotenuse(6, 8), 10.0);
}

// 2. Тест гипотенузы с рандомом
TEST(HypoRandomTest, RangeCheck) {
    for (int i = 0; i < 50; ++i) {
        double res = hypo_random::hypotenuse(3, 4);
        EXPECT_GE(res, 5.0);
        EXPECT_LE(res, 15.0);
    }
}

// 3. Демонстрация различия EXPECT и ASSERT (Задание 5.III.4)

// EXPECT: падает на 1-й строке, но проверяет 2-ю
TEST(ExpectVsAssert, ExpectFailsAndContinues) {
    EXPECT_DOUBLE_EQ(hypo_basic::hypotenuse(3, 4), 999.0);
    EXPECT_DOUBLE_EQ(hypo_basic::hypotenuse(3, 4), 5.0);
}

// ASSERT: падает на 1-й строке и сразу завершает тест (2-я строка не запустится)
TEST(ExpectVsAssert, AssertFailsAndStops) {
    ASSERT_DOUBLE_EQ(hypo_basic::hypotenuse(3, 4), 999.0);
    EXPECT_DOUBLE_EQ(hypo_basic::hypotenuse(3, 4), 5.0);
}
