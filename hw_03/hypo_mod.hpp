#pragma once
#include "hypo.hpp"
#include <random>

namespace hypo_random {
	template <typename T>
	T hypotenuse(T a, T b) {

		T res = hypo_basic::hypotenuse(a, b);

		static std::random_device rd;
		static std::mt19937 gen(rd());
		static std::uniform_int_distribution<int> coin(0, 1);
		static std::uniform_real_distribution<double> bonus(1, 10);

		if (coin(gen) == 0) {
			res += static_cast<T>(bonus(gen));
		}

		return res;
	}
}