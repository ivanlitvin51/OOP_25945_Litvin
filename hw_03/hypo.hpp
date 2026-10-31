#pragma once
#include <cmath>

namespace hypo_basic {

	template <typename T>
	T hypotenuse(T a, T b) {
		double res = std::sqrt(a * a + b * b);
		return res;
	}
}