#pragma once

class BlockPos;
class Vec3;

class ChunkPos
{
public:
	int x, z;
	
    ChunkPos(const BlockPos&);
    ChunkPos(const Vec3&);
    float distanceToSqr(const Entity&) const;
    BlockPos getMiddleBlockPosition(int) const;
	
    static ChunkPos INVALID;
};

