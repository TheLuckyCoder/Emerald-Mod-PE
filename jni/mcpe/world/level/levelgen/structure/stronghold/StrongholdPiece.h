#pragma once

#include"../StructurePiece.h"
class BoundingBox;
class BlockSource;
class Random;
class CompoundTag;
class SmallDoorType;

class StrongholdPiece : public StructurePiece {
public:
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;
	int x;
	int y;
	int z;

	~StrongholdPiece();
	void randomSmallDoor(Random&);
	void generateSmallDoor(BlockSource*, Random&, BoundingBox const&, SmallDoorType, int, int, int);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};