#pragma once

#include "stdafx.h"

class PerlinNoise {
	std::vector<int> p;

public:
	PerlinNoise(unsigned int);

	float Noise(float, float, float);

private:
	template <typename T>
	inline T Fade(T v) {
		return v * v * v * (v * (v * 6 - 15) + 10);
	}
};