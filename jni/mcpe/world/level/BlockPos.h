#pragma once

class ChunkPos;
class Vec3;

struct BlockPos {
	int x, y, z;
	
	BlockPos(const ChunkPos&, int);
	BlockPos(const Vec3&);
	BlockPos(float, float, float);
};

