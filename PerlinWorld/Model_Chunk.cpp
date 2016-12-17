#include "stdafx.h"

Chunk::Chunk() {
	heightMap.resize(ChunkWidthX, std::vector<INT16>(ChunkWidthY));
	isSolid.resize(ChunkWidthX, std::vector<std::vector<bool>>
		(ChunkWidthY, std::vector<bool>(ChunkHeight)));
}

void Chunk::Set(unsigned x, unsigned y, INT16 val) {
	heightMap[x][y] = val;
}

void Chunk::Set(unsigned x, unsigned y, unsigned z, bool val) {
	isSolid[x][y][z] = val;
}

INT16 Chunk::Get(unsigned x, unsigned y) {
	return heightMap[x][y];
}

bool Chunk::Get(unsigned x, unsigned y, unsigned z) {
	return isSolid[x][y][z];
}