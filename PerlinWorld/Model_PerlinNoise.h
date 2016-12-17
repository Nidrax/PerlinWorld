// implementation of improved Ken Perlin's noise: http://cs.nyu.edu/~perlin/noise/ | http://mrl.nyu.edu/~perlin/paper445.pdf

#ifndef PERLINWORLD_MODEL_PERLINNOISE_H
#define PERLINWORLD_MODEL_PERLINNOISE_H

#include "stdafx.h"

struct PerlinNoise {
	PerlinNoise(unsigned int);
	float Noise(float, float, float);

private:
	std::vector<int> p;
	template <typename T>
	inline T Fade(T v) { return v * v * v * (v * (v * 6 - 15) + 10); }
};

#endif // !PERLINWORLD_MODEL_PERLINNOISE_H