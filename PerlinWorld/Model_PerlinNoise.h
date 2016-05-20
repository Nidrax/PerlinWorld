// implementation of improved Ken Perlin's noise: http://cs.nyu.edu/~perlin/noise/ | http://mrl.nyu.edu/~perlin/paper445.pdf

#pragma once

#include "stdafx.h"

class PerlinNoise {
	std::vector<int> p;

public:
	PerlinNoise(unsigned int);

	float Noise(float, float, float);

private:
	template <typename T>
	inline T Fade(T v) { return v * v * v * (v * (v * 6 - 15) + 10); }
};