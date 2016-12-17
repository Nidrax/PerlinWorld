#include "stdafx.h"

PerlinNoise::PerlinNoise(unsigned int seed) {
	p.resize(ChunkHeight);

	std::iota(p.begin(), p.end(), 0);			
		// Fills vector p with consecutive values starting from 0
	std::default_random_engine engine(seed);	
		// Generates random engine for shuffling
	std::shuffle(p.begin(), p.end(), engine);	
		// Shuffles the vector p

	p.insert(p.end(), p.begin(), p.end());		
		// We double the permutation vector
}

float PerlinNoise::Noise(float x, float y, float z) {
	int X = (int)floor(x) & (ChunkHeight - 1),
		Y = (int)floor(y) & (ChunkHeight - 1),
		Z = (int)floor(z) & (ChunkHeight - 1);
	x -= floor(x);
	y -= floor(y);
	z -= floor(z);
	float u = Fade(x),
		v = Fade(y),
		w = Fade(z);
	int A = p[X] + Y, AA = p[A] + Z, AB = p[A + 1] + Z,
		B = p[X + 1] + Y, BA = p[B] + Z, BB = p[B + 1] + Z;

	return (BasicLerp(w, BasicLerp(v, BasicLerp(u, Gradient(p[AA], x, y, z),
		Gradient(p[BA], x - 1, y, z)),
		BasicLerp(u, Gradient(p[AB], x, y - 1, z),
			Gradient(p[BB], x - 1, y - 1, z))),
		BasicLerp(v, BasicLerp(u, Gradient(p[AA + 1], x, y, z - 1),
			Gradient(p[BA + 1], x - 1, y, z - 1)),
			BasicLerp(u, Gradient(p[AB + 1], x, y - 1, z - 1),
				Gradient(p[BB + 1], x - 1, y - 1, z - 1)))));
}