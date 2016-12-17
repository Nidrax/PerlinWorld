#ifndef PERLINWORLD_MODEL_CHUNK_H
#define PERLINWORLD_MODEL_CHUNK_H

#include "stdafx.h"

struct Chunk {
	Chunk();
	void Set(unsigned, unsigned, INT16);
	void Set(unsigned, unsigned, unsigned, bool);
	INT16 Get(unsigned, unsigned);
	bool Get(unsigned, unsigned, unsigned);

private:
	std::vector<std::vector<INT16>> heightMap;
		// We create a 16x16 vector to store our terrain height values
	std::vector<std::vector<std::vector<bool>>> isSolid;
		// And a 16x16x256 vector to define if the voxel is solid ground or air
};

#endif // !PERLINWORLD_MODEL_CHUNK_H