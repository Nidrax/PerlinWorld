#include "stdafx.h"

PerlinNoise::PerlinNoise(unsigned int seed) {
	p.resize(256);

	std::iota(p.begin(), p.end(), 0);			// Fills vector p with consecutive values starting from 0
	std::default_random_engine engine(seed);	// Generates random engine for shuffling
	std::shuffle(p.begin(), p.end(), engine);	// Shuffles the vector p

	p.insert(p.end(), p.begin(), p.end());		// We double the permutation vector
}

float PerlinNoise::Noise(float x, float y, float z) {
	// CPP implementation of Ken Perlin's Improved Noise found at http://cs.nyu.edu/~perlin/noise/

	int X = (int)floor(x) & 255,
		Y = (int)floor(y) & 255,
		Z = (int)floor(z) & 255;
	x -= floor(x);
	y -= floor(y);
	z -= floor(z);
	float u = Fade(x),
		v = Fade(y),
		w = Fade(z);
	int A = p[X] + Y, AA = p[A] + Z, AB = p[A + 1] + Z,
		B = p[X + 1] + Y, BA = p[B] + Z, BB = p[B + 1] + Z;

	return (Lerp(w, Lerp(v, Lerp(u, Gradient(p[AA], x, y, z),
		Gradient(p[BA], x - 1, y, z)),
		Lerp(u, Gradient(p[AB], x, y - 1, z),
			Gradient(p[BB], x - 1, y - 1, z))),
		Lerp(v, Lerp(u, Gradient(p[AA + 1], x, y, z - 1),
			Gradient(p[BA + 1], x - 1, y, z - 1)),
			Lerp(u, Gradient(p[AB + 1], x, y - 1, z - 1),
				Gradient(p[BB + 1], x - 1, y - 1, z - 1)))));
}