#pragma once

#include"../StructurePiece.h"
class BoundingBox;
class BlockSource;
class Random;
class CompoundTag;
class SmallDoorType;

class StrongholdPiece : public StructurePiece {
public:
	virtual ~StrongholdPiece();
	//virtual void addChildren(); //It's to hard to demangle
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);

	void randomSmallDoor(Random&);
	void generateSmallDoor(BlockSource*, Random&, BoundingBox const&, SmallDoorType, int, int, int);
};