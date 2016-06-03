#include "stdafx.h"

int main(int argc, char *argv[]) {
	unsigned seed = 130993;
	PerlinNoise pn(seed);
	ReSeed(&seed);
	PerlinNoise pn2(seed);

	for (unsigned m = 0; m != Map.size(); ++m) {
		for (unsigned n = 0; n != Map[0].size(); ++n) {

			for (unsigned i = 0; i < ChunkWidthX; ++i) {
				for (unsigned j = 0; j < ChunkWidthY; ++j) {
					float x = (float)(m * ChunkWidthX + i) / ((float)ChunkHeight);
					float y = (float)(n * ChunkWidthY + j) / ((float)ChunkHeight);

					float o = pn.Noise(x, y, 0.5f);
					o = o - floor(o);

					Map[m][n].Set(i, j, (INT16)floor((ChunkHeight-1) * o + 1));
				}
			}

			for (unsigned i = 0; i < ChunkWidthX; ++i) {
				for (unsigned j = 0; j < ChunkWidthY; ++j) {
					for (unsigned k = 0; k < ChunkHeight; ++k) {
						float x = (float)(m * ChunkWidthX + i) / ((float)ChunkHeight);
						float y = (float)(n * ChunkWidthY + j) / ((float)ChunkHeight);
						float z = (float)k / ((float)ChunkHeight);

						float o = pn2.Noise(x, y, z);
						o = o - floor(o);

						Map[m][n].Set(i, j, k, o > 0.2f);
					}
				}
			}

		}
	}

	ViewInit(argc, argv);

    return 0;
}