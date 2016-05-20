#include "stdafx.h"

std::vector<std::vector<INT16>> heightMap(64, std::vector<INT16>(64));	// We create a 16x16 vector to store our terrain height values
std::vector<std::vector<std::vector<bool>>> isSolid(64, std::vector<std::vector<bool>>(64, std::vector<bool>(64)));	// And a 16x16x256 vector to define if the voxel is solid ground or air

int main(int argc, char *argv[]) {
	unsigned int seed = 13091993;
	PerlinNoise pn(seed);
	std::cout << seed << std::endl;
	ReSeed(&seed);
	PerlinNoise pn2(seed);
	std::cout << seed << std::endl << std::endl;

	for (unsigned int i = 0; i < 64; i++) {
		for (unsigned int j = 0; j < 64; j++) {
			float x = (float)i / ((float)64);
			float y = (float)j / ((float)64);

			float n = 20 * pn.Noise(x, y, 0.3f);
			n = n - floor(n);

			heightMap[i][j] = (INT16)floor(64 * n);
		}
	}

	for (unsigned int i = 0; i < 64; i++) {
		for (unsigned int j = 0; j < 64; j++) {
			for (unsigned int k = 0; k < 64; k++) {
				float x = (float)i / ((float)64);
				float y = (float)j / ((float)64);
				float z = (float)k / ((float)64);

				float n = 20 * pn2.Noise(x, y, z);
				n = n - floor(n);

				isSolid[i][j][k] = (n > 0.2f);
			}
		}
	}

	ViewInit(argc, argv);

    return 0;
}